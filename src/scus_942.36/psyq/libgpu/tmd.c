#include "common.h"
#include "psyq/libgpu.h"
#include "psyq/libgs.h"

#define LOAD_SVECTOR_XYZ(dest, base, index, offset) do { \
    (dest).vx = (*(SVECTOR *)((index * 8) + base)).vx; \
    (dest).vy = (*(SVECTOR *)((index * 8) + base)).vy; \
    (dest).vz = (*(SVECTOR *)((index * 8) + base)).vz; \
} while(0)

typedef struct {
    int vert;
    int nvert;
    int norm;
    int nnorm;
    int prim;
    int nprim;
    int scaling;
} TmdObj;

typedef struct {
    int id;
    int flags;
    int nobj;
    TmdObj obj[1];
} TMD;

extern u32* D_8009B290;
extern s32 D_8009B294;
extern s32 D_8009B298;
extern s32 D_8009B29C;
extern s32 D_8009B2A0;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", OpenTIM);
int OpenTIM(u_long* addr)
{
    D_8009B290 = addr;
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ReadTIM);
TIM_IMAGE* ReadTIM(TIM_IMAGE* timimg)
{
    s32 addr;
    addr = get_tim_addr(D_8009B290, timimg);
    if (addr == -1) {
        return 0;
    }
    D_8009B290 = &D_8009B290[addr];
    return timimg;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", OpenTMD);
int OpenTMD(u_long* tmd, int obj_no)
{
    D_8009B2A0 = get_tmd_addr(
        tmd,
        obj_no,
        &D_8009B29C,
        &D_8009B294,
        &D_8009B298
    );
    return D_8009B2A0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ReadTMD);
TMD_PRIM* ReadTMD(TMD_PRIM* tmdprim)
{
    s32 packet;
    packet = unpack_packet((u8* ) D_8009B29C, tmdprim);
    if (packet < 0) return 0;
    
    D_8009B29C += packet;
    tmdprim->v_ofs = (SVECTOR*)(D_8009B294);
    tmdprim->n_ofs = (SVECTOR*)(D_8009B298);
    
    LOAD_SVECTOR_XYZ(tmdprim->n0, D_8009B298, tmdprim->norm0, 0);
    LOAD_SVECTOR_XYZ(tmdprim->n1, D_8009B298, tmdprim->norm1, 0);
    LOAD_SVECTOR_XYZ(tmdprim->n2, D_8009B298, tmdprim->norm2, 0);
    LOAD_SVECTOR_XYZ(tmdprim->n3, D_8009B298, tmdprim->norm3, 0);
    LOAD_SVECTOR_XYZ(tmdprim->x0, D_8009B294, tmdprim->vert0, 0);
    LOAD_SVECTOR_XYZ(tmdprim->x1, D_8009B294, tmdprim->vert1, 0);
    LOAD_SVECTOR_XYZ(tmdprim->x2, D_8009B294, tmdprim->vert2, 0);
    LOAD_SVECTOR_XYZ(tmdprim->x3, D_8009B294, tmdprim->vert3, 0);
    return tmdprim;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_tim_addr);
s32 get_tim_addr(u32* timaddr, TIM_IMAGE* img) {
    unsigned int clut_len;
    unsigned int img_len;
    if (*(int*)timaddr++ != 0x10) {
        return -1;
    }
    img->mode = *timaddr++;
    if (GetGraphDebug() == 2) {
        printf("id  =%08x\n", 0x10);
    }
    if (GetGraphDebug() == 2) {
        printf("mode=%08x\n", img->mode);
    }
    if (GetGraphDebug() == 2) {
        printf("timaddr=%08x\n", timaddr);
    }
    if (img->mode & 8) {
        clut_len = *timaddr >> 2;
        img->crect = (RECT*)(timaddr + 1);
        img->caddr = (u_long*)(timaddr + 3);
        timaddr = &timaddr[clut_len];
    } else {
        img->crect = NULL;
        img->caddr = NULL;
        clut_len = 0;
    }
    img_len = *timaddr >> 2;
    img->prect = (RECT*)(timaddr + 1);
    img->paddr = (u_long*)(timaddr + 3);
    return 2 + clut_len + img_len;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_tmd_addr);
u_long get_tmd_addr(
    TMD* tmd, int objid, u_long** t_prim, u_long** v_ofs, u_long** n_ofs) {
    TmdObj* obj = tmd->obj;
    if (GetGraphDebug() == 2) {
        printf("analizing TMD...\n");
    }
    if (GetGraphDebug() == 2) {
        printf("\tid=%08X, flags=%d, nobj=%d, objid=%d\n", tmd->id, tmd->flags,
               tmd->nobj, objid);
    }
    if (GetGraphDebug() == 2) {
        printf("\tvert=%08X, nvert=%d\n", obj[objid].vert, obj[objid].nvert);
    }
    if (GetGraphDebug() == 2) {
        printf("\tnorm=%08X, nnorm=%d\n", obj[objid].norm, obj[objid].nnorm);
    }
    if (GetGraphDebug() == 2) {
        printf("\tprim=%08X, nprim=%d\n", obj[objid].prim, obj[objid].nprim);
    }
    *v_ofs = (u_long*)((unsigned char*)obj + obj[objid].vert);
    *n_ofs = (u_long*)((unsigned char*)obj + obj[objid].norm);
    *t_prim = (u_long*)((unsigned char*)obj + obj[objid].prim);
    return obj[objid].nprim;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", unpack_packet);
s32 unpack_packet(PACKET* arg0, TMD_PRIM* arg1) {
    s32 temp_v0;
    u32 temp_v1;
    memset(arg1, 0, sizeof(TMD_PRIM));
    temp_v0 = *(u32*)(&arg0[0]);
    temp_v1 = temp_v0 & 0xFDFFFFFF;
    arg1->id = (u32)temp_v0;
    switch (temp_v1) {
    case 0x20000304: // F3L
        if (GetGraphDebug() == 2) {
            printf("F3L ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0xA]);
        arg1->vert1 = *(u16*)(&arg0[0xC]);
        arg1->vert2 = *(u16*)(&arg0[0xE]);
        arg1->norm0 = *(u16*)(&arg0[0x8]);
        arg1->norm1 = *(u16*)(&arg0[0x8]);
        arg1->norm2 = *(u16*)(&arg0[0x8]);
        return 0x10;
    case 0x30000406: // G3L
        if (GetGraphDebug() == 2) {
            printf("G3L ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0xA]);
        arg1->vert1 = *(u16*)(&arg0[0xE]);
        arg1->vert2 = *(u16*)(&arg0[0x12]);
        arg1->norm0 = *(u16*)(&arg0[0x8]);
        arg1->norm1 = *(u16*)(&arg0[0xC]);
        arg1->norm2 = *(u16*)(&arg0[0x10]);
        return 0x14;
    case 0x24000507: // FT3L
        if (GetGraphDebug() == 2) {
            printf("FT3L ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->vert0 = *(u16*)(&arg0[0x12]);
        arg1->vert1 = *(u16*)(&arg0[0x14]);
        arg1->vert2 = *(u16*)(&arg0[0x16]);
        arg1->norm0 = *(u16*)(&arg0[0x10]);
        arg1->norm1 = *(u16*)(&arg0[0x10]);
        arg1->norm2 = *(u16*)(&arg0[0x10]);
        return 0x18;
    case 0x34000609: // GT3L
        if (GetGraphDebug() == 2) {
            printf("GT3L ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->vert0 = *(u16*)(&arg0[0x12]);
        arg1->vert1 = *(u16*)(&arg0[0x16]);
        arg1->vert2 = *(u16*)(&arg0[0x1A]);
        arg1->norm0 = *(u16*)(&arg0[0x10]);
        arg1->norm1 = *(u16*)(&arg0[0x14]);
        arg1->norm2 = *(u16*)(&arg0[0x18]);
        return 0x1C;
    case 0x21010304: // F3
        if (GetGraphDebug() == 2) {
            printf("F3 ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0x8]);
        arg1->vert1 = *(u16*)(&arg0[0xA]);
        arg1->vert2 = *(u16*)(&arg0[0xC]);
        return 0x10;
    case 0x31010506: // G3
        if (GetGraphDebug() == 2) {
            printf("G3 ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x8];
        arg1->g1 = arg0[0x9];
        arg1->b1 = arg0[0xA];
        arg1->r2 = arg0[0xC];
        arg1->g2 = arg0[0xD];
        arg1->b2 = arg0[0xE];
        arg1->vert0 = *(u16*)(&arg0[0x10]);
        arg1->vert1 = *(u16*)(&arg0[0x12]);
        arg1->vert2 = *(u16*)(&arg0[0x14]);
        return 0x18;
    case 0x25010607: //FT3
        if (GetGraphDebug() == 2) {
            printf("FT3 ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->r0 = arg0[0x10];
        arg1->g0 = arg0[0x11];
        arg1->b0 = arg0[0x12];
        arg1->r1 = arg0[0x10];
        arg1->g1 = arg0[0x11];
        arg1->b1 = arg0[0x12];
        arg1->r2 = arg0[0x10];
        arg1->g2 = arg0[0x11];
        arg1->b2 = arg0[0x12];
        arg1->vert0 = *(u16*)(&arg0[0x14]);
        arg1->vert1 = *(u16*)(&arg0[0x16]);
        arg1->vert2 = *(u16*)(&arg0[0x18]);
        return 0x1C;
    case 0x35010809: // GT3
        if (GetGraphDebug() == 2) {
            printf("GT3 ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->vert0 = *(u16*)(&arg0[0x1C]);
        arg1->vert1 = *(u16*)(&arg0[0x1E]);
        arg1->vert2 = *(u16*)(&arg0[0x20]);
        arg1->r0 = arg0[0x10];
        arg1->g0 = arg0[0x11];
        arg1->b0 = arg0[0x12];
        arg1->r1 = arg0[0x14];
        arg1->g1 = arg0[0x15];
        arg1->b1 = arg0[0x16];
        arg1->r2 = arg0[0x18];
        arg1->g2 = arg0[0x19];
        arg1->b2 = arg0[0x1A];
        return 0x24;
    case 0x28000405: // F4L
        if (GetGraphDebug() == 2) {
            printf("F4L ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->r3 = arg0[0x4];
        arg1->g3 = arg0[0x5];
        arg1->b3 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0xA]);
        arg1->vert1 = *(u16*)(&arg0[0xC]);
        arg1->vert2 = *(u16*)(&arg0[0xE]);
        arg1->vert3 = *(u16*)(&arg0[0x10]);
        arg1->norm0 = *(u16*)(&arg0[0x8]);
        arg1->norm1 = *(u16*)(&arg0[0x8]);
        arg1->norm2 = *(u16*)(&arg0[0x8]);
        arg1->norm3 = *(u16*)(&arg0[0x8]);
        return 0x14;
    case 0x38000508: //G4L
        if (GetGraphDebug() == 2) {
            printf("G4L ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->r3 = arg0[0x4];
        arg1->g3 = arg0[0x5];
        arg1->b3 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0xA]);
        arg1->vert1 = *(u16*)(&arg0[0xE]);
        arg1->vert2 = *(u16*)(&arg0[0x12]);
        arg1->vert3 = *(u16*)(&arg0[0x16]);
        arg1->norm0 = *(u16*)(&arg0[0x8]);
        arg1->norm1 = *(u16*)(&arg0[0xC]);
        arg1->norm2 = *(u16*)(&arg0[0x10]);
        arg1->norm3 = *(u16*)(&arg0[0x14]);
        return 0x18;
    case 0x2C000709: // FT4L
        if (GetGraphDebug() == 2) {
            printf("FT4L ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->u3 = arg0[0x10];
        arg1->v3 = arg0[0x11];
        arg1->vert0 = *(u16*)(&arg0[0x16]);
        arg1->vert1 = *(u16*)(&arg0[0x18]);
        arg1->vert2 = *(u16*)(&arg0[0x1A]);
        arg1->vert3 = *(u16*)(&arg0[0x1C]);
        arg1->norm0 = *(u16*)(&arg0[0x14]);
        arg1->norm1 = *(u16*)(&arg0[0x14]);
        arg1->norm2 = *(u16*)(&arg0[0x14]);
        arg1->norm3 = *(u16*)(&arg0[0x14]);
        return 0x20;
    case 0x3C00080C: // GT4L
        if (GetGraphDebug() == 2) {
            printf("GT4L ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->u3 = arg0[0x10];
        arg1->v3 = arg0[0x11];
        arg1->vert0 = *(u16*)(&arg0[0x16]);
        arg1->vert1 = *(u16*)(&arg0[0x1A]);
        arg1->vert2 = *(u16*)(&arg0[0x1E]);
        arg1->vert3 = *(u16*)(&arg0[0x22]);
        arg1->norm0 = *(u16*)(&arg0[0x14]);
        arg1->norm1 = *(u16*)(&arg0[0x18]);
        arg1->norm2 = *(u16*)(&arg0[0x1C]);
        arg1->norm3 = *(u16*)(&arg0[0x20]);
        return 0x24;
    case 0x29010305: // F4
        if (GetGraphDebug() == 2) {
            printf("F4 ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->r3 = arg0[0x4];
        arg1->g3 = arg0[0x5];
        arg1->b3 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0x8]);
        arg1->vert1 = *(u16*)(&arg0[0xA]);
        arg1->vert2 = *(u16*)(&arg0[0xC]);
        arg1->vert3 = *(u16*)(&arg0[0xE]);
        return 0x10;
    case 0x39010608: // G4
        if (GetGraphDebug() == 2) {
            printf("G4 ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x8];
        arg1->g1 = arg0[0x9];
        arg1->b1 = arg0[0xA];
        arg1->r2 = arg0[0xC];
        arg1->g2 = arg0[0xD];
        arg1->b2 = arg0[0xE];
        arg1->r3 = arg0[0x10];
        arg1->g3 = arg0[0x11];
        arg1->b3 = arg0[0x12];
        arg1->vert0 = *(u16*)(&arg0[0x14]);
        arg1->vert1 = *(u16*)(&arg0[0x16]);
        arg1->vert2 = *(u16*)(&arg0[0x18]);
        arg1->vert3 = *(u16*)(&arg0[0x1A]);
        return 0x1C;
    case 0x2D010709: // FT4
        if (GetGraphDebug() == 2) {
            printf("FT4 ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->u3 = arg0[0x10];
        arg1->v3 = arg0[0x11];
        arg1->r0 = arg0[0x14];
        arg1->g0 = arg0[0x15];
        arg1->b0 = arg0[0x16];
        arg1->r1 = arg0[0x14];
        arg1->g1 = arg0[0x15];
        arg1->b1 = arg0[0x16];
        arg1->r2 = arg0[0x14];
        arg1->g2 = arg0[0x15];
        arg1->b2 = arg0[0x16];
        arg1->r3 = arg0[0x14];
        arg1->g3 = arg0[0x15];
        arg1->b3 = arg0[0x16];
        arg1->vert0 = *(u16*)(&arg0[0x18]);
        arg1->vert1 = *(u16*)(&arg0[0x1A]);
        arg1->vert2 = *(u16*)(&arg0[0x1C]);
        arg1->vert3 = *(u16*)(&arg0[0x1E]);
        return 0x20;
    case 0x3D010A0C: // GT4
        if (GetGraphDebug() == 2) {
            printf("GT4 ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->u3 = arg0[0x10];
        arg1->v3 = arg0[0x11];
        arg1->vert0 = *(u16*)(&arg0[0x24]);
        arg1->vert1 = *(u16*)(&arg0[0x26]);
        arg1->vert2 = *(u16*)(&arg0[0x28]);
        arg1->vert3 = *(u16*)(&arg0[0x2A]);
        arg1->r0 = arg0[0x14];
        arg1->g0 = arg0[0x15];
        arg1->b0 = arg0[0x16];
        arg1->r1 = arg0[0x18];
        arg1->g1 = arg0[0x19];
        arg1->b1 = arg0[0x1A];
        arg1->r2 = arg0[0x1C];
        arg1->g2 = arg0[0x1D];
        arg1->b2 = arg0[0x1E];
        arg1->r3 = arg0[0x20];
        arg1->g3 = arg0[0x21];
        arg1->b3 = arg0[0x22];
        return 0x2C;
    default: // unsupported type
        printf("unsupported type (%08x)\n", arg1->id & 0xFDFFFFFF);
        return -1;
    }
}

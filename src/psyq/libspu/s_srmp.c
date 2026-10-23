#include "common.h"
#include "libspu_internal.h"

u32 _spu_rev_startaddr_d[20] asm("_spu_rev_startaddr") = {
    0x0000FFFE, 0x0000FB28, 0x0000FC18, 0x0000F6F8,
    0x0000F204, 0x0000EA44, 0x0000E128, 0x0000CFF8,
    0x0000CFF8, 0x0000F880, 0x00000002, 0x000004D8,
    0x000003D8, 0x00000908, 0x00000DFC, 0x000015BC,
    0x00001ED8, 0x00003008, 0x00003008, 0x00000780,
};
u32 D_80097D00_d[170] asm("D_80097D00") = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x005B007D, 0x54B86D80,
    0x0000BED0, 0xBA800000, 0x53005800, 0x033304D6,
    0x022703F0, 0x01EF0374, 0x01B50334, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x013601B4,
    0x005C00B8, 0x80008000, 0x00000000, 0x00250033,
    0x4FA870F0, 0x4410BCE0, 0x9C00C0F0, 0x4EC05280,
    0x031B03E4, 0x02AF03A4, 0x02660372, 0x025D031C,
    0x018E025C, 0x0135022F, 0x00B701D2, 0x00B5018F,
    0x008000B4, 0x0026004C, 0x80008000, 0x00000000,
    0x007F00B1, 0x4FA870F0, 0x4510BCE0, 0xB4C0BEF0,
    0x4EC05280, 0x076B0904, 0x065F0824, 0x061607A2,
    0x05ED076C, 0x042E05EC, 0x0305050F, 0x02B70462,
    0x0265042F, 0x01B20264, 0x00800100, 0x80008000,
    0x00000000, 0x00A900E3, 0x4FA86F60, 0x4510BCE0,
    0xA680BEF0, 0x52C05680, 0x0B580DFB, 0x0A3C0D09,
    0x09730BD9, 0x08DA0B59, 0x05E908D9, 0x04B007EC,
    0x03D206EF, 0x031D05EA, 0x0238031C, 0x00AA0154,
    0x80008000, 0x00000000, 0x013901A5, 0x50006000,
    0xB8004C00, 0xC000BC00, 0x5C006000, 0x11BB15BA,
    0x10BD14C2, 0x0DC111BC, 0x0DC311C0, 0x09C10DC0,
    0x07C10BC4, 0x06CD0A00, 0x05C109C2, 0x041A05C0,
    0x013A0274, 0x80008000, 0x00000000, 0x0231033D,
    0x50007E00, 0xB000B400, 0xB0004C00, 0x54006000,
    0x1A311ED6, 0x183B1D14, 0x16B21BC2, 0x15EF1A32,
    0x105515EE, 0x0F2D1334, 0x0C5D11F6, 0x0AE11056,
    0x07A20AE0, 0x02320464, 0x80008000, 0x00000000,
    0x00010001, 0x7FFF7FFF, 0x00000000, 0x81000000,
    0x00000000, 0x0FFF1FFF, 0x00051005, 0x00000000,
    0x00051005, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x10021004, 0x00020004, 0x80008000,
    0x00000000, 0x00010001, 0x7FFF7FFF, 0x00000000,
    0x00000000, 0x00000000, 0x0FFF1FFF, 0x00051005,
    0x00000000, 0x00051005, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x10021004, 0x00020004,
    0x80008000, 0x00000000, 0x00130017, 0x4FA870F0,
    0x4510BCE0, 0x8500BEF0, 0x54C05F80, 0x02AF0371,
    0x01DF02E5, 0x01D702B0, 0x026A0358, 0x011E01D6,
    0x00B1012D, 0x0059011F, 0x00E301A0, 0x00400058,
    0x00140028, 0x80008000,
};

#define SPU_REV_ATTR_DAPF1 (0x01 << 0)
#define SPU_REV_ATTR_DAPF2 (0x01 << 1)
#define SPU_REV_ATTR_VIIR (0x01 << 2)
#define SPU_REV_ATTR_VCOMB1 (0x01 << 3)
#define SPU_REV_ATTR_VCOMB2 (0x01 << 4)
#define SPU_REV_ATTR_VCOMB3 (0x01 << 5)
#define SPU_REV_ATTR_VCOMB4 (0x01 << 6)
#define SPU_REV_ATTR_VWALL (0x01 << 7)
#define SPU_REV_ATTR_VAPF1 (0x01 << 8)
#define SPU_REV_ATTR_VAPF2 (0x01 << 9)
#define SPU_REV_ATTR_MLSAME (0x01 << 10)
#define SPU_REV_ATTR_MRSAME (0x01 << 11)
#define SPU_REV_ATTR_MLCOMB1 (0x01 << 12)
#define SPU_REV_ATTR_MRCOMB1 (0x01 << 13)
#define SPU_REV_ATTR_MLCOMB2 (0x01 << 14)
#define SPU_REV_ATTR_MRCOMB2 (0x01 << 15)
#define SPU_REV_ATTR_DLSAME (0x01 << 16)
#define SPU_REV_ATTR_DRSAME (0x01 << 17)
#define SPU_REV_ATTR_MLDIFF (0x01 << 18)
#define SPU_REV_ATTR_MRDIFF (0x01 << 19)
#define SPU_REV_ATTR_MLCOMB3 (0x01 << 20)
#define SPU_REV_ATTR_MRCOMB3 (0x01 << 21)
#define SPU_REV_ATTR_MLCOMB4 (0x01 << 22)
#define SPU_REV_ATTR_MRCOMB4 (0x01 << 23)
#define SPU_REV_ATTR_DLDIFF (0x01 << 24)
#define SPU_REV_ATTR_DRDIFF (0x01 << 25)
#define SPU_REV_ATTR_MLAPF1 (0x01 << 26)
#define SPU_REV_ATTR_MRAPF1 (0x01 << 27)
#define SPU_REV_ATTR_MLAPF2 (0x01 << 28)
#define SPU_REV_ATTR_MRAPF2 (0x01 << 29)
#define SPU_REV_ATTR_VLIN (0x01 << 30)
#define SPU_REV_ATTR_VRIN (0x01 << 31)

extern struct rev_param_entry D_80097D00[];
void _spu_setReverbAttr(struct rev_param_entry* arg0);
static inline void _memcpy(char* dst, char* src, size_t size) {
    while (size--) {
        *dst++ = *src++;
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_srmp", SpuSetReverbModeParam);

long SpuSetReverbModeParam(SpuReverbAttr* attr) {
    struct rev_param_entry entry;
    u32 var_s0;
    u16 cnt;

    bool var_s7 = false;
    bool var_s4 = false;
    bool var_s6 = false;
    bool sp58 = false;
    bool var_fp = false;

    u32 mask = attr->mask;
    bool bSetAll = attr->mask == 0;

    entry.flags = 0;
    if (bSetAll || mask & SPU_REV_MODE) {
        var_s0 = attr->mode;
        if (attr->mode & SPU_REV_MODE_CLEAR_WA) {
            var_s0 &= ~SPU_REV_MODE_CLEAR_WA;
            sp58 = true;
        }
        if (var_s0 >= 0xA ||
            _SpuIsInAllocateArea_(_spu_rev_startaddr[var_s0])) {
            return -1;
        }
        var_s4 = true;
        _spu_rev_attr.unk18 = var_s0;
        _spu_rev_offsetaddr = _spu_rev_startaddr[_spu_rev_attr.unk18];
        _memcpy(&entry, &D_80097D00[_spu_rev_attr.unk18],
                sizeof(struct rev_param_entry));
        switch (_spu_rev_attr.unk18) {
        case SPU_REV_MODE_ECHO:
            _spu_rev_attr.unk24 = 0x7F;
            _spu_rev_attr.unk20 = 0x7F;
            break;
        case SPU_REV_MODE_DELAY:
            _spu_rev_attr.unk24 = 0;
            _spu_rev_attr.unk20 = 0x7F;
            break;
        default:
            _spu_rev_attr.unk24 = 0;
            _spu_rev_attr.unk20 = 0;
            break;
        }
    }
    if (bSetAll || mask & SPU_REV_DELAYTIME) {
        switch (_spu_rev_attr.unk18) {
        case SPU_REV_MODE_ECHO:
        case SPU_REV_MODE_DELAY:
            var_s6 = true;
            if (!var_s4) {
                _memcpy(&entry, &D_80097D00[_spu_rev_attr.unk18],
                        sizeof(struct rev_param_entry));
                entry.flags = SPU_REV_ATTR_MLSAME | SPU_REV_ATTR_MRSAME |
                              SPU_REV_ATTR_MLCOMB1 | SPU_REV_ATTR_DLSAME |
                              SPU_REV_ATTR_MLAPF1 | SPU_REV_ATTR_MRAPF1;
            }
            _spu_rev_attr.unk20 = attr->delay;
            entry.mLSAME = ((_spu_rev_attr.unk20 << 0xD) / 0x7F) - entry.dAPF1;
            entry.mRSAME = ((_spu_rev_attr.unk20 << 0xC) / 0x7F) - entry.dAPF2;
            entry.mLCOMB1 =
                ((_spu_rev_attr.unk20 << 0xC) / 0x7F) + entry.mRCOMB1;
            entry.dLSAME = ((_spu_rev_attr.unk20 << 0xC) / 0x7F) + entry.dRSAME;
            entry.mLAPF1 = ((_spu_rev_attr.unk20 << 0xC) / 0x7F) + entry.mLAPF2;
            entry.mRAPF1 = ((_spu_rev_attr.unk20 << 0xC) / 0x7F) + entry.mRAPF2;
            break;
        }
    }
    if (bSetAll || mask & SPU_REV_FEEDBACK) {
        switch (_spu_rev_attr.unk18) {
        case SPU_REV_MODE_ECHO:
        case SPU_REV_MODE_DELAY:
            var_fp = true;
            if (!var_s4) {
                if (!var_s6) {
                    _memcpy(&entry, &D_80097D00[_spu_rev_attr.unk18],
                            sizeof(struct rev_param_entry));
                    entry.flags = SPU_REV_ATTR_VWALL;
                } else {
                    entry.flags |= SPU_REV_ATTR_VWALL;
                }
            }
            _spu_rev_attr.unk24 = attr->feedback;
            entry.vWALL = (_spu_rev_attr.unk24 * 0x8100) / 0x7F;
            break;
        }
    }
    if (var_s4) {
        var_s7 = (_spu_RXX->rxx.spucnt >> 7) & 1;
        if (var_s7) {
            cnt = _spu_RXX->rxx.spucnt;
            cnt &= ~0x80;
            _spu_RXX->rxx.spucnt = cnt;
        }
    }
    if (!var_s4) {
        if (bSetAll || mask & SPU_REV_DEPTHL) {
            _spu_RXX->rxx.rev_vol.left = attr->depth.left;
            _spu_rev_attr.unk1c = attr->depth.left;
        }
        if (bSetAll || mask & SPU_REV_DEPTHR) {
            _spu_RXX->rxx.rev_vol.right = attr->depth.right;
            _spu_rev_attr.unk1e = attr->depth.right;
        }
    } else {
        _spu_RXX->rxx.rev_vol.left = 0;
        _spu_RXX->rxx.rev_vol.right = 0;
        _spu_rev_attr.unk1c = 0;
        _spu_rev_attr.unk1e = 0;
    }
    if (var_s4 || var_s6 || var_fp) {
        _spu_setReverbAttr(&entry);
    }
    if (sp58) {
        SpuClearReverbWorkArea(_spu_rev_attr.unk18);
    }
    if (var_s4) {
        _spu_FsetRXX(0xD1, _spu_rev_offsetaddr, 0);
        if (var_s7) {
            cnt = _spu_RXX->rxx.spucnt;
            cnt |= 0x80;
            _spu_RXX->rxx.spucnt = cnt;
        }
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_srmp", _spu_setReverbAttr);

void _spu_setReverbAttr(struct rev_param_entry* attr) {
    u32 mask = attr->flags;
    int setAll = attr->flags == 0;

    if (setAll || mask & SPU_REV_ATTR_DAPF1) {
        _spu_RXX->rxx.dAPF1 = attr->dAPF1;
    }
    if (setAll || mask & SPU_REV_ATTR_DAPF2) {
        _spu_RXX->rxx.dAPF2 = attr->dAPF2;
    }
    if (setAll || mask & SPU_REV_ATTR_VIIR) {
        _spu_RXX->rxx.vIIR = attr->vIIR;
    }
    if (setAll || mask & SPU_REV_ATTR_VCOMB1) {
        _spu_RXX->rxx.vCOMB1 = attr->vCOMB1;
    }
    if (setAll || mask & SPU_REV_ATTR_VCOMB2) {
        _spu_RXX->rxx.vCOMB2 = attr->vCOMB2;
    }
    if (setAll || mask & SPU_REV_ATTR_VCOMB3) {
        _spu_RXX->rxx.vCOMB3 = attr->vCOMB3;
    }
    if (setAll || mask & SPU_REV_ATTR_VCOMB4) {
        _spu_RXX->rxx.vCOMB4 = attr->vCOMB4;
    }
    if (setAll || mask & SPU_REV_ATTR_VWALL) {
        _spu_RXX->rxx.vWALL = attr->vWALL;
    }
    if (setAll || mask & SPU_REV_ATTR_VAPF1) {
        _spu_RXX->rxx.vAPF1 = attr->vAPF1;
    }
    if (setAll || mask & SPU_REV_ATTR_VAPF2) {
        _spu_RXX->rxx.vAPF2 = attr->vAPF2;
    }
    if (setAll || mask & SPU_REV_ATTR_MLSAME) {
        _spu_RXX->rxx.mLSAME = attr->mLSAME;
    }
    if (setAll || mask & SPU_REV_ATTR_MRSAME) {
        _spu_RXX->rxx.mRSAME = attr->mRSAME;
    }
    if (setAll || mask & SPU_REV_ATTR_MLCOMB1) {
        _spu_RXX->rxx.mLCOMB1 = attr->mLCOMB1;
    }
    if (setAll || mask & SPU_REV_ATTR_MRCOMB1) {
        _spu_RXX->rxx.mRCOMB1 = attr->mRCOMB1;
    }
    if (setAll || mask & SPU_REV_ATTR_MLCOMB2) {
        _spu_RXX->rxx.mLCOMB2 = attr->mLCOMB2;
    }
    if (setAll || mask & SPU_REV_ATTR_MRCOMB2) {
        _spu_RXX->rxx.mRCOMB2 = attr->mRCOMB2;
    }
    if (setAll || mask & SPU_REV_ATTR_DLSAME) {
        _spu_RXX->rxx.dLSAME = attr->dLSAME;
    }
    if (setAll || mask & SPU_REV_ATTR_DRSAME) {
        _spu_RXX->rxx.dRSAME = attr->dRSAME;
    }
    if (setAll || mask & SPU_REV_ATTR_MLDIFF) {
        _spu_RXX->rxx.mLDIFF = attr->mLDIFF;
    }
    if (setAll || mask & SPU_REV_ATTR_MRDIFF) {
        _spu_RXX->rxx.mRDIFF = attr->mRDIFF;
    }
    if (setAll || mask & SPU_REV_ATTR_MLCOMB3) {
        _spu_RXX->rxx.mLCOMB3 = attr->mLCOMB3;
    }
    if (setAll || mask & SPU_REV_ATTR_MRCOMB3) {
        _spu_RXX->rxx.mRCOMB3 = attr->mRCOMB3;
    }
    if (setAll || mask & SPU_REV_ATTR_MLCOMB4) {
        _spu_RXX->rxx.mLCOMB4 = attr->mLCOMB4;
    }
    if (setAll || mask & SPU_REV_ATTR_MRCOMB4) {
        _spu_RXX->rxx.mRCOMB4 = attr->mRCOMB4;
    }
    if (setAll || mask & SPU_REV_ATTR_DLDIFF) {
        _spu_RXX->rxx.dLDIFF = attr->dLDIFF;
    }
    if (setAll || mask & SPU_REV_ATTR_DRDIFF) {
        _spu_RXX->rxx.dRDIFF = attr->dRDIFF;
    }
    if (setAll || mask & SPU_REV_ATTR_MLAPF1) {
        _spu_RXX->rxx.mLAPF1 = attr->mLAPF1;
    }
    if (setAll || mask & SPU_REV_ATTR_MRAPF1) {
        _spu_RXX->rxx.mRAPF1 = attr->mRAPF1;
    }
    if (setAll || mask & SPU_REV_ATTR_MLAPF2) {
        _spu_RXX->rxx.mLAPF2 = attr->mLAPF2;
    }
    if (setAll || mask & SPU_REV_ATTR_MRAPF2) {
        _spu_RXX->rxx.mRAPF2 = attr->mRAPF2;
    }
    if (setAll || mask & SPU_REV_ATTR_VLIN) {
        _spu_RXX->rxx.vLIN = attr->vLIN;
    }
    if (setAll || mask & SPU_REV_ATTR_VRIN) {
        _spu_RXX->rxx.vRIN = attr->vRIN;
    }
}

#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80045EFC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80046264);
extern void func_8004637C(void);
extern void func_80046CDC(void);
extern void func_8004AD8C(void);
extern void func_8004AFAC(void);
extern void func_8004D0C0(void);
extern void func_8004CFE0(void);
extern void func_8004DB3C(void);
extern void func_8004DC34(void);
extern void func_8004DD14(void);
extern void func_8004F5A4(void);
extern void func_8011AF78(void);
extern void func_8004E3EC(void);
extern void func_8004FB54(s32);
extern s16 D_1F8001C6;

void func_80046264(void)
{
    s32 u;
    SetLightMatrix(D_1F800118);
    func_8004637C();
    func_80046CDC();
    func_8004AD8C();
    func_8004AFAC();
    func_8004D0C0();
    func_8004CFE0();
    func_8004DB3C();
    func_8004DC34();
    func_8004DD14();
    if (D_1F8001C6 == 1)
        func_8004F5A4();
    switch (D_8009BCDD) {
    case 1:
    case 4:
        u = 0xff;
        break;
    case 2:
        u = 0xff;
        u -= D_8009BCDE;
        break;
    case 3:
    case 0x10:
        u = D_8009BCDE;
        break;
    default:
        goto end;
    }
    func_8004FB54(u);
end:
    if ((*(s32 *)&GAME) == 6)
        func_8011AF78();
    else
        func_8004E3EC();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004637C);
extern u8 D_800A5399[];
extern u8 D_800A539A[];
extern u8 PLAYER[];
extern void func_800E9484(void *);
extern void func_80046428(void *);
extern void func_800EAA5C(void *);
extern void func_800EA094(void *);
void func_8004637C(void)
{
    u8 *p = PLAYER;
    if (D_800A5399[0] != 0) {
        switch (D_800A539A[0]) {
        case 0:
            func_80046428(p);
            break;
        case 1:
            func_800E9484(p);
            break;
        case 2:
            func_800EAA5C(p);
            break;
        case 3:
            func_800EA094(p);
            break;
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80046428);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80046CDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80046EC0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80047FC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_800487A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80048BF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80049134);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80049994);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004A300);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004A6A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004AA70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004AD8C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004AFAC);
extern s16 D_1F8001C6;
extern s16 D_1F800252;
extern GameObject **D_1F800264;

s32 func_80045D0C(GameObject *o);
void func_8004B450(GameObject *o);
void func_80123148(GameObject *o);
void func_8004BAF0(GameObject *o);
void drawMessageBoxFrame(GameObject *o);
void func_800E9EB8(GameObject *o);
void func_800EB490(GameObject *o);
void func_800EAAC8(GameObject *o);
void func_8004CC84(GameObject *o);
void func_80123AC4(GameObject *o);
void func_8011B350(GameObject *o);
void func_800EC0E8(GameObject *o);
void func_80117D3C(GameObject *o);
void func_8011812C(GameObject *o);
void func_8004D2A8(GameObject *o);

void func_8004AFAC(void)
{
    s32 n;
    GameObject **p;
    GameObject *o;

    if (D_1F8001C6 != 0) {
        n = D_1F800252;
        p = D_1F800264;
        while (n != 0) {
            o = *p++;
            n--;
            switch (func_80045D0C(o)) {
            case 0: func_800487A4(o); break;
            case 2: func_80049134(o); break;
            case 4: func_8004B450(o); break;
            case 5: func_80123148(o); break;
            case 6: func_8004AA70(o); break;
            case 7: func_8004BAF0(o); break;
            case 8: func_80047FC8(o); break;
            case 1: case 9: func_80048BF0(o); break;
            case 10: drawMessageBox(o); break;
            case 3: case 11: func_80049994(o); break;
            case 12: drawMessageBoxFrame(o); break;
            case 13:
                switch ((*(u8 *)&D_800A539A)) {
                case 0: func_8004A6A0(o); break;
                case 1: func_800E9EB8(o); break;
                case 2: func_800EB490(o); break;
                case 3: func_800EAAC8(o); break;
                }
            case 14: func_8004CC84(o); break;
            case 16: func_8004A300(o); break;
            case 17: func_80123AC4(o); break;
            case 18: func_8011B350(o); break;
            case 19: func_800EC0E8(o); break;
            case 20: func_80117D3C(o); break;
            case 21: func_8011812C(o); break;
            case 22: func_8004D2A8(o); break;
            }
        }
    } else {
        D_1F800252 = D_1F80024A;
        D_1F800264 = D_1F800220;
        while (D_1F80024A != 0) {
            o = *D_1F800220++;
            D_1F80024A--;
            if (o->visible) {
                switch (func_80045D0C(o)) {
                case 0: func_800487A4(o); break;
                case 2: func_80049134(o); break;
                case 4: func_8004B450(o); break;
                case 5: func_80123148(o); break;
                case 6: func_8004AA70(o); break;
                case 7: func_8004BAF0(o); break;
                case 8: func_80047FC8(o); break;
                case 1: case 9: func_80048BF0(o); break;
                case 10: drawMessageBox(o); break;
                case 3: case 11: func_80049994(o); break;
                case 12: drawMessageBoxFrame(o); break;
                case 13:
                    switch ((*(u8 *)&D_800A539A)) {
                    case 0: func_8004A6A0(o); break;
                    case 1: func_800E9EB8(o); break;
                    case 2: func_800EB490(o); break;
                    case 3: func_800EAAC8(o); break;
                    }
                    break;
                case 14: func_8004CC84(o); break;
                case 16: func_8004A300(o); break;
                case 17: func_80123AC4(o); break;
                case 18: func_8011B350(o); break;
                case 19: func_800EC0E8(o); break;
                case 20: func_80117D3C(o); break;
                case 21: func_8011812C(o); break;
                case 22: func_8004D2A8(o); break;
                }
            }
        }
    }
}

const s32 D_800146DC = 0;

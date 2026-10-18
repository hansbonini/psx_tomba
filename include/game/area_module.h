#ifndef GAME_AREA_MODULE_H
#define GAME_AREA_MODULE_H

/* Functions of the area module (0x801151F4..) that the main executable
   calls: whatever code overlay is loaded provides them. Only for
   src/main; an overlay has its own function at these addresses. */

void func_80116444(GameObject* o);
void func_80117D3C(GameObject* o);
void func_80117E38(GameObject* o);
void func_8011812C(GameObject* o);
void func_8011AB74(GameObject* o);
void func_8011B350(GameObject* o);
void func_8011BCE0(GameObject* o, GameObject* e);
void func_8011C234(GameObject* o);
void func_8011C500(GameObject* o);
void func_8011C6B4(GameObject* o, GameObject* e);
void func_8011C824(GameObject* o);
void func_8011C840(GameObject* o);
void func_8011CF38(GameObject* o);
void func_8011D208();
void func_8011D23C(GameObject* o, GameObject* e);
void func_8011D2AC(GameObject* o, GameObject* e);
void func_8011DC04(GameObject* o, GameObject* e);
void func_8011DF10(GameObject* o);
s32 func_8011E2B8(GameObject* a, GameObject* b);
void func_8011E584(GameObject* o);
void func_8011E660(GameObject* o, GameObject* e);
void func_8011E67C(GameObject* a, GameObject* b);
void func_8011E6DC(GameObject* o, GameObject* p);
void func_8011E748(GameObject* o, GameObject* e);
void func_8011E78C(GameObject* o, GameObject* e);
void func_8011E7C4(GameObject* o, GameObject* p);
void func_8011E868(GameObject* o, GameObject* p);
void func_8011E888(GameObject* o, GameObject* p);
void func_8011E964(GameObject* o, GameObject* e);
void func_8011F720();
void func_8011FFA8(GameObject* o, GameObject* e);
void func_801203D4();
void func_80120404(GameObject* o, GameObject* e);
void func_801209E4();
void func_80120CB4();
void func_80120D60();
void func_80123148(GameObject* o);
void func_80123314(GameObject* o);
void func_80123AC4(GameObject* o);
void func_80123EE0(GameObject* o, GameObject* e);
void func_80124054(GameObject* o, u8* b);
void func_80124240(GameObject* o, GameObject* e);
void func_80124260(GameObject* o, GameObject* e);
void func_80124280(s32 a, char* o);
void func_80124318(GameObject* o, GameObject* e);
void func_8012437C(GameObject* o, GameObject* e);
void func_801243AC(GameObject* o, GameObject* e);
void func_801243DC(GameObject* a, GameObject* b);
void func_801244E8(GameObject* o, GameObject* e);
void func_801245FC(GameObject* o, GameObject* e);
void func_801246C4(GameObject* o, GameObject* p);
void func_80124F70(GameObject* o);
void func_80125D14(GameObject* o, GameObject* t);
void func_80125E94();
void func_80125FA4();
void func_80125FFC(u8* a, u8* b);
void func_801260C0();
void func_8012629C(GameObject* o, GameObject* e);
void func_8012631C(GameObject* o, GameObject* e);
void func_801263CC(GameObject* o);
s32 func_801269B4(GameObject* a, GameObject* b);
void func_80126BC4();
void func_80127314();
void func_80127414();
void func_801287FC(GameObject* o);
void func_80128D4C(GameObject* o);
void func_80128F34(GameObject* o);
void func_801293D4(GameObject* o);
void func_80129B68(GameObject* o);
void func_8012A7A4(GameObject* o);
void func_8012B22C(GameObject* o);
void func_8012BBA8(GameObject* o);
void func_8012D330(GameObject* o);
void func_8012F5D0(GameObject* o);
void func_801341B0(GameObject* o);

#endif

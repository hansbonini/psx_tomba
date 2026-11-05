#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_gpa", SsUtGetProgAtr);

/**
 * @brief Get the attributes of a VAB program
 * 
 * Copies the program header of the VAB into pProgAttr.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param pProgAttr Receives the program attributes
 * @return 0 on success, -1 if the VAB is not open
 */
short SsUtGetProgAtr(short vabId, short prog, ProgAtr* pProgAttr) {
    if (_svm_vab_used[vabId] == 1) {
        _SsVmVSetUp(vabId, prog);
        pProgAttr->tones = _svm_pg[prog].tones;
        pProgAttr->mvol = _svm_pg[prog].mvol;
        pProgAttr->prior = _svm_pg[prog].prior;
        pProgAttr->mode = _svm_pg[prog].mode;
        pProgAttr->mpan = _svm_pg[prog].mpan;
        pProgAttr->attr = _svm_pg[prog].attr;
        return 0;
    }
    return -1;
}

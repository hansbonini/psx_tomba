#include "common.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/strstr", strstr);
char* strstr(const char* str, const char* substr)
{
    const char* s = str;
    bool in_match = false;
    const char* subs = substr;
    const char* candidate = str;

    while (*s) {
        if (*s == *subs) {
            subs++;
            if (*subs == '\0') {
                // Found
                return (char*)candidate; // cast away const
            }
            if (!in_match) {
                candidate = s;
                in_match = true;
            }
        } else {
            subs = substr;
            in_match = false;
        }
        s++;
    }

    // Not found
    return NULL;
}

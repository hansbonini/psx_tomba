#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/strstr", strstr);
/**
 * @brief Find a substring
 * 
 * Searches str for the first occurrence of substr using a simple
 * single-pass scan (a partial match is not rescanned from the next
 * position).
 * 
 * @param str String to search in
 * @param substr Substring to look for
 * @return Pointer to the first occurrence, or NULL if not found
 */
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

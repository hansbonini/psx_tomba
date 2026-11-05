#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/strcat", strcat);
/**
 * @brief Append one string to another
 * 
 * Copies arg1, including its terminating NUL, to the end of arg0.
 * 
 * @param arg0 Destination string
 * @param arg1 String to append
 * @return The destination string (NULL if either pointer is NULL)
 */
char* strcat(char* arg0, char* arg1)
{
    char* temp_v1;
    char temp_v0;

    if (arg0 == NULL) {
        return NULL;
    }
    if (arg1 == NULL) {
        return NULL;
    }
    if (&arg0[strlen(arg0)] != &arg1[strlen(arg1)]) {
        temp_v1 = arg0;
        while (*arg0++ != '\0') {}
        arg0--;
        do {
            *arg0++ = temp_v0 = *arg1++;
        } while (temp_v0 != '\0');
        return temp_v1;
    }

    return NULL;
}

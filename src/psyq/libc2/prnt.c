#include "common.h"

//INCLUDE_ASM("nonmatchings/psyq/libc2/prnt", prnt);
extern unsigned char _ctype_[];
extern int putchar(int c);
extern void *memchr(const void *s, int c, unsigned int n);
extern unsigned int strlen(const char *s);

#define isdigit(c) (_ctype_[(c) + 1] & 4)
#define isascii(c) ((unsigned)(c) < 0x80)
#define to_digit(c) ((c) - '0')

#define LONGINT   0x01
#define LONGDBL   0x02
#define SHORTINT  0x04
#define ALT       0x08
#define LADJUST   0x10
#define ZEROPAD   0x20
#define HEXPREFIX 0x40

#define BUF 40

#define va_arg(ap, t) (ap += sizeof(t), *(t *)(ap - sizeof(t)))

#define ARG() \
    (flags & LONGINT ? va_arg(args, long) : \
     flags & SHORTINT ? (long)(short)va_arg(args, int) : \
     (long)va_arg(args, int))

/* PsyQ libc prnt (derived from the 4.3BSD vfprintf).
 * a0 is unused; a1 = control (format string); a2 = argument pointer (va_list) */
int prnt(void *unused, char *control, char *args)
{
    char buf[BUF];
    int ret;
    int dprec;
    int fprec;
    int width;
    char *digs;
    char *fmt;
    char *cp;
    char sign;
    int n;
    int size;
    int flags;
    int prec;
    int realsz;
    int fieldsz;
    int base;
    unsigned long _ulong;
    char *p;

    if (control == 0) {
        return 0;
    }

    fmt = control;
    digs = "0123456789abcdef";
    ret = 0;

    for (;; fmt++) {
        if (*fmt == '\0') {
            return ret;
        }

        if (*fmt == '%') {
            flags = 0;
            prec = -1;
            sign = '\0';
            dprec = 0;
            fprec = 0;
            width = 0;

rflag:
            switch (*++fmt) {
            case '\0':
                return ret;

            case ' ':
                if (!sign) {
                    sign = ' ';
                }
                goto rflag;

            case '#':
                flags |= ALT;
                goto rflag;

            case '*':
                width = va_arg(args, int);
                if (width >= 0) {
                    goto rflag;
                }
                width = -width;
                /* FALLTHROUGH */
            case '-':
                flags |= LADJUST;
                goto rflag;

            case '+':
                sign = '+';
                goto rflag;

            case '.':
                if (*++fmt == '*') {
                    n = va_arg(args, int);
                } else {
                    n = 0;
                    while (isascii(*fmt) && isdigit(*fmt)) {
                        n = 10 * n + to_digit(*fmt++);
                    }
                    --fmt;
                }
                prec = n < 0 ? -1 : n;
                goto rflag;

            case '0':
                flags |= ZEROPAD;
                goto rflag;

            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                n = 0;
                do {
                    n = 10 * n + to_digit(*fmt);
                } while (isascii(*++fmt) && isdigit(*fmt));
                width = n;
                --fmt;
                goto rflag;

            case 'L':
                flags |= LONGDBL;
                goto rflag;

            case 'h':
                flags |= SHORTINT;
                goto rflag;

            case 'l':
                flags |= LONGINT;
                goto rflag;

            case 'c':
                cp = buf;
                *cp = va_arg(args, int);
                size = 1;
                sign = '\0';
                break;

            case 'D':
                flags |= LONGINT;
                /* FALLTHROUGH */
            case 'd':
            case 'i':
                _ulong = ARG();
                if ((long)_ulong < 0) {
                    _ulong = -_ulong;
                    sign = '-';
                }
                base = 10;
                goto number;

            case 'n':
                if (flags & LONGINT) {
                    *va_arg(args, long *) = ret;
                } else if (flags & SHORTINT) {
                    *va_arg(args, short *) = ret;
                } else {
                    *va_arg(args, int *) = ret;
                }
                continue;

            case 'O':
                flags |= LONGINT;
                /* FALLTHROUGH */
            case 'o':
                _ulong = ARG();
                base = 8;
                goto nosign;

            case 'p':
                _ulong = (unsigned long)va_arg(args, void *);
                base = 16;
                goto nosign;

            case 's':
                cp = va_arg(args, char *);
                if (cp == 0) {
                    cp = "(null)";
                }
                if (prec >= 0) {
                    p = memchr(cp, 0, prec);
                    if (p != 0) {
                        size = p - cp;
                        if (size > prec) {
                            size = prec;
                        }
                    } else {
                        size = prec;
                    }
                } else {
                    size = strlen(cp);
                }
                sign = '\0';
                break;

            case 'U':
                flags |= LONGINT;
                /* FALLTHROUGH */
            case 'u':
                _ulong = ARG();
                base = 10;
                goto nosign;

            case 'X':
                digs = "0123456789ABCDEF";
                /* FALLTHROUGH */
            case 'x':
                _ulong = ARG();
                base = 16;
                if (flags & ALT && _ulong != 0) {
                    flags |= HEXPREFIX;
                }
nosign:
                sign = '\0';
number:
                if ((dprec = prec) >= 0) {
                    flags &= ~ZEROPAD;
                }
                cp = buf + BUF;
                if (_ulong != 0 || prec != 0) {
                    do {
                        *--cp = digs[_ulong % base];
                        _ulong /= base;
                    } while (_ulong);
                    digs = "0123456789abcdef";
                    if (flags & ALT && base == 8 && *cp != '0') {
                        *--cp = '0';
                    }
                }
                size = buf + BUF - cp;
                break;

            default:
                goto dflt;
            }

            /* field size */
            fieldsz = size + fprec;
            if (sign) {
                fieldsz++;
            }
            if (flags & HEXPREFIX) {
                fieldsz += 2;
            }
            realsz = dprec > fieldsz ? dprec : fieldsz;

            /* right-adjusting blank padding */
            if ((flags & (LADJUST | ZEROPAD)) == 0 && width) {
                for (n = realsz; n < width; n++) {
                    putchar(' ');
                }
            }

            /* prefix */
            if (sign) {
                putchar(sign);
            }
            if (flags & HEXPREFIX) {
                putchar('0');
                putchar(*fmt);
            }

            /* right-adjusting zero padding */
            if ((flags & (LADJUST | ZEROPAD)) == ZEROPAD) {
                for (n = realsz; n < width; n++) {
                    putchar('0');
                }
            }

            /* leading zeroes from decimal precision */
            for (n = fieldsz; n < dprec; n++) {
                putchar('0');
            }

            /* the string or number proper */
            for (n = size; --n >= 0;) {
                putchar(*cp++);
            }

            /* trailing f.p. zeroes */
            while (--fprec >= 0) {
                putchar('0');
            }

            /* left-adjusting padding (always blank) */
            if (flags & LADJUST) {
                for (n = realsz; n < width; n++) {
                    putchar(' ');
                }
            }

            ret += width > realsz ? width : realsz;
            continue;

dflt:
            ret++;
            putchar(*fmt);
        } else {
            putchar(*fmt);
        }
    }
}

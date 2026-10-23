#ifndef _VERSION_H
#define _VERSION_H

/*
 * The Makefile defines, for every build:
 *   REGION   - REGION_US (SCUS-94236), REGION_JP (SLPS-01144), REGION_EU (SCES-0133x)
 *   VERSION  - revision of the release: the last digit of the SCES serial in
 *              Europe (0 = 1.0, 1 = 1.1), 0 elsewhere
 *   LANGUAGE - language of the executable: each European MAINn.EXE is the
 *              same game built for one language of the menu, and the menu
 *              itself (SCES_013.3x) is LANGUAGE_NONE
 * They are preprocessor constants (not a C enum) so #if can test them.
 */
#define REGION_US 0
#define REGION_JP 1
#define REGION_EU 2

#define LANGUAGE_ENGLISH    0 /* MAIN0, and the US release */
#define LANGUAGE_FRENCH     1 /* MAIN1 */
#define LANGUAGE_GERMAN     2 /* MAIN2 */
#define LANGUAGE_ITALIAN    3 /* MAIN3 */
#define LANGUAGE_DUTCH      4 /* MAIN4 */
#define LANGUAGE_SPANISH    5 /* MAIN5 */
#define LANGUAGE_PORTUGUESE 6 /* MAIN6 */
#define LANGUAGE_SWEDISH    7 /* MAIN7 */
#define LANGUAGE_DANISH     8 /* MAIN8 */
#define LANGUAGE_JAPANESE   9 /* the Japanese release */
#define LANGUAGE_NONE      10 /* SCES_013.3x itself: the language menu */

#ifndef LANGUAGE
#if REGION == REGION_JP
#define LANGUAGE LANGUAGE_JAPANESE
#else
#define LANGUAGE LANGUAGE_ENGLISH
#endif
#endif

#if REGION == REGION_EU
#define NTSC_PAL(ntsc, pal) (pal)
#else
#define NTSC_PAL(ntsc, pal) (ntsc)
#endif

#if REGION == REGION_JP
#define NTSC_J(us, jp) (jp)
#else
#define NTSC_J(us, jp) (us)
#endif

#define SCREEN_HEIGHT NTSC_PAL(0xE0, 0x100)

#endif

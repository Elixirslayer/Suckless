/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:size=10"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
    [SchemeNorm] = { "#bbbbbb", "#444444" }, // Normal: fg (gray3), bg (gray1)
    [SchemeSel]  = { "#eeeeee", "#222222" }, // Selected: fg (gray4), bg (cyan)
    [SchemeOut]  = { "#000000", "#00ffff" }, // Out: Black fg, Cyan bg};
    };                                         
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */

static const unsigned int alphas[SchemeLast][2] = {
    /*          fg      bg    */
    [SchemeNorm] = { OPAQUE, 0xd0 }, // Normal: 208/256 opacity (≈ 81%)
    [SchemeSel]  = { OPAQUE, 0xf0 }, // Selected: 240/256 opacity (≈ 94%)
    [SchemeOut]  = { OPAQUE, OPAQUE }  // No transparency for "Out"
};

static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 2;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
//static const char *fonts[]          = { "monospace:size=10" };
static const char *fonts[] = {
    "Noto Sans:style=Regular:size=10", // Adjust size and style as needed
    "Noto Color Emoji:style=Regular:size=10", // For emoji icons
    "Nerd Symbols:size=12",         // Nerd Fonts Symbols
};
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#444444";
static const char col_gray2[]       = "#000000";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#222222";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = 0xd0;
static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
    [SchemeHid]  = { col_cyan,  col_gray1, col_cyan  },
};
static const unsigned int alphas[][3]      = {
    /*               fg      bg        border*/
    [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
    [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "󰈹", "", "", "", "", "", "", "", "󰍁" };

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class           instance    title       tags mask  isfloating  monitor  floatx  floaty  floatw  floath  floatborderpx */
    { "firefox-nightly", NULL,     NULL,       1 << 0,    0,          -1,      -1,     -1,     -1,     -1,     -1 },
    { "qutebrowser", NULL,     NULL,       1 << 0,    0,          -1,      -1,     -1,     -1,     -1,     -1 },
    { "LibreWolf",       NULL,     NULL,       1 << 0,    0,          -1,      -1,     -1,     -1,     -1,     -1 },
    { "discord",         NULL,     NULL,       1 << 6,    0,          -1,      -1,     -1,     -1,     -1,     -1 },
    { "Spotify",         NULL,     NULL,       1 << 7,    0,          -1,      -1,     -1,     -1,     -1,     -1 },
    { "YouTube Music",   NULL,     NULL,       1 << 7,    0,          -1,      -1,     -1,     -1,     -1,     -1 },
    { "st",              NULL,     "termusic", 1 << 7,    0,          -1,      -1,     -1,     -1,     -1,     -1 },
    { "st",              NULL,     "pulsemixer", 0,    1,          -1,      1441,     -1,     479,     291,     -1 },
    { "vlc",             NULL,     NULL,       1 << 7,    0,          -1,      -1,     -1,     -1,     -1,     -1 },
    { "KeePassXC",       NULL,     NULL,       1 << 8,    0,          -1,      -1,     -1,     -1,     -1,     -1 },
    { "Galculator",      NULL,     NULL,       0,         1,          -1,      -1,     -1,     -1,     -1,     -1 },
    { "mpv",             NULL,     NULL,       0,         1,          -1,      1441,   -1,      479,     291,     -1 },
    { "copyq",           NULL,     NULL,       0,         1,          -1,      -1,     -1,     -1,     -1,     -1 },
};


/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static int attachbelow = 1;    /* 1 means attach after the currently active window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"
static const Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    //	  { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    //    { Mod4Mask|ShiftMask,           XK_f,      spawn,          SHCMD("firefox-nightly") }, 
    { Mod4Mask,           XK_f,      spawn,          SHCMD("librewolf") }, 
    { Mod4Mask|ShiftMask,                     XK_f,      spawn,          SHCMD("qutebrowser") }, 
    { MODKEY|ShiftMask,             XK_e,      spawn,          SHCMD("pcmanfm") }, 
    { MODKEY,                       XK_c,      spawn,          {.v = (const char*[]){ "/home/oc/Scripts/clip.sh", "add", NULL } } },
    { MODKEY|ShiftMask,             XK_v,      spawn,          {.v = (const char*[]){ "/home/oc/Scripts/clip.sh", "sel", NULL } } },
    { MODKEY|ControlMask,           XK_p,      spawn,          {.v = (const char*[]){ "/home/oc/Scripts/clip.sh", "pin", NULL } } },
    { MODKEY|ControlMask|ShiftMask, XK_p,      spawn,          {.v = (const char*[]){ "/home/oc/Scripts/clip.sh", "unpin", NULL } } },
    { 0,    	                    XK_Print,  spawn,          {.v = (const char*[]){"zsh", "/home/oc/Scripts/screenshot-selection.zsh", NULL}} },
    { Mod4Mask,                     XK_Print,  spawn,          {.v = (const char*[]){"zsh", "/home/oc/Scripts/screenshot-full.zsh", NULL}} }, 
    { Mod4Mask,                     XK_c,      spawn,          SHCMD("/home/oc/Scripts/clip.sh add") }, 
    { Mod4Mask,                     XK_v,      spawn,          SHCMD("/home/oc/Scripts/clip.sh sel") }, 
    { Mod4Mask,                     XK_d,      spawn,          SHCMD("/home/oc/Scripts/dictionary") }, 
    { Mod4Mask,                     XK_e,      spawn,          SHCMD("rofi -modi emoji -show emoji") }, 
    { Mod4Mask,                     XK_c,      spawn,          SHCMD("copyq") }, 
    { Mod4Mask,                     XK_s,      spawn,          SHCMD("unipicker --command 'rofi -dmenu' --copy-command 'xclip -selection clipboard'") }, 
    { Mod4Mask,                     XK_n,      spawn,          SHCMD("/home/oc/Scripts/note") },
    { MODKEY|ControlMask|ShiftMask, XK_r,      spawn,          SHCMD("reboot") }, 
    { MODKEY|ShiftMask, 		    XK_Delete, spawn,          SHCMD("poweroff") }, 
    { MODKEY|ControlMask|ShiftMask, XK_s,      spawn,          SHCMD("systemctl suspend") }, 
    //	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },
    { MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
    { Mod4Mask,                     XK_j,      focusstackhid,  {.i = +1 } },
    { Mod4Mask,                     XK_k,      focusstackhid,  {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { Mod1Mask,                     XK_F4,     killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
    { MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
    { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
    { Mod4Mask|ShiftMask,           XK_h,      show,           {0} },
    { Mod4Mask|ShiftMask,           XK_s,      showall,        {0} },
    { Mod4Mask,                     XK_h,      hide,           {0} },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
    { 0,                            XF86XK_Tools,               spawn,          SHCMD("vlc") },
    { 0|ShiftMask,                  XF86XK_Tools,               spawn,          SHCMD("~/Suckless/dmenu/Scripts/dmenu_audioswitch") },
    { 0,                            XF86XK_AudioPlay,           spawn,          SHCMD("/home/oc/Scripts/media-play-pause.zsh") },
    { 0,                            XF86XK_AudioNext,           spawn,          SHCMD("/home/oc/Scripts/media-next.zsh") },
    { 0,                            XF86XK_AudioPrev,           spawn,          SHCMD("/home/oc/Scripts/media-previous.zsh") },
    { 0,                            XF86XK_AudioStop,           spawn,          SHCMD("/home/oc/Scripts/media-stop.zsh") },
    { 0, XF86XK_AudioRaiseVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5% && pkill -RTMIN+10 -f 'dwmblocks'") },
    { 0, XF86XK_AudioLowerVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5% && pkill -RTMIN+10 -f 'dwmblocks'") },
    { 0, XF86XK_AudioMute, spawn, SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle && pkill -RTMIN+10 -f 'dwmblocks'") },
    { 0|ShiftMask, XF86XK_AudioRaiseVolume, spawn, SHCMD("pactl set-source-volume @DEFAULT_SOURCE@ +5% && pkill -RTMIN+10 -f 'dwmblocks'") },
    { 0|ShiftMask, XF86XK_AudioLowerVolume, spawn, SHCMD("pactl set-source-volume @DEFAULT_SOURCE@ -5% && pkill -RTMIN+10 -f 'dwmblocks'") },
    { 0|ShiftMask, XF86XK_AudioMute,        spawn, SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle && pkill -RTMIN+10 -f 'dwmblocks'") },
};
/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button1,        togglewin,      {0} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
    { ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
    { ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/* Taken from https://github.com/djpohly/dwl/issues/466 */
#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
		((hex >> 16) & 0xFF) / 255.0f, \
		((hex >> 8) & 0xFF) / 255.0f, \
		(hex & 0xFF) / 255.0f }
#define OPAQUE      0xff
#define baralpha    0xd0  // Example: ~82% opacity
#define borderalpha 0xd0  // Example: ~82% opacity

/* appearance */
static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const int smartgaps                 = 1;  /* 1 means no outer gap when there is only one window */
static const int smartborders              = 1;
static int gaps                            = 1;  /* 1 means gaps between windows are added */
static const unsigned int gappx            = 1; /* gap pixel between windows */
static const unsigned int borderpx         = 2;  /* border pixel of windows */
static const float rootcolor[]             = COLOR(0x222222ff);
static const float bordercolor[]           = COLOR(0x444444ff);
static const float focuscolor[]            = COLOR(0x005577ff);
static const float urgentcolor[]           = COLOR(0xff0000ff);
/* This conforms to the xdg-protocol. Set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.0f, 0.0f, 0.0f, 1.0f}; /* You can also use glsl colors */
static const int respect_monitor_reserved_area = 0;  /* 1 to monitor center while respecting the monitor's reserved area, 0 to monitor center */


/* tagging - TAGCOUNT must be no greater than 31 */
#define TAGCOUNT (9)

/* logging */
static int log_level = WLR_ERROR;

/* Autostart */
static const char *const autostart[] = {
		// "wbg", "-s", "/home/oc/wallpapers/landscape7.jpg", NULL,
		"dunst", NULL,
		"waybar", NULL,
		"input-remapper-control", "--command", "autoload", NULL,
		"mpd-discord-rpc", NULL,
		"kdeconnectd", NULL,
		"mpd-mpris", NULL,
		"/home/oc/Scripts/playerctl-loopW", NULL,
		"/home/oc/Scripts/Pywal", NULL,
		NULL /* terminate */
};


/* NOTE: ALWAYS keep a rule declared even if you don't use rules (e.g leave at least one example) */
static const Rule rules[] = {
		/* app_id             title       tags mask     isfloating   monitor   x   y   width   height */
		/* examples: */
		{ "firefox-nightly", NULL,       1 << 0,    0,          -1,      -1,     -1,     -1,     -1	},
		{ "qutebrowser",	 NULL,       1 << 0,    0,          -1,      -1,     -1,     -1,     -1	},
		{ "LibreWolf",       NULL,       1 << 0,    0,          -1,      -1,     -1,     -1,     -1	},
		{ "discord",         NULL,       1 << 6,    0,          -1,      -1,     -1,     -1,     -1	},
		{ "Spotify",         NULL,       1 << 7,    0,          -1,      -1,     -1,     -1,     -1	},
		{ "YouTube Music",   NULL,       1 << 7,    0,          -1,      -1,     -1,     -1,     -1	},
		{ "foot",            "termusic", 1 << 7,    0,          -1,      -1,     -1,     -1,     -1	},
		{ "foot",            "wttr.in", 0,    1,          -1,      -1,     -1,     1920,     1080		},
		{ "foot",            "pulsemixer", 0,    1,          -1,      1280,     -1,     640,     360	},
		{ "foot",            "calcurse", 0,    1,          -1,      1280,     -1,     640,     360	},
		{ "vlc",             NULL,       1 << 7,    0,          -1,      -1,     -1,     -1,     -1	},
		{ "KeePassXC",       NULL,       1 << 8,    0,          -1,      -1,     -1,     -1,     -1	},
		{ "Galculator",      NULL,       0,         1,          -1,      -1,     -1,     -1,     -1	},
		{ "mpv",             NULL,       0,         1,          -1,      1441,   -1,      479,     291},
		{ "copyq",           NULL,       0,         1,          -1,      -1,     -1,     -1,     -1	},
};

/* layout(s) */
static const Layout layouts[] = {
		/* symbol     arrange function */
		{ "[]=",      tile },
		{ "><>",      NULL },    /* no layout function means floating behavior */
		{ "[M]",      monocle },
};

/* monitors */
/* (x=-1, y=-1) is reserved as an "autoconfigure" monitor position indicator
 * WARNING: negative values other than (-1, -1) cause problems with Xwayland clients
 * https://gitlab.freedesktop.org/xorg/xserver/-/issues/899
 */
/* NOTE: ALWAYS add a fallback rule, even if you are completely sure it won't be used */
static const MonitorRule monrules[] = {
		/* name       mfact  nmaster scale layout       rotate/reflect                x    y */
		/* example of a HiDPI laptop monitor:
		   { "eDP-1",    0.5f,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
		   */
		/* defaults */
		{ NULL,       0.55f, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
		/* can specify fields: rules, model, layout, variant, options */
		/* example:
		   .options = "ctrl:nocaps",
		   */
		.options = NULL,
};

static const int repeat_rate = 25;
static const int repeat_delay = 600;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
   LIBINPUT_CONFIG_SCROLL_NO_SCROLL
   LIBINPUT_CONFIG_SCROLL_2FG
   LIBINPUT_CONFIG_SCROLL_EDGE
   LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
   */
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
   LIBINPUT_CONFIG_CLICK_METHOD_NONE
   LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS
   LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER
   */
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
   LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
   LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
   LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
   */
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
   LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
   LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
   */
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;

/* You can choose between:
   LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
   LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
   */
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* If you want to use the windows key for Alt, use Super */
#define Alt WLR_MODIFIER_ALT
#define Ctrl WLR_MODIFIER_CTRL
#define Shift WLR_MODIFIER_SHIFT
#define Super WLR_MODIFIER_LOGO

#define TAGKEYS(KEY,SKEY,TAG) \
{ Alt,                    KEY,            view,            {.ui = 1 << TAG} }, \
{ Alt|Ctrl,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
{ Alt|Shift, SKEY,           tag,             {.ui = 1 << TAG} }, \
{ Alt|Ctrl|Shift,SKEY,toggletag, {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[] = { "foot", NULL };
static const char *menucmd[] = { "wofi", "--show", "drun", NULL };

static const Key keys[] = {
		/* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
		/* modifier                  key                 function        argument */
		{ Alt,                    XKB_KEY_b,          togglebar,      {0} },
		{ Alt,                    XKB_KEY_p,          spawn,          {.v = menucmd} },
		{ Alt|Shift, XKB_KEY_Return,     spawn,          {.v = termcmd} },
		{ Alt|Shift, XKB_KEY_F,		     spawn,          SHCMD("qutebrowser") },
		{ Alt|Shift, XKB_KEY_E,		     spawn,          SHCMD("nautilus") },
		{ Alt|Shift, XKB_KEY_D,		     spawn,          SHCMD("discord") },
		{ Alt|Shift, XKB_KEY_W, 		 spawn, 		 SHCMD("setsid -w -f foot --app-id=wttr.in --hold -e curl wttr.in/456001") },
		{ Super,					 XKB_KEY_r,		     spawn,          SHCMD("/home/oc/Scripts/record") },
		{ Super,					 XKB_KEY_d,		     spawn,          SHCMD("/home/oc/Scripts/dictionaryW") },
		{ Super,					 XKB_KEY_n,		     spawn,          SHCMD("/home/oc/Scripts/note") },
		{ 0,					 XKB_KEY_Print,		     spawn,          SHCMD("/home/oc/Scripts/screenshot-fullW") },
		{ Shift,					 XKB_KEY_Print,		     spawn,          SHCMD("/home/oc/Scripts/screenshot-selectionW") },
		{ Super,					XKB_KEY_e,		     spawn,          SHCMD("wofi-emoji") },
		{ Super,					 XKB_KEY_s,		     spawn,          SHCMD("unipicker --command 'wofi --show dmenu' --copy-command 'wl-copy --type text/plain'") },	
		{ Alt|Ctrl|Shift, XKB_KEY_R,		     spawn,          SHCMD("reboot") },
		{ Alt|Ctrl|Shift, XKB_KEY_P,		     spawn,          SHCMD("poweroff") },
		{ Alt|Ctrl|Shift, XKB_KEY_S,		     spawn,          SHCMD("systemctl suspend") },
		{ Super,					 XKB_KEY_v,		     spawn,          SHCMD("cliphist list | wofi --show dmenu | cliphist decode | wl-copy") },
		{ Alt|Shift, XKB_KEY_W,		     spawn,          SHCMD("setsid -w -f foot --app-id=wttr.in --hold -e curl wttr.in/456001") },

		/* Audio and Media Controls */
		{ Shift,              XKB_KEY_F1,      spawn,          SHCMD("~/Suckless/dmenu/Scripts/dmenu_audioswitch") },
		{ Shift,              XKB_KEY_F2,      spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5% && pkill -RTMIN+11 waybar") },
		{ Shift,              XKB_KEY_F3,      spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5% && pkill -RTMIN+11 waybar") },
		{ Shift,              XKB_KEY_F4,      spawn,          SHCMD("/home/oc/Scripts/media-play-pause.zsh") },
		{ Shift,              XKB_KEY_F5,      spawn,          SHCMD("/home/oc/Scripts/media-previous.zsh") },
		{ Shift,              XKB_KEY_F6,      spawn,          SHCMD("/home/oc/Scripts/media-next.zsh") },
		{ Shift,              XKB_KEY_F7,      spawn,          SHCMD("/home/oc/Scripts/media-stop.zsh") },
		{ Shift,              XKB_KEY_F8,      spawn,          SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle && pkill -RTMIN+11 waybar") },

		/* Microphone Volume Controls */
		{ Shift | Ctrl, XKB_KEY_F2, spawn, SHCMD("pactl set-source-volume @DEFAULT_SOURCE@ -5% && pkill -RTMIN+11 waybar") },
		{ Shift | Ctrl, XKB_KEY_F3, spawn, SHCMD("pactl set-source-volume @DEFAULT_SOURCE@ +5% && pkill -RTMIN+11 waybar") },
		{ Shift | Ctrl, XKB_KEY_F8, spawn, SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle && pkill -RTMIN+11 waybar") },
		{ Alt,                    XKB_KEY_j,          focusstack,     {.i = +1} },
		{ Alt,                    XKB_KEY_k,          focusstack,     {.i = -1} },
		{ Alt|Shift, XKB_KEY_J,          movestack,      {.i = +1} },
		{ Alt|Shift, XKB_KEY_K,          movestack,      {.i = -1} },
		{ Alt,                    XKB_KEY_i,          incnmaster,     {.i = +1} },
		{ Alt,                    XKB_KEY_d,          incnmaster,     {.i = -1} },
		{ Alt,                    XKB_KEY_h,          setmfact,       {.f = -0.05f} },
		{ Alt,                    XKB_KEY_l,          setmfact,       {.f = +0.05f} },
		{ Alt,                    XKB_KEY_Return,     zoom,           {0} },
		{ Alt,                    XKB_KEY_Tab,        view,           {0} },
		{ Alt,                    XKB_KEY_g,          togglegaps,     {0} },
		{ Alt|Shift, XKB_KEY_C,          killclient,     {0} },
		{ Alt,                    XKB_KEY_t,          setlayout,      {.v = &layouts[0]} },
		{ Alt,                    XKB_KEY_f,          setlayout,      {.v = &layouts[1]} },
		{ Alt,                    XKB_KEY_m,          setlayout,      {.v = &layouts[2]} },
		{ Alt,                    XKB_KEY_space,      setlayout,      {0} },
		{ Alt|Shift, XKB_KEY_space,      togglefloating, {0} },
		{ 0,	                     XKB_KEY_F11,         togglefullscreen, {0} },
		{ Alt,                    XKB_KEY_0,          view,           {.ui = ~0} },
		{ Alt|Shift, XKB_KEY_parenright, tag,            {.ui = ~0} },
		{ Alt,                    XKB_KEY_comma,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
		{ Alt,                    XKB_KEY_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
		{ Alt|Shift, XKB_KEY_less,       tagmon,         {.i = WLR_DIRECTION_LEFT} },
		{ Alt|Shift, XKB_KEY_greater,    tagmon,         {.i = WLR_DIRECTION_RIGHT} },
		TAGKEYS(          XKB_KEY_1, XKB_KEY_exclam,                     0),
		TAGKEYS(          XKB_KEY_2, XKB_KEY_at,                         1),
		TAGKEYS(          XKB_KEY_3, XKB_KEY_numbersign,                 2),
		TAGKEYS(          XKB_KEY_4, XKB_KEY_dollar,                     3),
		TAGKEYS(          XKB_KEY_5, XKB_KEY_percent,                    4),
		TAGKEYS(          XKB_KEY_6, XKB_KEY_asciicircum,                5),
		TAGKEYS(          XKB_KEY_7, XKB_KEY_ampersand,                  6),
		TAGKEYS(          XKB_KEY_8, XKB_KEY_asterisk,                   7),
		TAGKEYS(          XKB_KEY_9, XKB_KEY_parenleft,                  8),
		{ Alt|Shift, XKB_KEY_Q,          quit,           {0} },

		/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
		{ Ctrl|Alt,		XKB_KEY_Terminate_Server, quit, {0} },
		/* Ctrl-Alt-Fx is used to switch to another VT, if you don't know what a VT is
		 * do not remove them.
		 */
#define CHVT(n) { Ctrl|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
		CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
		CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
		{ Alt, BTN_LEFT,   moveresize,     {.ui = CurMove} },
		{ Alt, BTN_MIDDLE, togglefloating, {0} },
		{ Alt, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};

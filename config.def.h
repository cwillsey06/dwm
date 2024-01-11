/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;  /* border pixel of windows */
static const unsigned int snap      = 24; /* snap pixel */
static const int showbar            = 1;  /* 0 means no bar */
static const int topbar             = 0;  /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_black[]       = "black";
static const char col_white[]       = "white";
static const char col_red[]         = "red";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_black, col_white, col_black  },
	[SchemeSel]  = { col_white, col_black, col_white  }
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* Lockfile */
static char lockfile[] = "/tmp/dwm.lock";

static const Rule rules[] = {
  0
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int attachto    = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	{ "=[]", tileleft  },
	{ "[]=", tileright },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static const char *menucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_black, "-nf", col_white, "-sb", col_white, "-sf", col_black, "-shf", col_red, topbar ? NULL : "-b", NULL };
static const char *termcmd[] = { "st", NULL };
static const char *bwsrcmd[] = { "firefox", NULL };

static const char *incvol[] = { "pamixer", "-i", "5", NULL };
static const char *decvol[] = { "pamixer", "-d", "5", NULL };
static const char *mutvol[] = { "pamixer", "-t", NULL };

static const char *mediatogg[] = { "playerctl", "play-pause", NULL };
static const char *medianext[] = { "playerctl", "next", NULL };
static const char *mediaprev[] = { "playerctl", "previous", NULL };

static const char *scrotcmd[] = { "/home/coltrane/.local/bin/scrot.sh", NULL};

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = menucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = bwsrcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_b,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_v,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
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
	{ 0,        XF86XK_AudioRaiseVolume,       spawn,          {.v = incvol } },
	{ 0,        XF86XK_AudioLowerVolume,       spawn,          {.v = decvol } },
	{ 0,               XF86XK_AudioMute,       spawn,          {.v = mutvol } },
	{ 0,               XF86XK_AudioPlay,       spawn,          {.v = mediatogg } },
	{ 0,               XF86XK_AudioNext,       spawn,          {.v = medianext } },
	{ 0,               XF86XK_AudioPrev,       spawn,          {.v = mediaprev } },
	{ 0,                       XK_Print,       spawn,          {.v = scrotcmd } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkRootWin,           0,              Button1,        spawn,          {.v = termcmd } },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


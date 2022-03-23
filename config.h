/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
};

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
        { "color0",       STRING,  &colorname[INIT] },
        { "color4",       STRING,  &colorname[INPUT] },
        { "color1",       STRING,  &colorname[FAILED] },
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* number of failed password attempts until failcommand is executed.
   Set to 0 to disable */
static const int failcount = 3;

/* command to be executed after [failcount] failed password attempts */
static const char *failcommand = "ffmpeg -y -loglevel quiet -f v4l2 -i /dev/video0 -frames:v 1 -f image2 /home/mahdy/slock-%Y-%m-%d-%H%M%S.jpg";

/* time in seconds before the monitor shuts down */
static const int monitortime = 60;

/* insert grid pattern with scale 1:1, the size can be changed with logosize */
static const int logosize = 80;
static const int logow = 6;     /* grid width and height for right center alignment*/
static const int logoh = 6;
//static const int logow = 13;
//static const int logoh = 6;

static XRectangle rectangles[5] = {
	/* x    y       w       h */
	{ 0,    0,      1,      5 },
	{ 1,    1,      1,      1 },
	{ 2,    2,      1,      1 },
	{ 3,    1,      1,      1 },
	{ 4,    0,      1,      5 },
};
//static XRectangle rectangles[15] = {
//	/* x    y       w       h */
//	{ 0,    0,      1,      5 },
//	{ 1,    1,      1,      1 },
//	{ 2,    2,      1,      1 },
//	{ 3,    1,      1,      1 },
//	{ 4,    0,      1,      5 },
//	{ 6,    1,      1,      1 },
//	{ 6,    3,      1,      2 },
//	{ 8,    0,      1,      5 },
//	{ 9,    0,      1,      1 },
//	{ 9,    2,      1,      1 },
//	{ 10,   1,      1,      1 },
//	{ 10,   3,      1,      1 },
//	{ 11,   4,      1,      1 },
//};

/*Enable blur*/
#define BLUR
/*Set blur radius*/
static const int blurRadius=20;
/*Enable Pixelation*/
#define PIXELATION
/*Set pixelation radius*/
static const int pixelSize=20;

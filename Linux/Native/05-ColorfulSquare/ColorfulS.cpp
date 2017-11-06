#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <X11/keysym.h>

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>

using namespace std;

bool bFullscreen = false;

Display *gpDisplay = NULL;
XVisualInfo *gpXVisualInfo = NULL;

Colormap gColormap;
Window gWindow;

#define giWindowWidth 1024
#define giWindowHeight 768

GLXContext gGLXContext;

int main(void)
{
	void CreateWindow(void);
	void ToggleFullscreen(void);
	void initialize(void);
	void display(void);
	void resize(int,int);
	void uninitialize(void);

	int WinWidth = giWindowWidth;
	int WinHeight = giWindowHeight;

	bool bDone = false;

	CreateWindow();

	initialize();

	XEvent event;
	KeySym keysym;

	while(bDone == false) 
	{
		while(XPending(gpDisplay)) 
		{
			XNextEvent(gpDisplay,&event);
			switch(event.type)
			{
				case MapNotify :
					break;
				case KeyPress :
					keysym = XkbKeycodeToKeysym(gpDisplay,event.xkey.keycode,0,0);
					switch(keysym)
					{
						case XK_Escape :
							bDone = 0;
							//uninitialize();
							exit(0);
						case XK_F :
						case XK_f :
							if(bFullscreen == false)
							{
								ToggleFullscreen();
								bFullscreen = true;
							}
							else
							{
								ToggleFullscreen();
								bFullscreen = false;
							}
							break;
						default :
							break;
					}
					break;
				case ButtonPress :
					switch(event.xbutton.button)
					{
						case 1 :
							break;
						case 2 :
							break;
						case 3 :
							break;
						case 4 :
							break;
						case 5 :
							break;
						default :
							break;
					}
					break;
				case MotionNotify: 
					break;
				case ConfigureNotify: 
					WinWidth=event.xconfigure.width;
					WinHeight=event.xconfigure.height;
					resize(WinWidth,WinHeight);
					break;
				case Expose: 
					break;
				case DestroyNotify:
					break;
				case 33:
					bDone=true;
					break;
				default:
					break;
			}
		}
		display();
	}
	return(0);
}
void CreateWindow(void)
{
	void uninitialize(void);				//Second time prototyped

	XSetWindowAttributes WinAttribs;
	int defaultScreen;
	int defaultDepth;
	int styleMask;

	static int frameBufferAttributes[] = {GLX_RGBA,GLX_RED_SIZE,1,GLX_GREEN_SIZE,1,GLX_BLUE_SIZE,1,GLX_ALPHA_SIZE,1,None};
  	//static int frameBufferAttributes[] = {GLX_RGBA,GLX_RED_SIZE,8,GLX_GREEN_SIZE,8,GLX_BLUE_SIZE,8,GLX_ALPHA_SIZE,8,GLX_DOUBLEBUFFER,True,GLX_DEPTH_SIZE,24,None}; //for depth as well as double buffer here no use as only 2d is done

	gpDisplay = XOpenDisplay(NULL);
	if(gpDisplay == NULL)
	{
		printf("Unable to open XOpenDisplay line no.120\n");
		uninitialize();
		exit(1);
	}

	defaultScreen = XDefaultScreen(gpDisplay);

	gpXVisualInfo = glXChooseVisual(gpDisplay,defaultScreen,frameBufferAttributes);

	WinAttribs.border_pixel = 0;
	WinAttribs.background_pixmap = 0;
	WinAttribs.colormap = XCreateColormap(gpDisplay,RootWindow(gpDisplay,gpXVisualInfo->screen),gpXVisualInfo->visual,AllocNone);

	gColormap = WinAttribs.colormap;
	
	WinAttribs.background_pixel = BlackPixel(gpDisplay,defaultScreen);
	WinAttribs.event_mask = ExposureMask | VisibilityChangeMask | ButtonPressMask| KeyPressMask | PointerMotionMask |StructureNotifyMask; 

	styleMask = CWBackPixel | CWBorderPixel | CWColormap | CWEventMask;

	gWindow = XCreateWindow(gpDisplay,RootWindow(gpDisplay,gpXVisualInfo->screen),100,100,giWindowWidth,giWindowHeight,0,gpXVisualInfo->depth,InputOutput,gpXVisualInfo->visual,styleMask,&WinAttribs);

	if(!gWindow)
	{
		printf("Failed to create main window line no.141\n");
		uninitialize();
		exit(1);
	}

	XStoreName(gpDisplay,gWindow,"Native XWindows Perspective Colorful Square");

	Atom windowManagerDelete = XInternAtom(gpDisplay,"WM_DELETE_WINDOW",True);
	XSetWMProtocols(gpDisplay,gWindow,&windowManagerDelete,1);

	XMapWindow(gpDisplay,gWindow);

}

void ToggleFullscreen(void)
{
	Atom wm_state;
	Atom fullscreen;
	XEvent xev = { 0 };

	wm_state = XInternAtom(gpDisplay,"_NET_WM_STATE",False);
	memset(&xev,0,sizeof(xev));

	xev.type = ClientMessage;
	xev.xclient.window = gWindow;
	xev.xclient.message_type = wm_state;
	xev.xclient.format = 32;
	xev.xclient.data.l[0] = bFullscreen ? 0 : 1;

	fullscreen = XInternAtom(gpDisplay,"_NET_WM_STATE_FULLSCREEN",False);
	xev.xclient.data.l[1] = fullscreen;

	XSendEvent(gpDisplay,RootWindow(gpDisplay,gpXVisualInfo->screen),False,StructureNotifyMask,&xev);

}

void initialize(void)
{
	void resize(int ,int);				//defing prototye again

	gGLXContext = glXCreateContext(gpDisplay,gpXVisualInfo,NULL,GL_TRUE);

	glXMakeCurrent(gpDisplay,gWindow,gGLXContext);

	glClearColor(0.0f,0.0f,0.0f,0.0f);

	resize(giWindowWidth,giWindowHeight);

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-3.0f);
	glBegin(GL_QUADS);
		glColor3f(1.0f,0.0f,0.0f); 
		glVertex3f(1.0f,1.0f,0.0f);

		glColor3f(0.0f,0.0f,1.0f); 
		glVertex3f(-1.0f,1.0f,0.0f); 

		glColor3f(0.0f,1.0f,0.0f); 
		glVertex3f(-1.0f,-1.0,0.0f); 

		glColor3f(0.0f,0.0f,1.0f); 
		glVertex3f(1.0f,-1.0f,0.0f); 
	glEnd();
	glFlush();
}

void resize(int width,int height)
{
	if(height == 0)
		height = 1;
	if(width == 0)
		width = 1;
	glViewport(0,0,(GLsizei)width,(GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void uninitialize(void)
{
	GLXContext currentGLXContext;
	currentGLXContext = glXGetCurrentContext();

	if(currentGLXContext!=NULL && currentGLXContext==gGLXContext)
	{
		glXMakeCurrent(gpDisplay,0,0);
	}
	if(gGLXContext)
	{
		glXDestroyContext(gpDisplay,gGLXContext);
	}
	if(gWindow)
	{
		XDestroyWindow(gpDisplay,gWindow);
	}
	if(gColormap)
	{
		XFreeColormap(gpDisplay,gWindow);
	}
	if(gpXVisualInfo)
	{
		free(gpXVisualInfo);
		gpXVisualInfo = NULL;
	}
	if(gpDisplay)
	{
		XCloseDisplay(gpDisplay);
		gpDisplay = NULL;
	}
}
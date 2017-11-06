#include <GL/freeglut.h>

#include "Texture.h"

bool bFullscreen=false; 

GLfloat AngleTri=0.0f; 
GLfloat AngleSquare=0.0f; 

GLuint	Texture_Kundali; 
GLuint	Texture_Stone; 

int main(int argc,char** argv)
{
	void display(void);
	void resize(int,int);
	void keyboard(unsigned char,int,int);
	void mouse(int,int,int,int);
    void spin(void);
	void initialize(void);
	void uninitialize(void);

	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(1024,768); 
	glutInitWindowPosition(100,100); 
	glutCreateWindow("Texture of Pyramid And Cube"); 

	initialize();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutIdleFunc(spin);
	glutCloseFunc(uninitialize);

	glutMainLoop();

//	return(0); 
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(-1.5f,0.0f,-6.0f);
	glRotatef(AngleTri,0.0f,1.0f,0.0f);
	glBindTexture(GL_TEXTURE_2D, Texture_Stone);
	glBegin(GL_TRIANGLES);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(0.0f,1.0f,0.0f); 

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f,1.0f); 

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f,-1.0f,1.0f); 

		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(0.0f,1.0f,0.0f); 

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f,-1.0f,1.0f); 

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1.0f,-1.0f,-1.0f); 

		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(0.0f,1.0f,0.0f); 

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f,-1.0f,-1.0f); 

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f); 

		glTexCoord2f(0.5f, 1.0f);
		glVertex3f(0.0f,1.0f,0.0f); 

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f,-1.0f); 

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f,1.0f); 
	glEnd();

	glLoadIdentity();
	glTranslatef(1.5f,0.0f,-6.0f);
	glScalef(0.75f, 0.75f, 0.75f);
	glRotatef(AngleSquare,1.0f,1.0f,1.0f);
	glBindTexture(GL_TEXTURE_2D, Texture_Kundali);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f); 

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f); 

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f); 

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f); 

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f); 

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f); 

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f); 

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f); 

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 1.0f); 

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f); 

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f); 

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f); 

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f); 

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f); 

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f); 

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f); 

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f); 

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f); 

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f); 

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f); 

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

	glEnd();
	
	glutSwapBuffers();
}

void initialize(void)
{
	int LoadGLTextures(GLuint *, TCHAR[]);

	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);

	LoadGLTextures(&Texture_Kundali, MAKEINTRESOURCE(IDBITMAP_KUNDALI));
	LoadGLTextures(&Texture_Stone, MAKEINTRESOURCE(IDBITMAP_STONE));

	glEnable(GL_TEXTURE_2D);
}

int LoadGLTextures(GLuint *texture,TCHAR imageResourceId[])
{
	HBITMAP hBitmap;
	BITMAP bmp;
	int iStatus = FALSE;

	glGenTextures(1, texture); 
	hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), imageResourceId, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	if (hBitmap)
	{
		iStatus = TRUE;
		GetObject(hBitmap, sizeof(bmp), &bmp);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4); 
		glBindTexture(GL_TEXTURE_2D, *texture); 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp.bmBits);

		DeleteObject(hBitmap); 
	}
	return(iStatus);
}

void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if(bFullscreen==false)
		{
			glutFullScreen();
			bFullscreen=true;
		}
		else
		{
			glutLeaveFullScreen();
			bFullscreen=false;
		}
		break;
	default:
		break;
	}
}

void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		break;
	default:
		break;
	}
}

void resize(int width,int height)
{
	if(height==0)
		height=1;
	glViewport(0,0,(GLsizei)width,(GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void spin(void)
{
	AngleTri=AngleTri+1.0f;
	if(AngleTri>=360.0f)
		AngleTri=AngleTri-360.0f;

	AngleSquare=AngleSquare+1.0f;
	if(AngleSquare>=360.0f)
		AngleSquare=AngleSquare-360.0f;

	glutPostRedisplay();
}

void uninitialize(void)
{
}

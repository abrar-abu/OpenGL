#include <GL/freeglut.h>

bool bFullscreen = false;

GLfloat AngleTri = 0.0f;
GLfloat AngleSqare = 0.0f;

int main(int argc,char ** argv)
{
	void initialize(void);
	void display(void);
	void resize(int,int);
	void keyboard(unsigned char,int,int);
	void mouse(int,int,int,int);
	void spin(void);
	void uninitialize(void);

	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	glutInitWindowSize(1024,786);
	glutInitWindowPosition(100,100);
	glutCreateWindow("2D rotation");

	initialize();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutIdleFunc(spin);
	glutCloseFunc(uninitialize);

	glutMainLoop();

	//return 0;
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-1.5f,0.0f,-6.0f);
	glRotatef(AngleTri,-0.3f,0.5f,-0.3f);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0f,1.0f,0.0f);
		glVertex3f(-1.0f,-1.0f,0.0f);
		glVertex3f(1.0f,-1.0f,0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(1.5f,0.0f,-6.0f);
	glRotatef(AngleSqare,0.0f,0.5f,0.5f);
	glBegin(GL_QUADS);
		glVertex3f(1.0f,1.0f,0.0f); 
		glVertex3f(-1.0f,1.0f,0.0f); 
		glVertex3f(-1.0f,-1.0f,0.0f);
		glVertex3f(1.0f,-1.0f,0.0f);
	glEnd();
	glutSwapBuffers();
}
void initialize(void)
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
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
void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
	case 27: // Escape
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
void spin(void)
{
	AngleTri+=0.20f;
	if(AngleTri>= 360.0f)
		AngleTri-=360.0f;
	
	AngleSqare+=0.10f;
	if(AngleSqare>= 360.0f)
		AngleSqare-=360.0f;
	
	glutPostRedisplay();
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
void uninitialize(void)
{}
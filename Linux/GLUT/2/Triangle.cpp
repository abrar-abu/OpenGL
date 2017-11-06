#include <GL/freeglut.h>

bool bFullscreen = false ;

int main(int argc, char *argv[])
{
	void display(void);
	void resize(int,int);
	void keyboard(unsigned char,int,int);
	void mouse(int,int,int,int);
	void initialize(void);
	void uninitialize(void);

	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(1024,768);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Create Orthogonal Triangle");

	initialize();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

	return 0;
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f,0.0f,1.0f);
		glVertex3f(0.0f,50.0f,0.0f);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(-50.0f,-50.0f,0.0f);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(50.0f,-50.0f,0.0f);
	glEnd();
	glFlush();
}
void initialize(void)
{
	glClearColor(1.0f,1.0f,1.0f,0.0f);
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
			if(bFullscreen == false)
			{
				glutFullScreen();
				bFullscreen = true;			
			}
			else
			{
				glutLeaveFullScreen();
				bFullscreen = false;
			}
			break;
		default :
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
	if(height == 0)
		height = 1;
	if(width == 0)
		width = 1;
	glViewport(0,0,(GLsizei)width,(GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(width<=height)
		glOrtho(-100.0f,100.0f,(-100.0f * (GLfloat)height/(GLfloat)width),(100.0f * (GLfloat)height/(GLfloat)width),-100.0f,100.0f);
	else
		glOrtho(-100.0f,100.0f,(-100.0f * (GLfloat)width/(GLfloat)height),(100.0f * (GLfloat)width/(GLfloat)height),-100.0f,100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void uninitialize(void)
{
	
}
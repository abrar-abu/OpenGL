#include <GL/freeglut.h>

bool bFullScreen = false;

int main(int argc, char *argv[])
{
	//Here we declare the function prototypes
	//It different then usual decalration above the main function
	
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
	glutCreateWindow("Assignment 1");

	initialize();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

	//return 0;
}
void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void initialize (void)
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
}
void keyboard (unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27 :
			glutLeaveMainLoop();
			break;
		case 'F':
		case 'f':
			if (bFullScreen == false)
			{
				glutFullScreen();
				bFullScreen = true;
			}
			else
			{
				glutLeaveFullScreen();
				bFullScreen = false ;
			}
			break;
		default :
			break;
	}
}
void mouse (int button,int state,int x,int y)
{
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
			break;
		default :
			break;
	}
}
void resize(int width, int height)
{

}
void uninitialize (void)
{
	
}
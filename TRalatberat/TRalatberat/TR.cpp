#include <stdlib.h>
#include <GL/glut.h>
#include <windows.h>
#include <iostream>
//reonarudusu

using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;

void Myinit(void);
void display(void);
void keyboard(unsigned char, int, int);
void reshp(int, int);

int is_depth;

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}
void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}
void reshp(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, lebar / tinggi, 5, 500.0);
    glTranslatef(-40, -50.0, -200.0);
    glMatrixMode(GL_MODELVIEW);
}
void Myinit(void)
{
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
		case 'q':
    case 'Q':
        glTranslatef(0.0, 0.0, -1.0);
        break;
		case 'e':
    case 'E':
        glTranslatef(0.0, 0.0, 1.0);
        break;
	case 'w':
    case 'W':
        glTranslatef(0.0, 1.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(1.0, 0.0, 0.0);
        break;
	case 's':
    case 'S':
        glTranslatef(0.0, -1.0, 0.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-1.0, 0.0, 0.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}

void display(void)
{
	
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

	//dasar
	glBegin(GL_POLYGON);
	glColor3f(0.6,0.6,0.6);
	glVertex3d(-300, 0, 150);
	glVertex3d(300,0,150);
	glVertex3d(300,0,-50);
	glVertex3d(-300,0,-50);
	glEnd();

	//bawahan
	glBegin(GL_POLYGON); glColor3f(0.81 , 0.71 , 0.23);
	glVertex3f(-50, 20, 100); glVertex3f(0, 20, 100); glVertex3f(0, 20, 0);
	glVertex3f(-50, 20, 0);	glVertex3f(-100,20,50);	glVertex3f(-100,20,100);
	glVertex3f(-50, 20, 150); glEnd();
		//bawahan(bemper)
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);
			glVertex3f(0, 20, 0);	glVertex3f(-50, 20, 0);		glVertex3f(-50, 35, 0);
			glVertex3f(0, 35, 0);	glEnd();
			//2
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);
			glVertex3f(-50, 20, 0);		glVertex3f(-100, 20, 50);		glVertex3f(-100, 35, 50);
			glVertex3f(-50, 35, 0);		glEnd();
			//3
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);		glVertex3f(-100, 20, 50);		glVertex3f(-100, 20, 100);
			glVertex3f(-100, 35, 100);			glVertex3f(-100, 35, 50);		glEnd();
			//4
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(-50, 20, 150);		glVertex3f(-100, 20, 100);
			glVertex3f(-100, 35, 100);		glVertex3f(-50, 35, 150);		glEnd();
			//5
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(-50, 20, 150);		glVertex3f(-50, 20, 100);
			glVertex3f(-50, 35, 100);		glVertex3f(-50, 35, 150);		glEnd();
			//editan5
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(-50, 20, 150);		glVertex3f(-20, 20, 150);
			glVertex3f(-20, 35, 150);		glVertex3f(-50, 35, 150);		glEnd();
			//6
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(-50, 20, 100);		glVertex3f(0, 20, 100);
			glVertex3f(0, 35, 100);			glVertex3f(-50, 35, 100);		glEnd();
			//7
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(0, 20, 0);			glVertex3f(0, 20, 100);
			glVertex3f(0, 35, 100);			glVertex3f(0, 35, 0);			glEnd();
			//tutupdasar
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.23);	glVertex3f(-50, 35, 100);		glVertex3f(0, 35, 100);
			glVertex3f(0, 35, 0);			glVertex3f(-50, 35, 0);			glVertex3f(-100,35,50);
			glVertex3f(-100,35,100);		glVertex3f(-50, 35, 150);		glEnd();
//kandangmanungsa
			//1sisi
			glBegin(GL_POLYGON);
			glColor3f(0.1 , 0.1 , 0.1);
			glVertex3f(-50, 35, 150);
			glVertex3f(-50, 35, 100);
			glVertex3f(-50, 75, 100);
			glVertex3f(-50, 75, 150);
			glEnd();
			//2sisi
			glBegin(GL_POLYGON);
			glColor3f(0.2 , 0.2 , 0.2);
			glVertex3f(-50, 35, 100);
			glVertex3f(-20, 35, 100);
			glVertex3f(0, 50, 100);
			glVertex3f(0, 75, 100);
			glVertex3f(-20, 75, 100);
			glVertex3f(-50, 75, 100);
			glEnd();
			//3sisi
			glBegin(GL_POLYGON);
			glColor3f(0.2 , 0.2 , 0.2);
			glVertex3f(-50, 35, 150);
			glVertex3f(-20, 35, 150);
			glVertex3f(0, 50, 150);
			glVertex3f(0, 75, 150);
			glVertex3f(-20, 75, 150);		
			glVertex3f(-50, 75, 150);
			glEnd();
			//4dasar
			glBegin(GL_POLYGON);
			glColor3f(0.1 , 0.1 , 0.1);
			glVertex3f(-50, 35, 150);
			glVertex3f(-20, 35, 150);
			glVertex3f(-20, 35, 100);		
			glVertex3f(-50, 35, 100);
			glEnd();
			//miring
			glBegin(GL_POLYGON);
			glColor3f(0.1 , 0.1 , 0.1);
			glVertex3f(-20, 35, 150);
			glVertex3f(-20, 35, 100);
			glVertex3f(0, 50, 100);		
			glVertex3f(0, 50, 150);
			glEnd();



	
	glPopMatrix();
    glutSwapBuffers();
}



int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 100);
    glutCreateWindow("Leonardus Aldian CN - 672018263");
    Myinit();
	glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshp); 
	glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutMainLoop();
    return 0;
}
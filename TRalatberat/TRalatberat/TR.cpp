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

	//jalan
	//glBegin(GL_POLYGON);
	glColor3f(0.6,0.6,0.6);
	glVertex3d(-300, 0, 140);
	glVertex3d(300,0,140);
	glVertex3d(300,0,-50);
	glVertex3d(-300,0,-50);
	//glEnd();

	//bawahan
	glBegin(GL_POLYGON); glColor3f(0.81 , 0.71 , 0.6);
	glVertex3f(-50, 20, 100);
	glVertex3f(0, 20, 100);
	glVertex3f(0, 20, 50);
	glVertex3f(-50, 20, 50);
	glVertex3f(-50, 20, 0);
	glVertex3f(-100,20,50);
	glVertex3f(-100,20,100);
	glVertex3f(-50, 20, 130);
	glEnd();
		    //bawahan(bemper)
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);
			glVertex3f(0, 20, 50);	glVertex3f(-50, 20, 50);		glVertex3f(-50, 35, 50);
			glVertex3f(0, 35, 50);	glEnd();
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
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(-50, 20, 130);		glVertex3f(-100, 20, 100);
			glVertex3f(-100, 35, 100);		glVertex3f(-50, 35, 130);		glEnd();
			//5
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(-50, 20, 130);		glVertex3f(-50, 20, 100);
			glVertex3f(-50, 35, 100);		glVertex3f(-50, 35, 130);		glEnd();
			//editan5
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(-50, 20, 130);		glVertex3f(-20, 20, 130);
			glVertex3f(-20, 35, 130);		glVertex3f(-50, 35, 130);		glEnd();
			//6
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(-50, 20, 100);		glVertex3f(0, 20, 100);
			glVertex3f(0, 35, 100);			glVertex3f(-50, 35, 100);		glEnd();
			//7
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(-50, 20, 0);			glVertex3f(-50, 20, 50);
			glVertex3f(-50, 35, 50);			glVertex3f(-50, 35, 0);			glEnd();
			//8
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(0, 20, 50);			glVertex3f(0, 20, 100);
			glVertex3f(0, 35, 100);			glVertex3f(0, 35, 50);			glEnd();
			//tutupdasar
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.23);
			glVertex3f(-50, 35, 100);
			glVertex3f(0, 35, 100);
			glVertex3f(0, 35, 50);
			glVertex3f(-50, 35, 50);
			glVertex3f(-50, 35, 0);
			glVertex3f(-100, 35, 50);
			
			glVertex3f(-100,35,100);
			
			glVertex3f(-50, 35, 130);		glEnd();
//kandangmanungsa
			//1sisi
			glBegin(GL_POLYGON);
			glColor3f(0.1 , 0.1 , 0.1);
			glVertex3f(-50, 35, 130);
			glVertex3f(-50, 35, 90);
			glVertex3f(-50, 75, 90);
			glVertex3f(-50, 75, 130);
			glEnd();
			//2sisi
			glBegin(GL_POLYGON);
			glColor3f(0.2 , 0.2 , 0.2);
			glVertex3f(-50, 35, 90);
			glVertex3f(-20, 35, 90);
			glVertex3f(0, 50, 90);
			glVertex3f(0, 75, 90);
			glVertex3f(-20, 75, 90);
			glVertex3f(-50, 75, 90);
			glEnd();
			//3sisi
			glBegin(GL_POLYGON);
			glColor3f(0.2 , 0.2 , 0.2);
			glVertex3f(-50, 35, 130);
			glVertex3f(-20, 35, 130);
			glVertex3f(0, 50, 130);
			glVertex3f(0, 75, 130);
			glVertex3f(-20, 75, 130);		
			glVertex3f(-50, 75, 130);
			glEnd();
			//4dasar
			glBegin(GL_POLYGON);
			glColor3f(0.1 , 0.1 , 0.1);
			glVertex3f(-50, 35, 130);
			glVertex3f(-20, 35, 130);
			glVertex3f(-20, 35, 90);		
			glVertex3f(-50, 35, 90);
			glEnd();
			//miring
			glBegin(GL_POLYGON);
			glColor3f(0.1 , 0.1 , 0.1);
			glVertex3f(-20, 35, 130);
			glVertex3f(-20, 35, 90);
			glVertex3f(0, 50, 90);		
			glVertex3f(0, 50, 130);
			glEnd();
//mesin
			//kapdepan
			glBegin(GL_POLYGON);
			glColor3f(0.1 , 0.1 , 0.1);
			glVertex3f(-100, 35, 60);
			glVertex3f(-100, 35, 90);
			glVertex3f(-97, 75, 90);
			glVertex3f(-97, 75, 60);
			glEnd();
			//monconglampu1
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.1);
			glVertex3f(-100, 35, 50);
			glVertex3f(-100, 35, 60);
			glVertex3f(-97, 60, 60);
			glVertex3f(-97, 60, 50);
			glEnd();
			//sampinglampukanan
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.4);
			glVertex3f(-100, 35, 50);
			glVertex3f(-97, 60, 50);
			glVertex3f(-50, 60, 50);
			glVertex3f(-50, 35, 50);
			glEnd();
			//sampinglampu1
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.4);
			glVertex3f(-100, 35, 59.98);
			glVertex3f(-97, 60, 59.98);
			glVertex3f(-50, 60, 59.98);
			glVertex3f(-50, 35, 59.98);
			glEnd();
			//tutuplampu2
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.2);
			glVertex3f(-97, 60, 50);
			glVertex3f(-97, 60, 60);
			glVertex3f(-50, 60, 60);
			glVertex3f(-50, 60, 50);
			glEnd();
			//monconglampu2
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.1);
			glVertex3f(-100, 35, 90);
			glVertex3f(-100, 35, 100);
			glVertex3f(-97, 60, 100);
			glVertex3f(-97, 60, 90);
			glEnd();
			//sampinglampu2
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.4);
			glVertex3f(-100, 35, 100);
			glVertex3f(-97, 60, 100);
			glVertex3f(-50, 60, 100);
			glVertex3f(-50, 35, 100);
			glEnd();
			//tutuplampu2
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.2);
			glVertex3f(-97, 60, 90);
			glVertex3f(-97, 60, 100);
			glVertex3f(-50, 60, 100);
			glVertex3f(-50, 60, 90);
			glEnd();

			//tutupkapkecil
			glBegin(GL_POLYGON);
			glColor3f(0.6,0.6,0.6);
			glVertex3d(-97, 75, 60);
			glVertex3d(-97,75,90);
			glVertex3d(-94,80,90);
			glVertex3d(-94,80,60);
			glEnd();
			//tutupkap
			glBegin(GL_POLYGON);
			glColor3f(0.6,0.6,0.9);
			glVertex3d(-94,80,60);
			glVertex3d(-94,80,90);
			glVertex3d(0,85,90);
			glVertex3d(0,85,60);
			glEnd();
			//tutupsampingmesin
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);
			glVertex3f(-100, 35, 89.99);
			glVertex3f(-97, 75, 89.99);
			glVertex3f(-94,80,89.99);
			glVertex3f(0,85,89.99);
			glVertex3f(0,35,89.99);
			glEnd();
			//tutusampingmesinkiri
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);
			glVertex3f(-100, 35, 59.99);
			glVertex3f(-97, 75, 59.99);
			glVertex3f(-94,80,59.99);
			glVertex3f(0,85,59.99);
			glVertex3f(0,35,59.99);
			glEnd();

//bandepan
		//bankiri 
			glBegin(GL_POLYGON);
			glColor3f(0.6 , 0.6 , 0.6);
			glVertex3f(-20, 20, 130);
			glVertex3f(-20, 35, 130);
			glVertex3f(-20, 35, 100);		
			glVertex3f(-20, 20, 100);
			glEnd();
			//miring1
			glBegin(GL_POLYGON);
			glColor3f(0.6 , 0.6 , 0.5);
			glVertex3f(-20, 35, 130);
			glVertex3f(0, 49.9, 130);
			glVertex3f(0, 49.9, 100);
			glVertex3f(-20, 35, 100);
			glEnd();
			//datar
			glBegin(GL_POLYGON);
			glColor3f(0.6 , 0.6 , 0.6);
			glVertex3f(0, 49.9, 130);
			glVertex3f(25, 49.9, 130);
			glVertex3f(25, 49.9, 100);
			glVertex3f(0, 49.9, 100);
			glEnd();
			//miring2
			glBegin(GL_POLYGON);
			glColor3f(0.6 , 0.6 , 0.5);
			glVertex3f(45, 35, 130);
			glVertex3f(25, 49.9, 130);
			glVertex3f(25, 49.9, 100);
			glVertex3f(45, 35, 100);
			glEnd();
			//sleborjancug
			glBegin(GL_POLYGON);
			glColor3f(0.6 , 0.6 , 0.6);
			glVertex3f(45, 20, 130);
			glVertex3f(45, 35, 130);
			glVertex3f(45, 35, 100);		
			glVertex3f(45, 20, 100);
			glEnd();
	//ban kanan
			glBegin(GL_POLYGON);
			glColor3f(0.6 , 0.6 , 0.6);
			glVertex3f(-20, 20, 50);
			glVertex3f(-20, 35, 50);
			glVertex3f(-20, 35, 0);		
			glVertex3f(-20, 20, 0);
			glEnd();
			//miring1
			glBegin(GL_POLYGON);
			glColor3f(0.6 , 0.6 , 0.5);
			glVertex3f(-20, 35, 50);
			glVertex3f(0, 49.9, 50);
			glVertex3f(0, 49.9, 0);
			glVertex3f(-20, 35, 0);
			glEnd();
			//datar
			glBegin(GL_POLYGON);
			glColor3f(0.6 , 0.6 , 0.6);
			glVertex3f(0, 49.9, 50);
			glVertex3f(25, 49.9, 50);
			glVertex3f(25, 49.9, 0);
			glVertex3f(0, 49.9, 0);
			glEnd();
			//miring2
			glBegin(GL_POLYGON);
			glColor3f(0.6 , 0.6 , 0.5);
			glVertex3f(45, 35, 50);
			glVertex3f(25, 49.9, 50);
			glVertex3f(25, 49.9, 0);
			glVertex3f(45, 35, 0);
			glEnd();
			//sleborjancug
			glBegin(GL_POLYGON);
			glColor3f(0.6 , 0.6 , 0.6);
			glVertex3f(45, 20, 50);
			glVertex3f(45, 35, 50);
			glVertex3f(45, 35, 0);		
			glVertex3f(45, 20, 0);
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
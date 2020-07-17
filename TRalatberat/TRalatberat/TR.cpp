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
void frontBody(void);
void ControlCenter(void);
void TractorMachine(void);
void SideMachine(void);
void frontWheels(void);
void TractorMachineExtensions(void);
void ShredderMachine(void);
void GateControl(void);
void Extras(void);

void Myinit(void);
void display(void);
void keyboard(unsigned char, int, int);
void reshp(int, int);
int i;
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
    gluPerspective(100, lebar / tinggi, 50, 1000.0);
    glTranslatef(-50, -100.0, -300.0);
    glMatrixMode(GL_MODELVIEW);
}
void Myinit(void)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glClearColor(1,1,1, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;


    
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key){
    
	   
		case 'q':
    case 'Q':
        glTranslatef(0.0, 0.0, -3.0);
        break;
		case 'e':
    case 'E':
        glTranslatef(0.0, 0.0, 3.0);
        break;
	case 'w':
    case 'W':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
	case 's':
    case 'S':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
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

void frontBody(void)
{
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
	glVertex3f(-50, 20, 100);glVertex3f(0, 20, 100);
	glVertex3f(0, 20, 50);glVertex3f(-50, 20, 50);
	glVertex3f(-50, 20, 0);glVertex3f(-100,20,50);
	glVertex3f(-100,20,100);glVertex3f(-50, 20, 130);
	glEnd();
		    //bawahan(bemper)
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);
			glVertex3f(0, 20, 50);glVertex3f(-50, 20, 50);glVertex3f(-50, 35, 50);
			glVertex3f(0, 35, 50);glEnd();
			//2
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);
			glVertex3f(-50, 20, 0);	glVertex3f(-100, 20, 50);glVertex3f(-100, 35, 50);
			glVertex3f(-50, 35, 0);	glEnd();
			//3
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);glVertex3f(-100, 20, 50);glVertex3f(-100, 20, 100);
			glVertex3f(-100, 35, 100);glVertex3f(-100, 35, 50);glEnd();
			//4
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);glVertex3f(-50, 20, 130);glVertex3f(-100, 20, 100);
			glVertex3f(-100, 35, 100);glVertex3f(-50, 35, 130);glEnd();
			//5
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);glVertex3f(-50, 20, 130);glVertex3f(-50, 20, 100);
			glVertex3f(-50, 35, 100);glVertex3f(-50, 35, 130);glEnd();
			//editan5
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);glVertex3f(-50, 20, 130);glVertex3f(-20, 20, 130);
			glVertex3f(-20, 35, 130);glVertex3f(-50, 35, 130);glEnd();
			//6
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);glVertex3f(-50, 20, 100);glVertex3f(0, 20, 100);
			glVertex3f(0, 35, 100);	glVertex3f(-50, 35, 100);glEnd();
			//7
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);glVertex3f(-50, 20, 0);glVertex3f(-50, 20, 50);
			glVertex3f(-50, 35, 50);glVertex3f(-50, 35, 0);	glEnd();
			//8
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);glVertex3f(0, 20, 50);	glVertex3f(0, 20, 100);
			glVertex3f(0, 35, 100);	glVertex3f(0, 35, 50);	glEnd();
			//tutupdasar
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.23);	glVertex3f(-50, 35, 100);
			glVertex3f(0, 35, 100);	glVertex3f(0, 35, 50);	glVertex3f(-50, 35, 50);
			glVertex3f(-50, 35, 0);	glVertex3f(-100, 35, 50); glVertex3f(-100,35,100);
			glVertex3f(-50, 35, 130); glEnd();
			//glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.1);	glVertex3f(0, 35, 50);	glVertex3f(0, 35, 100);
			glVertex3f(0,85,59.99); glVertex3f(0,35,59.99);
			//glEnd();
}
void ControlCenter(void)
{
	//kandangmanungsa
		//1 sisi
			glBegin(GL_POLYGON);
			glColor3f(0.1 , 0.1 , 0.1);
			glVertex3f(-50, 35, 130);	glVertex3f(-50, 35, 90);
			glVertex3f(-50, 75, 90);	glVertex3f(-50, 75, 130);
			glEnd();
			//frame kiri
				glBegin(GL_POLYGON);
				glColor3f(0.1 , 0.1 , 0.1);
				glVertex3f(-50, 75, 90);	glVertex3f(-50, 75, 95);
				glVertex3f(-50, 120, 95);	glVertex3f(-50, 120, 90);
				glEnd();
			//frame kanan
				glBegin(GL_POLYGON);
				glColor3f(0.1 , 0.1 , 0.1);
				glVertex3f(-50, 75, 125);	glVertex3f(-50, 75, 130);
				glVertex3f(-50, 120, 130);	glVertex3f(-50, 120, 125);
				glEnd();

			//2sisi
			glBegin(GL_POLYGON);
			glColor3f(0.2 , 0.2 , 0.2);
			glVertex3f(-50, 35, 90);	glVertex3f(-20, 35, 90);
			glVertex3f(0, 50, 90);		glVertex3f(0, 75, 90);
			glVertex3f(-20, 75, 90);	glVertex3f(-50, 75, 90);
			glEnd();
					//frame kiri
					glBegin(GL_POLYGON);
					glColor3f(0.1 , 0.1 , 0.1);
					glVertex3f(0, 75, 90);	 glVertex3f(-5, 75, 90);
					glVertex3f(-5, 120, 90); glVertex3f(0, 120, 90);
					glEnd();
					//frame kanan
					glBegin(GL_POLYGON);
					glColor3f(0.1 , 0.1 , 0.1);
					glVertex3f(-45, 75, 90);	glVertex3f(-50, 75, 90);
					glVertex3f(-50, 120, 90);	glVertex3f(-45, 120, 90);
					glEnd();
			
			//3sisi
			glBegin(GL_POLYGON);
			glColor3f(0.2 , 0.2 , 0.2);
			glVertex3f(-50, 35, 130);	glVertex3f(-20, 35, 130);
			glVertex3f(0, 50, 130);		glVertex3f(0, 75, 130);
			glVertex3f(-20, 75, 130);	glVertex3f(-50, 75, 130);
			glEnd();
					//frame kiri
					glBegin(GL_POLYGON);
					glColor3f(0.1 , 0.1 , 0.1);
					glVertex3f(0, 75, 130);		glVertex3f(-5, 75, 130);
					glVertex3f(-5, 120, 130);	glVertex3f(0, 120, 130);
					glEnd();
					//frame kanan
					glBegin(GL_POLYGON);
					glColor3f(0.1 , 0.1 , 0.1);
					glVertex3f(-45, 75, 130);	glVertex3f(-50, 75, 130);
					glVertex3f(-50, 120, 130);  glVertex3f(-45, 120, 130);
					glEnd();

			//4dasar
			glBegin(GL_POLYGON);
			glColor3f(0.1 , 0.1 , 0.1);
			glVertex3f(-50, 35.1, 130);	glVertex3f(-20, 35.1, 130);
			glVertex3f(-20, 35.1, 90);	glVertex3f(-50, 35.1, 90);
			glEnd();
			//miring
			glBegin(GL_POLYGON);
			glColor3f(0.1 , 0.1 , 0.1);
			glVertex3f(-20, 35, 130);	glVertex3f(-20, 35, 90);
			glVertex3f(0, 50, 90);		glVertex3f(0, 50, 130);
			glEnd();
			
			//coverbelakang
			glBegin(GL_POLYGON);
			glColor3f(0.3 , 0.3 , 0.3);
			glVertex3f(0, 50, 90);		glVertex3f(0, 50, 130);
			glVertex3f(0, 120, 130);	glVertex3f(0, 120, 90);	
			glEnd();
			//cover atas
			glBegin(GL_POLYGON);
			glColor3f(0.3 , 0.3 , 0.3);
			glVertex3f(-50, 120, 90);	glVertex3f(-50, 120, 130);
			glVertex3f(0, 120, 130);    glVertex3f(0, 120, 90);
			glEnd();
				//kap atas depan
				glBegin(GL_POLYGON);
				glColor3f(0.25 , 0.25 , 0.25);
				glVertex3f(-50, 120, 90);	glVertex3f(-50, 120, 130);
				glVertex3f(-50, 130, 130);	glVertex3f(-50, 130, 90);
				glEnd();
				//kap atas samping
				glBegin(GL_POLYGON);
				glColor3f(0.25 , 0.25 , 0.25);
				glVertex3f(0, 120, 90);		glVertex3f(-50, 120, 90);
				glVertex3f(-50, 130, 90);	glVertex3f(0, 130, 90);		
				glEnd();
				//kap atas samping
				glBegin(GL_POLYGON);
				glColor3f(0.25 , 0.25 , 0.25);
				glVertex3f(0, 120, 130);	glVertex3f(-50, 120, 130);
				glVertex3f(-50, 130, 130);	glVertex3f(0, 130, 130);
				glEnd();
				//kap atas belakang
				glBegin(GL_POLYGON);
				glColor3f(0.25 , 0.25 , 0.25);
				glVertex3f(0, 120, 90);		glVertex3f(0, 120, 130);
				glVertex3f(0, 130, 130);	glVertex3f(0, 130, 90);
				glEnd();
				//cover atas
				glBegin(GL_POLYGON);
				glColor3f(0.3 , 0.3 , 0.3);
				glVertex3f(-50, 130, 90);	glVertex3f(-50, 130, 130);
				glVertex3f(0, 130, 130);	glVertex3f(0, 130, 90);
				glEnd();
}
void TractorMachine(void)
{
//mesin
			//kapdepan
			glBegin(GL_POLYGON);
			glColor3f(0.1 , 0.1 , 0.1);
			glVertex3f(-100, 35, 60);	glVertex3f(-100, 35, 90);
			glVertex3f(-97, 75, 90);	glVertex3f(-97, 75, 60);
			glEnd();
			//monconglampu1
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.1);
			glVertex3f(-100, 35, 50);	glVertex3f(-100, 35, 60);
			glVertex3f(-97, 60, 60);	glVertex3f(-97, 60, 50);
			glEnd();
			//sampinglampukanan
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.3);
			glVertex3f(-100, 35, 50);  glVertex3f(-97, 60, 50);
			glVertex3f(-50, 60, 50);   glVertex3f(-50, 35, 50);
			glEnd();
			//sampinglampu1
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.3);
			glVertex3f(-100, 35, 59.98);	glVertex3f(-97, 60, 59.98);
			glVertex3f(-50, 60, 59.98);		glVertex3f(-50, 35, 59.98);
			glEnd();
			//tutuplampu2
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.2);
			glVertex3f(-97, 60, 50);		glVertex3f(-97, 60, 60);
			glVertex3f(-50, 60, 60);		glVertex3f(-50, 60, 50);
			glEnd();
			//monconglampu2
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.1);
			glVertex3f(-100, 35, 90);		glVertex3f(-100, 35, 100);
			glVertex3f(-97, 60, 100);		glVertex3f(-97, 60, 90);
			glEnd();
			//sampinglampu2
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.3);
			glVertex3f(-100, 35, 100);		glVertex3f(-97, 60, 100);
			glVertex3f(-50, 60, 100);		glVertex3f(-50, 35, 100);
			glEnd();
			//tutuplampu2
			glBegin(GL_POLYGON);
			glColor3f(0.7 , 0.6 , 0.2);
			glVertex3f(-97, 60, 90);		glVertex3f(-97, 60, 100);
			glVertex3f(-50, 60, 100);		glVertex3f(-50, 60, 90);	
			glEnd();

			//tutupkapkecil
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3d(-97, 75, 60);		glVertex3d(-97,75,90);
			glVertex3d(-94,80,90);  		glVertex3d(-94,80,60);
			glEnd();
			//tutupkap
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3d(-94,80,60);			glVertex3d(-94,80,90);
			glVertex3d(0,85,90);			glVertex3d(0,85,60);
			glEnd();
			//tutupsampingmesin
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.0);
			glVertex3f(-100, 35, 89.99);	glVertex3f(-97, 75, 89.99);
			glVertex3f(-94,80,89.99);		glVertex3f(0,85,89.99);	
			glVertex3f(0,35,89.99);
			glEnd();
			//tutusampingmesinkiri
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.0);
			glVertex3f(-100, 35, 59.99);	glVertex3f(-97, 75, 59.99);
			glVertex3f(-94,80,59.99);		glVertex3f(0,85,59.99);
			glVertex3f(0,35,59.99);			glEnd();
			
			

}
void SideMachine(void)
{
//
//SideMachine
//			//1sisi
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(-50, 35, 59.9);	glVertex3f(-50, 35, 0);
			glVertex3f(-50, 75, 0); 	glVertex3f(-50, 75, 59.9);
			glEnd();
			//2sisi
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(-50, 35, 0); 	glVertex3f(-20, 35, 0);
			glVertex3f(0, 50, 0);		glVertex3f(0, 75, 0);
			glVertex3f(-20, 75, 0);		glVertex3f(-50, 75, 0);
			glEnd();
			//3sisi
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(-50, 35, 59.9);	glVertex3f(-20, 35, 59.9);
			glVertex3f(0, 50, 59.9);	glVertex3f(0, 75, 59.9);
			glVertex3f(-20, 75, 59.9);	glVertex3f(-50, 75, 59.9);	
			glEnd();
			//4dasar
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(-50, 35, 59.9);	glVertex3f(-20, 35, 59.9);
			glVertex3f(-20, 35, 0);		glVertex3f(-50, 35, 0);
			glEnd();
			//miring
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(-20, 35, 59.9);	glVertex3f(-20, 35, 0);
			glVertex3f(0, 50, 0);		glVertex3f(0, 50, 59.9);
			glEnd();


}
void frontWheels(void)
{
//bandepan
		//bankiri 
			//ban
					for (int i=0;i<50;i++)
					{
					glBegin(GL_POLYGON);
					glColor3f(0.1 , 0.1 , 0.1);
					glVertex3f(-10, 35, 90+i);			glVertex3f(5, 45, 90+i);
					glVertex3f(25, 45, 90+i);			glVertex3f(40, 35, 90+i);
					glVertex3f(40, 0, 90+i);				glVertex3f(25, -15, 90+i);		
					glVertex3f(5, -15, 90+i);			glVertex3f(-10, 0, 90+i);
					glEnd();
					}

	//velg
					//slebordepan
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
			//ban
					for(int i=0; i<50;i++)
					{
					glBegin(GL_POLYGON);
					glColor3f(0.1 , 0.1 , 0.1);
					glVertex3f(-10, 35, 0+i);
					glVertex3f(5, 45, 0+i);
					glVertex3f(25, 45, 0+i);
					glVertex3f(40, 35, 0+i);
					glVertex3f(40, 0, 0+i);
					glVertex3f(25, -15, 0+i);
					glVertex3f(5, -15, 0+i);
					glVertex3f(-10, 0, 0+i);
					glEnd();
					}
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
}
void TractorMachineExtensions(void)
{
//EXTENDSIONS
			
			glBegin(GL_QUADS);
			//dasar
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(0, 20, 50);
			glVertex3f(50, 20, 50);
			glVertex3f(50, 20, 100);		
			glVertex3f(0, 20, 100);
			//depan
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(0.1, 20, 50);
			glVertex3f(0.1, 75, 50);
			glVertex3f(0.1, 75, 100);		
			glVertex3f(0.1, 20, 100);
			//belakang
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(49.9, 20, 50);
			glVertex3f(49.9, 75, 50);
			glVertex3f(49.9, 75, 100);		
			glVertex3f(49.9, 20, 100);
			//sampingkiri
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(0, 20, 100);
			glVertex3f(50, 20, 100);
			glVertex3f(50, 75, 100);		
			glVertex3f(0, 75, 100);
			//sampingkanan
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(0, 20, 50);
			glVertex3f(50, 20, 50);
			glVertex3f(50, 75, 50);		
			glVertex3f(0, 75, 50);
			//coveratasroda
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(0, 50, 0);
			glVertex3f(50, 50, 0);
			glVertex3f(50, 50, 130);		
			glVertex3f(0, 50, 130);
			//
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(0, 75, 0);
			glVertex3f(50, 75, 0);
			glVertex3f(50, 75, 130);		
			glVertex3f(0, 75, 130);
			//tutupsamping
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(0, 50, 130);
			glVertex3f(50, 50, 130);
			glVertex3f(50, 75, 130);		
			glVertex3f(0, 75, 130);
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(0, 50, 0);
			glVertex3f(50, 50, 0);
			glVertex3f(50, 75, 0);		
			glVertex3f(0, 75, 0);
			//tutupSideMachine
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(-50, 75, 0);
			glVertex3f(0, 75, 0);
			glVertex3f(0, 75, 60);		
			glVertex3f(-50, 75, 60);
			//tutupbelakang
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(50, 50, 0);
			glVertex3f(50, 75, 0);
			glVertex3f(50, 75, 130);		
			glVertex3f(50, 50, 130);
			glEnd();
}
void BackWheels(void)
{
//bankiri 
			//ban
					for(int i =0 ;i<50;i++)
					{
					glBegin(GL_POLYGON);
					glColor3f(0.1 , 0.1 , 0.1);
					glVertex3f(290, 35, 90+i);			glVertex3f(305, 45, 90+i);
					glVertex3f(325, 45, 90+i);			glVertex3f(340, 35, 90+i);
					glVertex3f(340, 0, 90+i);			glVertex3f(325, -15, 90+i);		
					glVertex3f(305, -15, 90+i);			glVertex3f(290, 0, 90+i);
					glEnd();
					}

			//velg
					//slebordepan
					glBegin(GL_POLYGON);
					glColor3f(0.6 , 0.6 , 0.6);
					glVertex3f(280, 20, 130);
					glVertex3f(280, 35, 130);
					glVertex3f(280, 35, 100);		
					glVertex3f(280, 20, 100);
					glEnd();
			
					//miring1
					glBegin(GL_POLYGON);
					glColor3f(0.6 , 0.6 , 0.5);
					glVertex3f(280, 35, 130);
					glVertex3f(300, 49.9, 130);
					glVertex3f(300, 49.9, 100);
					glVertex3f(280, 35, 100);
					glEnd();
					//datar
					glBegin(GL_POLYGON);
					glColor3f(0.6 , 0.6 , 0.6);
					glVertex3f(300, 49.9, 130);
					glVertex3f(325, 49.9, 130);
					glVertex3f(325, 49.9, 100);
					glVertex3f(300, 49.9, 100);
					glEnd();
					//miring2
					glBegin(GL_POLYGON);
					glColor3f(0.6 , 0.6 , 0.5);
					glVertex3f(345, 35, 130);
					glVertex3f(325, 49.9, 130);
					glVertex3f(325, 49.9, 100);
					glVertex3f(345, 35, 100);
					glEnd();
					//sleborjancug
					glBegin(GL_POLYGON);
					glColor3f(0.6 , 0.6 , 0.6);
					glVertex3f(345, 20, 130);
					glVertex3f(345, 35, 130);
					glVertex3f(345, 35, 100);		
					glVertex3f(345, 20, 100);
					glEnd();
	//ban kanan
					
			//ban
					for(int i =0 ;i<50;i++)
					{
					glBegin(GL_POLYGON);
					glColor3f(0.1 , 0.1 , 0.1);
					glVertex3f(290, 35, 0+i);			glVertex3f(305, 45, 0+i);
					glVertex3f(325, 45, 0+i);			glVertex3f(340, 35, 0+i);
					glVertex3f(340, 0, 0+i);			glVertex3f(325, -15, 0+i);		
					glVertex3f(305, -15, 0+i);			glVertex3f(290, 0, 0+i);
					glEnd();
					}
			//velg
					//slebordepan
					glBegin(GL_POLYGON);
					glColor3f(0.6 , 0.6 , 0.6);
					glVertex3f(280, 20, 30);
					glVertex3f(280, 35, 30);
					glVertex3f(280, 35, 0);		
					glVertex3f(280, 20, 0);
					glEnd();
			
					//miring1
					glBegin(GL_POLYGON);
					glColor3f(0.6 , 0.6 , 0.5);
					glVertex3f(280, 35, 30);
					glVertex3f(300, 49.9, 30);
					glVertex3f(300, 49.9, 0);
					glVertex3f(280, 35, 0);
					glEnd();
					//datar
					glBegin(GL_POLYGON);
					glColor3f(0.6 , 0.6 , 0.6);
					glVertex3f(300, 49.9, 30);
					glVertex3f(325, 49.9, 30);
					glVertex3f(325, 49.9, 0);
					glVertex3f(300, 49.9, 0);
					glEnd();
					//miring2
					glBegin(GL_POLYGON);
					glColor3f(0.6 , 0.6 , 0.5);
					glVertex3f(345, 35, 30);
					glVertex3f(325, 49.9, 30);
					glVertex3f(325, 49.9, 0);
					glVertex3f(345, 35, 0);
					glEnd();
					//sleborjancug
					glBegin(GL_POLYGON);
					glColor3f(0.6 , 0.6 , 0.6);
					glVertex3f(345, 20, 30);
					glVertex3f(345, 35, 30);
					glVertex3f(345, 35, 0);		
					glVertex3f(345, 20, 0);
					glEnd();
}
void ShredderMachine(void)
{
//machineChasis
			glBegin(GL_QUADS);
			//dasar
			glColor3f(0.6 , 0.6 , 0.6);
			glVertex3f(300, 20, 30);
			glVertex3f(350, 20, 30);
			glVertex3f(350, 20, 100);		
			glVertex3f(300, 20, 100);
			//belakang
			glColor3f(0.81 , 0.71 , 0.1);
			glVertex3f(350, 20, 30);
			glVertex3f(350, 20, 100);
			glVertex3f(350, 80, 100);		
			glVertex3f(350, 80, 30);
			//depan
			glColor3f(0.81 , 0.71 , 0.2);
			glVertex3f(300, 20, 30);
			glVertex3f(300, 20, 100);
			glVertex3f(280, 90, 100);		
			glVertex3f(280, 90, 30);
			//atas
			glColor3f(0.81 , 0.71 , 0.1);
			glVertex3f(350, 80, 30);
			glVertex3f(350, 80, 100);
			glVertex3f(280, 90, 100);		
			glVertex3f(280, 90, 30);
			glEnd();
			//samping
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.0);
			glVertex3f(280, 90, 100);
			glVertex3f(350, 80, 100);
			glVertex3f(350, 20, 100);	
			glVertex3f(300, 20, 100);
			glEnd();
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.71 , 0.0);
			glVertex3f(280, 90, 30);
			glVertex3f(350, 80, 30);
			glVertex3f(350, 20, 30);	
			glVertex3f(300, 20, 30);
			glEnd();
//MachineExtras
	//pipeDASAR
			glBegin(GL_POLYGON);
			glColor3f(0,0,0);
			glVertex3f(330, 84, 40 );
			glVertex3f(340, 82.5, 40);
			glVertex3f(340, 82.5, 50);	
			glVertex3f(330, 84, 50);
			glEnd();
			//side
			//front
			glBegin(GL_QUADS);
			glColor3f(0.1,0.1,0.1);
			glVertex3f(330, 84, 40 );
			glVertex3f(330, 120, 40);
			glVertex3f(330, 120, 50);	
			glVertex3f(330, 84, 50);
			//back
			glColor3f(0.1,0.1,0.1);
			glVertex3f(340, 82.5, 40 );
			glVertex3f(340, 115, 40);
			glVertex3f(340, 115, 50);	
			glVertex3f(340, 82.5, 50);
			//sides
			glColor3f(0,0,0);
			glVertex3f(330, 84, 40 );
			glVertex3f(340, 82.5, 40);
			glVertex3f(340, 115, 40);	
			glVertex3f(330, 120, 40);
			glColor3f(0,0,0);
			glVertex3f(330, 84, 50 );
			glVertex3f(340, 82.5, 50);
			glVertex3f(340, 115, 50);	
			glVertex3f(330, 120, 50);
			glEnd();
/////////////////////////////////////////
//
//
//
//
//				THE SHREDDER PART			
//
//
//
/////////////////////////////////////////
			//shredder important part
			glBegin(GL_QUADS);
			glColor3f(0.3 , 0.3 , 0.3);
			glVertex3f(80, -5, 0);
			glVertex3f(75, -2.5, 0);
			glVertex3f(75, -2.5, 130);
			glVertex3f(80, -5, 130);
			glColor3f(0.3 , 0.3 , 0.3);
			glVertex3f(80, 0, 0);
			glVertex3f(75, -2.5, 0);
			glVertex3f(75, -2.5, 130);
			glVertex3f(80, 0, 130);
			//dasar
			glBegin(GL_QUADS);
			glColor3f(0.81 , 0.71 , 0.1);
			glVertex3f(80, 0, 0);
			glVertex3f(250, -10, 0);
			glVertex3f(250, -10, 130);
			glVertex3f(80, 0, 130);
			//dasar2
			glVertex3f(80, -5, 0);
			glVertex3f(250, -10, 0);
			glVertex3f(250, -10, 130);
			glVertex3f(80,-5, 130);
			//tutupmoncongdasar
			glVertex3f(80, 5, 0);
			glVertex3f(80, -5, 0);
			glVertex3f(80, -5, 130);
			glVertex3f(80,5, 130);
			
			//belakang
			glColor3f(0.81 , 0.71 , 0.3);
			glVertex3f(250, -10, 0);
			glVertex3f(290, 50, 0);
			glVertex3f(290, 50, 130);
			glVertex3f(250, -10, 130);
			//samping
			glColor3f(0.81 , 0.71 , 0.5);
			glVertex3f(70, 60, 130);
			glVertex3f(290, 50, 130);
			glVertex3f(250, -10, 130);
			glVertex3f(80, 0, 130);
			glColor3f(0.81 , 0.71 , 0.6);
			glVertex3f(70, 60, 0);
			glVertex3f(290, 50, 0);
			glVertex3f(250, -10, 0);
			glVertex3f(80, -10, 0);
			glEnd();
}
void GateControl(void)
{
//mesinkatup
		
			//dasar
			glBegin(GL_QUADS);
			glColor3f(0.81 , 0.71 , 0.0);
			glVertex3f(0, 75.1, 0);
			glVertex3f(50, 75.1, 0);
			glVertex3f(50, 75.1, 90);
			glVertex3f(0, 75.1, 90);
			//depan
			glColor3f(0.81 , 0.71 , 0.0);
			glVertex3f(0, 75.1, 0);
			glVertex3f(0, 100, 0);
			glVertex3f(0, 100, 90);
			glVertex3f(0, 75.1, 90);
			//belakang
			glColor3f(0.81 , 0.71 , 0.0);
			glVertex3f(50, 75.1, 0);
			glVertex3f(50, 100, 0);
			glVertex3f(50, 100, 90);
			glVertex3f(50, 75.1, 90);
			//samping
			glColor3f(0.81 , 0.71 , 0.0);
			glVertex3f(0, 75.1, 0);
			glVertex3f(50, 75.1, 0);
			glVertex3f(50, 100, 0);
			glVertex3f(0, 100, 0);
			glColor3f(0.81 , 0.71 , 0.0);
			glVertex3f(0, 75.1, 90);
			glVertex3f(50, 75.1, 90);
			glVertex3f(50, 100, 90);
			glVertex3f(0, 100, 90);
			//tutup
			glColor3f(0.81 , 0.71 , 0.4);
			glVertex3f(0, 100, 0);
			glVertex3f(50, 100, 0);
			glVertex3f(50, 100, 90);
			glVertex3f(0, 100, 90);
			glEnd();
//tuastutupatas
			//1
			glBegin(GL_QUADS);
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(0, 100, 60);
			glVertex3f(0, 100, 90);
			glVertex3f(10, 120, 90);
			glVertex3f(10, 120, 60);
			//2
			glVertex3f(10, 120, 60);
			glVertex3f(10, 120, 90);
			glVertex3f(25, 140, 90);
			glVertex3f(25, 140, 60);
			//3
			glVertex3f(25, 140, 60);
			glVertex3f(25, 140, 90);
			glVertex3f(45, 150, 90);
			glVertex3f(45, 150, 60);
			//4
			glVertex3f(45, 150, 60);
			glVertex3f(45, 150, 90);
			glVertex3f(65, 140, 90);
			glVertex3f(65, 140, 60);
			//openedPart
			glVertex3f(65, 140, 80);
			glVertex3f(65, 140, 90);
			glVertex3f(85, 110, 90);
			glVertex3f(85, 110, 80);
			//
			glVertex3f(85, 110, 90);
			glVertex3f(85, 110, 80);
			glVertex3f(95, 80, 80);
			glVertex3f(95, 80, 90);
			//openedpart
			glVertex3f(65, 140, 60);
			glVertex3f(65, 140, 70);
			glVertex3f(85, 110, 70);
			glVertex3f(85, 110, 60);
			//
			glVertex3f(85, 110, 60);
			glVertex3f(85, 110, 70);
			glVertex3f(95, 80, 70);
			glVertex3f(95, 80, 60);
			glEnd();
	//Extension Single Part top part
			glBegin(GL_QUADS);
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(65, 140, 70);
			glVertex3f(65, 140, 80);
			glVertex3f(85, 170, 80);
			glVertex3f(85, 170, 70);
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(85, 170, 70);
			glVertex3f(85, 170, 80);
			glVertex3f(95, 175, 80);
			glVertex3f(95, 175, 70);
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(95, 175, 70);
			glVertex3f(95, 175, 80);
			glVertex3f(110, 165, 80);
			glVertex3f(110, 165, 70);
			//
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(110, 165, 70);
			glVertex3f(110, 165, 80);
			glVertex3f(120, 150, 80);
			glVertex3f(120, 150, 70);
			//
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(120, 150, 70);
			glVertex3f(120, 150, 80);
			glVertex3f(125, 90, 80);
			glVertex3f(125, 90, 70);
			glEnd();
//Extension Single Part bot part
			glBegin(GL_QUADS);
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(80, 100, 70);
			glVertex3f(80, 100, 80);
			glVertex3f(95, 115, 80);
			glVertex3f(95, 115, 70);
			//
			glVertex3f(95, 115, 70);
			glVertex3f(95, 115, 80);
			glVertex3f(105, 125, 80);
			glVertex3f(105, 125, 70);
			//
			glVertex3f(105, 125, 70);
			glVertex3f(105, 125, 80);
			glVertex3f(110, 90, 80);
			glVertex3f(110, 90, 70);
			glEnd();
//sideCover for extension part
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(105, 125, 80);
			glVertex3f(80, 100, 80);
			glVertex3f(65, 140, 80);
			glVertex3f(85, 170, 80);
			glVertex3f(95, 175, 80);
			glVertex3f(110, 165, 80);
			glVertex3f(120, 150, 80);
			glVertex3f(125, 90, 80);
			glVertex3f(110, 90, 80);
			glEnd();
			//OTHERSIDE
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(105, 125, 70);
			glVertex3f(80, 100, 70);
			glVertex3f(65, 140, 70);
			glVertex3f(85, 170, 70);
			glVertex3f(95, 175, 70);
			glVertex3f(110, 165, 70);
			glVertex3f(120, 150, 70);
			glVertex3f(125, 90, 70);
			glVertex3f(110, 90, 70);
			glEnd();
//pistonPart
			//FRONT
			glBegin(GL_QUADS);
			glColor3f(0.6,0.6,0.6);
			glVertex3f(111, 100, 70);
			glVertex3f(111, 100, 80);
			glVertex3f(111, 70, 80);
			glVertex3f(111, 70, 70);
			//BACK
			glVertex3f(120, 100, 70);
			glVertex3f(120, 100, 80);
			glVertex3f(120, 70, 80);
			glVertex3f(120, 70, 70);
			//side
			glColor3f(0.5,0.5,0.5);
			glVertex3f(111, 100, 71);
			glVertex3f(120, 100, 71);
			glVertex3f(120, 70, 71);
			glVertex3f(111, 70, 71);
			//side
			glColor3f(0.5,0.5,0.5);
			glVertex3f(111, 100, 79);
			glVertex3f(120, 100, 79);
			glVertex3f(120, 70, 79);
			glVertex3f(111, 70, 79);
			glEnd();
//gatePart
			//top part
			glBegin(GL_QUADS);
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(100, 70, 1);
			glVertex3f(100, 70, 129);
			glVertex3f(130, 70, 129);
			glVertex3f(130, 70, 1);
			
	//curved-like back part 1
			glColor3f(0.81 , 0.7 , 0);
			glVertex3f(130, 70, 1);
			glVertex3f(130, 70, 129);
			glVertex3f(120, 50, 129);
			glVertex3f(120, 50, 1);
			//2
			glColor3f(0.81 , 0.7 , 0.3);
			glVertex3f(120, 50, 1);
			glVertex3f(120, 50, 129);
			glVertex3f(122, 30, 129);
			glVertex3f(122, 30, 1);
			//3
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(122, 30, 1);
			glVertex3f(122, 30, 129);
			glVertex3f(135, 20, 129);
			glVertex3f(135, 20, 1);
			//4
			glVertex3f(135, 20, 1);
			glVertex3f(135, 20, 129);
			glVertex3f(150, 5, 129);
			glVertex3f(150, 5, 1);
			glEnd();
//curved-like front part 2
			glBegin(GL_QUADS);
			glColor3f(0.81 , 0.7 , 0);
			glVertex3f(100, 70, 1);
			glVertex3f(100, 70, 129);
			glVertex3f(100, 50, 129);
			glVertex3f(100, 50, 1);
			//2
			glVertex3f(100, 50, 1);
			glVertex3f(100, 50, 129);
			glVertex3f(110, 30, 129);
			glVertex3f(110, 30, 1);
			//3
			glColor3f(0.81 , 0.7 , 0.4);
			glVertex3f(110, 30, 1);
			glVertex3f(110, 30, 129);
			glVertex3f(115, 15, 129);
			glVertex3f(115, 15, 1);
			//4
			glVertex3f(115, 15, 1);
			glVertex3f(115, 15, 129);
			glVertex3f(150, 5, 129);
			glVertex3f(150, 5, 1);
			glEnd();
//curved-like side part 
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0);
			glVertex3f(100, 70, 129);
			glVertex3f(130, 70, 129);
			glVertex3f(120, 50, 129);
			glVertex3f(122, 30, 129);
			glVertex3f(150, 5, 129);
			glVertex3f(115, 15, 129);
			glVertex3f(110, 30, 129);
			glVertex3f(100, 50, 129);
			glEnd();
			//other side
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0);
			glVertex3f(100, 70, 1);
			glVertex3f(130, 70, 1);
			glVertex3f(120, 50, 1);
			glVertex3f(122, 30, 1);
			glVertex3f(150, 5, 1);
			glVertex3f(115, 15, 1);
			glVertex3f(110, 30, 1);
			glVertex3f(100, 50, 1);
			glEnd();


			
			 


//tuastutupbawah
			//1
			glBegin(GL_QUADS);
			glColor3f(0.81 , 0.7 , 0.3);
			glVertex3f(50, 100, 60);
			glVertex3f(50, 100, 90);
			glVertex3f(60, 105, 90);
			glVertex3f(60, 105, 60);
			//2
			glVertex3f(60, 105, 60);
			glVertex3f(60, 105, 90);
			glVertex3f(70, 90, 90);
			glVertex3f(70, 90, 60);
			//3
			glVertex3f(70, 90, 60);
			glVertex3f(70, 90, 90);
			glVertex3f(75, 80, 90);
			glVertex3f(75, 80, 60);
			glEnd();
//tutuptuassamping
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(0, 100, 90);
			glVertex3f(10, 120, 90);
			glVertex3f(25, 140, 90);
			glVertex3f(45, 150, 90);
			glVertex3f(65, 140, 90);
			glVertex3f(85, 110, 90);
			glVertex3f(95, 80, 90);
			glVertex3f(75, 80, 90);
			glVertex3f(70, 90, 90);
			glVertex3f(60, 105, 90);
			glEnd();
		//samping satunya
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0);
			glVertex3f(0, 100, 60);
			glVertex3f(10, 120, 60);
			glVertex3f(25, 140, 60);
			glVertex3f(45, 150, 60);
			glVertex3f(65, 140, 60);
			glVertex3f(85, 110, 60);
			glVertex3f(95, 80, 60);
			glVertex3f(75, 80, 60);
			glVertex3f(70, 90, 60);
			glVertex3f(60, 105, 60);
			glEnd();
//penyanggashredder
			glBegin(GL_QUADS);
			//atas
			glColor3f(0.81 , 0.7 , 0.3);
			glVertex3f(95, 80, -0.1);
			glVertex3f(95, 80, 130.1);
			glVertex3f(75, 80, 130.1);
			glVertex3f(75, 80,-0.1);
			//bawah
			glVertex3f(95, 65, -0.1);
			glVertex3f(95, 65, 130.1);
			glVertex3f(75, 65, 130.1);
			glVertex3f(75, 65, -0.1);
			//depan
			glColor3f(0.81 , 0.7 , 0);
			glVertex3f(75, 80, -0.1);
			glVertex3f(75, 65, -0.1);
			glVertex3f(75, 65, 130.1);
			glVertex3f(75, 80, 130.1);
			//belakang
			glVertex3f(95, 80, -0.1);
			glVertex3f(95, 65, -0.1);
			glVertex3f(95, 65, 130.1);
			glVertex3f(95, 80, 130.1);
			glEnd();
			//samping
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(75, 80, 130.1);
			glVertex3f(95, 80, 130.1);
			glVertex3f(150,-10, 130.1);
			glVertex3f(90, -10, 130.1);
			glVertex3f(75, 65, 130.1);
			glEnd();
			//
			glBegin(GL_POLYGON);
			glVertex3f(75, 80, 135);
			glVertex3f(95, 80, 135);
			glVertex3f(150,-10, 135);
			glVertex3f(90, -10, 135);
			glVertex3f(75, 65, 135);
			glEnd();
				//tutupataspenyangga
				glBegin(GL_POLYGON);
				glColor3f(0.81 , 0.7 , 0.3);
				glVertex3f(75, 80, 130.1);
				glVertex3f(95, 80, 130.1);
				glVertex3f(150,-10, 130.1);
				glVertex3f(150,-10, 135);
				glVertex3f(95,80, 135);
				glVertex3f(75, 80, 135);
				glEnd();
			//masih samping
			glBegin(GL_POLYGON);
			glColor3f(0.81 , 0.7 , 0.0);
			glVertex3f(75, 80, -0.1);
			glVertex3f(95, 80, -0.1);
			glVertex3f(150,-10, -0.1);
			glVertex3f(90, -10, -0.1);
			glVertex3f(75, 65, -0.1);
			glEnd();
			//
			glBegin(GL_POLYGON);
			glVertex3f(75, 80, -5);
			glVertex3f(95, 80, -5);
			glVertex3f(150,-10, -5);
			glVertex3f(90, -10, -5);
			glVertex3f(75, 65, -5);
			glEnd();
				//tutupataspenyangga
				glBegin(GL_POLYGON);
				glColor3f(0.81 , 0.7 , 0.3);
				glVertex3f(75, 80, -0.1);
				glVertex3f(95, 80, -0.1);
				glVertex3f(150,-10, -0.1);
				glVertex3f(150,-10, -5);
				glVertex3f(95,80, -5);
				glVertex3f(75, 80, -5);
				glEnd();
}
void Extras(void)
{
	//dasar kursi
			glBegin(GL_POLYGON);
			glColor3f(0.5 , 0.5 , 0.5);
			glVertex3f(-30, 60, 120);	glVertex3f(-30, 60, 100);
			glVertex3f(-10, 60, 100);		glVertex3f(-10, 60, 120);
			glEnd();
	//punggung kursi
			glBegin(GL_POLYGON);
			glLineWidth(10);
			glColor3f(0.4 , 0.4 , 0.4);
			glVertex3f(-10, 60, 100);
			glVertex3f(-8, 75, 95);
			glVertex3f(-6, 95, 100);
			glVertex3f(-6, 95, 120);
			glVertex3f(-8, 75, 125);
			glVertex3f(-10, 60, 120);
			glEnd();
	//controlPart
			//top
			glBegin(GL_POLYGON);
			glColor3f(0.5 , 0.5 , 0.5);
			glVertex3f(-40, 70, 129);	glVertex3f(-40, 70, 91);
			glVertex3f(-49, 80, 91);		glVertex3f(-49, 80, 129);
			glEnd();
			//FRONTcover
			glBegin(GL_QUADS);
			glColor3f(0.4 , 0.4 , 0.4);
			glVertex3f(-49, 80, 91);
			glVertex3f(-49, 80, 129);
			glVertex3f(-49, 35, 129);
			glVertex3f(-49, 35, 91);
			//backCover
			glVertex3f(-40, 70, 91);
			glVertex3f(-40, 70, 129);
			glVertex3f(-40, 35, 129);
			glVertex3f(-40, 35, 91);
			//buttons and stuff
			glColor3f(0.8 , 0 , 0);
			glVertex3f(-45, 77, 93);
			glVertex3f(-45, 77, 98);
			glVertex3f(-42, 73, 98);
			glVertex3f(-42, 73, 93);
			//
			glColor3f(0.1 , 0.8 , 0);
			glVertex3f(-45, 77, 100);
			glVertex3f(-45, 77, 105);
			glVertex3f(-42, 73, 105);
			glVertex3f(-42, 73, 100);
			glColor3f(0.1 , 0.8 , 0);
			//
			glColor3f(0 , 0 , 0.8);
			glVertex3f(-45, 77, 107);
			glVertex3f(-45, 77, 112);
			glVertex3f(-42, 73, 112);
			glVertex3f(-42, 73, 107);
			//
			glColor3f(0.8 , 0 , 0.8);
			glVertex3f(-45, 77, 114);
			glVertex3f(-45, 77, 119);
			glVertex3f(-42, 73, 119);
			glVertex3f(-42, 73, 114);
			//
			glColor3f(0 , 0.8 , 0.8);
			glVertex3f(-45, 77, 121);
			glVertex3f(-45, 77, 126);
			glVertex3f(-42, 73, 126);
			glVertex3f(-42, 73, 121);
			glEnd();
			//stick control
			glBegin(GL_QUADS);glColor3f(0 , 0 , 0);
			glVertex3f(-30, 77, 93);glVertex3f(-30, 77, 98);
			glVertex3f(-27, 73, 98);glVertex3f(-27, 73, 93);
			//front
			glVertex3f(-30, 77, 93);glVertex3f(-30, 77, 98);
			glVertex3f(-30, 35, 98);glVertex3f(-30, 35, 93);
			//back
			glVertex3f(-27, 73, 93);glVertex3f(-27, 73, 98);
			glVertex3f(-27, 35, 98);glVertex3f(-27, 35, 93);
			//side
			glVertex3f(-30, 77, 93);glVertex3f(-27, 73, 93);
			glVertex3f(-27, 35, 93);glVertex3f(-30, 35, 93);
			//side
			glVertex3f(-30, 77, 98);glVertex3f(-27, 73, 98);
			glVertex3f(-27, 35, 98);glVertex3f(-30, 35, 98);
			glEnd();
//stairs
			//ladder
			glBegin(GL_QUADS);glColor3f(0,0,0);
			glVertex3f(-22, 35.1, 131);glVertex3f(-20, 35.1, 131);
			glVertex3f(-20, -5, 131);glVertex3f(-22, -5, 131);
			//ladder2
			glVertex3f(-37, 35.1, 131);glVertex3f(-35, 35.1, 131);
			glVertex3f(-35, -5, 131);glVertex3f(-37, -5, 131);
			glEnd();
			//stepper
			glBegin(GL_LINES);glLineWidth(5);glColor3f(0,0,0);
			glVertex3f(-22, 32, 131);glVertex3f(-37, 32, 131);glEnd();
			//
			glBegin(GL_LINES);glLineWidth(5);glColor3f(0,0,0);
			glVertex3f(-22, 25, 131);glVertex3f(-37, 25, 131);glEnd();
			//
			glBegin(GL_LINES);glLineWidth(5);glColor3f(0,0,0);
			glVertex3f(-22, 15, 131);glVertex3f(-37, 15, 131);glEnd();
			//
			glBegin(GL_LINES);glLineWidth(5);glColor3f(0,0,0);
			glVertex3f(-22, 5, 131);glVertex3f(-37, 5, 131);glEnd();
			

//glasess
			//side
			glBegin(GL_QUADS);glColor4f(0 , 0.8 , 0.8,0.3);
			glVertex3f(-5, 75, 90);glVertex3f(-45, 75, 90);
			glVertex3f(-45, 120, 90);glVertex3f(-5, 120, 90);
			//side		
			glVertex3f(-5, 75, 130);glVertex3f(-45, 75, 130);
			glVertex3f(-45, 120, 130);glVertex3f(-5, 120, 130);
			//front
			glVertex3f(-50, 75, 95);glVertex3f(-50, 120, 95);
			glVertex3f(-50, 120, 125);glVertex3f(-50, 75, 125);
			glEnd();
			
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


	//call part func
	frontBody();
	ControlCenter();
	TractorMachine();
	SideMachine();
	frontWheels();
	TractorMachineExtensions();

	BackWheels();
	ShredderMachine();
	GateControl();
	Extras();

	glPopMatrix();
    glutSwapBuffers();
}



int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
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
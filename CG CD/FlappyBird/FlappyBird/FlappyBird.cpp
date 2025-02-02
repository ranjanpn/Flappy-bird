#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

float bspd = 0.01; // block dx value(bird speed(x_axis))
char name[20];
float b1x = 45.0, b1y = 0;  //position of first pipe 
int win1, win2;
float hm = 0.0;   //bird moving dy value(up-down)
int wflag = 1; //welcome_flag init w/ 1
int i = 0;
int score = 0;

void renderBitmapString(float x, float y, float z, void* font, const char* string)
{
	const char* c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}


void frontsheet(void)
{
	glClearColor(0.5, 0.3, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	renderBitmapString(-0.55, 0.9, 0.5, GLUT_BITMAP_TIMES_ROMAN_24, "JAWAHARLAL NEHRU NEW COLLEGE OF ENGINEERING");
	renderBitmapString(-0.155, 0.8, 1, GLUT_BITMAP_TIMES_ROMAN_24, "Department of CSE");
	glColor3f(1.0, 0.0, 0.0);
	renderBitmapString(-0.175, 0.6, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "FLAPPY BIRD GAME");
	glColor3f(1.0, 1.0, 0.5);
	renderBitmapString(-0.1, -0.8, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'S' to start game");
	renderBitmapString(-0.1, -0.9, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'I' for instruction");
	glColor3f(1, 1, 0.0);
	renderBitmapString(-1.0, 0.4, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "  Submitted by:");
	glColor3f(1.0, 1.0, 1.0);
	renderBitmapString(-1.0, 0.3, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "  1. Aishwarya S : 4JN20CS004");
	renderBitmapString(-1.0, 0.2, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "  2. Chandana C S : 4JN20CS025");
	renderBitmapString(-1.0, 0.1, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "  3. Nikhil M : 4JN20CS064");
	renderBitmapString(-1.0, 0.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "  4. Ranjan P N : 4JN20CS082");
	glColor3f(1, 1, 0.0);
	renderBitmapString(-1.0, -0.2, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "  Under the guidance of: ");
	glColor3f(1.0, 1.0, 1.0);
	renderBitmapString(-1.0, -0.3, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, " 1.Mrs.Sushma R B");
	renderBitmapString(-0.74, -0.3, 0.0, GLUT_BITMAP_HELVETICA_12, "B.E, M.Tech.");
	renderBitmapString(-0.9, -0.4, 0.0, GLUT_BITMAP_HELVETICA_18, "Asst.Prof., Dept. of CS&E");
	renderBitmapString(-0.9, -0.5, 0.0, GLUT_BITMAP_HELVETICA_18, "JNNCE, SHIMOGA");
	renderBitmapString(-0.3, -0.3, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, " 2.Mrs.Shreedevi S");
	renderBitmapString(-0.06, -0.3, 0.0, GLUT_BITMAP_HELVETICA_12, " B.E,M.Tech");
	renderBitmapString(-0.2, -0.4, 0.0, GLUT_BITMAP_HELVETICA_18, "Asst.Prof., Dept. of CS&E");
	renderBitmapString(-0.2, -0.5, 0.0, GLUT_BITMAP_HELVETICA_18, "JNNCE, SHIMOGA");
	glutSwapBuffers();
	glFlush();
}


void instruction(void)
{
	
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	renderBitmapString(-0.155, 0.8, 1, GLUT_BITMAP_TIMES_ROMAN_24, "RULES");
	glColor3f(0, 0, 0.0);
	renderBitmapString(-1.0, 0.4, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "  1. Press 8 to move the bird Upwards");
	renderBitmapString(-1.0, 0.3, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "  2. Press 2 to move the bird Downwards");
	renderBitmapString(-1.0, 0.2, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "  3. If You Hit the pipe then its Game Over");
	glColor3f(1, 0, 0);
	renderBitmapString(-0.3, -0.8, 1, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'S' to start game");
	glutSwapBuffers();
	glFlush();
}

void drawbird()
{
	glColor3f(1, 1, 0);
	glRectf(8, 38, 15, 45);   //body
	glColor3f(0, 0, 0);
	glRectf(13, 42, 13.5, 42.5);   //eye
	glColor3f(1, 0, 0);
	glRectf(15, 41.8, 16, 42.8);   //beak
	glRectf(10, 44.5, 12, 46.5);   //up_wing
	glRectf(10, 36.5, 12, 38.5);   //down_wing
	glRectf(8.3, 41, 7.2, 42.8);  //tail
}


void movebirdU(void)
{
	hm += 0.05;
	i++;
	glutPostRedisplay();
}

void movebirdD()
{
	hm -= 0.05;
	i--;
	glutPostRedisplay();
}
void init(void)
{
	b1y = (rand() % 45) + 10; //b/w 10 to 44
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, .0);
}

void keys(unsigned char key, int x, int y)
{
	if (key == '8') glutIdleFunc(movebirdU);
	if (key == '2') glutIdleFunc(movebirdD);

}


void display(void)
{
	glClearColor(0, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//GameOver Checking
	if (
		(i == 1000 || i == -1000)
		//top and bottom checking
		||
		(((int)b1x == 7 || (int)b1x == 4 || (int)b1x == 4 || (int)b1x == 1) && (int)b1y < 53 + (int)hm && (int)b1y + 35>53 + (int)hm)
		// propeller front checking
		||
		(((int)b1x == 9 || (int)b1x == 3 || (int)b1x == 6) && (int)b1y < 45 + (int)hm && (int)b1y + 35>45 + (int)hm)
		//lower body checking

		||
		(((int)b1x == 0) && (int)b1y < 46 + (int)hm && (int)b1y + 35>46 + (int)hm))
		// lower tail checking

	{
		//glColor3f(1.0, 0.5, 0.0);
			//glRectf(0.0, 0.0, 100.0, 100.0);
		glColor3f(0.0, 0.0, 0.0);
		glutSwapBuffers();
		renderBitmapString(40.0, 70.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER");
		glutSwapBuffers();
		glFlush();
		printf("\nGAME OVER\n");
		printf("\nClose the console window to exit...\n");
		system("pause");
		exit(0);
	}
	else if (wflag == 1)  //Welcome Screen
	{
		wflag = 0;
		drawbird();
		//glutSwapBuffers();
		glFlush();
	}
	else
	{
		glPushMatrix();
		glTranslatef(0.0, hm, 0.0);
		drawbird();
		if (b1x < -10)
		{
			b1x = 50; //total width is 50
			b1y = (rand() % 25) + 20;
		}
		else
		{
			b1x -= bspd;
		}
		glTranslatef(b1x, -hm, 0.0);
		glColor3f(0.0, 1.0, 0.0);
		//drawpipe();
		glRectf(b1x, b1y, b1x + 5, b1y + 35);  //block 1
		glPopMatrix();
		glutFullScreen();
		glutSwapBuffers();
		glFlush();
	}

}


void game(unsigned char key, int x4, int y4)
{

	if (key == 's' || key == 'S')
	{
		glutDestroyWindow(win1);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1000, 600);
		glutInitWindowPosition(100, 100);
		win2 = glutCreateWindow("Flappy Bird");
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glFlush();
		glutDisplayFunc(display);
		glutFullScreen();
		gluOrtho2D(-1000, 1000, 0, 1000);
		init();
		glutKeyboardFunc(keys);
	}
	if (key == 'i' || key=='I')
	{
		glutDestroyWindow(win1);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1000, 600);
		glutInitWindowPosition(100, 100);
		win2 = glutCreateWindow("Flappy Bird");
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glFlush();
		glutDisplayFunc(instruction);
		glutFullScreen();
		glutKeyboardFunc(game);

	}

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(100, 100);
	win1 = glutCreateWindow("Mini Project");
	glFlush();
	glutDisplayFunc(frontsheet);
	glutKeyboardFunc(game);
	glutFullScreen();
	glutMainLoop();
	return 0;
}
#ifndef _MAIN_H
#define _MAIN_H

#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<gl/glut.h>

struct ball
{
	GLfloat x,y;
};

typedef GLfloat glColor[3];
typedef GLclampf glClampf[4];
typedef GLdouble glDouble[2];
typedef struct ball Kookaburra;

void Sprint( int x, int y, char *st);
void Sprin( int x,int y, char *st);
void myInit(glDouble xy, glDouble z);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
void ballAnimate(void);
void display();

#endif
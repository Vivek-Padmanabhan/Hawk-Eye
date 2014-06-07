#include "Main.h"
#include "Primitive.h"

void drawPolygon(GLfloat r,GLfloat g,GLfloat b,GLint x1,GLint x2,GLint x3,GLint x4,GLint y1,GLint y2,GLint y3,GLint y4)
{
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
		glVertex2i(x3,y3);
		glVertex2i(x4,y4);
	glEnd();
}

void drawStripe(GLfloat c,GLint x1,GLint x2,GLint x3,GLint x4,GLint y1,GLint y2,GLint y3,GLint y4,int i,int j)
{
	glColor3f(0.0,c,0.0);
	glBegin(GL_POLYGON);
		glVertex2i(x1+i,y1+j);
		glVertex2i(x2+i,y2+j);
		glVertex2i(x3+i,y3+j);
		glVertex2i(x4+i,y4+j);
	glEnd();
}

void drawLineWhite(GLint x1,GLint y1,GLint x2,GLint y2)
{
	glColor3f(1.0,1.0,1.0);
	glLineWidth(3.0);
	glBegin(GL_LINES);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
	glEnd();
}
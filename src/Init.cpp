#include "Main.h"

void Sprint( int x, int y, char *st)
{
	int l,i;
	l=strlen( st ); 
	glRasterPos2i( x, y);
	for( i=0; i < l; i++) 
		{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]); 
	}
}

	void Sprin( int x, int y, char *st)
{
	int l,i;
	l=strlen( st ); 
	glRasterPos2i( x, y);
	for( i=0; i < l; i++) 
		{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]); 
	}
}

void myInit(glDouble xy,glDouble z)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xy[0],xy[1],xy[0],xy[1],z[0],z[1]); 
}
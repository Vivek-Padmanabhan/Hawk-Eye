#include "Main.h"
#include "Cricket.h"
#include "Primitive.h"

void drawPitch(GLfloat r,GLfloat g,GLfloat b,GLint x1,GLint x2,GLint x3,GLint x4,GLint y1,GLint y2,GLint y3,GLint y4,bool bail)
{
	drawPolygon(r,g,b,x1,x2,x3,x4,y1,y2,y3,y4);
	drawPolygon(r,g-0.1,b,x1+40,x2-40,x3-40,x4+40,y1,y2,y3,y4);						
	drawCrease(x1,y1,x2,y2,0,0);
	drawCrease(x1,y1,x2,y2,y1-(y4+80),y2-(y3+40));
	drawStump(x1+40,y1,x2-40,y2,0,bail);
	drawStump(x1+40,y1,x2-40,y2,y2-(y3+40),false);
}

void drawCrease(GLint x1,GLint y1,GLint x2,GLint y2,GLint i,GLint j)
{
	drawLineWhite(x1-10,(y1-40)-i,x2+10,(y2-40)-i);
	drawLineWhite(x1+10,(y1-40)-j,x1+10,y1-j);
	drawLineWhite(x2-10,(y2-40)-j,x2-10,y2-j);
	drawLineWhite(x1+10,(y1-20)-j,x2-10,(y2-20)-j);
}

void drawCircle(glColor c,bool solid,GLfloat x1,GLfloat y1,int rr)
{
	int k;
	glColor3fv(c);
	if(solid)
		glBegin(GL_TRIANGLE_FAN);
	else
	{
		glPointSize(3.0);
		glBegin(GL_POINTS);
	}
	for(k=0;k<720;k++)
	{
		glVertex2f(x1+sinf(k)*rr,y1+cosf(k)*rr);
	}
	glEnd();
}

void drawGround(GLfloat c,GLint x1,GLint x2,GLint y1,GLint y2)
{
	int i,j;
	for(i=0;i<=500;i+=60)
	{
		j=0;
		drawStripe(0.6,x1,x1,x2,x2,y1,y2,y2,y1,i,j);
	}
	for(j=0;j<=500;j+=60)
	{
		i=0;
		drawStripe(0.7,y1,y2,y2,y1,x1,x1,x2,x2,i,j);
	}
}

void drawStump(GLint x1,GLint y1,GLint x2,GLint y2,int i,bool bail)
{
		drawLineWhite(x1,(y1+20)-i,x1,(y1-20)-i);
		drawLineWhite((x1+x2)/2,(y1+20)-i,(x1+x2)/2,(y1-20)-i);
		drawLineWhite(x2,(y2+20)-i,x2,(y2-20)-i);
		if(bail==true)
		{
			glColor3f(0.0,0.0,0.0);
			Sprint(340.0,250.0,"OUT!!!!");
			glColor3f(1.0,0.0,0.0);
		Sprin(350.0,230.0,"Leg Before Wicket");
		
		}
		
		if(bail!=true)
		{
		drawLineWhite(x1+1,(y1+20)-i,((x1+x2)/2)-1,(y1+20)-i);
		drawLineWhite(((x1+x2)/2)+1,(y1+20)-i,x2-1,(y2+20)-i);
		
        }
		
}
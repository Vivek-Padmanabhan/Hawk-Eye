#ifndef _CRICKET_H
#define _CRICKET_H

void drawPitch(GLfloat r,GLfloat g,GLfloat b,GLint x1,GLint x2,GLint x3,GLint x4,GLint y1,GLint y2,GLint y3,GLint y4,bool bail);
void drawCrease(GLint x1,GLint y1,GLint x2,GLint y2,GLint i,GLint j);
void drawCircle(glColor c,bool soild,GLfloat x1,GLfloat y1,int rr);
void drawGround(GLfloat c,GLint x1,GLint x2,GLint y1,GLint y2);
void drawStump(GLint x1,GLint y1,GLint x2,GLint y2,int i,bool bail);

#endif
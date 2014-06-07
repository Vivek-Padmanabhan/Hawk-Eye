#include "Main.h"
#include "Cricket.h"

glColor rgb[]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0}};
glColor bw[]={{0.0,0.0,0.0},{1.0,1.0,1.0}};
glClampf a[]={{0.0,0.5,0.0,1.0},{0.0,0.0,0.0,0.0},{1.0,1.0,1.0,1.0}};
glDouble b[]={{0.0,500.0},{0.0,1.0}};

Kookaburra kb;
bool start=false,begin=false,animate=false,pitch=false,off=false,leg=false,bail=false,inlin=false,outline=false;

void main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(700,700);
	glutCreateWindow("CG Project");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(ballAnimate);
	myInit(b[0],b[1]);
	glutMainLoop();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(begin)
	{
	glClearColor(a[0][0],a[0][1],a[0][2],a[0][3]);
	drawGround(0.6,30,60,0,500);
	drawCircle(bw[1],false,250,250,240);
	drawPitch(0.5,0.7,0.0,200,300,300,200,400,400,100,100,bail);
	drawCircle(rgb[0],true,kb.x,kb.y,4);
	if(inlin)
		Sprint(80.0,250.0,"PITCHED IN LINE");
	if(outline)
		Sprint(80.0,250.0,"PITCHED OUTSIDE");
	
	}
	else if(start)
	{
		glClearColor(a[1][0],a[1][1],a[1][2],a[1][3]);
		glColor3fv(rgb[0]);
		Sprint(170.0,450.0,"INSTRUCTIONS");
		glColor3f(0.5,0.1,0.8);
		Sprin(80.0,350.0,"PRESS O TO BOWL OVER THE WICKET");
		Sprin(80.0,300.0,"PRESS A TO BOWL AROUND THE WICKET");
		Sprin(80.0,250.0,"CLICK THE LEFT MOUSE BUTTON TO START THE BALL MOVEMENT");
		Sprin(80.0,200.0,"CLICK THE RIGHT BUTTON OF THE MOUSE TO PITCH THE BALL");
		Sprin(80.0,150.0,"PRESS R TO REBOWL");
		Sprin(80.0,100.0,"PRESS ESC TO EXIT FROM THE PROGRAM");
	}
	
	else
	{
		glClearColor(a[2][0],a[2][1],a[2][2],a[2][3]);
		glColor3fv(rgb[2]);
		Sprint(145.0,450,"SIMULATION OF A HAWK EYE");
		glColor3f(0.0,0.5,0.5);
		Sprin(160.0,400,"PROJECT TEAM MEMBERS");
		glColor3f(0.6,0.5,0.0);
		Sprint(120.0,350,"Aditya Chandrashekhar--USN:1DS08CS144");
		Sprint(120.0,300,"Ramdas.R--USN:1DS08CS080");
		Sprint(120.0,250,"Ranganath K Ingalagi--USN:1DS08CS082");
		Sprint(120.0,200,"Vivek Padmanabhan--USN:1DS09CS417");
	}
	


	glFlush();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		animate=true;
	}
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
		
			pitch=true;

	}
}
void keyboard(unsigned char key, int x, int y)
{
	if(key==13)
	{
		start=true;
	}
	if(key=='o' || key=='O')
	{
		kb.x=220.0;
		kb.y=150.0;
		begin=true;
		off=true;		
	}
	else if(key=='a' || key=='A')
	{
		kb.x=280.0;
		kb.y=150.0;
		begin=true;
		leg=true;
	}
	else if(key==27)
	{
		exit(0);
	}
	glutPostRedisplay();
}

void ballAnimate(void)
{
	if(animate)
	{
		if(off)
		{
			kb.x+=0.4;
			kb.y+=1.8;
		}
		if(leg)
		{
			kb.x-=0.4;
			kb.y+=1.8;
		}
	}
	if(pitch)
	{

		if(kb.x>245 && kb.x<255)
		inlin=true;
		else
			outline=true;

		animate=false;
		kb.y+=1.0;
    }

	if(kb.x>245 && kb.x<255 && kb.y>400 )
	{
		bail=true;
		
	}
	if(kb.y>500)
	{
		start=true,begin=false,animate=false,pitch=false,off=false,leg=false,bail=false,inlin=false,outline=false;
	}
	glutPostRedisplay();
}

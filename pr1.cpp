//1.DDA Line Drawing 
#include<GL/glut.h>
#include<iostream>
using namespace std;
int x1;
int Y1; 
int x2; 
int y2;
int choice;

int sign( float delta) 
{
  if(delta<0)
  {  return -1;
  }
  else
  {  
     return 1;
  }
}
void displayline(void )
{
glClear(GL_COLOR_BUFFER_BIT);
glPointSize(2);
// calculated dx and dy
int dx=x2-x1;
int dy=y2-Y1;
int length;
// calculate the length
if(abs(dx)>=abs(dy))
{
   length=dx;
}
else
{
    length=dy;
}
float deltaX=(float) dx/length;
float deltaY=(float)dy/length;
float x = x1; 
float y = Y1; 
switch(choice)
{
case 1:
   for(int i=0; i<=length; i++)
{ glBegin(GL_POINTS);
glColor3f(1,0,0);
 glVertex2i(x,y);
  glEnd();
   x=x+sign(deltaX);
   y=y+sign(deltaY);
 }
break;
case 2:
    for(int i=0; i<=length; i++)
{
if(i%8==0)
{ 
glBegin(GL_POINTS);
glColor3f(1,0,0);
 glVertex2i(x,y);
  glEnd();
 }
   x=x+sign(deltaX);
   y=y+sign(deltaY);
 
}
break;
case 3:
    for(int i=0; i<=length; i++)
{
if(i%16<=8)
{ 
glBegin(GL_POINTS);
glColor3f(1,0,0);
 glVertex2i(x,y);
  glEnd();
 }
   x=x+sign(deltaX);
   y=y+sign(deltaY);
 
}
break;
}

glBegin(GL_LINES);
glColor3f(1,1,1);
  glVertex2f(0,500);
  glVertex2f(0,-500);
  glVertex2f(-500,0);
  glVertex2f(500,0);
 glEnd();
 glFlush();
}

void myInit (void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
 
  gluOrtho2D(-500, 500, -500, 500);
}
int main(int argc , char **argv)
{
cout<<"Enter the value x1="<<endl;
cin>>x1;
cout<<"Enter the value y1="<<endl;
cin>>Y1;
cout<<"Enter the value x2="<<endl;
cin>>x2;
cout<<"Enter the value y2="<<endl;
cin>>y2;

cout<<"1.Simple"<<endl;
cout<<"2.Dotted"<<endl;
cout<<"3.Dash"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>choice;
glutInit(&argc , argv);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowSize(640, 480);
glutInitWindowPosition(100,100);
glutCreateWindow("DDA");
myInit ();
glutDisplayFunc(displayline);
glutMainLoop();
return 0;

}



//2.1 Bresenham Line Drawing 
#include<GL/glut.h>
#include<iostream>
using namespace std;
int x1;
int Y1; 
int x2; 
int y2;
int choice;

void displayline()
{
int deltax=x2-x1;
int deltay=y2-Y1;
int pk=(2*deltay)-deltax;
glBegin(GL_POINTS);
glColor3f(1,0,0);
glVertex2i(x1,Y1);
glEnd();
switch(choice)
{
case 1:
for(int i=0;i<deltax;i++)
{
	if(pk<0)
	{
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	x1=x1+1;
	glVertex2i(x1,Y1);
	glEnd();
	pk=pk+(2*deltay);
	}
else
{
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	x1=x1+1;
	Y1=Y1+1;
	glVertex2i(x1,Y1);
	glEnd();
	pk=pk+(2*(deltay-deltax));
	}
}
break;
case 2:
	for(int i=0;i<deltax;i++)
	{
	if(pk<0)
	{	x1=x1+1;
		if(i%8==0)
		{
		glBegin(GL_POINTS);
		glColor3f(1,0,0);
		
		glVertex2i(x1,Y1);
		glEnd();
		}
	pk=pk+(2*deltay);
	}
	else
	{       x1=x1+1;
		Y1=Y1+1;
	       if(i%8==0)
		{
		glBegin(GL_POINTS);
		glColor3f(1,0,0);
		
		glVertex2i(x1,Y1);
		glEnd();
		}
	pk=pk+(2*(deltay-deltax));
	}
	}
break;
case 3:
	for(int i=0;i<deltax;i++)
	{
	if(pk<0)
	{       x1=x1+1;
		if(i%16<=8)
		{
		glBegin(GL_POINTS);
		glColor3f(1,0,0);
		
		glVertex2i(x1,Y1);
		glEnd();
		}
	pk=pk+(2*deltay);
	}
	else
	{       x1=x1+1;
		Y1=Y1+1;
	       if(i%16<=8)
		{
		glBegin(GL_POINTS);
		glColor3f(1,0,0);
		
		glVertex2i(x1,Y1);
		glEnd();
		}
	pk=pk+(2*(deltay-deltax));
	}
}
break;
}
glBegin(GL_LINES);
glColor3f(1,1,1);
  glVertex2f(0,500);
  glVertex2f(0,-500);
  glVertex2f(-500,0);
  glVertex2f(500,0);
 glEnd();
 glFlush();


}


void myInit()
{
glClearColor(0,0,0,0);
gluOrtho2D(-500,500,-500,500);
}

int main(int argc, char **argv)
{
cout<<"Enter the value x1="<<endl;
cin>>x1;
cout<<"Enter the value y1="<<endl;
cin>>Y1;
cout<<"Enter the value x2="<<endl;
cin>>x2;
cout<<"Enter the value y2="<<endl;
cin>>y2;
cout<<"1.Simple"<<endl;
cout<<"2.Dotted"<<endl;
cout<<"3.Dash"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>choice;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowSize(640, 480);
glutInitWindowPosition(100,100);
glutCreateWindow("Bresenham");
myInit ();
glutDisplayFunc(displayline);
glutMainLoop();
return 0;
}


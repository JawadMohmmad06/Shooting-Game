#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>

#include <iostream>
using namespace std;
GLfloat position = 0.0f;
GLfloat speed = 0.1f;
GLfloat position1 = 0.0f, posRocket= 0.0f;
GLfloat speed1 = 0.05f;
GLfloat position2 = 1.6f;
GLfloat speed2 = 0.2f;
GLfloat laserposition = -0.0f;
GLfloat laserspeed = 0.2f;
GLfloat laserpositionvr = 0.0f;
int on=0,fire=0,crash2=0,crash1=0,crash=0,rocketcrash=0;

bool laser=false;
void update(int value) {

    if(position < -1.6)
        position = 1.2f;

    if(fire==0||crash2==0)
    {


    if(position1 < -1.6)
        position1 = 1.2f;

    }

    if(position2 < -1)
    {
        if(fire==0||crash1==0)

{

        position2 = 1.6f;}
}
        if(crash1==0){
    position2 -= speed2;}


if(position2<=laserposition-1.0&&fire==1)
{
if(laserpositionvr>-0.2&&laserpositionvr<0.2)
    {


    position2=2.0f;
    crash1=1;


}
}
//helow

if(position1<-1.2&&position1>-1.25&&posRocket>0.59){

    rocketcrash=1;
    laserpositionvr=2.0f;
    posRocket=2.0f;

}
if(position<-1.2&&position>-1.25&&posRocket<-0.59){

    rocketcrash=1;
    laserpositionvr=2.0f;
    posRocket=2.0f;

}
if(position2<-1.2&&position2>-1.25&&posRocket>-0.5&&posRocket<0.5){

    rocketcrash=1;
    laserpositionvr=2.0f;
    posRocket=2.0f;

}
//sssssssssssssssssssssss
if(crash2==0){
    position1 -= speed1;}
if(position1<=laserposition-1.0&&fire==1)
{
if(laserpositionvr>0.7)
    {


    position1=2.0f;
    crash2=1;


}
}


//dfff
if(crash==0){
    position -= speed;}
if(position<=laserposition-1.0&&fire==1)
{
if(laserpositionvr<-0.7)
    {


    position=2.0f;
    crash=1;


}
}

if(laser==true&&rocketcrash==0)
{

 laserposition += laserspeed;





}
if(laserposition==1.2f)
{
    laser=false;
    fire=0;
    laserposition = -0.0f;
}



glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'a':
    if(posRocket>-0.7f&&rocketcrash==0){
    posRocket -= 0.2f;
    laserpositionvr=posRocket;}

    break;
case 'd':
    if(posRocket<0.7&&rocketcrash==0){
    posRocket += 0.2f;
    laserpositionvr=posRocket;}
    break;
    case 'w':
        if(rocketcrash==0){
    laser=true;
    fire=1;
    break;
        }

glutPostRedisplay();


	}
}


void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();



glPushMatrix();

glTranslatef(0.0f,position, 0.0f);
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.8f,0.6f);
   glVertex2f(-0.6f, 0.9f);
   glVertex2f(-1.0f, 0.9f);
   glEnd();

glPopMatrix();
glPushMatrix();
glTranslatef(0.0f,position1, 0.0f);
   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex2f(0.8f,0.6f);
   glVertex2f(0.6f, 0.9f);
   glVertex2f(1.0f, 0.9f);
   glEnd();

glPopMatrix();
glPushMatrix();
glTranslatef(0.0f,position2, 0.0f);
   glBegin(GL_TRIANGLES);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(0.0f,0.6f);
   glVertex2f(-0.2f, 0.9f);
   glVertex2f(0.2f, 0.9f);
   glEnd();

glPopMatrix();


glPushMatrix();
glTranslatef(posRocket,0.0f, 0.0f);
   glBegin(GL_QUADS);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2f(-0.2f,-1.0f);
   glVertex2f(0.2f, -1.0f);
   glVertex2f(0.2f, -0.7f);
   glVertex2f(-0.2f, -0.7f);
   glEnd();

glPopMatrix();
for(int i=0;i<13;i++)
{



glPushMatrix();
glTranslatef(posRocket,laserposition, 0.0f);
   glBegin(GL_TRIANGLES);
   glColor3f(1.0f, 1.0f, 0.0f);
   glVertex2f(-0.05f,-0.7f);
   glVertex2f(0.05f, -0.7f);
   glVertex2f(0.0f, -0.6f);

   glEnd();

glPopMatrix();


}
   glFlush();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Basic Animation");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 0);
   glutMainLoop();

   return 0;
}

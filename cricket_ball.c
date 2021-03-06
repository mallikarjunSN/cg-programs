#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>
#include <conio.h>




#define PI 22.0/7.0

int color_r=0,color_g=0,color_b=0;

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h){
        glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-1,1);
    }else{
        glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-1,1);
    }
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void init(){

    float rad;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // gluOrtho2D(-40.0,40.0,-40.0,40.0);
    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);

    glNewList(2,GL_COMPILE);

        float theta,thetar,phi,phir,phir20;
        float x,y,z;
        glLineWidth(1.0);
        int i;
        for(phi=-80.0;phi<=80.0;phi+=10.0){
            phir=PI*phi/180.0;
            phir20=PI*(phi+10.0)/180.0;
            glBegin(GL_QUAD_STRIP);
            for(theta=-180.0,i=0;theta<=180.0;theta+=10.0,i++){
            thetar=theta*PI/180.0;
            x=sin(thetar)*cos(phir);
            y=cos(thetar)*cos(phir);
            z=sin(phir);
            glVertex3d(x,y,z);
            x=sin(thetar)*cos(phir20);
            y=cos(thetar)*cos(phir20);
            z=sin(phir20);
            glVertex3d(x,y,z);
            }
            glEnd();
        } 
        float zc;
        glBegin(GL_TRIANGLE_FAN);
            zc=80.0*PI/180.0;
            z=sin(zc);
            for(theta=-180.0;theta<=180.0;theta+=10.0){
            glVertex3d(0,0,1);
            thetar=theta*PI/180.0;
            x=sin(thetar)*cos(zc);
            y=cos(thetar)*cos(zc);
            glVertex3d(x,y,z);
            thetar=(theta+10.0)*PI/180.0;
            x=sin(thetar)*cos(zc);
            y=cos(thetar)*cos(zc);
            glVertex3d(x,y,z);
            }
        glEnd();

        glBegin(GL_LINE_LOOP);
            zc=80.0*PI/180.0;
            z=-sin(zc);

            for(theta=-180.0;theta<=180.0;theta+=10.0){
            glVertex3d(0,0,-1);
            thetar=theta*PI/180.0;
            x=sin(thetar)*cos(zc);
            y=cos(thetar)*cos(zc);
            glVertex3d(x,y,z);
            thetar=(theta+10.0)*PI/180.0;
            x=sin(thetar)*cos(zc);
            y=cos(thetar)*cos(zc);
            glVertex3d(x,y,z);
            }
            glEnd();
    glEndList();

    glNewList(3,GL_COMPILE);
        glBegin(GL_LINES);
        for(theta=0;theta<=360;theta+=6){
            rad=theta*PI/180.0;
            glVertex3d(cos(rad),sin(rad),0.01);
            rad=(theta+6)*PI/180.0;
            glVertex3d(cos(rad),sin(rad),-0.01);
        }
        glEnd();
    glEndList();

    glNewList(4,GL_COMPILE);
        glBegin(GL_LINES);
        for(theta=0;theta<=360;theta+=7){
            rad=theta*PI/180.0;
            glVertex3d(cos(rad),sin(rad),0.0);
            rad=(theta+6)*PI/180.0;
            glVertex3d(cos(rad),sin(rad),0.0);
        }
        glEnd();
    glEndList();

    glNewList(5,GL_COMPILE);
        glBegin(GL_LINES);
        for(theta=0;theta<=360;theta+=6){
            rad=theta*PI/180.0;
            glVertex3d(cos(rad),sin(rad),0.0);
            rad=(theta+6)*PI/180.0;
            glVertex3d(cos(rad),sin(rad),0.0);
        }
        glEnd();
    glEndList();

    glNewList(6,GL_COMPILE);
        glBegin(GL_QUADS);
        glVertex3d(0.3,0.4,0.0);
        glVertex3d(0.3,0.6,0.0);
        glVertex3d(-0.3,0.6,0.0);
        glVertex3d(-0.3,0.4,0.0);

        glVertex3d(0.3,-0.4,0.0);
        glVertex3d(0.3,-0.6,0.0);
        glVertex3d(-0.3,-0.6,0.0);
        glVertex3d(-0.3,-0.4,0.0);

        glVertex3d(0.1,0.5,0.0);
        glVertex3d(0.1,-0.5,0.0);
        glVertex3d(-0.1,-0.5,0.0);
        glVertex3d(-0.1,0.5,0.0);
        glEnd();
    glEndList();

}

float rotate_x,rotate_y,rotate_z,scale;

int dist_x=0;
void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  glColor3f(0.5,0,0);

  glRotatef(rotate_x,1.0,0.0,0.0);
  glRotatef(rotate_y,0.0,1.0,0.0);
  glRotatef(rotate_z,0.0,0.0,1.0);
  glLineWidth(2);
  glPushMatrix();
  glTranslated(dist_x+0,0,0);
  // glScalef(scale,scale,scale);
  glCallList(2);
  glPopMatrix();

  // glColor3f(0,0,0);
  glColor3f(0.4,0,0);
  glLineWidth(10);
  glPushMatrix();
  glTranslated(dist_x+0,0,0.0);
  glCallList(4);
  glPopMatrix();

  glColor3f(245/255.0,245/255.0,162/205.0);
  glLineWidth(2);
  glPushMatrix();
  glTranslated(dist_x+0,0,0.06);
  glCallList(4);
  glPopMatrix();

  glLineWidth(2);
  glPushMatrix();
  glTranslated(dist_x+0,0,-0.06);
  glCallList(4);
  glPopMatrix();

  glLineWidth(5);
  glPushMatrix();
  glTranslated(dist_x+0,0,-0.15);
  glScalef(0.99,0.99,1);
  glCallList(3);
  glPopMatrix();

  glLineWidth(5);
  glPushMatrix();
  glTranslated(dist_x+0,0,-0.25);
  glScalef(0.966,0.966,1);
  glCallList(3);
  glPopMatrix();

  glLineWidth(5);
  glPushMatrix();
  glTranslated(dist_x+0,0,0.15);
  glScalef(0.99,0.99,1);
  glCallList(3);
  glPopMatrix();

  glLineWidth(5);
  glPushMatrix();
  glTranslated(dist_x+0,0,0.25);
  glScalef(0.966,0.966,1);
  glCallList(3);
  glPopMatrix();


  glColor3f(220/255.0,190/255.0,55/255.0);
  glLineWidth(2);
  glPushMatrix();
  glTranslated(dist_x+0,0,0.82);
  glScalef(0.57,0.57,1);
  glCallList(5);
  glPopMatrix();

  glLineWidth(2);
  glPushMatrix();
  glTranslated(dist_x+0,0,0.84);
  glScalef(0.55,0.55,1);
  glCallList(5);
  glPopMatrix();

  glLineWidth(2);
  glPushMatrix();
  glTranslated(dist_x+0,0,-0.82);
  glScalef(0.57,0.57,1);
  glCallList(5);
  glPopMatrix();
  
  glLineWidth(2);
  glPushMatrix();
  glTranslated(dist_x+0,0,-0.84);
  glScalef(0.54,0.54,1);
  glCallList(5);
  glPopMatrix();

  glLineWidth(20);
  glPushMatrix();
  glTranslated(dist_x+0,0,-0.99);
  glScalef(0.54,0.5,0.1);
  glCallList(6);
  glPopMatrix();

  glLineWidth(20);
  glPushMatrix();
  glTranslated(dist_x+0,0,0.99);
  glScalef(0.54,0.5,0.1);
  glCallList(6);
  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}

void delay(int x){
  int i;

  while(x--){
    for(i=0;i<1000;i++);
  }
}

void idle(){

    // glClearColor(1,1,1,1);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glRotatef(10.5,1,0,0);
    // glTranslated(0.1,0,0);
    rotate_y+=.1;
    rotate_x+=.1;
    rotate_z+=.1;

    dist_x+=0.5;

    glutPostRedisplay();
}

void specialKeys( int key, int x, int y )
{
  // Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
  rotate_y += 5;
  // Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
  rotate_y -= 5;
  else if (key == GLUT_KEY_UP)
  rotate_x += 5;
  else if (key == GLUT_KEY_DOWN)
  rotate_x -= 5;

  else if( key == GLUT_KEY_PAGE_UP)
    scale+=0.1;
  else if( key == GLUT_KEY_PAGE_DOWN)
    scale-=0.1;
  // Request display update
  glutPostRedisplay();
}

int main(int argc,char **argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(1024,768);
  glutCreateWindow("Cricket Ball");
  init();
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(display);
  glutIdleFunc(idle);
  glutSpecialFunc(specialKeys);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
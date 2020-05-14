#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>

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
    glClearColor(1.0, 1.0, 1.0, 0.0);
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
}

float rotate_x,rotate_y,scale;


int angles=90,anglem=90,angleh=90,min=0,hr=0,sec=0;
void display(){
  // int i;
  float x,y;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  // glColor3f(color_r/255.0,color_g/255.0,color_b/255.0);
  // printf("%d %d %d\n",color_r,color_g,color_b);
  glColor3f(0.7,0,0);

  glRotatef(rotate_x,1.0,0.0,0.0);
  glRotatef(rotate_y,0.0,1.0,0.0);
  glLineWidth(2);
  glPushMatrix();
  glTranslated(0,0,0);
  // glScalef(scale,scale,scale);
  glCallList(2);
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
    // rotate_y+=0.1;
    // rotate_x+=0.1;

    // color_b=(color_b+1)%255;
    // color_g=(color_g+1)%255;

    // color_r=(color_r+1)%255;
    

    sec=(sec+1)%60;
    if(angles==0)angles=360;
    angles=(angles-6)%360;
    if(sec==0){
      if(anglem==0)anglem=360;
      anglem=(anglem-6)%360;
      min=(min+1)%60;
    }
    if(min==0 && sec == 0){
      if(angleh==0)angleh=360;
      angleh=(angleh-6)%360;
      hr=(hr+1)%24;
    }
    delay(500);

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
  glutCreateWindow("Cricket Ground");
  init();
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(display);
  glutIdleFunc(idle);
  glutSpecialFunc(specialKeys);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
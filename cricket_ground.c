#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h){
        gluOrtho2D(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w);
    }else{
        gluOrtho2D(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    gluOrtho2D(-40.0,40.0,-40.0,40.0);
    // gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
    
    glNewList (1, GL_COMPILE);

      //pitch
      glBegin(GL_POLYGON);
        glColor3f(209/255.0,132/255.0,114/255.0);

        glVertex2d(1.83,11.28);
        glVertex2d(1.83,-11.28);
        glVertex2d(-1.83,-11.28);
        glVertex2d(-1.83,11.28);
      
      glEnd();

      //crease
      glBegin(GL_LINES);
      glColor3f(1.0,1.0,1.0);

      //crease top
      glVertex2d(1.83,8.84);
      glVertex2d(-1.83,8.84);
      glVertex2d(1.32,10.16);
      glVertex2d(-1.32,10.16);

      //crease bottom
      glVertex2d(1.83,-8.84);
      glVertex2d(-1.83,-8.84);
      glVertex2d(1.32,-10.16);
      glVertex2d(-1.32,-10.16);

      glVertex2d(0,10.16);
      glVertex2d(0,8.84);

      glVertex2d(0,-10.16);
      glVertex2d(0,-8.84);

      //wide line top
      glVertex2d(1.32,11.28);
      glVertex2d(1.32,8.84);
      glVertex2d(-1.32,11.28);
      glVertex2d(-1.32,8.84);

      //wide line bottom
      glVertex2d(1.32,-11.28);
      glVertex2d(1.32,-8.84);
      glVertex2d(-1.32,-11.28);
      glVertex2d(-1.32,-8.84);

    glEnd();
    glBegin(GL_LINES);
      //stumps
      // glLineWidth(3.5);
      glColor3f(1.0,1.0,0.0);
      
      glVertex2d(0,10.16);
      glVertex2d(0.3,11.46);

      glVertex2d(0.2,10.16);
      glVertex2d(0.5,11.46);

      glVertex2d(-0.2,10.16);
      glVertex2d(0.1,11.46);

      

      glVertex2d(0.2,-10.16);
      glVertex2d(0.5,-8.87);

      glVertex2d(0,-10.16);
      glVertex2d(0.3,-8.87);

      glVertex2d(-0.2,-10.16);
      glVertex2d(0.1,-8.87);
      
      glEnd();


    glEndList ();
}

void display(){
  float theta,rad;
  // int i;
  glColor3f(0.0,0.0,0.0);
  // glLineWidth(2.0);

  glBegin(GL_POLYGON);
  glColor3f(1.0,1.0,1.0);
  for(theta=0.0;theta<=360.0;theta+=1.0){
        rad=theta/180.0*3.142;
        glVertex2d(75.5*cos(rad),80.0*sin(rad));
  }
  glEnd();


  glBegin(GL_POLYGON);
  glColor3f(32/255.0,146/255.0,15/255.0);
  for(theta=0.0;theta<=360.0;theta+=1.0){
        rad=theta/180.0*3.142;
        glVertex2d(68.5*cos(rad),75.0*sin(rad));
  }
  glEnd();
  // glLineWidth(0.5);
  glBegin(GL_LINE_STRIP);
  glColor3f(0.0,0.0,0.0);
  for(theta=0.0;theta<=360.0;theta+=1.0){
        rad=theta/180.0*3.142;
        glVertex2d(68.5*cos(rad),75.0*sin(rad));
  }
  glEnd();

  


  glBegin(GL_POLYGON);
  glColor3f(52/255.0,189/255.0,32/255.0);
  for(theta=0.0;theta<=180.0;theta+=1.0){
        rad=theta/180.0*3.142;
        glVertex2d(27.4*cos(rad),10.16+27.4*sin(rad));
  }
  for(theta=180;theta<=360.0;theta+=1.0){
        rad=theta/180.0*3.142;
        glVertex2d(27.4*cos(rad),-10.16+27.4*sin(rad));
  }
  glEnd();

  glBegin(GL_LINE_STRIP);
  glColor3f(52/255.0,189/255.0,32/255.0);
  for(theta=0.0;theta<=180.0;theta+=10.0){
        rad=theta/180.0*3.142;
        glVertex2d(27.4*cos(rad),10.16+27.4*sin(rad));

        if((int)theta%20==0)
          glColor3f(1.0,1.0,1.0);
        else
          glColor3f(52/255.0,189/255.0,32/255.0);
  }


  glColor3f(52/255.0,189/255.0,32/255.0);
  for(theta=180.0;theta<=360.0;theta+=10.0){
        rad=theta/180.0*3.142;
        glVertex2d(27.4*cos(rad),-10.16+27.4*sin(rad));

        if((int)theta%20==0)
          glColor3f(1.0,1.0,1.0);
        else
          glColor3f(52/255.0,189/255.0,32/255.0);
  }
  glEnd();



  glBegin(GL_POLYGON);
  glColor3f(209/255.0,132/255.0,114/255.0);

  glVertex2d(1.83,11.28);
  glVertex2d(1.83,-11.28);
  glVertex2d(-1.83,-11.28);
  glVertex2d(-1.83,11.28);
  
  glEnd();
  // glScalef(2,2,2);
  glLineWidth(1.0);

  glPushMatrix();
  glTranslated(0,0,0);
  glCallList(1);
  glPopMatrix();

  glLineWidth(3.0);
  glPushMatrix();
  glTranslated(90,0,0);
  glScalef(6.7,6.7,2);
  glCallList(1);
  glPopMatrix();



  char str[100];
  strcpy(str,"SIDDAGANGA INSTITUTE OF TECHNOLOGY TUMAKURU");
  int i=0;
  glColor3f(0.0,0.0,1.0);
  glRasterPos3f(-25.0,-40.0,0.0);
  while(i<strlen(str)-8){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13,str[i]);
    i++;
  }

  glColor3f(42/255.0,14/255.0,121/255.0);
  glRasterPos3f(-5.0,-45.0,0.0);
  while(i<strlen(str)){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13,str[i]);
    i++;
  }

  strcpy(str,"PITCH");
  glColor3f(0.0,0.0,0.0);
  glRasterPos3f(85,0,0.0);i=0;
  while(i<strlen(str)){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13,str[i]);
    i++;
  }
  glFlush();
}

int main(int argc,char **argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(1024,768);
  glutCreateWindow("Cricket Ground");
  init();
  glutDisplayFunc(display);
  // glEnable(GL_DEPTH_TEST);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
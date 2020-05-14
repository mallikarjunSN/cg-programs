#include <stdio.h>
#include <GL/glut.h>
#include <math.h>


void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
}

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h){
        gluOrtho2D(-5.0,5.0,-5.0*(GLfloat)h/(GLfloat)w,5.0*(GLfloat)h/(GLfloat)w);
    }else{
        gluOrtho2D(-5.0*(GLfloat)w/(GLfloat)h,5.0*(GLfloat)w/(GLfloat)h,-5.0,5.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void display(){
    float theta,rad;float r=10.0;int i=0,j,k,row=0;
    float color[8][3];

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++,row++){
                color[row][0]=i/1.0;
                color[row][1]=j/1.0;
                color[row][2]=k/1.0;
            }

        }
    }

    glBegin(GL_LINE_LOOP);
    //glVertex2d(30.0,30.0);
    //glColor3f(0.0,0.0,1.0);

    for(i=0,theta=0.0;theta<=360.0;theta+=10.0){
        rad=theta/180.0*3.142;
        glVertex2d(r*cos(rad),r*sin(rad));
        glColor3fv(color[i]);
        i=(i+1)%8;
        //printf("%f %f %f\n",color[0],color[1],color[2]);
    }
    
    glEnd();
    // glBegin(GL_POLYGON);
    // glColor3f(0.0,1.0,0.0);

    // for(theta=0.0;theta<=360.0;theta+=10.0){
    //     rad=theta/180.0*3.142;
    //     glVertex2d(20.0+r*cos(rad),25.0+r*sin(rad));
    // }
    
    // glEnd();

    glFlush();
}


int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("New Experiment");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
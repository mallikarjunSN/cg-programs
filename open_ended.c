#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define PI 22.0/7.0


void init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 50.0, 0.0, 50.0);
}

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h){
        gluOrtho2D(0.0,50.0,0.0,50.0*(GLfloat)h/(GLfloat)w);
    }else{
        gluOrtho2D(0.0,50.0*(GLfloat)w/(GLfloat)h,0.0,50.0);
    }
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void delay(int x){
    int i;
    int j=x;

    while(j--)
        for(i=0;i<10000;i++);
}


void drawPie(float from,float to,float radius,float c){
    glBegin(GL_POLYGON);

    float theta,rad;

    glVertex2d(c,c);

    for(theta=from;theta<=to;theta+=1.0){
        rad=theta/180.0*PI;
        glVertex2d(c+radius*cos(rad),c+radius*sin(rad));
    }
    glEnd();
}

void display(){
    float theta,rad;float r=10.0;int i=0,j,k,row=0;
    float color[100][3];

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++,row++){
                color[row][0]=i/1.0;
                color[row][1]=j/1.0;
                color[row][2]=k/1.0;
                printf("%f %f %f \n",color[row][0],color[row][1],color[row][2]);
            }
        }
    }
    int random;
    for(i=8;i<100;i++){
        //random=rand()%i;
        color[i][0]=color[rand()%i][rand()%3]-0.4;
        color[i][1]=color[rand()%i][rand()%3]-0.4;
        color[i][2]=color[rand()%i][rand()%3]-0.4;
    }
    
    float from=0.0,to=45.0;
    i=1;
    for(theta=0.0;theta<=360.0;theta+=30.0){
        drawPie(theta,theta+45.0,10.0,25.0);
        glColor3fv(color[i++]);
        //from=to;
        //to+=45.0;
    }

    /*
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,1.0);
    for(theta=0.0;theta<=3600.0;theta+=1.0){
        rad=theta/180.0*PI;
        //printf("%f %f\n",theta,rad);
        glVertex2d(rad*5.0,25.0+5.0*(cos(rad))); 
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0,1.0,0.0);
    for(theta=0.0;theta<=360.0;theta+=1.0){
        rad=theta/180.0*PI;
        //printf("%f %f\n",theta,rad);
        glVertex2d(rad*5.0,25.0+5.0*(tan(rad))); 
    }
    glEnd();

    */

    glFlush();
}


int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("New Experiment");
    init();
    //glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
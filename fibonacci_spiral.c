#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define PI 22.0/7.0

float CX,CY;


void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
    CX=0.0;CY=0.0;
}

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

void delay(int x){
    int i;
    int j=x;

    while(j--)
        for(i=0;i<10000;i++);
}

void drawPie(float from,float to,float radius,float c[2]){
    glBegin(GL_LINE_STRIP);

    float theta,rad;
    //glVertex2d(c[0],c[1]);

    for(theta=from;theta<=to;theta+=1.0){
        rad=theta/180.0*PI;
        glVertex2d(c[0]+radius*cos(rad),c[1]+radius*sin(rad));
    }
    glEnd();
}

void display(){
    float theta;int i=0,j,k,row=0;
    float color[100][3];

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++,row++){
                color[row][0]=i/1.0;
                color[row][1]=j/1.0;
                color[row][2]=k/1.0;
                //printf("%f %f %f \n",color[row][0],color[row][1],color[row][2]);
            }
        }
    }
    int random;
    for(i=8;i<30;i++){
        random=rand()%i+1;
        color[i][0]=color[random][rand()%3]-0.4;
        color[i][1]=color[random][rand()%3]-0.4;
        color[i][2]=color[random][rand()%3]-0.4;
    }
    glLineWidth(2);
    //float from=0.0,to=45.0;


    glColor3f(0.0,0.0,0.0);
    int n=0;
    float fib1=0,fib2=1,fib3,rad;
    float center[2]={CX,CY};
    i=0;
    for(theta=0.0;theta<3600.0;theta+=90.0){
        rad=theta/180.0*PI;
        fib3=fib1+fib2;
        switch(n%4){
            case 0:center[0]-=(fib3-fib2);break;
            case 1:center[1]-=(fib3-fib2);break;
            case 2:center[0]+=(fib3-fib2);break;
            case 3:center[1]+=(fib3-fib2);break;
        }
        drawPie(theta,theta+90.0,fib3,center);
        n++;       
        fib1=fib2;
        fib2=fib3;
        
        //calcCenter(fib3,center,++n,point);
        //glColor3fv(color[i++]);
        //printf("%d : %f %f\n",n,center[0],center[1]);
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
    //glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("New Experiment");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
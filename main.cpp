#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-15,15,-15,15,-15,5);
}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++)
    {
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(10,10,0,0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circle(10,10,5,2);
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Moon - Marjuk");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}

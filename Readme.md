To run the files in linux run thses commands : 

```bash
g++ <filename>.c -lGL -lglut   
```
<br/><br/>

<p align=right>Adarsh Kumar Singh</p>
<p align=right>111915005</p>

Table of Contents
- [3D Model : Spinning Pyramid](#3d-model--spinning-pyramid)
- [3D Model : Spinning Cube](#3d-model--spinning-cube)
- [3D Model : Cylinder](#3d-model--cylinder)


<br/><br/>

## 3D Model : Spinning Pyramid

```c
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

GLfloat d = 0;
int a = 0;

void MyInit()
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
}

void Spin()
{
    d = d + 0.5;
    if (d > 360)
        d = 0;
    glutPostRedisplay();
}

void Face(GLfloat A[], GLfloat B[], GLfloat C[])
{
    glBegin(GL_POLYGON);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glEnd();
}

void Tri(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[])
{
    glColor3f(1, 0, 0);
    Face(V0, V1, V2);
    glColor3f(0, 1, 0);
    Face(V0, V1, V3);
    glColor3f(0, 0, 1);
    Face(V0, V2, V3);
    glColor3f(1, 1, 0);
    Face(V1, V2, V3);
}

void disp()
{
    GLfloat V[4][3] = {
        {0.5, 0, 0},
        {0, 0.5, 0},
        {-0.5, -0.5, 0.5},
        {0.5, -0.5, 0.5},
    };

    GLfloat rV[4][3], r;
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    r = d * 3.14 / 180;

    if (a == 1)
    {
        for (i = 0; i < 4; i++)
        {
            rV[i][0] = V[i][0];
            rV[i][1] = V[i][1] * cos(r) - V[i][2] * sin(r);
            rV[i][2] = V[i][1] * sin(r) + V[i][2] * cos(r);
        }
    }

    if (a == 2)
    {
        for (i = 0; i < 4; i++)
        {
            rV[i][0] = V[i][2] * sin(r) + V[i][0] * cos(r);
            rV[i][1] = V[i][1];
            rV[i][2] = V[i][2] * cos(r) - V[i][0] * sin(r);
        }
    }

    if (a == 3)
    {
        for (i = 0; i < 4; i++)
        {
            rV[i][0] = V[i][0] * cos(r) - V[i][1] * sin(r);
            rV[i][1] = V[i][0] * sin(r) + V[i][1] * cos(r);
            rV[i][2] = V[i][2];
        }
    }

    Tri(rV[0], rV[1], rV[2], rV[3]);
    glutSwapBuffers();
}

int main(int C, char *V[])
{
    printf("Enter the Axis of Rotation [ 1->Xaxis | 2->Yaxis | 3->Zaxis ]: ");
    scanf("%d", &a);

    glutInit(&C, V);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50, 150);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("3D Model : Spinning Pyramid");
    MyInit();
    glutDisplayFunc(disp);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}
```


![3D Model : Spinning Pyramid](/assets/SpinningPyramid.png)

<br/><br/>
<div style="page-break-after: always"></div>


## 3D Model : Spinning Cube

```c
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

GLfloat d = 0;
int a = 0;

void MyInit()
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
}

void Spin()
{
    d = d + 0.25;
    if (d > 360)
        d = 0;
    glutPostRedisplay();
}

void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{
    glBegin(GL_POLYGON);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);
    glEnd();
}

void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[])
{
    glColor3f(1, 0, 0);
    Face(V0, V1, V2, V3);
    glColor3f(0, 1, 0);
    Face(V4, V5, V6, V7);
    glColor3f(0, 0, 1);
    Face(V0, V4, V7, V3);
    glColor3f(1, 1, 0);
    Face(V1, V5, V6, V2);
    glColor3f(1, 0, 1);
    Face(V2, V3, V7, V6);
    glColor3f(0, 1, 1);
    Face(V0, V1, V5, V4);
}

void display()
{
    GLfloat V[8][3] = {
        {-0.5, 0.5, 0.5},
        {0.5, 0.5, 0.5},
        {0.5, -0.5, 0.5},
        {-0.5, -0.5, 0.5},
        {-0.5, 0.5, -0.5},
        {0.5, 0.5, -0.5},
        {0.5, -0.5, -0.5},
        {-0.5, -0.5, -0.5},
    };

    GLfloat rV[8][3], r;
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    r = d * 3.14 / 180;

    if (a == 1)
    {
        for (i = 0; i < 8; i++)
        {
            rV[i][0] = V[i][0];
            rV[i][1] = V[i][1] * cos(r) - V[i][2] * sin(r);
            rV[i][2] = V[i][1] * sin(r) + V[i][2] * cos(r);
        }
    }

    if (a == 2)
    {
        for (i = 0; i < 8; i++)
        {
            rV[i][0] = V[i][2] * sin(r) + V[i][0] * cos(r);
            rV[i][1] = V[i][1];
            rV[i][2] = V[i][2] * cos(r) - V[i][0] * sin(r);
        }
    }

    if (a == 3)
    {
        for (i = 0; i < 8; i++)
        {
            rV[i][0] = V[i][0] * cos(r) - V[i][1] * sin(r);
            rV[i][1] = V[i][0] * sin(r) + V[i][1] * cos(r);
            rV[i][2] = V[i][2];
        }
    }

    Cube(rV[0], rV[1], rV[2], rV[3], rV[4], rV[5], rV[6], rV[7]);

    glutSwapBuffers();
}

int main(int C, char *V[])
{
    printf("Enter the Axis of Rotation [ 1->Xaxis | 2->Yaxis | 3->Zaxis ]: ");
    scanf("%d", &a);

    glutInit(&C, V);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(50, 150);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("3D Model : Spinning Cube");
    MyInit();
    glutDisplayFunc(display);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}

```


![3D Model : Spinning Cube](/assets/SpinningCube.png)

<br/><br/>
<div style="page-break-after: always"></div>


## 3D Model : Cylinder

```c
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415927

void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    glColor3ub(R - 140, G - 130, B - 45);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();

    glColor3ub(R, G, B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI)
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, -0.4, -3.0);
    glRotatef(-40, 1.0, 0.0, 0.0);

    draw_cylinder(0.3, 1.0, 255, 160, 100);

    glFlush();
}

void reshape(int width, int height)
{
    if (width == 0 || height == 0)
        return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)width / (GLdouble)height,
                   0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);
}

int main(int C, char *V[])
{
    glutInit(&C, V);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Create Cylinder");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
```


![3D Model : Cylinder](/assets/Cylinder.jpeg)


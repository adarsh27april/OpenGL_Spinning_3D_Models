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

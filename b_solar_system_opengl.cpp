#include <GL/glut.h>
#include <cmath>

float earthAngle = 0.0f;
float moonAngle = 0.0f;

void initLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
}

void drawSphere(float radius) {
    glutSolidSphere(radius, 30, 30);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 5.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0); drawSphere(2.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(earthAngle, 0.0, 1.0, 0.0);
    glTranslatef(7.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 1.0); drawSphere(1.0);

    glPushMatrix();
    glRotatef(moonAngle, 0.0, 1.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0);
    glColor3f(0.6, 0.6, 0.6); drawSphere(0.3);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void update(int value) {
    earthAngle += 0.5f; if (earthAngle > 360) earthAngle -= 360;
    moonAngle += 2.0f; if (moonAngle > 360) moonAngle -= 360;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void setupScene() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    initLighting();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Solar System Simulation");
    setupScene();
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}

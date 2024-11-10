#include <GL/glut.h>

float rotationX = 0.0f;
float rotationY = 0.0f;
float rotationZ = 0.0f;

// Función para dibujar cada cara del dado
void drawFace(float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glEnd();
}

// Función para dibujar el dado
void drawDice() {
    glPushMatrix();

    // Cara frontal (1)
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawFace(1.0f, 0.0f, 0.0f); // Roja
    glTranslatef(0.0f, 0.0f, -0.5f);

    // Cara posterior (6)
    glPushMatrix();
    glRotatef(180, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawFace(0.0f, 1.0f, 0.0f); // Verde
    glPopMatrix();

    // Cara derecha (3)
    glPushMatrix();
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawFace(0.0f, 0.0f, 1.0f); // Azul
    glPopMatrix();

    // Cara izquierda (4)
    glPushMatrix();
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawFace(1.0f, 1.0f, 0.0f); // Amarillo
    glPopMatrix();

    // Cara superior (5)
    glPushMatrix();
    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawFace(1.0f, 0.0f, 1.0f); // Magenta
    glPopMatrix();

    // Cara inferior (2)
    glPushMatrix();
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawFace(0.0f, 1.0f, 1.0f); // Cian
    glPopMatrix();

    glPopMatrix();
}

// Función para configurar la escena y rotar el dado
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -3.0f); // Coloca el dado en el centro de la pantalla

    // Aplica la rotación en los tres ejes
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationZ, 0.0f, 0.0f, 1.0f);

    drawDice(); // Dibuja el dado

    glutSwapBuffers();
}

// Actualiza los ángulos de rotación y redibuja la escena
void update(int value) {
    rotationX += 1.0f;
    rotationY += 1.5f;
    rotationZ += 1.2f;

    if (rotationX > 360) rotationX -= 360;
    if (rotationY > 360) rotationY -= 360;
    if (rotationZ > 360) rotationZ -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Llama a update cada 16 ms
}

// Configuración de la perspectiva
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

// Configuración de OpenGL y GLUT
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo negro
    glEnable(GL_DEPTH_TEST); // Habilita el test de profundidad
}

// Función principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 900);
    glutCreateWindow("Dado 3D Giratorio");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}

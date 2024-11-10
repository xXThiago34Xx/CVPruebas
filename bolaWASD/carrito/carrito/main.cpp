#include <GL/glut.h>
#include <cmath>
#include <iostream>
#define M_PI 3.14159265358979323846


const int WIDTH = 1000;
const int HEIGHT = 750;

float circleX = WIDTH / 2.0f;
float circleY = HEIGHT / 2.0f;
const float circleRadius = 50.0f;
const float moveSpeed = 50.0f;

// Función para dibujar un círculo
void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Centro del círculo
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * M_PI * i / 100;
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

// Función de visualización
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibujar el círculo
    glColor3f(0.0f, 0.5f, 1.0f); // Color del círculo
    drawCircle(circleX, circleY, circleRadius);

    glutSwapBuffers();
}

// Función de teclado
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w': circleY += moveSpeed; break; // Arriba
    case 's': circleY -= moveSpeed; break; // Abajo
    case 'a': circleX -= moveSpeed; break; // Izquierda
    case 'd': circleX += moveSpeed; break; // Derecha
    case 32: // Espacio
        circleX = WIDTH / 2.0f;
        circleY = HEIGHT / 2.0f;
        break;
    }
    glutPostRedisplay(); // Volver a dibujar
}

// Función de inicialización
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Color de fondo blanco
    glColor3f(0.0f, 0.0f, 0.0f); // Color de los puntos por defecto
    glPointSize(5.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WIDTH, 0.0, HEIGHT, -1.0, 1.0); // Configurar el sistema de coordenadas
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    // Inicializar GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Circulo en movimiento");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    // Bucle principal
    glutMainLoop();
    return 0;
}

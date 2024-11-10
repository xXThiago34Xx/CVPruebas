#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>

// Definici�n de M_PI si no est� disponible
#define M_PI 3.14159265358979323846

// Constantes de f�sica
const float GRAVITY = 9.81f;  // Aceleraci�n gravitacional en m/s�
const float INITIAL_VELOCITY = 20.0f;  // Velocidad inicial en m/s

// Variables de lanzamiento
float angle;  // �ngulo de lanzamiento en grados
float angleRad;  // �ngulo en radianes
float timeElapsed = 0.0f;  // Tiempo transcurrido

// Dimensiones calculadas
float maxHeight;      // Altura m�xima alcanzada
float maxDistance;    // Distancia m�xima horizontal

// Funci�n para calcular el valor de posici�n en X
float calculateX(float time) {
    return INITIAL_VELOCITY * cos(angleRad) * time;
}

// Funci�n para calcular el valor de posici�n en Y
float calculateY(float time) {
    return INITIAL_VELOCITY * sin(angleRad) * time - 0.5 * GRAVITY * time * time;
}

// Inicializa la animaci�n, c�lculos previos
void initializeSimulation() {
    angleRad = angle * M_PI / 180.0f;  // Convierte �ngulo a radianes
    maxHeight = (INITIAL_VELOCITY * INITIAL_VELOCITY * sin(angleRad) * sin(angleRad)) / (2 * GRAVITY);
    maxDistance = (INITIAL_VELOCITY * INITIAL_VELOCITY * sin(2 * angleRad)) / GRAVITY;
}

// Renderiza la esfera
void drawSphere(float x, float y) {
    glColor3f(0.0f, 0.8f, 0.8f);  // Color turquesa
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();
}

// Muestra informaci�n de distancia y altura m�xima
void displayInfo() {
    std::stringstream info;
    info << "Max Height: " << std::fixed << std::setprecision(2) << maxHeight << " m";
    info << ", Max Distance: " << maxDistance << " m";

    std::string infoStr = info.str();
    glRasterPos2f(-10.0f, 8.0f);
    for (char c : infoStr) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

// Funci�n de visualizaci�n
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Dibuja la esfera en su posici�n actual
    float x = calculateX(timeElapsed);
    float y = calculateY(timeElapsed);
    if (y >= 0.0f) {
        drawSphere(x, y);
    }
    else {
        // Reinicia la animaci�n al llegar al suelo
        timeElapsed = 0.0f;
    }

    displayInfo();  // Muestra la distancia m�xima y altura m�xima

    glutSwapBuffers();
}

// Actualiza el tiempo de la animaci�n
void update(int value) {
    timeElapsed += 0.05f;  // Incremento de tiempo
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);  // Llama a update cada 16 ms (aproximadamente 60 fps)
}

// Configuraci�n inicial de OpenGL
void setupOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Fondo negro
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 50, -5, 20);  // Configura la proyecci�n ortogr�fica para ver la trayectoria
    glMatrixMode(GL_MODELVIEW);
}

// Funci�n principal
int main(int argc, char** argv) {
    std::cout << "Ingrese el angulo de lanzamiento en grados: ";
    std::cin >> angle;

    initializeSimulation();  // Calcula la distancia y altura m�xima

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lanzamiento Parabolico de una Esfera");

    setupOpenGL();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);  // Inicia el temporizador para la animaci�n

    glutMainLoop();
    return 0;
}

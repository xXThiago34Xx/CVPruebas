#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>

// Definición de M_PI si no está disponible
#define M_PI 3.14159265358979323846

// Constantes de física
const float GRAVITY = 9.81f;  // Aceleración gravitacional en m/s²
const float INITIAL_VELOCITY = 20.0f;  // Velocidad inicial en m/s

// Variables de lanzamiento
float angle;  // Ángulo de lanzamiento en grados
float angleRad;  // Ángulo en radianes
float timeElapsed = 0.0f;  // Tiempo transcurrido

// Dimensiones calculadas
float maxHeight;      // Altura máxima alcanzada
float maxDistance;    // Distancia máxima horizontal

// Función para calcular el valor de posición en X
float calculateX(float time) {
    return INITIAL_VELOCITY * cos(angleRad) * time;
}

// Función para calcular el valor de posición en Y
float calculateY(float time) {
    return INITIAL_VELOCITY * sin(angleRad) * time - 0.5 * GRAVITY * time * time;
}

// Inicializa la animación, cálculos previos
void initializeSimulation() {
    angleRad = angle * M_PI / 180.0f;  // Convierte ángulo a radianes
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

// Muestra información de distancia y altura máxima
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

// Función de visualización
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Dibuja la esfera en su posición actual
    float x = calculateX(timeElapsed);
    float y = calculateY(timeElapsed);
    if (y >= 0.0f) {
        drawSphere(x, y);
    }
    else {
        // Reinicia la animación al llegar al suelo
        timeElapsed = 0.0f;
    }

    displayInfo();  // Muestra la distancia máxima y altura máxima

    glutSwapBuffers();
}

// Actualiza el tiempo de la animación
void update(int value) {
    timeElapsed += 0.05f;  // Incremento de tiempo
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);  // Llama a update cada 16 ms (aproximadamente 60 fps)
}

// Configuración inicial de OpenGL
void setupOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Fondo negro
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 50, -5, 20);  // Configura la proyección ortográfica para ver la trayectoria
    glMatrixMode(GL_MODELVIEW);
}

// Función principal
int main(int argc, char** argv) {
    std::cout << "Ingrese el angulo de lanzamiento en grados: ";
    std::cin >> angle;

    initializeSimulation();  // Calcula la distancia y altura máxima

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lanzamiento Parabolico de una Esfera");

    setupOpenGL();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);  // Inicia el temporizador para la animación

    glutMainLoop();
    return 0;
}

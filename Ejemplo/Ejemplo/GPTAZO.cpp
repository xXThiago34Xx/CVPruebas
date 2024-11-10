#include <GL/glut.h>
#include <cstdlib>

// Función de inicialización
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo negro
    glEnable(GL_DEPTH_TEST);           // Habilita el test de profundidad
}

// Función para dibujar la esfera
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpia la pantalla y el buffer de profundidad

    glLoadIdentity(); // Resetea la matriz de transformación
    glTranslatef(0.0f, 0.0f, -5.0f); // Traslada la esfera hacia atrás para que sea visible

    glColor3f(0.0, 1.0, 0.0); // Color de la esfera (verde)
    glutSolidSphere(1.0, 50, 50); // Dibuja una esfera sólida (radio, segmentos longitudinales, segmentos latitudinales)

    glutSwapBuffers(); // Intercambia los buffers
}

// Configuración de la perspectiva
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

// Configuración de teclado para salir
void keyboard(unsigned char key, int x, int y) {
    if (key == 27) { // Tecla ESC
        exit(0);
    }
}

// Función principal
int GPTAZO(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Esfera en OpenGL");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

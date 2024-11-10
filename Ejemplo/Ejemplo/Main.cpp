#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibujar un triángulo
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0); // Color rojo
    glVertex2f(-0.5, -0.5); // Vértice inferior izquierdo
    glColor3f(0.0, 1.0, 0.0); // Color verde
    glVertex2f(0.5, -0.5); // Vértice inferior derecho
    glColor3f(0.0, 0.0, 1.0); // Color azul
    glVertex2f(0.0, 0.5); // Vértice superior
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Tamaño de la ventana
    glutInitWindowPosition(100, 100); // Posición de la ventana
    glutCreateWindow("GLUT Test"); // Crear ventana
    glutDisplayFunc(display); // Función de dibujado
    glutMainLoop(); // Iniciar el loop principal
    return 0;
}

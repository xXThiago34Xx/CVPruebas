#include <GL/glut.h>

// Función que se llama para dibujar en pantalla
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia el buffer de color
    glColor3f(1.0, 0.0, 0.0);     // Establece el color de dibujo (rojo)

    // Dibuja un triángulo
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glFlush(); // Manda los comandos al buffer de salida
}

// Función principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);                       // Inicializa GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Configura el modo de visualización
    glutInitWindowSize(500, 500);                // Tamaño de la ventana
    glutCreateWindow("Triángulo con GLUT");      // Crea la ventana con un título

    // Configura el color de fondo de la ventana
    glClearColor(0.0, 0.0, 0.0, 1.0); // Negro

    // Registra la función display para que se llame al dibujar
    glutDisplayFunc(display);

    // Inicia el loop principal de GLUT
    glutMainLoop();

    return 0;
}

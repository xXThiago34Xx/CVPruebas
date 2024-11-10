#include <GL/glut.h>

// Funci�n que se llama para dibujar en pantalla
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpia el buffer de color
    glColor3f(1.0, 0.0, 0.0);     // Establece el color de dibujo (rojo)

    // Dibuja un tri�ngulo
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glFlush(); // Manda los comandos al buffer de salida
}

// Funci�n principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);                       // Inicializa GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Configura el modo de visualizaci�n
    glutInitWindowSize(500, 500);                // Tama�o de la ventana
    glutCreateWindow("Tri�ngulo con GLUT");      // Crea la ventana con un t�tulo

    // Configura el color de fondo de la ventana
    glClearColor(0.0, 0.0, 0.0, 1.0); // Negro

    // Registra la funci�n display para que se llame al dibujar
    glutDisplayFunc(display);

    // Inicia el loop principal de GLUT
    glutMainLoop();

    return 0;
}

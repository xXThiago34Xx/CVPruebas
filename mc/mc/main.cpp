#include <GL/glut.h>

// Función para dibujar un cubo
void drawCube(float width, float height, float depth, float r, float g, float b) {
    glPushMatrix();
    glScalef(width, height, depth); // Escala el cubo a las dimensiones deseadas

    // Establece el color del cubo
    glColor3f(r, g, b);
    glutSolidCube(1.0); // Dibuja un cubo centrado en el origen
    glPopMatrix();
}

// Función para dibujar el personaje de Minecraft
void drawMinecraftCharacter() {
    // Cabeza
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f); // Posiciona la cabeza sobre el cuerpo
    drawCube(0.6f, 0.6f, 0.6f, 1.0f, 0.8f, 0.5f); // Color de la cabeza
    glPopMatrix();

    // Cuerpo
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f); // Posiciona el cuerpo debajo de la cabeza
    drawCube(0.8f, 1.0f, 0.3f, 0.0f, 0.0f, 1.0f); // Color azul para el cuerpo
    glPopMatrix();

    // Brazo izquierdo
    glPushMatrix();
    glTranslatef(-0.6f, 0.6f, 0.0f); // Posiciona el brazo izquierdo al costado del cuerpo
    drawCube(0.2f, 0.7f, 0.2f, 0.0f, 1.0f, 0.0f); // Color verde para el brazo izquierdo
    glPopMatrix();

    // Brazo derecho
    glPushMatrix();
    glTranslatef(0.6f, 0.6f, 0.0f); // Posiciona el brazo derecho al otro costado del cuerpo
    drawCube(0.2f, 0.7f, 0.2f, 1.0f, 0.0f, 0.0f); // Color rojo para el brazo derecho
    glPopMatrix();

    // Pierna izquierda
    glPushMatrix();
    glTranslatef(-0.25f, -0.5f, 0.0f); // Posiciona la pierna izquierda debajo del cuerpo
    drawCube(0.2f, 0.7f, 0.2f, 1.0f, 1.0f, 0.0f); // Color amarillo para la pierna izquierda
    glPopMatrix();

    // Pierna derecha
    glPushMatrix();
    glTranslatef(0.25f, -0.5f, 0.0f); // Posiciona la pierna derecha debajo del cuerpo
    drawCube(0.2f, 0.7f, 0.2f, 0.5f, 0.5f, 0.5f); // Color gris para la pierna derecha
    glPopMatrix();
}

// Función de visualización
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpia el buffer de color y profundidad
    glLoadIdentity();
    gluLookAt(0.0, 1.5, 15.0,  // Cámara más alejada
        0.0, 0.6, 0.0,   // Punto al que mira la cámara
        0.0, 1.0, 0.0);  // Vector "arriba" para la cámara

    // Dibuja el personaje
    drawMinecraftCharacter();

    glutSwapBuffers();
}

// Configuración de la ventana y del entorno de OpenGL
void setupOpenGL() {
    glClearColor(0.5f, 0.8f, 0.9f, 1.0f); // Color de fondo
    glEnable(GL_DEPTH_TEST); // Habilita el test de profundidad para el 3D

    // Configuración de iluminación
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = { 0.0, 10.0, 10.0, 1.0 }; // Posición de la luz
    GLfloat light_color[] = { 1.0, 1.0, 1.0, 1.0 }; // Color de la luz
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_color);
}

// Función principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Personaje Minecraft en OpenGL");

    setupOpenGL();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

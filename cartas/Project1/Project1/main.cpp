#include <GL/glut.h>
#include <iostream>
#include <string>

enum Choice { NONE, ROCK, PAPER, SCISSORS };
Choice player1Choice = NONE, player2Choice = NONE;
bool player1Turn = true;
std::string result;

void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawChoices() {
    glColor3f(1.0, 1.0, 1.0);
    drawText("1: Rock", -0.9f, 0.8f);
    drawText("2: Paper", -0.9f, 0.6f);
    drawText("3: Scissors", -0.9f, 0.4f);

    // Solo mostrar la elección del jugador 1 si el jugador 2 ha hecho su elección
    if (player2Choice != NONE) {
        drawText("Player 1 choice: ", -0.9f, 0.1f);
        drawText((player1Choice == ROCK ? "Rock" : player1Choice == PAPER ? "Paper" : "Scissors"), 0.3f, 0.1f);

        drawText("Player 2 choice: ", -0.9f, -0.2f);
        drawText((player2Choice == ROCK ? "Rock" : player2Choice == PAPER ? "Paper" : "Scissors"), 0.3f, -0.2f);
    }

    if (!result.empty()) {
        drawText("Result: ", -0.9f, -0.5f);
        drawText(result.c_str(), -0.3f, -0.5f);
    }
}

void determineWinner() {
    if (player1Choice == player2Choice) {
        result = "It's a draw!";
    }
    else if ((player1Choice == ROCK && player2Choice == SCISSORS) ||
        (player1Choice == PAPER && player2Choice == ROCK) ||
        (player1Choice == SCISSORS && player2Choice == PAPER)) {
        result = "Player 1 wins!";
    }
    else {
        result = "Player 2 wins!";
    }
}

void keyboard(unsigned char key, int x, int y) {
    if (key == '1' || key == '2' || key == '3') {
        Choice choice = (key == '1') ? ROCK : (key == '2') ? PAPER : SCISSORS;

        if (player1Turn) {
            player1Choice = choice;
            player1Turn = false;
            // Mensaje para indicar que el Jugador 1 ha hecho su elección
            std::cout << "Player 1 has made a choice. Now Player 2, choose!" << std::endl;
        }
        else {
            player2Choice = choice;
            determineWinner();
        }
    }
    else if (key == 'r') {  // Reiniciar el juego
        player1Choice = player2Choice = NONE;
        player1Turn = true;
        result.clear();
    }

    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawChoices();
    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Fondo negro
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Rock, Paper, Scissors Game");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}

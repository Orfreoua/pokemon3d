/*#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

// Fonction pour activer le mode non canonique du terminal
void enableRawMode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Fonction pour désactiver le mode non canonique du terminal
void disableRawMode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag |= (ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    enableRawMode();

    while (1) {
        char c;
        if (read(STDIN_FILENO, &c, 1) == 1) {
            // Affichez le code de la touche appuyée
            printf("Touche appuyée : %d\n", c);
            if (c == 27) {  // Code d'échappement (ESC)
                break;
            }
        }
    }

    disableRawMode();
    return 0;
}*/
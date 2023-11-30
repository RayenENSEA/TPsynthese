#include <unistd.h>
#include <string.h>

int main() {
	
    // welcome message
    write(STDOUT_FILENO, "Bienvenue dans le Shell ENSEA.\n", strlen("Bienvenue dans le Shell ENSEA.\n"));
    write(STDOUT_FILENO, "Pour quitter, tapez 'exit'.\n", strlen("Pour quitter, tapez 'exit'.\n"));

    // prompt
    write(STDOUT_FILENO, "enseash % ", strlen("enseash % "));


    return 0;
}

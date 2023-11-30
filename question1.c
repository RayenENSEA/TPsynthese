#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
	
    char *buffer = "Bienvenue dans le Shell ENSEA.\n Pour quitter, tapez 'exit'.\n enseash %";
    
    write(STDOUT_FILENO, buffer, strlen(buffer));

    return 0;
}

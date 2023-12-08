#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
	
    char *buffer = "Bienvenue dans le Shell ENSEA.\n Pour quitter, tapez 'exit'.\n enseash %\n"; // welcome message
    
    write(STDOUT_FILENO, buffer, strlen(buffer)); //  write the content of the buffer to the standard output associated with the console

    return 0;
}

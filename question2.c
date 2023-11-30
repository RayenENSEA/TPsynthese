#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define BUFFER_SIZE = 256

int main() {
	
    char *welcomeMessage = "Bienvenue dans le Shell ENSEA.\n Pour quitter, tapez 'exit'.\n";
    
    char *prompt = "enseash %";
    
    char buffer[BUFFER_SIZE];
    
    while(1){
		write(STDOUT_FILENO, prompt, strlen(prompt));
		
		read(STDIN_FILENO, buffer, BUFFER_SIZE);
		
		

    return 0;
}

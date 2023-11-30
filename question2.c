#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define BUFFER_SIZE 256

int main() {
	
    char *welcomeMessage = "Bienvenue dans le Shell ENSEA.\n Pour quitter, tapez 'exit'.\n";
    
    char *prompt = "enseash %";
    
    char buffer[BUFFER_SIZE];
    
    write(STDOUT_FILENO, welcomeMessage, strlen(welcomeMessage));
    
    while(1){
		
		write(STDOUT_FILENO, prompt, strlen(prompt));
		
		read(STDIN_FILENO, buffer, sizeof(buffer));
		
		if(strncmp(buffer, "ls", 2) == 0){
			execl("/bin/ls", buffer, NULL);
		}
		
		if(strncmp(buffer, "pwd", 3) == 0){
			execl("/bin/pwd", buffer, NULL);
		}
		if(strncmp(buffer, "fortune", 7) == 0){
			execl("/bin/fortune", buffer, NULL);
		}
		else{
			write(STDOUT_FILENO, prompt, strlen(prompt));
		}
			
	}

    return 0;
}

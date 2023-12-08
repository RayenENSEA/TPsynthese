#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


# define BUFFER_SIZE 256

int main() {
	
	char *welcomeMessage = "Bienvenue dans le Shell ENSEA.\n Pour quitter, tapez 'exit'.\n";
	char *prompt = "enseash %";
	char *error = "Command not found\n"; // error message
	char buffer[BUFFER_SIZE];
	    
	int command_len;
	int status;
	    
	write(STDOUT_FILENO, welcomeMessage, strlen(welcomeMessage));

	while(1){
		write(STDOUT_FILENO, prompt, strlen(prompt));	// display the shell prompt
		command_len=read(STDIN_FILENO, buffer, sizeof(buffer));	
		buffer[command_len-1]='\0'; 	// replace the newline character with a null terminator
		pid_t pid;
		pid=fork(); 	// creating a child process
		if(pid==0){ 	// entering the chlid process
			execlp(buffer, buffer, NULL); 	// execute the command entered by the user
			write(STDOUT_FILENO, error, strlen(error)); 	// display error message if exec fails
			exit(EXIT_FAILURE);
		}

		else{
			wait(&status); 	// wait for the child process to complete
		}
	}
	return 0;
}

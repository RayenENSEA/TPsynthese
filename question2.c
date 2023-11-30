#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>


# define BUFFER_SIZE 256

int main() {
	
	char *welcomeMessage = "Bienvenue dans le Shell ENSEA.\n Pour quitter, tapez 'exit'.\n";
	char *prompt = "enseash %";
	char *error = "Command not found\n";
	char buffer[BUFFER_SIZE];
	    
	int command_len;
	int status;
	    
	pid_t pid;
	    
	write(STDOUT_FILENO, welcomeMessage, strlen(welcomeMessage));
	    
	pid=fork();
			
	if(pid==0){
		write(STDOUT_FILENO, prompt, strlen(prompt));
		command_len=read(STDIN_FILENO, buffer, sizeof(buffer));
		buffer[command_len-1]='\0';
		
		execlp(buffer, buffer, NULL);
		perror("Command not found\n");
	}

	else{
		wait(&status);
	}
	return 0;
}

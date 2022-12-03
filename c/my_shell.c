#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define STR_SIZE 100
#define P_SIZE 100

void forkToChild(pid_t pid, int status);
void cleanProcess(pid_t pid[], int size);

int main()
{
	char command[STR_SIZE];
	pid_t parent = getpid();
	pid_t pid[P_SIZE];
	int index = -1;

	while (1) {
		printf("1092926 ms> ");

		fgets(command, STR_SIZE, stdin);
		command[strlen(command) - 1] = '\0';
		
		if (strcmp(command, "hello") == 0) {
			printf("\nParent process(%d) is in the FOREGOUND\n\n", parent);
		}
		else if (strcmp(command, "child") == 0) {
			pid[++index] = fork();
			forkToChild(pid[index], 0);
			waitpid(pid[index], NULL, 0);
		}
		else if (strcmp(command, "child &") == 0) {
			pid[++index] = fork();
			forkToChild(pid[index], 1);
		}
		else if (strcmp(command, "exit") == 0) {
			cleanProcess(pid, index);
			break;
		}
		else {
			continue;
		}

		command[0] = '\0';
	}


	return 0;
}

void forkToChild(pid_t pid, int status) {
	if (pid < 0) {
		printf("Creating process failed.\n");
	}
	else if (pid == 0) {
		//printf("Child process.\n");
		if (status == 0) {
			execl("./child", "child", NULL);
		}
		else if (status == 1) {
			execl("./child", "child", "&", NULL);
		}
	}
	else {
		printf("Parent process.\n");
	}

	return ;
}

void cleanProcess(pid_t pid[], int size) {
	for (int i=0;i <= size;i++) {
		if (pid[i] > 0) {
			kill(pid[i], SIGKILL);
		}
	}

	return ;
}
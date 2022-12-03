#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{   
	printf("Hello, child!, pid = %d\n", getpid());
	if (argc > 1 && strcmp(argv[1], "&") == 0) {
		while (1) {
			printf("\nChild process(%d) is in the BACKGROUND.\n\n", getpid());
			sleep(10);
		}
		exit(getpid());
	}
	else {
		char command[100];
		while (1) {
			printf("1092926 child> ");
			scanf("%s", command);
			
			if (strcmp(command, "hello") == 0) {
				printf("\nChild process(%d) is in the FOREGOUND.\n\n", getpid());
			}
			else if (strcmp(command, "exit") == 0) {
				break;
			}
			else {
				continue;
			}
		}
	}

	exit(getpid());
	return 0;
}
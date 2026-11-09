#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child executing ls:\n");

        execlp("ls", "ls", "-l", (char *)NULL);

        perror("execlp");
        return 1;
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Parent process completed\n");
    }
    else {
        perror("fork");
        return 1;
    }

    return 0;
}

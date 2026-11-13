#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(void) {
    sem_t *s = mmap(NULL, sizeof(*s), PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (s == MAP_FAILED) { perror("mmap"); return 1; }
    if (sem_init(s, 1, 1) == -1) { perror("sem_init"); return 1; }

    pid_t pid = fork();
    if (pid == 0) {
        sem_wait(s);
        printf("Child in critical section\n");
        sleep(1);
        printf("Child leaving critical section\n");
        sem_post(s);
        return 0;
    } else if (pid > 0) {
        sem_wait(s);
        printf("Parent in critical section\n");
        sem_post(s);
        wait(NULL);
    } else {
        perror("fork");
        return 1;
    }

    sem_destroy(s);
    munmap(s, sizeof(*s));
    return 0;
}

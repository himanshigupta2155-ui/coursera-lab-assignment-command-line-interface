#
include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void sigchld_handler(int sig) {
    (void)sig;
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigchld_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;
    sigaction(SIGCHLD, &sa, NULL);

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("[Child PID %d] Running...\n", getpid());
        sleep(10);
        exit(0);
    } else {
        printf("[Parent PID %d] Created Child PID %d\n", getpid(), pid);
        sleep(2);
        
        if (kill(pid, 0) == 0) {
            printf("[Parent] Child %d unresponsive. Terminating...\n", pid);
            kill(pid, SIGTERM);
        }
        
        sleep(1);
        printf("[Parent] Execution complete.\n");
    }

    return 0;
}

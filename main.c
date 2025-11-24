#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    int N;

    printf("Inserisci un numero positivo N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {

        pid_t pid = fork();

        if (pid < 0) {  // Errore
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // CODICE DEL FIGLIO
            printf("Processo figlio %d: PID=%d, PPID=%d\n",
                   i, getpid(), getppid());
            exit(0);   
        }
    }

    for (int i = 0; i < N; i++) {
        wait(NULL);
    }

    return 0;
}

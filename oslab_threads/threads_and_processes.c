#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int data;

void *worker(void *arg) {
    int *p = (int *)arg;
    *p = *p + 1;
    printf("Data is %d\n", *p);
    return (void *)42;
}

int main() {
    int status;
    data = 0;

    pid_t pid = fork();

    if (pid == 0) {
        // child process: one thread
        pthread_t thread;
        pthread_create(&thread, NULL, &worker, &data);

        void *ret = NULL;
        pthread_join(thread, &ret);
        // optional: print return value
        // printf("Child worker returned %ld\n", (long)ret);
    } else {
        // parent process: two threads (one after the other)
        pthread_t thread;
        void *ret = NULL;

        pthread_create(&thread, NULL, &worker, &data);
        pthread_join(thread, &ret);

        pthread_create(&thread, NULL, &worker, &data);
        pthread_join(thread, &ret);

        wait(&status);
    }

    return 0;
}

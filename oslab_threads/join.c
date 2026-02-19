#include <pthread.h>
#include <stdio.h>
#include <sched.h>

void *helper(void *arg) {
    printf("HELPER\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, &helper, NULL);
    sched_yield();              // similar idea to pthread_yield in your worksheet
    printf("MAIN\n");
    return 0;
}

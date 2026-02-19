#include <pthread.h>
#include <stdio.h>

void *helper(void *arg) {
    printf("HELPER\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, &helper, NULL);

    pthread_join(thread, NULL);   // wait until HELPER finishes
    printf("MAIN\n");
    return 0;
}

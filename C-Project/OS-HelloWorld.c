#include <pthread.h>
#include <stdio.h>

/* Thread function that prints "Hello World" */
void *worker(void *arg)
{
    printf("Hello World!\n");
    return NULL;  /* Thread exits (dies) */
}

int main()
{
    pthread_t thread;
    int ret;

    /* Create a new thread */
    ret = pthread_create(&thread, NULL, worker, NULL);
    if (ret != 0) {
        perror("pthread_create failed");
        return 1;
    }

    /* Wait for the thread to finish */
    pthread_join(thread, NULL);

    return 0;
}
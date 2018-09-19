#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 10

int thread_id[NUM_THREADS];

void * PrintHello(int i) {
    printf("Hello from thread %d - I was created in iteration %d !\n", 
        (int) pthread_self(), i);
    sleep(2);
    pthread_exit(NULL);
}

int main(int argc, char * argv[]) {
    int rc, i;
    for (i = 0; i < NUM_THREADS; ++i) {
        rc = pthread_create(&thread_id[i], NULL, PrintHello, i);
        if (rc) {
            printf("\n ERROR: return code from pthread_create is %d \n", rc);
            exit(1);
        }
        printf("\n I am thread %d. Created new thread (%d) in iteration %d ... \n",
            (int) pthread_self(), (int) thread_id[i], i);
        sleep(1);
    }
    pthread_exit(NULL);
}
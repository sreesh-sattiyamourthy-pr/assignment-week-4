#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
#define N 10000

int sum = 0;
pthread_mutex_t lock;

void* partial_sum(void* arg) {
    int start = *(int*)arg;
    int local_sum = 0;

    for (int i = start; i < N; i += NUM_THREADS) {
        local_sum += i;
    }

    pthread_mutex_lock(&lock);
    sum += local_sum;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, partial_sum, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final Sum = %d\n", sum);
    pthread_mutex_destroy(&lock);
    return 0;
}

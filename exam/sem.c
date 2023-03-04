#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t mutex;
char str[10];

void * thread1(void * arg){
    sem_wait(&mutex);

    printf("Entering critical section....");
    for(int i =0; i<strlen(str); i++){
        str[i] = str[i] + 1;

    }
    printf("\nEncoded string: %s",str);
    printf("\nExiting critical section....");

    sem_post(&mutex);

}

void * thread2(void * arg){
    sem_wait(&mutex);

    printf("\nEntering critical section...");
    for(int i = 0; i<strlen(str); i++){
        str[i] = str[i] - 1;
    }
    printf("\nDecoded string: %s",str);
    printf("Exting criticl section....");

    sem_post(&mutex);
}

int main(){
    printf("Enter a string: ");
    scanf("%s",str);

    sem_init(&mutex,0,1);

    pthread_t t1,t2;

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&mutex);

    return 0;

}
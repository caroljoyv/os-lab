#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHMSIZE 100

int main(){
    void * shared_memory;
    int shmid;
    char buffer[100];
    key_t key = 1234;

    //creating shared  memory
    shmid = shmget(key, SHMSIZE, IPC_CREAT|0666);
    printf("\nShared memory created wit id: %d\n",shmid);

    //attaching to shared memory
    shared_memory = shmat(shmid, NULL, 0);
    printf("\nAttached to shared memory at %p\n",shared_memory);

    //writing to shared memory
    printf("\nEnter a string to write to the shared memory: ");
    scanf("%s",buffer);
    strcpy(shared_memory, buffer);
    printf("\n String written to the shared memory is: %s\n",(char*)shared_memory);

    return 0;




}
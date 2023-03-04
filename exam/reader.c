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

    //creating a shared memory
    shmid = shmget(key, SHMSIZE, IPC_CREAT|0666);
    printf("shared memory created with id: %d\n",shmid);

    //attaching to the shared memory
    shared_memory = shmat(shmid, NULL, 0);
    printf("\nattached to shared memory at %p\n",shared_memory);

    //readin from shared memory
    printf("String from shared memory is: %s\n",(char *)shared_memory);
    strcpy(buffer, (char*)shared_memory);

    //to reverse the string
    int length = strlen(buffer);
    char reverse[100];
    int j = length -1;
    for(int i =0; i<length; i++){
        reverse[i] = buffer[j];
        j --;
    }
    printf("\n the reversed string is: %s",reverse);
    
    return 0;


}
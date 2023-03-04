//client.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
struct shmseg{
    char data[100];
    int complete;
};
void main()
{
    struct shmseg *shm;
    char b[100];
    int shmid, i, j=0, l;
    key_t key = 1122;
    shmid = shmget(key, 1024, 0666|IPC_CREAT);
    printf("Key of shm %d\n", shmid);
    shm = shmat(shmid, NULL, 0);
    printf("Process attached at %p\n", shm);
    printf("Data read from shm %s\n", shm->data);
    l = strlen(shm->data);
    for(i=l-1;i>=0;i--)
    {
        b[i] = shm -> data[j];
        j++;
    }
    b[i] = '\0';
    printf("Reversed string: %s\n", b);
    strcpy(shm->data, b);
    shm -> complete = 1;
}
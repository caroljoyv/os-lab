#include<stdio.h>
#include<stdlib.h>

int mutex = 1, empty = 5, full = 0, temp = 0;

void producer(){
    mutex --;
    full ++;
    empty --;
    temp ++;
    printf("\nProducer produces %d",temp);
    mutex ++;
}

void consumer(){
    mutex --;
    empty ++;
    full --;
    printf("\nconsumed value is %d",temp);
    temp --;
    mutex ++;
}

int main(){
    int n, i;
    while(1){
         printf("\nEnter 1 for producer and 2 for cumsumer and 3 to exit: ");
    scanf("%d",&n);
    switch(n){
        case 1: if( mutex ==1 && empty!= 0){
            producer();
        }
        else{
            printf("\nBuffer is full");
        }
        break;
        case 2:if(mutex ==1 && full != 0){
            consumer();
        }
        else{
            printf("Buffer is empty");
        }
        break;
        case 3:
        exit(0);
    }
    }
   
    return 0 ;
}
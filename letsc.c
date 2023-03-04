#include<stdio.h>

void fruits(int num){
    switch(num){
        case 1: printf("Apple \n");
        break;
        case 2: printf("Orange\n");
        break;
        case 3: printf("watermelon\n");
        break;
        default : printf("Enter a valid numbers!!");
        
    }
}

int main(){
    int num;
    printf("Enter a number between 1 and 3: ");
    scanf("%d ",&num);
    fruits(num);

    return 0;
}

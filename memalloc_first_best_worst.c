#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int nb,nf,block[MAX],file[MAX],f[MAX];

void read(){
    printf("\nEnter the number of blocks: ");
    scanf("%d",&nb);
    printf("\nEnter the the number of files: ");
    scanf("%d",&nf);
    
    for(int i =0;i<nb;i++){
        printf("\nEnter the size of block %d: ",i+1);
        scanf("%d",&block[i]);
    }
    
    for(int 1=0;i<nf;i++){
        printf("\nEnter the size of file %d: ",i+1);
        scanf("%d",&file[i]);
    }
}


void display(){

}

void first_fit(){
    for(int i=0;i<nf;i++){
        for(int j=0;j<nb;j++){
            
        }
    }
}

int main(){
    int ch;
    printf("1.first fit\n2.best fit\n3.worst fit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            read();
            first_fit();
            break;
        case 2:
            read();
            best_fit();
            break;
        case 3:
            read();
            worst_fit();
            break;
        default : printf("Enter valid choice!!!");
    
    }
    display();
    return 0;
}
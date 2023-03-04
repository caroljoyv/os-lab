#include<stdio.h>
#define max 10

int nf, nb, temp, lowest = 100000, highest = 0, block[max], frag[max], file[max], i, j, bn[max], f[max], f1;

void first_fit(){
    for(i=1;i<=nf;i++){
        f1=0;  
        for(j=1;j<=nb;j++){
            if(f[j]!=1){ //block has no process
                temp = block[j] - file[i];
            }
            if(temp >=0){
                bn[i] = j;
                f1 = 1;
                break;
            }
        }
    }

    if(f1 == 1){
        frag[i] = temp;
        f[bn[i]] = 1;
    }
    else{
        frag [i] = -1;
        bn[i] = -1;
        block
    }


}


void best_fit(){
    for(i=1;i<nf;i++){
        f1 = 0;
        for(j=1;j<=nb;j++){
            if(f[j] != 1){
                temp = block[j] - file[i];
            }
        }
    }


}

void worst_fit(){
    for(i=1;i<=nf;i++){
        f1=0;
        for(j=1;j<=nb;j++){
            if(f[j] != 1){
                temp = block[j] - file[i];
            }
        }
    }



}


void read(){



}
void display(){



}

int main(){
    int ch;
    while(1){
        printf("\n1.first fit\n2.best fit\n3.worst fit");
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
       }
       display();
    }

}
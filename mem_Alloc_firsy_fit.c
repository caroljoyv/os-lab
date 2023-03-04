#include<stdio.h>

int main(){
    int pno,bno,psize[10],bsize[10],allocation[10],frag[10];
    for(int i=0;i<10;i++){
        allocation[i] = -1;

    }
    printf("Enter pno:");
    scanf("%d",&pno);
    printf("enter process sizes:");
    for(int i = 0;i<pno;i++){
        scanf("%d",&psize[i]);
    }

    printf("Enter bno:");
    scanf("%d",&bno);
    printf("enter block sizes:");
    for(int i = 0;i<bno;i++){
        scanf("%d",&bsize[i]);
    }

    for(int i =0;i<pno;i++){
        for(int j =0;j<bno;j++){
            if(bsize[j] >= psize[i]){
                allocation[i] = j;
                bsize[j] = bsize[j] - psize[i];
                break;
            }
        }
    }

    printf("\nProcessno\tprocess size\tblockno\t\n");
    for(int i =0;i<pno;i++){
        printf("%d\t\t%d\t\t",i+1,psize[i]);
        if(allocation[i]!=-1){
            printf("%d\n",allocation[i]+1);

        }
        else{
            printf("Not allocated\t\n");
        }
        
    }

}











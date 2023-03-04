#include<stdio.h>
#include<math.h>
#include<stdio.h>


int head, n_req, req[10];



void main(){
    printf("\nEnter head: ");
    scanf("%d",&head);
    printf("\nEnter n_req: ");
    scanf("%d",&n_req);
    printf("\nEnter the request queue: ");
    for(int i =0;i<n_req;i++){
        scanf("%d",&req[i]);
    }

    int time =0;
    
    for(int i=0;i<n_req;i++){
        time = time + abs(head-req[i]);
        head = req[i];
    }

    printf("\nTime is:  %d ",time);

}
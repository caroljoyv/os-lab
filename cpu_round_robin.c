#include<stdio.h>
#define MAXSIZE 10

int n,i;
typedef struct process{
    int pid;  //process id
    int bt;//burst time
    int wt;//waiting time to calculate
    int tt;//turnaround time to calculate
}process;
process p[MAXSIZE];







void main(){
    printf("Eter the number of processes: ");
    scanf("%d",&n);
    
    for(i = 0;i<n;i++){
        printf("Enter the process id of %d th process: ",i+1);
        scanf("%d",&p[i].pid);
    }
    for(i = 0;i<n;i++){
        printf("Enter the burst time of %d th process: ",i+1);
        scanf("%d",&p[i].bt);
    }
      



    printf("pid  bt  wt tt\n");
    for(i=0;i<n;i++){
        printf("%d  %d  %d  %d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);

    }
   
}
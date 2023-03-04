#include<stdio.h>
#define MAXSIZE 10

int n;

struct process{
    int pid;
    int bt;
    int tt;
    int wt;
    int pri;
}p[MAXSIZE],temp;

void sort(){
    
    for(int i = 1; i<n; i++){
        for(int j = 0; j<n-i; j++){
            if(p[j].pri > p[j+1].pri){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void waiting_time(){
    p[0].wt = 0;
    for(int i=0;i<n; i++){
        p[i].wt = p[i-1].wt + p[i-1].bt;
    }
}

void turn_around_time(){
    p[0].tt = p[0].bt;
    for(int i =0; i<n; i++){
        p[i].tt = p[i-1].tt + p[i].bt;
    }
}

float avg_waiting_time(){
    float total = 0;
    for(int i =0; i<n; i++){
        total = total + p[i].wt;
    }
    return total/n;
}

float avg_turn_around_time(){
    float total = 0;
    for(int i =0; i<n; i++){
        total = total + p[i].tt;
    }
    return total/n;
}


int main(){
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("\nEnter the pid of processes: ");
    for(int i=0; i<n; i++){
        scanf("%d",&p[i].pid);
    
    printf("\nEnter the burst time of processes: ");
    for(int i=0; i<n; i++){
        scanf("%d",&p[i].bt);
    }

    printf("\nEnter the priority of processes: ");
    for(int i=0; i<n; i++){
        scanf("%d",&p[i].pri);
    }
    sort();
    waiting_time();
    turn_around_time();
    float avg_wt = avg_waiting_time();
    float avg_tt = avg_turn_around_time();

    printf("pid  pri  bt  wt  tt");
    for(int i=0; i<n; i++){
        printf("\n%d %d %d %d %d\n",p[i].pid,p[i].pri,p[i].bt,p[i].wt,p[i].tt);
    }
    printf("\n avg wt = %f and avg tt = %f", avg_wt, avg_tt);




    return 0;
}
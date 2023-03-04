#include<stdio.h>
#define MAXSIZE 10

int n;

struct process{
    int pid;
    int bt;
    int tt;
    int wt;
}p[MAXSIZE],temp;

void sort(){
    
    for(int i = 0; i<n-1; i++){
        for(int j = 1; j<n; j++){
            if(p[i].bt > p[j].bt){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
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
    }
    printf("\nEnter the burst time of processes: ");
    for(int i=0; i<n; i++){
        scanf("%d",&p[i].bt);
    }

    sort();
    waiting_time();
    turn_around_time();
    float avg_wt = avg_waiting_time();
    float avg_tt = avg_turn_around_time();

    printf("pid bt wt tt");
    for(int i=0; i<n; i++){
        printf("\n%d %d %d %d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
    }
    printf("\n avg wt = %f and avg tt = %f", avg_wt, avg_tt);




    return 0;
}
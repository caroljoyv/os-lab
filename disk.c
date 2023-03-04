#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int m=200, h, a[20], n,stime;
void fcfs(){
    stime = abs(h-a[0]);
    for(int i=0;i<n-1;i++){
        stime = stime + abs(a[i] - a[i+1]);
        
    }

    printf("\n fcfs = %d",stime);
}

void scan(){
    stime = m-h;
    int small = a[0];
    for(int i =0;i<n;i++){
        if(small > a[i] ){
            small = a[i];
        }
    }
    stime = stime + (m-small);
    printf("\nscan %d",stime);
}

void cscan(){
    stime = m -h;
    int k = 0;
    for(int i =0;i<n;i++){
        if(a[i]>h){
            k = a[i-1];
            printf("%d",k);
        }
        break;
    }
    stime = stime +m+k;
    printf("\n cscan :%d",stime);

}





int main(){
    printf("\nhead: ");
    scanf("%d",&h);
    printf("\nno of request: ");
    scanf("%d",&n);
    printf("Enter request: ");
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
    }
    fcfs();
    scan();
    cscan();
    return 0;
}
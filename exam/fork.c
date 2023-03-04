#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    char str[10];
    pid_t id_of_newly_created_process;
    printf("\nEnter a string: ");
    scanf("%s",str);

    id_of_newly_created_process = fork();

    if(id_of_newly_created_process <0 ){
        printf("\nUncessful attempt to create child process");
    }
    else if(id_of_newly_created_process == 0){
        int length = strlen(str);
        int j = length-1;
        char reverse[10];
        for(int i = 0; i<length; i++){
            reverse[i] = str[j];
            j --;
        }
        //reverse[length] = '\0';
        printf("\nThe reversed string is: %s",reverse);
    }

    else{
        wait(NULL);
        printf("\nChild process has completed execution and returned to parent!");
    }



}
#include <stdio.h>
#include <stdlib.h>
const int MAX = 100;
int question1(char *pattern,char * s);
void question2(FILE * fp);
int main()
{

    char c[1000];
    char strTotal[MAX][MAX];
    int size = 0;
    FILE *fptr;

    fptr = fopen("demoText1.txt", "r");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fscanf(fptr,"%[^\0]", c);

    int leng = 0;
    for(int i = 0; i<= strlen(c) - 1; i++){
        strTotal[size][leng] = c[i];
        leng++;
        if(c[i] == 10){
            leng--;
            strTotal[size][leng] = 0;
            size++;
            leng = 0;
        }else if( i == (strlen(c) - 1)){
            strTotal[size][leng] = 0;
            size++;
            leng = 0;
        }
    }

    int choice;
    char buffer;
    do{
        printf("\nMENU:");
        printf("\n1.Q1");
        printf("\n2.Q2");
        printf("\n3.EXIT");
        do{
            printf("\nVui long nhap lua chon: ");
            scanf("%d", &choice);
            scanf("%c", &buffer);
            fflush(stdin);
            if(buffer != 10){
                printf("\nVui long nhap so: ");
            }
        }while(buffer != 10);
        switch(choice){
            case 1:{
                printf("\n%d", question1(strTotal[1], strTotal[0]));
                break;
            }
            case 2:{
                question2(fopen("demoText1.txt", "r"));
                break;
            }
            case 3:{
                printf("\nSee you next time");
                break;
            }
            default: {
                printf("\nVui long nhap tu 1 - 3 thoi:");
                break;
            }
        }
    }while(choice != 3);
    return 0;
}
int question1(char *pattern,char * s){
    for(int i = 0; i <= strlen(pattern) - 1; i++){
        if(pattern[i] == s[0]){
            int pos = i;
            for(int j = 0; j<= strlen(s) - 1; j++){
                if(pattern[pos] != s[j]){
                    break;
                }
                pos++;
                if(j == strlen(s) - 1){
                    return i;
                }
            }
        }
    }
    return -1;
}
void question2(FILE * fp){

    char c[1000];
    c[0] = 0;
    char strTotal[MAX][MAX];
    int size = 0;
    if(fp == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fscanf(fp,"%[^\0]", c);

    int leng = 0;
    for(int i = 0; i<= strlen(c) - 1; i++){
        strTotal[size][leng] = c[i];
        leng++;
        if(c[i] == 10){
            leng--;
            strTotal[size][leng] = 0;
            size++;
            leng = 0;
        }else if( i == (strlen(c) - 1)){
            strTotal[size][leng] = 0;
            size++;
            leng = 0;
        }
    }

    int max = strlen(strTotal[0]);
    for(int i = 0; i<= size - 1; i++){
        if(max < strlen(strTotal[i])){
            max = strlen(strTotal[i]);
        }
    }

    for(int i = 0; i<= size - 1; i++){
        if(max == strlen(strTotal[i])){
            printf("%d  %d",i,strlen(strTotal[i]));
            return;
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "AQueue/AQueue.h"

AQueue *aq  = NULL;


typedef struct string
{
    char value[11];
    int length;
} String;

int num = 1;

void printString(void *q){
    String s = *(String*)q;
    printf("%d.",num);
    for(int i = 0  ; i < s.length ; i ++){
        printf("%c",s.value[i]);

    }
    printf("\n");
    num ++;
}
void printStringOnly(String q){
    for(int i = 0  ; i < q.length ; i ++){
        printf("%c",q.value[i]);

    }
    num ++;
}

void outputA(){
    if(aq ==NULL){
        return;
    }
    if(IsEmptyAQueue(aq)){
        printf("The queue is empty !\n");
    }else{
        num = 1;
        printf("The queue : \n");
        TraverseAQueue(aq ,printString);
    }

}

int startA(){
    if(aq == NULL){
        aq = malloc(sizeof(AQueue));
        InitAQueue(aq , sizeof(String));
    }
    system("cls");
    outputA();
    printf("What would you like to do?\n");
    printf("1.Queue in;\n");
    printf("2.Queue out;\n");
    printf("3.Exit;\n");

    while (1){
        char *input1 = malloc(sizeof(char)*1024);
        char *input = malloc(sizeof(char)*1024);
        scanf("%[^\n]",input);
        getchar();
        String *s = malloc(sizeof(String));
        switch (*input - '0'){
            case 1:
                printf("Please enter the value : (Item Size limited : 10)\n");
                scanf("%[^\n]",input1);
                getchar();

                int l = 0;
                for(int i = 0 ; i < 10 ; i ++){
                    if(*(input1+i) != '\0'){
                        s->value[i] = *(input1+i);
                        l ++;
                    } else{
                        break;
                    }
                }
                s->length = l;
                if(EnAQueue(aq ,&s) == TRUE){
                    printf("Complete !\n");
                    system("pause");
                    return 1;
                }else{
                    printf("Error !\n");
                    printf("Maybe the queue is full.\n");
                    system("pause");
                    return 1;
                };
                break;
            case 2:
                if(DeAQueue(aq ,&s) == TRUE){
                    printf("Complete !\n");
                    printf("The item is ");
                    printStringOnly(*s);
                    printf("\n");
                    system("pause");
                    return 1;
                }else{
                    printf("Error !\n");
                    printf("Maybe the queue is empty.\n");
                    system("pause");
                    return 1;
                }
                break;
            case 3:
                printf("Bye Bye ~\n");
                system("pause");
                return 0;
            default:
                printf("Please enter the right num !!\n");
                continue;
        }
    }




}


int main() {

    printf("Welcome !! I am Guangchuan Lin\n");
    printf("This is my second homework ! \n");
    printf("Hope it can satisfy you ! \n");
    system("pause");

    system("cls");
    while (startA()){}



    return 0;
}



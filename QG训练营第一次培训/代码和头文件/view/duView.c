/**
 * Created by HeYanLe on 2020/4/3 0003.
 * https://github.com/heyanLE
 */

#include "../head/duView.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DuLinkedList p = NULL;

int DuChar2int(char *c ,int *i){
    int num = 0;
    int isNegative = 0;
    char *pp = c;
    if (*pp == '-'){
        pp++;
        isNegative = 1;
    }
    while (*pp){
        int n = *pp - '0';
        if( n < 0 || n > 9){
            return 0;
        }
        num = num*10+n;
        pp ++;
    }
    if (isNegative){
        *i = -num;
    }else{
        *i = num;
    }
    return 1;


}


void DuVisit(ElemType e){
    printf("%d\n",e);
}

/**
 * show menu
 * @param p linkedList
 */
int duStart(){
    system("cls");
    if (p == NULL){
        duInput(&p);
    }
    printf("Linked List : ");
    duOutput(&p);
    printf("\n");
    printf("What would you like to do :\n");
    printf("1.Insert after;\n");
    printf("2.Insert before;\n");
    printf("3.Traverse it;\n");
    printf("4.Delete one node;\n");
    printf("5.Destroy it - Input again;\n");
    printf("6.Exit;\n\n");
    printf("Please enter the number :");


    while (1){

        char *inputC = malloc(sizeof(char)*5);
        gets(inputC);
        int i = inputC[0] - '0';

        if(inputC[0] == '1' && inputC[1] == '0'){
            i = 10;
        }else if(inputC[1] != '\0'){
            printf("Please enter the right number :");
            continue;
        }


        if ( i <= 0 || i > 6){
            printf("Please enter the right number :");
            continue;
        }
        DuLinkedList ii = malloc(sizeof(DuLinkedList));
        enum Status status;
        switch (i){
            case 1:
                duInput(&ii);
                status = InsertAfterList_DuL(p ,ii);
                if(status == SUCCESS){
                    printf("Insert Complete !\n");
                }else{
                    printf("Insert Error !!\n");
                }
                printf("\n");system("pause");
                return 1;
            case 2:
                duInput(&ii);
                status = InsertBeforeList_DuL(p ,ii);
                p = ii;
                if(status == SUCCESS){
                    printf("Insert Complete !\n");
                }else{
                    printf("Insert Error !!\n");
                }
                printf("\n");system("pause");
                return 1;
            case 3:
                TraverseList_DuL(p ,DuVisit);
                printf("\n");
                system("pause");
                return 1;
                break;
            case 4:
                printf("Please enter a index ( first is 0 ) :");
                char *inputCCC = malloc(sizeof(char)*5);
                gets(inputCCC);
                int iii = 0;
                if(DuChar2int(inputCCC ,&iii)){
                    DuLinkedList  d = p;
                    if(iii == 0){
                        printf("Delete complete, the deleted node is %d",p->data);
                        p->next = p->next->next;
                        if(p->next != NULL){
                            p->next->prior = p;
                        }
                        printf("\n");system("pause");
                        return 1;
                    }
                    for(int iiii = 0 ; iiii < iii+1 ; iiii++){
                        if (d == NULL){
                            printf("Please enter a exist index !");
                            printf("\n");system("pause");
                            return 1;
                        }
                        d = d->next;
                    }
                    int e = 0;
                    status = DeleteList_DuL(d ,&e);
                    if (status == SUCCESS){
                        printf("Delete complete, the deleted node is %d",e);
                        printf("\n");system("pause");
                        return 1;
                    }else{
                        printf("Delete Error !");
                        printf("\n");system("pause");
                        return 1;
                    }
                }else{
                    printf("Please enter the right number !");
                    printf("\n");system("pause");
                    return 1;
                }
                
                break;
            case 5:
                DestroyList_DuL(&p);
                p = NULL;
                printf("Destroy complete!");
                printf("\n");
                system("pause");
                return 1;
            case 6:
                printf("Bye bye ~");
                printf("\n");
                system("pause");
                return 0;
            default:
                return 1;
        }


    }


};

/**
 * input a LinkedList
 * @param p linkedList
 */
void duInput(DuLinkedList *pp){
    free(*pp);

    printf("Please enter the linked List \n");
    printf("It would end with enter 'end' \n");

    int i = 1;

    DuLinkedList n = NULL;
    DuLinkedList f = NULL;
    while(1){

        printf("%d.",i);
        char *inputC = malloc(sizeof(char)*5);
        gets(inputC);



        if(strcmp(inputC ,"end") == 0){
            if (*pp == NULL){
                printf("Please enter more than one node !");
                continue;
            }
            break;
        }

        int ii = 0;
        if(inputC[0] == 0){
            continue;
        }
        if(DuChar2int(inputC ,&ii) ){
            if (n == NULL){
                *pp = malloc(sizeof(DuLNode));
                n = *pp;
                n->data = ii;
                n->next =NULL;
                n->prior = NULL;
                f = n;
            }else{
                n->next = malloc(sizeof(DuLNode));
                n->next->prior = n;
                n = n->next;
                n->data = ii;
                n->next = NULL;
            }
            i ++;
            continue;
        }else{
            printf("Please enter the right value ! \n");
            continue;
        }


    }
};

/**
 * output a LinkedList
 * @param p linkedList
 */
void duOutput(DuLinkedList *nn){

    DuLinkedList n = *nn;
    while ( n != NULL){
        printf("%d",n->data);
        if (n->next != NULL){
            printf("-");
        }
        n = n->next;
    }

};




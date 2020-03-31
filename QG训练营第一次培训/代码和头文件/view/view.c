/**
 * Created by HeYanLe on 2020/3/30 0030.
 * https://github.com/heyanLE
 */

#include "../head/view.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList p = NULL;

int char2int(char *c ,int *i){
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

int viI = 1;

void visit(ElemType e){
    printf("%d.%d\n",viI ,e);
    viI ++;
}

/**
 * show menu
 * @param p linkedList
 */
int start(){
    system("cls");
    if (p == NULL){
        input(&p);
    }
    printf("Linked List : ");
    output(&p);
    printf("\n");
    printf("What would you like to do :\n");
    printf("1.Insert after;\n");
    printf("2.Delete first by value;\n");
    printf("3.Traverse it;\n");
    printf("4.Check is it exist;\n");
    printf("5.Reverse it;\n");
    printf("6.Check is it loop;\n");
    printf("7.Reverse even it;\n");
    printf("8.Find the middle node;\n");
    printf("9.Destroy it - Input again;\n");
    printf("10.Exit;\n\n");

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


        if ( i <= 0 || i > 10){
            printf("Please enter the right number :");
            continue;
        }
        LinkedList ii = malloc(sizeof(LinkedList));
        enum Status status;
        switch (i){
            case 1:
                input(&ii);
                status = InsertList(p ,ii);
                if(status == SUCCESS){
                    printf("Insert Complete !\n");
                }else{
                    printf("Insert Error !!\n");
                }
                printf("\n");system("pause");
                
                return 1;
            case 2:
                printf("Please enter your value :");
                char *inputC2 = malloc(sizeof(char)*5);
                gets(inputC2);
                int inputI2 = 0;
                if(char2int(inputC2 ,&inputI2)){
                    status = DeleteList(p ,&inputI2);
                    if (status == SUCCESS){
                        printf("The result is:");
                        output(&p);
                        printf("\n");system("pause");
                        return 1;
                    }else{
                        printf("Error !!");
                        printf("\n");system("pause");
                        return 1;
                    }
                }else{
                    printf("Please enter the right value !!");
                    printf("\n");system("pause");
                    return 1;
                }

                break;
            case 3:
                viI = 1;
                TraverseList(p ,visit);
                printf("\n");
                system("pause");
                return 1;
                break;
            case 4:
                printf("Please enter your value :");
                char *inputC3 = malloc(sizeof(char)*5);
                gets(inputC3);
                int inputI3 = 0;
                if(char2int(inputC3 ,&inputI3)){
                    LinkedList ll = p;
                    status = SearchList(ll ,inputI3);
                    if (status == SUCCESS){
                        printf("Is is exist !\n");system("pause");
                        return 1;
                    }else{
                        printf("Is is not exist !");
                        printf("\n");system("pause");
                        return 1;
                    }
                }else{
                    printf("Please enter the right value !!");
                    printf("\n");system("pause");
                    return 1;
                }
                break;
            case 5:
                status = ReverseList(&p);
                if (status == SUCCESS){
                    printf("The result is :");
                    output(&p);
                    printf("\n");system("pause");
                    return 1;
                }else{
                    printf("Error !!");
                    printf("\n");system("pause");
                    return 1;
                }
                break;
            case 6:
                status = IsLoopList(p);
                if (status == SUCCESS){
                    printf("It is Loop !");
                    printf("\n");system("pause");
                    return 1;
                }else{
                    printf("It is not Loop !");
                    printf("\n");system("pause");
                    return 1;
                }
                break;
            case 7:
                printf("The result is :");
                LinkedList lll = ReverseEvenList(&p);
                p = lll;
                output(&lll);
                printf("\n");
                system("pause");
                return 1;
                break;
            case 8:
                printf("The result is :");
                LinkedList lllf = FindMidNode(&p);
                output(&lllf);
                printf("\n");
                system("pause");
                return 1;
            case 9:
                DestroyList(p);
                p = NULL;
                printf("Destroy complete!");
                printf("\n");
                system("pause");
                return 1;
                break;
            case 10:
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
void input(LinkedList *pp){
    free(*pp);

    printf("Please enter the linked List \n");
    printf("It would end with enter 'end' \n");

    int i = 1;

    LinkedList n = NULL;
    LinkedList f = NULL;
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
        if(char2int(inputC ,&ii) ){
            if (n == NULL){
                *pp = malloc(sizeof(LNode));
                n = *pp;
                n->data = ii;
                n->next =NULL;
                f = n;
            }else{
                n->next = malloc(sizeof(LNode));
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
void output(LinkedList *nn){

    LinkedList n = *nn;
    while ( n != NULL){
        printf("%d",n->data);
        if (n->next != NULL){
            printf("-");
        }
        n = n->next;
    }

};


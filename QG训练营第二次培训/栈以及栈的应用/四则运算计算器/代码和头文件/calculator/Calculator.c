/**
 * Created by HeYanLe on 2020/4/4 0004.
 * https://github.com/heyanLE
 */

#include "../head/Calculator.h"
#include "../head/LinkStack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

LinkStack *linkStack = NULL;


int str2int(char *input ,int *output){

    int isN = 0;
    int isZ = 0;
    int r = 0;
    int o = 0;
    if(*input == '-'){
        isN = 1;
        input ++;
        r ++;
    }
    if(*input == '+'){
        input ++;
        isZ = 1;
        r ++;
    }
    while (*input && *input != ' '){

        int i = *input - '0';
        if( i >= 0 && i <= 9 ){
            o*= 10;
            o+= i;
            r ++;
        }else{
            break;
        }

        input ++;
    }
    if(output != NULL){
        if(isN){
            o = -o;
        }
        *output = o;
    }

    if(r == 1 && isN){
        return  0;
    }
    if(r == 1 && isZ == 1){
        return 0;
    }
    return r;
}

int char2int(char input ,int *output){
    int i = input - '0';
    if(i >= 0 && i <= 9){
        if(output != NULL){
            *output = i;
        }

        return 1;
    }
    return 0;
}

int check(char *input){

    char *p = input;
    int s = 0;

    if(!char2int(*p ,NULL)
        && *p != '+'
        && *p != '-'){
        return 0;
    }
    int isF = 0;
    while(*p){
        if (char2int(*p ,NULL)){
            isF = 0;
            p ++;
            continue;
        }
        switch (*p){
            case '+':
            case '-':
                if(isF == 2){
                    return 0;
                }
            case '*':
            case '/':
                if(*p == '*' || *p == '/'){
                    if(isF == 1){
                        return 0;
                    }
                }
                isF ++;
            case '(':

                if(*p == '(') {
                    isF = 0;
                    s -=1;
                    if(char2int(*(p-1),NULL)){
                        return 0;
                    }
                    if(!char2int(*(p+1),NULL) && *(p+1) != '-'){
                        return 0;
                    }
                }


            case ')':

                if(*p == ')'){
                    s +=1;
                    isF = 0;
                    if(!char2int(*(p-1),NULL)
                       || char2int(*(p+1),NULL)){
                        return 0;
                    }
                }
                p ++;
                continue;
            default:
                return 0;
        }
    }
    p --;
    if(!char2int(*p ,NULL) && *p != ')'){
        return 0;
    }

    return (s == 0);
}

int operatorLevel(char c1){
    //printf("operatorLevel => %c \n",c1);
    switch (c1){
        case '*':
        case '/':
            return 1;
        case '+':
        case '-':
            return 0;
        default:
            return -1;
    }
}

void infix2suffix(char *input ,char *output){

    char *cp = input;
    char *r = output;
    char *rf = r;
    int isY = 0;
    while(*cp){

        int ii = 0;
        int ll = str2int(cp ,&ii);
        if(ll > 0 && !char2int(*(cp-1),NULL)){ // 运算数
            for(int j = 0 ; j < ll ; j ++){
                *r = *cp;
                r ++;
                cp ++;
            }
            *r = ' ';
            r ++;
        }else if (*cp == '('){// 左括号
            pushLStack(linkStack ,*cp);
            cp ++;
        }else if (*cp == ')' ){// 右括号
            int cc = '0';
            while (cc != '('){
                popLStack(linkStack ,&cc);
                if(cc != '('){
                    *r = (char)cc;
                    r ++;
                    *r = ' ';
                    r ++;
                }
            }
            cp ++;
        }else {// 运算符

            while(1){
                int ccc = '0';
                if( getTopLStack(linkStack ,&ccc) == ERROR){
                    ccc = '0';
                }
                if(operatorLevel(*cp) > operatorLevel((char)ccc)
                   || ccc == '('){
                    pushLStack(linkStack , *cp);
                    break ;
                }else{
                    popLStack(linkStack ,&ccc);
                    *r = (char)ccc;
                    //printf("*r = %c\n",(char) ccc);
                    r ++;
                    *r = ' ';
                    r ++;
                }
            }

            cp ++;
        }

    }


    int p = 0;

    while (popLStack(linkStack ,&p) == SUCCESS){
        *r = (char)p;
        r ++;
        *r = ' ';
        r ++;
    }

}

int count(char *input ,int *output){

    clearLStack(linkStack);
    while (*input){
        int ii = 0;
        int ll = str2int(input ,&ii);
        if(ll > 0) { // 运算数
            pushLStack(linkStack ,ii);
            input += ll;
        }else{
            int b = 0;
            int a = 0;
            int c = 0;
            popLStack(linkStack ,&b);
            popLStack(linkStack ,&a);
            switch (*input){
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = a - b;
                    break;
                case '*':
                    c = a * b;
                    break;
                case '/':
                    if (b == 0){
                        return 0;
                    }
                    c = a/b;
                    break;
            }
            input ++;
            pushLStack(linkStack ,c);
        }
        input ++;
    }
    popLStack(linkStack ,output);
    return 1;
}



int start(){

    system("cls");

    if(linkStack == NULL){
        initLStack(&linkStack);
    }
    if(linkStack == NULL){
        printf("LinkStack is NULL \n");
    }
    printf("You can enter 'end' to exit\n");
    printf("Please enter your formula :\n");

    while(1){
        char *input = malloc(sizeof(char)*1024);
        scanf("%[^\n]",input);
        getchar();
        if(strcmp(input, "end") == 0){
            printf("Bye bye ~\n");
            system("pause");
            return 0;
        }
        if(! check(input)){
            printf("Please enter the right formula :\n");
            continue;
        }

        char *r = malloc(sizeof(char)*1024);
        infix2suffix(input ,r);
        int c = 0;
        int i = count(r ,&c);
        if(i){
            printf("Reverse Polish :%s\n",r);
            printf("Result :%s=%d\n",input,c);
            system("pause");
            return 1;
        }else{
            printf("Count Error !!!\n");
            system("pause");
            return 1;
        }


    }




}

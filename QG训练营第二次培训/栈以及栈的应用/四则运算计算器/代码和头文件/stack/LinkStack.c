/**
 * Created by HeYanLe on 2020/4/4 0004.
 * https://github.com/heyanLE
 */

#include "../head/LinkStack.h"
#include <stdlib.h>
#include <stdio.h>

//链栈
Status initLStack(LinkStack **s){
    *s = malloc(sizeof(LinkStack));
    (*s)->count = 0;
    (*s)->top = NULL;
    if ((*s) == NULL){
        return ERROR;
    }
    return SUCCESS;
}
Status isEmptyLStack(LinkStack *s){
    if (s == NULL){
        return ERROR;
    }
    if (s->count == 0){
        return SUCCESS;
    }
    return ERROR;
}
Status getTopLStack(LinkStack *s,ElemType *e){
    if (s == NULL){
        return ERROR;
    }
    if (isEmptyLStack(s) == SUCCESS){
        //printf("isEmpty \n");
        return ERROR;
    }
    if(s->top == NULL){
        //printf("top is NULL \n");
        return ERROR;
    }

    *e = s->top->data;
    //printf("getTopLStack => %c \n",*e);
    return SUCCESS;
}
Status clearLStack(LinkStack *s){
    if (s == NULL){
        return ERROR;
    }
    s->count = 0;

    LinkStackPtr lp = s->top;
    LinkStackPtr d = lp;
    while (lp != NULL){
        free(d);
        lp ++;
        d = lp;
    }
    s->top = NULL;
    return SUCCESS;
}
Status destroyLStack(LinkStack *s){
    if (s == NULL){
        return SUCCESS;
    }
    LinkStackPtr lp = s->top;
    LinkStackPtr d = lp;
    while (lp != NULL){
        free(d);
        lp ++;
        d = lp;
    }
    s->top = NULL;
    free(s);
    return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length){
    if (s == NULL){
        return ERROR;
    }
    *length = s->count;
    return SUCCESS;
}
Status pushLStack(LinkStack *s,ElemType data){
    if (s == NULL){
        return ERROR;
    }
    //printf("Push => %c \n",(char) data);
    LinkStackPtr t = malloc(sizeof(StackNode));
    t->next = s->top;
    t->data = data;

    s->top = t;
    (s->count) ++;
    //printf("count => %d \n",s->count);
    return SUCCESS;

}
Status popLStack(LinkStack *s,ElemType *data){
    if (s == NULL){
        return ERROR;
    }
    if (isEmptyLStack(s) == SUCCESS){
        return ERROR;
    }

    *data = s->top->data;
    //printf("Pop => %c \n",(char) *data);
    s->top = s->top->next;
    (s->count) --;
    return SUCCESS;
}

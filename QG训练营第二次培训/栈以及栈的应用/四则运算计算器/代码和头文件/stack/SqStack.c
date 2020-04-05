/**
 * Created by HeYanLe on 2020/4/4 0004.
 * https://github.com/heyanLE
 */

#include "../head/SqStack.h"
#include <stdlib.h>

Status initStack(SqStack *s,int sizes){
    s = malloc(sizeof(SqStack));
    s->elem = malloc(sizeof(ElemType) * sizes);
    s->size = sizes;
    s->top = -1;

    if(s == NULL || s->elem == NULL){
        return ERROR;
    }else{
        return SUCCESS;
    }
}
Status isEmptyStack(SqStack *s){
    if(s == NULL){
        return ERROR;
    }
    if (s->top == -1){
        return SUCCESS;
    }
    return ERROR;
}
Status getTopStack(SqStack *s,ElemType *e){
    if(s == NULL){
        return ERROR;
    }
    if(s->top > s->size-1 || s->top == -1){
        return ERROR;
    }
    *e = s->elem[s->top];
    return SUCCESS;
}
Status clearStack(SqStack *s){
    if(s == NULL){
        return ERROR;
    }
    s->top = -1;
    return SUCCESS;

}
Status destroyStack(SqStack *s){
    free(s->elem);
    free(s);
    return SUCCESS;
}
Status stackLength(SqStack *s,int *length){
    if(s == NULL){
        return ERROR;
    }
    *length = s->size;
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data){
    if(s == NULL){
        return ERROR;
    }
    if((s->top) +1 >= s->size){
        return ERROR;
    }

    (s->top) ++;
    (s->elem)[s->top] = data;
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data){
    if(s == NULL){
        return ERROR;
    }
    if(s->top == -1){
        return ERROR;
    }
    *data = (s->elem)[s->top];
    (s->top) --;
    return SUCCESS;
}


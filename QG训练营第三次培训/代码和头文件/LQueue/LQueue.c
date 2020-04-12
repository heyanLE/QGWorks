/**
 * Created by HeYanLe on 2020/4/11 0011.
 * https://github.com/heyanLE
 */

#include "LQueue.h"
#include <stdlib.h>
#include <string.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q ,int typeSize){
    Q->typeSize = typeSize;
    Q->length = 0;
    Q->front = NULL;
    Q->rear = NULL;
};

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
    if(Q == NULL){
        return;
    }
    Node *f = Q->front;
    while (f != NULL){
        free(f);
        f = f->next;
    }
    free(Q);
};

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
    if(Q == NULL){
        return FALSE;
    }
    if (Q->length > 0){
        return FALSE;
    }
    return TRUE;
};

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){

    if(Q == NULL){
        return FALSE;
    }
    if(Q->length == 0){
        return FALSE;
    }
    if(Q->front == NULL){
        return FALSE;
    }
    *((char**)e) = (char*)Q->front->data;
    return TRUE;
};

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
    if(Q == NULL){
        return -1;
    }
    return Q->length;
};

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
    if(Q == NULL){
        return FALSE;
    }
    if(Q->rear == NULL){
        Q->rear = malloc(sizeof(Node));
    }else{
        Q->rear->next = malloc(sizeof(Node));
        Q->rear = Q->rear->next;
    }

    Q->rear->data = malloc(Q->typeSize);
    strncpy((char*)Q->rear->data ,*((char**)data) ,Q->typeSize);
    Q->rear->next = NULL;
    if(Q->front == NULL){
        Q->front = Q->rear;
    }
    (Q->length) ++;
    return TRUE;

};

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q ,void *e){

    if(Q == NULL){
        return FALSE;
    }
    if(Q->length == 0){
        return FALSE;
    }
    if(Q->front == NULL){
        return FALSE;
    }
    *((char**)e) = *((char**)Q->front->data);
    Q->length --;
    if(Q->length == 0){
        if(Q->front !=NULL){
            free(Q->front);
        }
        if(Q->rear !=NULL){
            free(Q->rear);
        }
        Q->front =NULL;
        Q->rear = NULL;
    }else{
        Node *dd = Q->front->next;
        free(Q->front);
        Q->front = dd;
    }

};

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
    Node *f = Q->front;
    while (f != NULL){
        free(f);
        f = f->next;
    }
    Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0;
};

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    Node *f = Q->front;
    while (f != NULL){
        foo(f->data);
        f = f->next;
    }
};


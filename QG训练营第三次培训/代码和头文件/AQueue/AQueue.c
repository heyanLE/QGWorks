/**
 * Created by HeYanLe on 2020/4/11 0011.
 * https://github.com/heyanLE
 */
#include "AQueue.h"
#include <stdlib.h>
#include <string.h>
/**
 *  @name              void InitAQueue(AQueue *Q)
 *    @description      初始化队列
 *    @param Q          队列指针
 *    @param typeSize   类型占的内存大小
 *  @notice      : None
 */
void InitAQueue(AQueue *Q , int typeSize){
    Q->data = calloc(MAXQUEUE , sizeof(void*));
    for(int i = 0 ; i < typeSize ; i ++){
        Q->data[i] = malloc(typeSize);
    }
    Q->typeSize = typeSize;
    Q->front = -1;
    Q->rear = -1;
    Q->length = 0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q){

    if(Q == NULL){
        return;
    }
    for(int i = 0 ; i < MAXQUEUE ; i ++){
        free((Q->data)[i]);
    }
    free(Q->data);
    free(Q);
};



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
    if (Q == NULL){
        return FALSE;
    }
    if (Q->length == MAXQUEUE){
        return TRUE;
    }
    return FALSE;
};

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
    if (Q == NULL){
        return FALSE;
    }
    if (Q->length == 0){
        return TRUE;
    }
    if(Q->rear == -1 || Q->front == -1){
        return TRUE;
    }
    return FALSE;
};



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e){

    if (Q == NULL || e == NULL){
        return FALSE;
    }
    *((char**)e) = (char*)Q->data[Q->front];
    return TRUE;

};



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
    if(Q == NULL){
        return -1;
    }
    return Q->length;
};



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){
    if(Q == NULL){
        return FALSE;
    }
    if(Q->length == MAXQUEUE){
        return FALSE;
    }
    if(Q->length == 0){
        strncpy((char*)(Q->data[0]) ,*(char**)data ,Q->typeSize);
        Q->front = 0;
        Q->rear = 0;
    }else{
        int index = (Q->rear +1)%MAXQUEUE;
        strncpy((char*)(Q->data[index]) ,*(char**)data ,Q->typeSize);
        Q->rear = index;
    }

    Q->length ++;
    return TRUE;
};



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q ,void *e){
    if(Q == NULL){
        return FALSE;
    }
    if(Q->length == 0){
        return FALSE;
    }
    *((char**)e) = (char*)Q->data[Q->front];
    Q->front = ((Q->front) +1)%MAXQUEUE;
    (Q->length) --;
    if(Q->length == 0){
        Q->rear = -1;
        Q->front = -1;
    }
    return TRUE;
};



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
    if(Q == NULL){
        return;
    }
    Q->rear = -1;
    Q->front = -1;
    Q->length = 0;
};



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){

    if (Q == NULL){
        return FALSE;
    }
    if(Q->length == 0){
        return FALSE;
    }
    for(int i = Q->front ; i <= Q->rear ; i = (i+1)%MAXQUEUE){
        foo(Q->data[i]);
    }
    return TRUE;
};



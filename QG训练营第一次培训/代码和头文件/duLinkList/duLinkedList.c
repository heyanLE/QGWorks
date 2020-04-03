#include "../head/duLinkedList.h"
#include <stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    enum Status status;
    *L = (DuLinkedList )malloc(sizeof(DuLNode));
    if (*L == NULL){
        status = ERROR;
    }else{
        (*L)->data = 0;
        (*L)->next = NULL;
        (*L)->prior = NULL;
        status = SUCCESS;
    }
    return status;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLNode *p = *L;
    while (p != NULL){
        DuLNode *d = p;
        free(d);
        p = p->next;
    }
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    enum Status status;
    DuLNode *f = q;

    if (p == NULL || q == NULL){
        status = ERROR;
    }else{

        while ( q->next != NULL){
            q = q->next;
        }

        q->next = p;
        p->prior = q;




        status = SUCCESS;
    }
    return status;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    enum Status status;
    if (p == NULL || q == NULL){
        status = ERROR;
    }else{

        while ( p->next != NULL){
            p = p->next;
        }


        p->next = q;
        q->prior = p;
        status = SUCCESS;
    }
    return status;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    enum Status status;

    if(p == NULL || p->next == NULL){
        status = ERROR;
        return status;
    }

    *e = p->next->data;
    p->next = p->next->next;
    p->next->prior = p;
    status = SUCCESS;
    return status;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    while (L != NULL){
        (*visit)(L->data);
        L = L->next;
    }
}

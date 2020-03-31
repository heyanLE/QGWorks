/**
 * Created by HeYanLe on 2020/3/30 0030.
 * https://github.com/heyanLE
 */
#include "../head/linkedList.h"
#include <stdlib.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    enum Status status;
    *L = (LinkedList )malloc(sizeof(LNode));
    if (*L == NULL){
        status = ERROR;
    }else{
        (*L)->data = 0;
        (*L)->next = NULL;
        status = SUCCESS;
    }
    return status;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LNode *L) {
    LNode *p = L;
    while (L != NULL && p != NULL){
        L = (*L).next;
        free(p);
        p = L;
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    enum Status status;
    if (p == NULL || q == NULL){
        status = ERROR;
    }else{

        while ( p->next != NULL){
            p = p->next;
        }

        p->next = q;
        status = SUCCESS;
    }
    return status;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    enum Status status;

    if(p == NULL){
        status = ERROR;
        return status;
    }

    LNode *l = NULL;
    LNode *h = p;

    LNode *d = NULL;
    while (h != NULL){
        if (h->data == *e){
            d = h;
            h = h->next;
            if(l!= NULL){
                l->next = h;
                free(d);
            }else{
                p = h;
                free(d);
            }
            break;
        }else{
            l = h;
            h = h->next;
        }
    }

    status = SUCCESS;
    return status;

}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {

    while (L != NULL){
        (*visit)(L->data);
        L = L->next;
    }

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    enum Status status = ERROR;
    while (L != NULL){
        if ((L)->data == e){
            status = SUCCESS;
            return status;
        }
        L = (L)->next;
    }
    return status;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {

    enum Status status;

    if(*L == NULL){
        status = ERROR;
        return status;
    }

    LinkedList p0 = NULL;
    LinkedList p1 = *L;
    LinkedList p2 = p1->next;

    while (p1 != NULL){
        p1->next = p0;
        p0 = p1;
        p1 = p2;
        if (p2 != NULL) {
            p2 = p2->next;
        }
    }
    *L = p0;
    status = SUCCESS;
    return status;

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {

    enum Status status;

    LinkedList pS = L;
    LinkedList pF = L;

    while (pF != NULL){

        if(pS->next == NULL){
            status = ERROR;
            return status;
        }
        pS = pS->next;

        if (pF->next == NULL){
            status = ERROR;
            return status;
        }else{
            pF = pF->next->next;
        }

        if (pF == pS){
            status = SUCCESS;
            return status;
        }

    }
    status = ERROR;
    return status;

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

    if((*L)==NULL){
        return NULL;
    }
    if((*L)->next==NULL){
        return (*L);
    }
    LinkedList pr=*L;
    LinkedList ps=pr->next;
    pr->next=ReverseEvenList(&(ps->next));
    ps->next=pr;
    return ps;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LinkedList FindMidNode(LinkedList *L) {

    LinkedList p0 = *L;
    LinkedList p1 = *L;

    while (p1 != NULL){

        if (p1->next == NULL){
            break;
        }
        p0 = p0->next;
        p1 = p1->next->next;

    }

    return p0;

}



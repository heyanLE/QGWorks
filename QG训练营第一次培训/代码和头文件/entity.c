/**
 * Created by HeYanLe on 2020/4/3 0003.
 * https://github.com/heyanLE
 */

#ifndef QGPROJECTI_ENTITY_C
#define QGPROJECTI_ENTITY_C

#include <stdio.h>

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;


// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;

// define status
typedef enum Status {
    ERROR,
    SUCCESS,
} Status;



#endif //QGPROJECTI_ENTITY_C

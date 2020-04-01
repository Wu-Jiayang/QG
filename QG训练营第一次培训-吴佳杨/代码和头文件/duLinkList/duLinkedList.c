#include "../head/duLinkedList.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if (*L){
		(*L)->next = (*L)->prior = NULL;
		return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode *p = *L,*p1 = *L,*p2;
	int i=2;				//适用于头尾成环
	while (p1){
		if (p1 == p) if (!(--i)) break;
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	*L = NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if (!p || !q) return ERROR;		//判断节点是否存在
	q->next = p;
	q->prior = p->prior;
	p->prior = q;
	if (q->prior) q->prior->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if (!p || !q) return ERROR;		//判断节点是否存在
	q->next = p->next;
	p->next = q;
	q->prior = p;
	if (q->next) q->next->prior = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	DuLNode *p2;
	if (!p || !p->next) return ERROR;
	*e = p->next->data;
	p2 = p->next;
	p->next = p->next->next;
	if (p->next) p->next->prior = p;
	free(p2);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode *p = L;
	if (!L) return;				//适用于头尾成环
	(*visit)(L->data);
	L = L->next;
	while (L && L != p){
		(*visit)(L->data);
		L = L->next;
	}
}

/**
 *  @name        : void visit(ElemType e)
 *	@description : print the value
 *	@param		 : the value e
 *	@return		 : None
 *  @notice      : None
 */
void visit(ElemType e){
	printf("%d ",e);
}

/**
 *  @name        : void judgeError(Status e)
 *	@description : judge whether there is a error
 *	@param		 : the status e
 *	@return		 : None
 *  @notice      : None
 */
void judgeError(Status e){
	if (!e){
		system("cls");
		printf("Error!");
		system("pause");
		exit(0);
	}
}

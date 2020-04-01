#include "../head/linkedList.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L = (LinkedList)malloc(sizeof(LNode));
	if (*L){
		(*L)->next = NULL;
		return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LNode *p = *L,*p1 = *L,*p2;
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
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if (!p || !q) return ERROR;		//判断节点是否存在
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	LNode *p2;
	if (!p || !p->next) return ERROR;
	*e = p->next->data;
	p2 = p->next;
	p->next = p->next->next;
	free(p2);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode *p = L;
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

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LNode *p = L;				//适用于头尾成环
	if (!L) return ERROR;
	if (L->data == e) return SUCCESS;
	L = L->next;
	while (L && L != p){
		if (L->data == e) return SUCCESS;
		L = L->next;
	}
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LNode *p0 = NULL,*p1 = *L,*p2;
	if (!p1) return ERROR;
	while (p1){
		p2 = p1->next;
		p1->next = p0;
		p0 = p1;
		p1 = p2;
	}
	*L = p0;
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LNode *p1,*p2;
	if (!L || !L->next) return ERROR;
	p1 = L->next,p2 = L->next->next;
	while (p2){
		if (p1 == p2) return SUCCESS;
		if (!p2->next) return ERROR;
		p1 = p1->next;
		p2 = p2->next->next;
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	LNode *p1 = *L,*p2;
	if (!p1) return NULL;
	if (!(p2 = p1->next)) return p1;
	if (!(p2->data%2)) *L = p2;
	while (p2){
		if (!(p2->data%2)){
			p1->next = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p2->next;
		}
		p1 = p2;
		p2 = p2->next;
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LNode *p1 = *L,*p2 = *L;
	while (p2 && p2->next){
		p1 = p1->next;
		p2 = p2->next->next;
	}
	return p1;
}


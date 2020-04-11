#include "LQueue.h"
#include <string.h>

void InitLQueue(LQueue *Q){
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	Q->front->next = NULL;
	Q->length = 0;
}

void DestoryLQueue(LQueue *Q){
	Node *p;
	while (Q->front){
		p = Q->front->next;
		free(Q->front);
		Q->front = p;
	}
	Q->front = Q->length = Q->rear = NULL;
}

Status IsEmptyLQueue(const LQueue *Q){
	if (Q->length) return FALSE;
	return TRUE;
}

Status GetHeadLQueue(LQueue *Q, void *e){
	if (IsEmptyLQueue(Q)) return FALSE;
	memcpy(e,Q->front->data,typesize());
	return TRUE;
}

int LengthLQueue(LQueue *Q){
	return Q->length;
}

Status EnLQueue(LQueue *Q, void *data){
	Q->rear->data = malloc(typesize());
	memcpy(Q->rear->data,data,typesize());
	Q->rear = Q->rear->next = (Node*)malloc(sizeof(Node));\
	Q->rear->next = NULL;
	Q->length+=1;
	return TRUE;
}

Status DeLQueue(LQueue *Q){
	Node *p = Q->front->next;
	if (IsEmptyLQueue(Q)) return FALSE;
	free(Q->front);
	Q->front = p;
	Q->length-=1;
	return TRUE;
}

void ClearLQueue(LQueue *Q){
	Node *p;
	while (Q->front){
		p = Q->front->next;
		free(Q->front);
		Q->front = p;
	}
	InitLQueue(Q);
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	Node *p = Q->front;
	while (p->next){
		(*foo)(p->data);
		p = p->next;
	}
	return TRUE;
}

void LPrint(void *q){
	switch(type){
	case 'i':
		printf("%d ",*(int*)q);
		break;
	case 'l':
		printf("%ld ",*(long*)q);
		break;
	case 'f':
		printf("%f ",*(float*)q);
		break;
	case 'd':
		printf("%.9lf ",*(double*)q);
		break;
	case 'c':
		printf("%c ",*(char*)q);
	}
}

int typesize(){
	switch(type){
	case 'i':
		return sizeof(int);
	case 'l':
		return sizeof(long);
	case 'f':
		return sizeof(float);
	case 'd':
		return sizeof(double);
	case 'c':
		return sizeof(char);
	}
}

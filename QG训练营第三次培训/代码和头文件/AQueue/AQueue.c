#include "AQueue.h"
#include <string.h>

void InitAQueue(AQueue *Q){
	Q->length = Q->front = Q->rear = 0;
}

void DestoryAQueue(AQueue *Q){
	for (int i=0;i<MAXQUEUE;i++) free(Q->data[i]);
	Q->length = Q->front = Q->rear = 0;
}

Status IsFullAQueue(const AQueue *Q){
	if (Q->length == MAXQUEUE) return TRUE;
	return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q){
	if (Q->length) return FALSE;
	return TRUE;
}

Status GetHeadAQueue(AQueue *Q, void *e){
	if (IsEmptyAQueue(Q)) return FALSE;
	memcpy(e,Q->data[Q->front],typesize());
	return TRUE;
}

int LengthAQueue(AQueue *Q){
	return Q->length;
}

Status EnAQueue(AQueue *Q, void *data){
	if (IsFullAQueue(Q)) return FALSE;
	Q->data[Q->rear] = malloc(typesize());
	memcpy(Q->data[Q->rear],data,typesize());
	Q->rear = (Q->rear+1)%MAXQUEUE;
	Q->length+=1;
	return TRUE;
}

Status DeAQueue(AQueue *Q){
	if (IsEmptyAQueue(Q)) return FALSE;
	free(Q->data[Q->front]);
	Q->front = (Q->front+1)%MAXQUEUE;
	Q->length-=1;
	return TRUE;
}

void ClearAQueue(AQueue *Q){
	for (int i=0;i<MAXQUEUE;i++) free(Q->data[i]);
	Q->length = Q->front = Q->rear = 0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	for (int i=Q->front;i<Q->front+Q->length;i++) (*foo)(Q->data[i%MAXQUEUE]);
	return TRUE;
}

void APrint(void *q){
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

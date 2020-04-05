#include "../head/SqStack.h"
#include <stdlib.h>
#include <windows.h>

Status initStack(SqStack *s,int sizes){			// ��ʼ����ջ
	if (!s) return ERROR;
	s->top = 0;
	s->size = sizes;
	s->elem = (ElemType*)malloc(sizes*sizeof(ElemType));
	if (s->elem) return SUCCESS;
	return ERROR;
}

Status isEmptyStack(SqStack *s){			// �ж�ջ�Ƿ�Ϊ�գ�ERRORΪ�ջ��쳣��SUCCESSΪ�ǿ�
	if (!s || !s->elem || !s->top) return ERROR;
	return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e){		// �õ�ջ��Ԫ��
	if (!s || !s->elem || !s->top) return ERROR;
	*e = s->elem[s->top-1];
	return SUCCESS;
}

Status clearStack(SqStack *s){				// ���ջ
	if (!s || !s->elem) return ERROR;
	s->top = 0;
	return SUCCESS;
}

Status destroyStack(SqStack *s){			// ����ջ
	if (!s) return ERROR;
	if (s->elem) free(s->elem);
	s->elem = NULL;
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length){		// ���ջ����
	if (!s || !s->elem) return ERROR;
	*length = s->top;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data){		// ��ջ
	if (!s || !s->elem || s->top>=s->size) return ERROR;
	s->elem[s->top++] = data;
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data){		// ��ջ
	if (!s || !s->elem || !s->top) return ERROR;
	*data = s->elem[--s->top];
	return SUCCESS;
}

void error(){						// ����
	system("cls");
	printf("\n\tError!");
	system("pause");
	exit(0);
}

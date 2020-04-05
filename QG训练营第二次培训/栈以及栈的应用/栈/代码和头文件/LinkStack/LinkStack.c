#include "../head/LinkStack.h"
#include <stdlib.h>
#include <windows.h>

Status initLStack(LinkStack *s){			// ��ʼ��ջ
	if (!s) return ERROR;
	s->top = s->count = 0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s){			// �ж�ջ�Ƿ�Ϊ�գ�ERRORΪ�ջ��쳣��SUCCESSΪ�ǿ�
	if (!s || !s->top) return ERROR;
	return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e){		// �õ�ջ��Ԫ��
	if (!s || !s->top) return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

Status clearLStack(LinkStack *s){			// ���ջ
	StackNode *p;
	if (!s) return ERROR;
	while (s->top){
		p = s->top->next;
		free(s->top);
		s->top = p;
	}
	s->count = 0;
	return SUCCESS;
}

Status destroyLStack(LinkStack *s){			// ����ջ
	StackNode *p;
	if (!s) return ERROR;
	while (s->top){
		p = s->top->next;
		free(s->top);
		s->top = p;
	}
	s->count = 0;
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length){		// ���ջ����
	if (!s) return ERROR;
	*length = s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data){		// ��ջ
	StackNode *p;
	if (!s) return ERROR;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data){		// ��ջ
	StackNode *p;
	if (!s || !data || !s->top) return ERROR;
	*data = s->top->data;
	p = s->top->next;
	free(s->top);
	s->top = p;
	s->count--;
	return SUCCESS;
}

void error(){						// ����
	system("cls");
	printf("\n\tError!");
	system("pause");
	exit(0);
}

#include "../head/LinkStack.h"
#include <stdlib.h>
#include <windows.h>

Status initLStack(LinkStack *s){			// 初始化栈
	if (!s) return ERROR;
	s->top = s->count = 0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s){			// 判断栈是否为空，ERROR为空或异常，SUCCESS为非空
	if (!s || !s->top) return ERROR;
	return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e){		// 得到栈顶元素
	if (!s || !s->top) return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

Status clearLStack(LinkStack *s){			// 清空栈
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

Status destroyLStack(LinkStack *s){			// 销毁栈
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

Status LStackLength(LinkStack *s,int *length){		// 检测栈长度
	if (!s) return ERROR;
	*length = s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data){		// 入栈
	StackNode *p;
	if (!s) return ERROR;
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data){		// 出栈
	StackNode *p;
	if (!s || !data || !s->top) return ERROR;
	*data = s->top->data;
	p = s->top->next;
	free(s->top);
	s->top = p;
	s->count--;
	return SUCCESS;
}

void error(){						// 报错
	system("cls");
	printf("\n\tError!");
	system("pause");
	exit(0);
}

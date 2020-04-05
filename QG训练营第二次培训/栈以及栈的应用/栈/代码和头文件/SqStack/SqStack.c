#include "../head/SqStack.h"
#include <stdlib.h>
#include <windows.h>

Status initStack(SqStack *s,int sizes){			// 初始化空栈
	if (!s) return ERROR;
	s->top = 0;
	s->size = sizes;
	s->elem = (ElemType*)malloc(sizes*sizeof(ElemType));
	if (s->elem) return SUCCESS;
	return ERROR;
}

Status isEmptyStack(SqStack *s){			// 判断栈是否为空，ERROR为空或异常，SUCCESS为非空
	if (!s || !s->elem || !s->top) return ERROR;
	return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e){		// 得到栈顶元素
	if (!s || !s->elem || !s->top) return ERROR;
	*e = s->elem[s->top-1];
	return SUCCESS;
}

Status clearStack(SqStack *s){				// 清空栈
	if (!s || !s->elem) return ERROR;
	s->top = 0;
	return SUCCESS;
}

Status destroyStack(SqStack *s){			// 销毁栈
	if (!s) return ERROR;
	if (s->elem) free(s->elem);
	s->elem = NULL;
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length){		// 检测栈长度
	if (!s || !s->elem) return ERROR;
	*length = s->top;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data){		// 入栈
	if (!s || !s->elem || s->top>=s->size) return ERROR;
	s->elem[s->top++] = data;
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data){		// 出栈
	if (!s || !s->elem || !s->top) return ERROR;
	*data = s->elem[--s->top];
	return SUCCESS;
}

void error(){						// 报错
	system("cls");
	printf("\n\tError!");
	system("pause");
	exit(0);
}

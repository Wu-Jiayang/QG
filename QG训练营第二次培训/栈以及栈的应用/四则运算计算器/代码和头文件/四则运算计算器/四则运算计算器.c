#include "../head/四则运算计算器.h"
#include <stdlib.h>
#include <windows.h>

void DestroyList(linklistNode **L){				// 销毁链表
	linklistNode *p = *L,*p1 = *L,*p2;
	int i=2;						// 适用于头尾成环
	while (p1){
		if (p1 == p) if (!(--i)) break;
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	*L = NULL;
}

linklistNode* inputError(linklistNode **L,linklistNode *p){	// 用于异常处理
	printf("输入错误！");
	p->next = NULL;
	DestroyList(L);
	system("pause");
	return NULL;
}

linklistNode* input(){						// 输入式子并进行检测和整理，以链表形式返回，不能超过255个字符。
	char str[256],i,ch = '\0';				// ch用于储存上个字符
	linklistNode *head = (linklistNode*)malloc(sizeof(linklistNode)) , *p = head;
	system("cls");
	printf("\n\t请输入你的式子（不能超过255个字符）：");
	scanf("%s",str);
	str[255] = '\0';
	for (i = 0;str[i];i++){
		if ((str[i]<'0' || str[i]>'9') && (str[i]<'(' || str[i]>'+') && str[i] != '-' && str[i] != '/') return inputError(&head,p);
		if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '\0'){
			if (str[i] >= ')' && str[i] <= '+' || str[i] == '/') return inputError(&head,p);
			else if (str[i] == '-'){
				if (ch == '-' || ch == '*' || ch == '/') return inputError(&head,p);
				p->ch = '\0';
				p->num = 0;
				p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
				ch = p->ch = '-';
				p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
			}
			else if (str[i] == '('){
				ch = p->ch = str[i];
				p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
			}
			else{
				if (str[i] == '0' && ch == '/') return inputError(&head,p);
				p->ch = '\0';
				p->num = str[i]-'0';
				ch = str[i];
			}
		}
		else if (ch == ')'){
			if (str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/' && str[i]!=')') return inputError(&head,p);
			p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
			ch = p->ch = str[i];
			if (str[i] != ')') p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
		}
		else if (str[i] == '(') return inputError(&head,p);
		else if (str[i] >= ')' && str[i] <= '+' || str[i] == '/' || str[i] == '-'){
			p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
			ch = p->ch = str[i];
			if (str[i] != ')') p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
		}
		else p->num = p->num*10+str[i]-'0';
	}
	if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '\0') return inputError(&head,p);
	p->next = NULL;
	return head;
}

void printlist(linklistNode *head){				// 打印整个链表
	printf ("\n\t");
	for (;head;head = head->next) if (head->ch) printf("%c ",head->ch); else printf("%ld ",head->num);
}

void pushStack(LinkStack *L,linklistNode *l){			// 压栈
	linklistNode *p = (linklistNode*)malloc(sizeof(linklistNode));
	p->ch = l->ch;
	p->num = l->num;
	p->next = L->top;
	L->top = p;
}

void popStack(LinkStack *L,linklistNode *l){			// 弹栈
	linklistNode *p = L->top->next;
	l->ch = L->top->ch;
	l->num = L->top->num;
	free (L->top);
	L->top = p;
}

linklistNode *turn1(linklistNode *head){			// 转化为后缀表达式
	linklistNode *L = (linklistNode*)malloc(sizeof(linklistNode)) , *p = L;
	LinkStack stack = {NULL,0};
	for (;head;head = head->next) if (head->ch == ')'){
		while (stack.top && stack.top->ch != '('){
			p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
			popStack(&stack,p);
		}
		if (!stack.top){
			printf ("\n\t括号数目不对称");
			system("pause");
			exit(0);
		}
		stack.top = stack.top->next;
	}
	else if (head->ch){
		while (stack.top && (head->ch == '*' || head->ch == '/') && (stack.top->ch == '*' || stack.top->ch == '/')){
			p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
			popStack(&stack,p);
		}
		while (stack.top && (head->ch == '+' || head->ch == '-') && stack.top->ch!='('){
			p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
			popStack(&stack,p);
		}
		pushStack(&stack,head);
	}
	else{
		p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
		p->ch = '\0';
		p->num = head->num;
	}
	while (stack.top){
		p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
		popStack(&stack,p);
	}
	p->next = NULL;
	p = L->next;
	free(L);
	for (L = p;p;p = p->next) if (p->ch == '('){
		printf ("\n\t括号数目不对称");
		system("pause");
		exit(0);
	}
	return L;
}

long int calculation(linklistNode *head){			// 最终计算
	LinkStack stack = {NULL,0};
	linklistNode x,y;
	for (;head;head = head->next) if (head->ch){
		popStack(&stack,&y);
		popStack(&stack,&x);
		if (head->ch == '+') x.num += y.num;
		else if (head->ch == '-') x.num -= y.num;
		else if (head->ch == '*') x.num *= y.num;
		else x.num /= y.num;
		pushStack(&stack,&x);
	}
	else pushStack(&stack,head);
	return stack.top->num;
}

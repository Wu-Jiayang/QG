#include "../head/�������������.h"
#include <stdlib.h>
#include <windows.h>

void DestroyList(linklistNode **L){				// ��������
	linklistNode *p = *L,*p1 = *L,*p2;
	int i=2;						// ������ͷβ�ɻ�
	while (p1){
		if (p1 == p) if (!(--i)) break;
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	*L = NULL;
}

linklistNode* inputError(linklistNode **L,linklistNode *p){	// �����쳣����
	printf("�������");
	p->next = NULL;
	DestroyList(L);
	system("pause");
	return NULL;
}

linklistNode* input(){						// ����ʽ�Ӳ����м���������������ʽ���أ����ܳ���255���ַ���
	char str[256],i,ch = '\0';				// ch���ڴ����ϸ��ַ�
	linklistNode *head = (linklistNode*)malloc(sizeof(linklistNode)) , *p = head;
	system("cls");
	printf("\n\t���������ʽ�ӣ����ܳ���255���ַ�����");
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

void printlist(linklistNode *head){				// ��ӡ��������
	printf ("\n\t");
	for (;head;head = head->next) if (head->ch) printf("%c ",head->ch); else printf("%ld ",head->num);
}

void pushStack(LinkStack *L,linklistNode *l){			// ѹջ
	linklistNode *p = (linklistNode*)malloc(sizeof(linklistNode));
	p->ch = l->ch;
	p->num = l->num;
	p->next = L->top;
	L->top = p;
}

void popStack(LinkStack *L,linklistNode *l){			// ��ջ
	linklistNode *p = L->top->next;
	l->ch = L->top->ch;
	l->num = L->top->num;
	free (L->top);
	L->top = p;
}

linklistNode *turn1(linklistNode *head){			// ת��Ϊ��׺���ʽ
	linklistNode *L = (linklistNode*)malloc(sizeof(linklistNode)) , *p = L;
	LinkStack stack = {NULL,0};
	for (;head;head = head->next) if (head->ch == ')'){
		while (stack.top && stack.top->ch != '('){
			p = p->next = (linklistNode*)malloc(sizeof(linklistNode));
			popStack(&stack,p);
		}
		if (!stack.top){
			printf ("\n\t������Ŀ���Գ�");
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
		printf ("\n\t������Ŀ���Գ�");
		system("pause");
		exit(0);
	}
	return L;
}

long int calculation(linklistNode *head){			// ���ռ���
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

#include "BinaryTree.h"

Status InitBiTree(BiTree T){
	T->lchild = T->rchild = NULL;
	return SUCEESS;
}

Status DestroyBiTree(BiTree T){
	if (!T) return ERROR;
	if (T->lchild) DestroyBiTree(T->lchild);
	if (T->rchild) DestroyBiTree(T->rchild);
	free(T);
	return SUCEESS;
}

Status CreateBiTree(BiTree T, char** definition){
	if (!(**definition)) return ERROR;
	T->data = *((*definition)++);
	if (**definition != '#'){
		T->lchild = (BiTNode*)malloc(sizeof(BiTNode));
		CreateBiTree(T->lchild, definition);
	}
	else T->lchild = NULL;
	if (*(++(*definition)) != '#'){
		T->rchild = (BiTNode*)malloc(sizeof(BiTNode));
		CreateBiTree(T->rchild, definition);
	}
	else {
		T->rchild = NULL;
		(*definition)++;
	}
	return SUCEESS;
}

Status CreateBiTree2(BiTree T, char** definition){
	if (!(**definition)) return ERROR;
	T->data = *((*definition)++);
	T->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	T->rchild = (BiTNode*)malloc(sizeof(BiTNode));
	if (**definition < '0'){
		CreateBiTree2(T->lchild, definition);
		(*definition)++;
	}
	else{
		T->lchild->data = *((*definition)++);
		T->lchild->lchild = T->lchild->rchild = NULL;
	}
	if (**definition < '0') CreateBiTree2(T->rchild, definition);
	else {
		T->rchild->data = **definition;
		T->rchild->lchild = T->rchild->rchild = NULL;
	}
	return SUCEESS;
}

Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	StackNode *head = (StackNode*)malloc(sizeof(StackNode)), *p;
	BiTNode *t;
	head->next = NULL;
	head->data = T;
	while (head){
		t = head->data;
		(*visit)(t->data);
		p = head;
		head = head->next;
		free(p);
		if (t->rchild){
			p = (StackNode*)malloc(sizeof(StackNode));
			p->data = t->rchild;
			p->next = head;
			head = p;
		}
		if (t->lchild){
			p = (StackNode*)malloc(sizeof(StackNode));
			p->data = t->lchild;
			p->next = head;
			head = p;
		}
	}
	return SUCEESS;
}

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	if (T->lchild) InOrderTraverse(T->lchild, visit);
	(*visit)(T->data);
	if (T->rchild) InOrderTraverse(T->rchild, visit);
	return SUCEESS;
}

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	if (T->lchild) PostOrderTraverse(T->lchild, visit);
	if (T->rchild) PostOrderTraverse(T->rchild, visit);
	(*visit)(T->data);
	return SUCEESS;
}

Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	StackNode *head = (StackNode*)malloc(sizeof(StackNode)), *p = head, *q;
	head->next = NULL;
	head->data = T;
	while (head){
		(*visit)(head->data->data);
		if (head->data->lchild){
			p = p->next = (StackNode*)malloc(sizeof(StackNode));
			p->data = head->data->lchild;
			p->next = NULL;
		}
		if (head->data->rchild){
			p = p->next = (StackNode*)malloc(sizeof(StackNode));
			p->data = head->data->rchild;
			p->next = NULL;
		}
		q = head;
		head = head->next;
		free(q);
	}
	return SUCEESS;
}

int Value(BiTree T){
	int num;
	if (T->data >= '0') return T->data - '0';
	else if (T->data == '+') return Value(T->lchild) + Value(T->rchild);
	else if (T->data == '-') return Value(T->lchild) - Value(T->rchild);
	else if (T->data == '*') return Value(T->lchild) * Value(T->rchild);
	else if (num = Value(T->rchild)) return Value(T->lchild) / num;
	else inputError(NULL);
}

void inputError(char *str){									// 用于异常处理
	free(str);
	printf("\n\t输入错误！");
	system("pause");
	exit(0);
}

char* input(){											// 输入式子并进行检测和整理，以链表形式返回，不能超过255个字符。
	char *str = (char*)malloc(128*sizeof(char)), i, ch = '\0';				// ch用于储存上个字符
	StackNode *head1 = NULL, *head2 = NULL, *p;
	system("cls");
	printf("\n\t请输入你的式子（不能超过127个字符）：");
	scanf_s("%s", str, 128);
	for (i = 0; str[i]; i++){
		if ((str[i]<'0' || str[i]>'9') && (str[i]<'(' || str[i]>'+') && str[i] != '-' && str[i] != '/') inputError(str);
		if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '\0'){
			if (str[i] >= ')' && str[i] <= '+' || str[i] == '/') inputError(str);
			else if (str[i] == '-'){
				if (ch == '-' || ch == '*' || ch == '/') inputError(str);
				ch = '-';
			}
			else if (str[i] == '(') ch = str[i];
			else{
				if (str[i] == '0' && ch == '/') inputError(str);
				ch = str[i];
			}
		}
		else if (ch == ')'){
			if (str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/' && str[i]!=')') inputError(str);
			ch = str[i];
		}
		else if (str[i] == '(') inputError(str);
		else if (str[i] >= ')' && str[i] <= '+' || str[i] == '/' || str[i] == '-') ch = str[i];
	}
	if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '\0') inputError(str);
	for (i--; i>=0; i--){
		if (str[i] >= '0' && str[i] <= '9'){
			p = (StackNode*)malloc(sizeof(StackNode));
			p->ch = str[i];
			p->next = head1;
			head1 = p;
		}
		else if (!head2 || str[i] != '(' && !((str[i] == '+' || str[i] == '-') && (head2->ch == '*' || head2->ch == '/'))){
			p = (StackNode*)malloc(sizeof(StackNode));
			p->ch = str[i];
			p->next = head2;
			head2 = p;
			if (str[i] == '-' && (!i || str[i-1] < '0' && str[i-1] != ')')){
				p = (StackNode*)malloc(sizeof(StackNode));
				p->ch = '0';
				p->next = head1;
				head1 = p;
			}
		}
		else if (str[i] == '('){
			while (head2 && head2->ch != ')'){
				p = (StackNode*)malloc(sizeof(StackNode));
				p->ch = head2->ch;
				p->next = head1;
				head1 = p;
				p = head2;
				head2 = head2->next;
				free(p);
			}
			if (!head2) inputError(str);
			p = head2;
			head2 = head2->next;
			free(p);
		}
		else {
			while (head2->ch != '+' && head2->ch != '-' && head2->ch != ')'){
				p = (StackNode*)malloc(sizeof(StackNode));
				p->ch = head2->ch;
				p->next = head1;
				head1 = p;
				p = head2;
				head2 = head2->next;
				free(p);
			}
			p = (StackNode*)malloc(sizeof(StackNode));
			p->ch = str[i];
			p->next = head2;
			head2 = p;
			if (str[i] == '-' && (!i || str[i-1] < '0' && str[i-1] != ')')){
				p = (StackNode*)malloc(sizeof(StackNode));
				p->ch = '0';
				p->next = head1;
				head1 = p;
			}
		}
	}
	while (head2){
		if (head2->ch == ')') inputError(str);
		p = (StackNode*)malloc(sizeof(StackNode));
		p->ch = head2->ch;
		p->next = head1;
		head1 = p;
		p = head2;
		head2 = head2->next;
		free(p);
	}
	for (i=0; head1; i++){
		str[i] = head1->ch;
		p = head1;
		head1 = head1->next;
		free(p);
	}
	str[i] = '\0';
	return str;
}

Status visit(TElemType e){
	printf("%c\t", e);
}



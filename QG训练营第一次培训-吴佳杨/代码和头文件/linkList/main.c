#include "../head/linkedList.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main(){
	LinkedList head = NULL;
	LNode *p = NULL,*q;
	int i;
	while (1){
		system("cls");
		printf("\n\t\tQG单链表考核\n\n\t1.创建链表\n\t2.打印链表\n\t3.插入节点\n\t4.链表倒置\n\t5.删除链表");
		switch (getch()){
		case '1':
			system("cls");
			printf("\n\t请输入链表数据，空格分隔，0结束：");
			scanf("%d",&i);
			if (!i) break;
			judgeError(InitList(&head));
			p = head;
			p->data = i;
			scanf("%d",&i);
			while (i){
				judgeError(InitList(&p->next));
				p = p->next;
				p->data = i;
				scanf("%d",&i);
			}
			printf("\n创建成功！\n");
			system("pause");
			break;
		case '2':
			system("cls");
			TraverseList(head,visit);
			system("pause");
			break;
		case '3':
			system("cls");
			printf("\n\t请输入节点数据，回车结束：");
			judgeError(InitList(&q));
			scanf("%d",&q->data);
			judgeError(InsertList(p,q));
			p = q;
			printf("\n插入成功！\n");
			system("pause");
			break;
		case '4':
			system("cls");
			judgeError(ReverseList(&head));
			printf("\n\t倒置成功！\n");
			system("pause");
			break;
		case '5':
			system("cls");
			DestroyList(&head);
			p = NULL;
			printf("\n\t删除成功！\n");
			system("pause");
			break;
		}
	}
}

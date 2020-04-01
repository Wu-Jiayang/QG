#include "../head/duLinkedList.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main(){
	DuLinkedList head = NULL;
	DuLNode *p = NULL,*q;
	int i;
	while (1){
		system("cls");
		printf("\n\t\tQG双向链表考核\n\n\t1.创建链表\n\t2.打印链表\n\t3.插入节点\n\t4.删除链表");
		switch (getch()){
		case '1':
			system("cls");
			printf("\n\t请输入链表数据，空格分隔，0结束：");
			scanf("%d",&i);
			if (!i) break;
			judgeError(InitList_DuL(&head));
			p = head;
			p->data = i;
			scanf("%d",&i);
			while (i){
				judgeError(InitList_DuL(&p->next));
				p = p->next;
				p->data = i;
				scanf("%d",&i);
			}
			printf("\n创建成功！\n");
			system("pause");
			break;
		case '2':
			system("cls");
			TraverseList_DuL(head,visit);
			system("pause");
			break;
		case '3':
			system("cls");
			printf("\n\t请输入节点数据，回车结束：");
			judgeError(InitList_DuL(&q));
			scanf("%d",&q->data);
			judgeError(InsertAfterList_DuL(p,q));
			p = q;
			printf("\n插入成功！\n");
			system("pause");
			break;
		case '4':
			system("cls");
			DestroyList_DuL(&head);
			p = NULL;
			printf("\n\t删除成功！\n");
			system("pause");
			break;
		}
	}
}

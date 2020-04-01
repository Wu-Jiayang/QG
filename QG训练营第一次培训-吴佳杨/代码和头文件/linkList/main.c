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
		printf("\n\t\tQG��������\n\n\t1.��������\n\t2.��ӡ����\n\t3.����ڵ�\n\t4.������\n\t5.ɾ������");
		switch (getch()){
		case '1':
			system("cls");
			printf("\n\t�������������ݣ��ո�ָ���0������");
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
			printf("\n�����ɹ���\n");
			system("pause");
			break;
		case '2':
			system("cls");
			TraverseList(head,visit);
			system("pause");
			break;
		case '3':
			system("cls");
			printf("\n\t������ڵ����ݣ��س�������");
			judgeError(InitList(&q));
			scanf("%d",&q->data);
			judgeError(InsertList(p,q));
			p = q;
			printf("\n����ɹ���\n");
			system("pause");
			break;
		case '4':
			system("cls");
			judgeError(ReverseList(&head));
			printf("\n\t���óɹ���\n");
			system("pause");
			break;
		case '5':
			system("cls");
			DestroyList(&head);
			p = NULL;
			printf("\n\tɾ���ɹ���\n");
			system("pause");
			break;
		}
	}
}

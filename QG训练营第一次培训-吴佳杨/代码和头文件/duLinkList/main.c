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
		printf("\n\t\tQG˫��������\n\n\t1.��������\n\t2.��ӡ����\n\t3.����ڵ�\n\t4.ɾ������");
		switch (getch()){
		case '1':
			system("cls");
			printf("\n\t�������������ݣ��ո�ָ���0������");
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
			printf("\n�����ɹ���\n");
			system("pause");
			break;
		case '2':
			system("cls");
			TraverseList_DuL(head,visit);
			system("pause");
			break;
		case '3':
			system("cls");
			printf("\n\t������ڵ����ݣ��س�������");
			judgeError(InitList_DuL(&q));
			scanf("%d",&q->data);
			judgeError(InsertAfterList_DuL(p,q));
			p = q;
			printf("\n����ɹ���\n");
			system("pause");
			break;
		case '4':
			system("cls");
			DestroyList_DuL(&head);
			p = NULL;
			printf("\n\tɾ���ɹ���\n");
			system("pause");
			break;
		}
	}
}

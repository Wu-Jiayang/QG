#include "AQueue.h"
#include <conio.h>
#include <windows.h>

int main(){
	AQueue q;
	void *p;
	type = '\0';
	InitAQueue(&q);
	while (!type){
		system("cls");
		printf("\n\t\t��ѡ���������ͣ�\n\n\ti : int\n\tl : long\n\tf : float\n\td : double\n\tc : char");
		switch(type = getch()){
		case 'i':
		case 'l':
		case 'f':
		case 'd':
		case 'c':
			p = malloc(typesize());
			break;
		default:
			type = '\0';
			system("cls");
			printf("\n\t����������������룡");
			system("pause");
		}
	}
	while (1){
		system("cls");
		printf("\n\t\tQG˳����п���\n\n\t1.������г���\n\t2.��ӡ��ǰ����\n\t3.����\n\t4.����\n\t5.���ٲ��˳�");
		switch (getch()){
		case '1':
			system("cls");
			printf("\n\t��ǰ���г���Ϊ%d��",LengthAQueue(&q));
			system("pause");
			break;
		case '2':
			system("cls");
			printf("\n\t");
			TraverseAQueue(&q,APrint);
			system("pause");
			break;
		case '3':
			system("cls");
			printf("\n\t�������������ݣ�");
			switch(type){
			case 'i':
				scanf("%d",(int*)p);
				break;
			case 'l':
				scanf("%ld",(long*)p);
				break;
			case 'f':
				scanf("%f",(float*)p);
				break;
			case 'd':
				scanf("%lf",(double*)p);
				break;
			case 'c':
				*(char*)p = getch();
			}
			if (EnAQueue(&q,p)) printf("\n\t���гɹ���\n");
			else printf("\n\t����������\n");
			system("pause");
			break;
		case '4':
			system("cls");
			if (GetHeadAQueue(&q,p)){
				DeAQueue(&q);
				printf("\n\t���гɹ�����������Ϊ");
				APrint(p);
			}
			else printf("\n\t����Ϊ�գ�");
			system("pause");
			break;
		case '5':
			system("cls");
			DestoryAQueue(&q);
			printf("\n\t���ٳɹ���\n");
			system("pause");
			return 0;
		}
	}
}

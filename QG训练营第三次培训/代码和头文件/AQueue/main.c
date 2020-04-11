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
		printf("\n\t\t请选择数据类型：\n\n\ti : int\n\tl : long\n\tf : float\n\td : double\n\tc : char");
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
			printf("\n\t输入错误，请重新输入！");
			system("pause");
		}
	}
	while (1){
		system("cls");
		printf("\n\t\tQG顺序队列考核\n\n\t1.输出队列长度\n\t2.打印当前队列\n\t3.入列\n\t4.出列\n\t5.销毁并退出");
		switch (getch()){
		case '1':
			system("cls");
			printf("\n\t当前队列长度为%d。",LengthAQueue(&q));
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
			printf("\n\t请输入入列数据：");
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
			if (EnAQueue(&q,p)) printf("\n\t入列成功！\n");
			else printf("\n\t队列已满！\n");
			system("pause");
			break;
		case '4':
			system("cls");
			if (GetHeadAQueue(&q,p)){
				DeAQueue(&q);
				printf("\n\t出列成功！出列数据为");
				APrint(p);
			}
			else printf("\n\t队列为空！");
			system("pause");
			break;
		case '5':
			system("cls");
			DestoryAQueue(&q);
			printf("\n\t销毁成功！\n");
			system("pause");
			return 0;
		}
	}
}

#include "../head/SqStack.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main(){
	SqStack stack;
	ElemType data;
	printf("\n\t������ջ���ܳߴ磺");
	scanf("%d",&data);
	if (!initStack(&stack,data)) error();
	while (1){
		system("cls");
		printf("\n\t\tQG˳��ջ����\n\n\t1.���ջ����\n\t2.��ӡȫջ��ջ����ǰ��\n\t3.ѹջ\n\t4.��ջ\n\t5.���ٲ��˳�");
		switch (getch()){
		case '1':
			system("cls");
			if (!stackLength(&stack,&data)) error();
			printf("\n\t��ǰջ����Ϊ%d��",data);
			system("pause");
			break;
		case '2':
			system("cls");
			printf("\n\t");
			for (data = 0;data<stack.top;data++) printf("%d ",stack.elem[data]);
			system("pause");
			break;
		case '3':
			system("cls");
			printf("\n\t������ѹջ���ݣ��س�������");
			scanf("%d",&data);
			if (!pushStack(&stack,data)) error();
			printf("\nѹջ�ɹ���\n");
			system("pause");
			break;
		case '4':
			system("cls");
			if (!popStack(&stack,&data)) error();
			printf("\n\t��ջ�ɹ�����������Ϊ%d��\n",data);
			system("pause");
			break;
		case '5':
			system("cls");
			if (!destroyStack(&stack)) error();
			printf("\n\t���ٳɹ���\n");
			system("pause");
			return 0;
		}
	}
}

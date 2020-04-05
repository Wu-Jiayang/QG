#include "../head/SqStack.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main(){
	SqStack stack;
	ElemType data;
	printf("\n\t请输入栈的总尺寸：");
	scanf("%d",&data);
	if (!initStack(&stack,data)) error();
	while (1){
		system("cls");
		printf("\n\t\tQG顺序栈考核\n\n\t1.输出栈长度\n\t2.打印全栈（栈底在前）\n\t3.压栈\n\t4.弹栈\n\t5.销毁并退出");
		switch (getch()){
		case '1':
			system("cls");
			if (!stackLength(&stack,&data)) error();
			printf("\n\t当前栈长度为%d。",data);
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
			printf("\n\t请输入压栈数据，回车结束：");
			scanf("%d",&data);
			if (!pushStack(&stack,data)) error();
			printf("\n压栈成功！\n");
			system("pause");
			break;
		case '4':
			system("cls");
			if (!popStack(&stack,&data)) error();
			printf("\n\t弹栈成功！弹出数据为%d。\n",data);
			system("pause");
			break;
		case '5':
			system("cls");
			if (!destroyStack(&stack)) error();
			printf("\n\t销毁成功！\n");
			system("pause");
			return 0;
		}
	}
}

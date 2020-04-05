#include "../head/LinkStack.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main(){
	LinkStack stack;
	ElemType data;
	StackNode *p;
	if (!initLStack(&stack)) error();
	while (1){
		system("cls");
		printf("\n\t\tQG链栈考核\n\n\t1.输出栈长度\n\t2.打印全栈（栈顶在前）\n\t3.压栈\n\t4.弹栈\n\t5.销毁并退出");
		switch (getch()){
		case '1':
			system("cls");
			if (!LStackLength(&stack,&data)) error();
			printf("\n\t当前栈长度为%d。",data);
			system("pause");
			break;
		case '2':
			system("cls");
			printf("\n\t");
			for (p = stack.top;p;p = p->next) printf("%d ",p->data);
			system("pause");
			break;
		case '3':
			system("cls");
			printf("\n\t请输入压栈数据，回车结束：");
			scanf("%d",&data);
			if (!pushLStack(&stack,data)) error();
			printf("\n压栈成功！\n");
			system("pause");
			break;
		case '4':
			system("cls");
			if (!popLStack(&stack,&data)) error();
			printf("\n\t弹栈成功！弹出数据为%d。\n",data);
			system("pause");
			break;
		case '5':
			system("cls");
			if (!destroyLStack(&stack)) error();
			printf("\n\t销毁成功！\n");
			system("pause");
			return 0;
		}
	}
}

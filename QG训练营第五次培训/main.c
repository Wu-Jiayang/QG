#include "BinaryTree.h"

int main(){
	char *str = input(), *p = str;
	BiTNode t;
	InitBiTree(&t);
	CreateBiTree2(&t, &p);
	printf("\t\t=%s\n\t\t=%d\n\n\t先序遍历（非递归）：", str, Value(&t));
	PreOrderTraverse(&t, visit);
	printf("\n\t中序遍历（递归）：");
	InOrderTraverse(&t, visit);
	printf("\n\t后序遍历（递归）：");
	PostOrderTraverse(&t, visit);
	printf("\n\t层序遍历（队列）：");
	LevelOrderTraverse(&t, visit);
	printf("\n\n\t即将销毁二叉树并退出，");
	system("pause");
	DestroyBiTree(&t);
}

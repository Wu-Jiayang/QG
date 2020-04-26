#include "BinaryTree.h"

int main(){
	char *str = input(), *p = str;
	BiTNode t;
	InitBiTree(&t);
	CreateBiTree2(&t, &p);
	printf("\t\t=%s\n\t\t=%d\n\n\t����������ǵݹ飩��", str, Value(&t));
	PreOrderTraverse(&t, visit);
	printf("\n\t����������ݹ飩��");
	InOrderTraverse(&t, visit);
	printf("\n\t����������ݹ飩��");
	PostOrderTraverse(&t, visit);
	printf("\n\t������������У���");
	LevelOrderTraverse(&t, visit);
	printf("\n\n\t�������ٶ��������˳���");
	system("pause");
	DestroyBiTree(&t);
}

#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <stdlib.h>
#include <windows.h>

typedef char TElemType;     			// �������������Ԫ������Ϊ�ַ�

typedef struct BiTNode{
	TElemType data;     			// ������
	struct BiTNode *lchild, *rchild;  	// ���Һ���ָ��
}BiTNode, *BiTree;   				// ��������

typedef enum Status{
	Error = 0,
	SUCEESS = 1
}Status;

typedef struct StackNode{
	BiTNode *data;
	char ch;
	struct StackNode *next;
}StackNode;

Status InitBiTree(BiTree T);
//�������������ն�����T
Status DestroyBiTree(BiTree T);
//��ʼ������������T����
//����������ݻٶ�����T
Status CreateBiTree(BiTree T, char** definition);
Status CreateBiTree2(BiTree T, char** definition);
//��ʼ������ definition�����������Ķ���
//�����������definition���������T


//���²��ֺ�������δָ����������
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
int Value(BiTree T);							//������Ķ�������ֵ
/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/
void inputError(char *str);
char* input();
Status visit(TElemType e);

#endif

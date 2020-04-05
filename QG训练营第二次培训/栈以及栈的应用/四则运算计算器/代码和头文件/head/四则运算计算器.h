typedef struct linklistNode{
	long int num;
	char ch;
	struct linklistNode *next;
}linklistNode;

typedef  struct  LinkStack{
	linklistNode *top;
	int count;
}LinkStack;

linklistNode* input();						// ����ʽ�Ӳ����м���������������ʽ���أ����ܳ���255���ַ���
void DestroyList(linklistNode **L);				// ��������
linklistNode* inputError(linklistNode **L,linklistNode *p);	// �����쳣����
void printlist(linklistNode *head);				// ��ӡ��������
void pushStack(LinkStack *L,linklistNode *l);			// ѹջ
void popStack(LinkStack *L,linklistNode *l);			// ��ջ
linklistNode *turn1(linklistNode *head);			// ת��Ϊ��׺���ʽ
long int calculation(linklistNode *head);			// ���ռ���

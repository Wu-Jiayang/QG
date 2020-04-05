typedef struct linklistNode{
	long int num;
	char ch;
	struct linklistNode *next;
}linklistNode;

typedef  struct  LinkStack{
	linklistNode *top;
	int count;
}LinkStack;

linklistNode* input();						// 输入式子并进行检测和整理，以链表形式返回，不能超过255个字符。
void DestroyList(linklistNode **L);				// 销毁链表
linklistNode* inputError(linklistNode **L,linklistNode *p);	// 用于异常处理
void printlist(linklistNode *head);				// 打印整个链表
void pushStack(LinkStack *L,linklistNode *l);			// 压栈
void popStack(LinkStack *L,linklistNode *l);			// 弹栈
linklistNode *turn1(linklistNode *head);			// 转化为后缀表达式
long int calculation(linklistNode *head);			// 最终计算

#include "../head/四则运算计算器.h"
#include <stdlib.h>
#include <windows.h>

int main(){
	linklistNode *head;
	while (!(head = input()));
	printlist(head);
	head = turn1(head);
	printlist(head);
	printf ("\n\t结果等于%ld。",calculation(head));
	system ("pause");
}

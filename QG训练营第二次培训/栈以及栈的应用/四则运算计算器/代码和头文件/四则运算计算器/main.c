#include "../head/�������������.h"
#include <stdlib.h>
#include <windows.h>

int main(){
	linklistNode *head;
	while (!(head = input()));
	printlist(head);
	head = turn1(head);
	printlist(head);
	printf ("\n\t�������%ld��",calculation(head));
	system ("pause");
}

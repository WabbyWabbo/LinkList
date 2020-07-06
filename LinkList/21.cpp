#include "LinkList.h"

int Search_K(LinkList L, int k) {
	LNode* p = L->next;
	LNode* q = p;

	//q往后移k位
	while (k-- && q != NULL) {
		q = q->next;
	}

	if (q == NULL)
	{
		return 0;//链表总长不够
	}
	else
	{
		//p,q同步后移直至表尾
		while (q != NULL) {
			p = p->next;
			q = q->next;
		}
		printf("%d", p->data);
		return 1;
	}
}
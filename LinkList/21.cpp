#include "LinkList.h"

int Search_K(LinkList L, int k) {
	LNode* p = L->next;
	LNode* q = p;

	//q������kλ
	while (k-- && q != NULL) {
		q = q->next;
	}

	if (q == NULL)
	{
		return 0;//�����ܳ�����
	}
	else
	{
		//p,qͬ������ֱ����β
		while (q != NULL) {
			p = p->next;
			q = q->next;
		}
		printf("%d", p->data);
		return 1;
	}
}
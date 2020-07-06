#include "LinkList.h"

void Del_All(LinkList L) {
	while (L->next != NULL) {
		LNode* pre = L, * p = L->next;
		LNode* minpre = pre, * minp = p;

		//�ҵ���ǰL�����е���Сֵλ��
		while (p != NULL) {
			if (p->data < minp->data)
			{
				minpre = pre;
				minp = p;
			}

			pre = p;
			p = p->next;
		}

		//ɾ��
		cout << minp->data;
		minpre->next = minp->next;
		free(minp);
	}

	free(L);
}
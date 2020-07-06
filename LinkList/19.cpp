#include "LinkList.h"

void Del_All(LinkList L) {
	while (L->next != NULL) {
		LNode* pre = L, * p = L->next;
		LNode* minpre = pre, * minp = p;

		//找到当前L链表中的最小值位置
		while (p != NULL) {
			if (p->data < minp->data)
			{
				minpre = pre;
				minp = p;
			}

			pre = p;
			p = p->next;
		}

		//删除
		cout << minp->data;
		minpre->next = minp->next;
		free(minp);
	}

	free(L);
}
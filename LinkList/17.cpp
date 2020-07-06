#include "DLinkList.h"

int Symmetry(DLinkList L) {
	DNode* p = L->next, * q = L->prior;

	while (q->next != p && p != q) {

		if (p->data == q->data) {
			p = p->next;
			q = q->prior;
		}
		else {
			return 0;
		}

	}

	return 1;
}
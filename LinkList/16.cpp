#include "LinkList.h"

bool subset(LinkList A, LinkList B) {
	LNode* p = A->next, * q = B->next;
	while (p && p->data != q->data)
		p = p->next;
	
	if (!p) {
		return false;
	}

	while (q && p) {
		if (p->data != q->data) {
			return false;
		}
		p = p->next;
		q = q->next;
	}

	if (!q)
		return true;

	if (!p)
		return false;
}

int main(void) {
	LinkList A = CreateList2(A);
	LinkList B = CreateList2(B);

	bool result = subset(A, B);
	
	cout << result;

	return 0;
}
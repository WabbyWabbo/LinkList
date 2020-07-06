#include "LinkList.h"

LinkList intersection(LinkList& A, LinkList &B) {
	LNode* p = A->next, * q = B->next, * temp;
	LNode* p_pre = A;

	while (p != NULL && q != NULL) {
		if (p->data < q->data) {//删掉*p结点，p后移
			p_pre->next = p->next;
			temp = p;
			p = p->next;
			free(temp);
		}
		else if (p->data > q->data) {//删除*q并后移
			temp = q;
			q = q->next;
			free(temp);
		}
		else {//找到交集，p_pre和p同步后移，*q删掉并后移
			p_pre = p;
			p = p->next;
			temp = q;
			q = q->next;
			free(temp);
		}
	}

	while (p != NULL) {//释放A中剩余结点
		temp = p;
		p = p->next;
		free(temp);
	}

	while (q != NULL) {//释放B中剩余结点
		temp = q;
		q = q->next;
		free(temp);
	}

	p_pre->next = NULL;//结果链表尾置空

	free(B);//释放B头节点

	return A;
}

//int main(void) {
//	LinkList A = CreateList2(A);
//	LinkList B = CreateList2(B);
//
//	intersection(A, B);
//	PrintList(A);
//
//	return 0;
//}
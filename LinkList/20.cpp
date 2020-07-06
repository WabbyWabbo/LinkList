#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;

typedef struct DNode {
	ElemType data;
	struct DNode* next, * prior;
	int freq = 0;
}DLNode, * DLinkList;

DLNode* Locate(DLinkList L, ElemType x) {
	//遍历找到x的位置，使其频度加1
	DLNode* p = L->next;
	while (p) {
		if (p->data == x)
			break;
		p = p->next;
	}

	if (!p) {
		printf("not found\n");
		exit(0);
	}
	else
	{
		p->freq++;

		//摘下p结点
		p->next->prior = p->prior;
		p->prior->next = p->next;

		//用q往前查找，找到p插入的正确位置
		DLNode* q = p->prior;
		while (q != L && q->freq <= p->freq)
		{
			q = q->prior;
		}

		//插入找到的q的后面
		p->next = q->next;
		q->next->prior = p;
		q->next = p;
		p->prior = q;
	}
	
	return p;
}
#include "LinkList.h"

LinkList Link(LinkList& h1, LinkList& h2) {
	LNode* p = h1;
	//�ҵ�h1�ı�β
	while (p->next != h1)
		p = p->next;

	p->next = h2;

	//�ҵ�h2�ı�β
	p = h2;
	while (p->next != h2)
	{
		p = p->next;
	}

	p->next = h1;
}
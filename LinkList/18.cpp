#include "LinkList.h"

LinkList Link(LinkList& h1, LinkList& h2) {
	LNode* p = h1;
	//找到h1的表尾
	while (p->next != h1)
		p = p->next;

	p->next = h2;

	//找到h2的表尾
	p = h2;
	while (p->next != h2)
	{
		p = p->next;
	}

	p->next = h1;
}
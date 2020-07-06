#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;

typedef struct DNode {
	ElemType data;
	struct DNode* next, * prior;
	int freq = 0;
}DLNode, * DLinkList;

DLNode* Locate(DLinkList L, ElemType x) {
	//�����ҵ�x��λ�ã�ʹ��Ƶ�ȼ�1
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

		//ժ��p���
		p->next->prior = p->prior;
		p->prior->next = p->next;

		//��q��ǰ���ң��ҵ�p�������ȷλ��
		DLNode* q = p->prior;
		while (q != L && q->freq <= p->freq)
		{
			q = q->prior;
		}

		//�����ҵ���q�ĺ���
		p->next = q->next;
		q->next->prior = p;
		q->next = p;
		p->prior = q;
	}
	
	return p;
}
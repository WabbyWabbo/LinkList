typedef int ElemType;

typedef struct DNode {
	ElemType data;
	struct DNode *next, *prior;
}DLNode, *DLinkList;
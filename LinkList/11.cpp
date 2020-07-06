/*
不用计数器，实现第10题功能，不过是B表用的是头插法
*/

#include "LinkList.h"
LinkList Split_List(LinkList &A)
{
    LinkList B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;

    LNode *p = A->next, *q;
    LNode *r = A;

    while (p != NULL)
    {
        //尾插法，到A表尾
        r->next = p;
        r = p;
        //p后移的同时，用q保存后继，以防断链
        p = p->next;
        q = p->next;
        //头插法下一个元素，到B表头
        p->next = B->next;
        B->next = p;
        //让p重新回到主表
        p = q;
    }

    r->next = NULL;

    return B;
}
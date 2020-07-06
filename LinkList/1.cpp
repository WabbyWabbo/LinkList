#include "LinkList.h"/*
设计一个递归算法，删除不带头节点的单链表L中所有值为x的结点
*/
void DeleteX(LinkList &L, ElemType x)
{
    //p指向待删除的结点
    LNode *p;

    //递归出口
    if (L == NULL)
    {
        return;
    }
    //首结点等于x,则删掉然后递归，否则直接递归
    if (L->data == x)
    {
        p = L;
        L = L->next;
        free(p);
        DeleteX(L, x);
    }
    else
    {
        DeleteX(L->next, x);
    }
}
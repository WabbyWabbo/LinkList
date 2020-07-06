#include "LinkList.h"/*
在带头节点的单链表L中，删除所有值为x的结点，并释放空间，假设x的值不唯一
*/

//解法1
void DeleteX(LinkList &L, ElemType x)
{
    LNode *p = L->next, *pre = L, *q;
    while (p != NULL)
    {
        if (p->data == x)
        {
            //q用于暂存要删的结点
            q = p;
            p = p->next;
            pre->next = p;
            free(p);
        }
        else
        {
            //同步后移
            pre = p;
            p = p->next;
        }
    }
}

//解法2:尾插法
void DeleteX2(LinkList &L, ElemType x)
{
    //r是尾指针，初始位置在L
    LNode *p = L->next, *r = L, *q;
    while (p != NULL)
    {
        if (p->data == x)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            q = p;
            p = p->next;
            free(q);
        }
    }
    //表尾置空
    r->next = NULL;
}

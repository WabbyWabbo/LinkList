#include "LinkList.h"/*
带头节点的单链表L，就地逆置
*/

LinkList ReverseList(LinkList &L)
{
    LNode *p = L->next;
    LNode *q;//q是p的后继，防止断链
    L->next = NULL;

    while (p != NULL)
    {
        //暂存p的后继
        q = p->next;
        //头插法插入p
        p->next = L->next;
        L->next = p;
        //借助q后移一位
        p = q;
    }

    return L;
}

// int main(void)
// {
//     LinkList L = CreateList2(L);
//     PrintList(L);
//     ReverseList(L);
//     PrintList(L);
// }
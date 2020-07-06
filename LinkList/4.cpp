#include "LinkList.h"/*
带头节点的单链表L，删除一个最小值结点（假设是唯一的）
*/

LinkList Delete_Min(LinkList &L)
{
    LNode *pre = L, *p = L->next;
    LNode *minpre = pre, *minp = p;
    //查找最小结点位置
    while(p != NULL)
    {
        if(p->data < minp->data)
        {
            minp = p;
            minpre = pre;
        }

        pre = p;
        p = p->next;
    }
    //删除最小结点
    minpre->next = minp->next;
    free(minp);
    return L;
}
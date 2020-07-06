#include "LinkList.h"
void Delete_Same(LinkList &L)
{
    LNode *p = L->next, *q;
    //因为是比较p和p的后一个是否相同，其实p只需要指到倒数第二个就可以结束了
    while (p->next != NULL)
    {
        q = p->next;
        if (p->data == q->data)
        {
            //删除q结点，并保持p不动，因为q后面可能还有跟p相同的元素
            p->next = q->next;
            free(q);
        }
        else{
            p = p->next;
        }
    }
}
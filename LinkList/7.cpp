#include "LinkList.h"
void Delete_Between(LinkList &L, ElemType min, ElemType max)
{
    LNode *pre = L, *p = L->next;

    while (p != NULL)
    {
        if(p->data > min && p->data < max){
            pre->next = p->next;
            free(p);
            p = pre->next;
        }

        pre = p;
        p = p->next;
    }
}
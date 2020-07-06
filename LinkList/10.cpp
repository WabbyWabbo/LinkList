/*
将一个带有头节点的单链表A分解为两个呆头节点的单链表A和B，
A中保留序号是奇数的元素
B中保留序号是偶数的元素
*/
#include "LinkList.h"
LinkList Split_List(LinkList &A)
{
    LinkList B = (LinkList)malloc(sizeof(LNode));
    LNode *r = B;

    int num = 0;

    LNode *p = A->next;
    LNode *pre;

    while (p != NULL)
    {
        num++;
        if (num % 2 != 0)
        {
            pre = p;//将奇数位置暂存在pre
            p = p->next;
        }
        else
        {
            //尾插法
            r->next = p;
            r = p;

            p = p->next;
            pre->next = p;
        }
    }

    r->next = NULL;

    return B;
}

// int main(void)
// {
//     LinkList A = CreateList2(A);
//     LinkList B = Split_List(A);

//     PrintList(A);
//     PrintList(B);
// }
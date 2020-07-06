#include "LinkList.h"/*
在带头节点的单链表L中，编写算法实现反向输出每个结点的值
*/

void R_Print(LinkList L)
{
   if (L->next != NULL)
    {
        R_Print(L->next);
    }
    
    cout << L->data << "\t";
}

// int main(void)
// {
//     LinkList L;

//     CreateList2(L);

//     PrintList(L);

//     R_Print(L);
// }
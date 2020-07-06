#include "LinkList.h"
void Min_Delete(LinkList &head)
{
    while (head->next != NULL)
    {
        //找到当前链表中最小元素
        LNode *pre = head, *p = head->next;
        LNode *minpre = pre, *min = p;
        while (p != NULL)
        {
            if (p->data < min->data)
            {
                minpre = pre;
                min = p;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        //打印并删除
        cout << min->data << " ";
        minpre->next = min->next;
        free(min);
    }

    //释放头节点
    free(head);
}

// int main(void)
// {
//     LinkList L = CreateList2(L);
//     PrintList(L);
//     Min_Delete(L);
// }
#include "LinkList.h"
LinkList SortList(LinkList &L)
{
    //p为工作指针,遍历无序表
    LNode *p = L->next;
    //r是p的后继，保证不断链
    LNode *r = p->next;
    //q用于从头节点开始，往后遍历有序表，寻找p应插入的位置
    LNode *q;
    //pre用于保存p应插入的位置
    LNode *pre;
    //构造只有一个数据结点的初始有序表
    p->next = NULL;

    p = r;//为了让p先进入无序表
    while(p != NULL)
    {
        r = p->next;
        //遍历有序表查找p的应插入位置
        q = L;
        while(q->next != NULL && q->next->data < p->data)
        {
            q = q->next;
        }
        //完成插入
        pre = q;
        p->next = pre->next;
        pre->next = p;
        //p后移
        p = r;

    }
    return L;
}
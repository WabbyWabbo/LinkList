#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//头插法
LinkList CreateList1(LinkList &L)
{
    LNode *s;
    int x;
    //申请空间且初始化为空表
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }

    return L;
}

//尾插法
LinkList CreateList2(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//按序号查找第i个元素的指针
LNode *GetElem(LinkList L, int i)
{
    int cnt = 1;
    LNode *p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    while (p && cnt < i)
    {
        p = p->next;
        cnt++;
    }
    return p;
}

//按值查找
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

//插入
void ListInsert(LinkList &L, int i, ElemType e)
{
    LNode *p = GetElem(L, i - 1);
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
}

//删除
void ListDelete(LinkList &L, int i)
{
    LNode *p = GetElem(L, i - 1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
}

//表长
int Length(LinkList &L)
{
    int length = 0;
    LNode *p = L->next;

    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    
    return length;
}

//打印 *有头节点* 的单链表
void PrintList(LinkList &L)
{
    LNode *p = L->next;

    if (p == NULL)
    {
        cout << "empty list!";
    }

    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
}
// int main(void)
// {
//     LinkList L;
//     CreateList2(L);

//     PrintList(L);

//     ListInsert(L, 1, 100);
//     PrintList(L);

//     ListDelete(L, 1);
//     PrintList(L);
// }
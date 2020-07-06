#include "LinkList.h"
LinkList Search_1st_Common(LinkList L1, LinkList L2)
{
    int len1 = Length(L1), len2 = Length(L2);
    LinkList longList, shortList;
    int dist = 0;

    //判断谁是长表，求表长之差
    if (len1 > len2)
    {
        longList = L1;
        shortList = L2;
        dist = len1 - len2;
    }
    else
    {
        longList = L2;
        shortList = L1;
        dist = len2 - len1;
    }

    //长表后移dist个结点，与短表并齐
    while(dist != 0){
        longList = longList->next;
        dist--;
    }

    //同步后移，判断是否汇合
    while(longList != NULL)
    {
        if(longList == shortList)
        {
            return longList;
        }
        else
        {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    //退出while时仍未汇合，则无公共结点
    return NULL;
}
/*
point to offer
给定一个单向链表，输出该链表中倒数第K个结点。倒数从1开始计数。
遍历链表一次。
倒数第K个结点，即为正数第n-k+1个结点。
用2个指针进行遍历，第一个指针先走k-1个位置。第二个指针与第一个指针相差k-1，
然后开始一起后移。
当第一个指针走到尾部的时候，也即指向第n个元素时候，第二个指针指向第n-k+1个元素。
*/
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if (!pListHead || k < 1)
        return NULL;
    ListNode* pAhead = pListHead;
    ListNode* pBehind = NULL;
    for (unsigned i = 0; i < k - 1; ++i)
    {
        if (pAhead->m_pNext != NULL)
        {
            pAhead = pAhead->m_pNext;
        }
        else
            return NULL;
    }
    pBehind = pListHead;
    while (pAhead->m_pNext != NULL)
    {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}

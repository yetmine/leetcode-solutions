#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val)
{
    struct ListNode *node;
    
    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (node != NULL)
    {
        node->val = val;
        node->next = NULL;
        return (node);
    }
    return (NULL);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int sum = 0;
    struct ListNode *head = NULL;
    struct ListNode **node = &head;

    while (l1 || l2 || sum) {
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        *node = createNode(sum % 10);
        node = &((*node)->next);
        sum /= 10;
    }
    return (head);
}
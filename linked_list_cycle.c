struct ListNode {
 	int val;
 	struct ListNode *next;
 };

int hasCycle(struct ListNode *head) {
	if (head == 0 || head->next == 0)
		return 0;
	struct ListNode *slow = head;
	struct ListNode *fast = head->next;

	while (fast->next && fast->next->next)
	{
		if (fast == slow)
			return 1;
		fast = fast->next->next;
		slow = slow->next;
	}
	return 0;
}

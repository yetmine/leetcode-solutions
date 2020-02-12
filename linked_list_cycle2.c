
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
	if (head == 0 || head->next == 0)
		return 0;
	struct ListNode *slow = head;
	struct ListNode *fast = head;

	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			slow = head;
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return 0;
}

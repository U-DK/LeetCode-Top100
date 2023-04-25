#pragma once
#include "No_0_common.h"

class No_19
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		if (NULL == head || NULL == head->next)
		{
			return NULL;
		}
		ListNode* fast = head;
		for (int i = 0; i != n; ++i)
		{
			fast = fast->next;
		}
		if (NULL== fast)
		{
			return head->next;
		}

		ListNode* slow = head;
		while (NULL != fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return head;

	}
};
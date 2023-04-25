#pragma once
#include "No_0_common.h"

class No_24
{
public:
	ListNode* swapPairs(ListNode* head)
	{
		ListNode* temp = new ListNode();
		temp->next = head;
		ListNode* prev = temp;
		while (head && head->next)
		{
			prev->next = head->next;
			head->next = head->next->next;
			prev->next->next = head;

			prev = head;
			head = head->next;
		}
		return temp->next;
	}
};
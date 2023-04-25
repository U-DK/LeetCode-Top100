#pragma once
#include "No_0_common.h"

class 
{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		if (NULL==list1)
		{
			return list2;
		}
		if (NULL==list2)
		{
			return list1;
		}

		if (list1->val<=list2->val)
		{
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}
		list2->next = mergeTwoLists(list2->next, list1);
		return list2;
	}
	ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2)
	{
		if (NULL == list1)
		{
			return list2;
		}
		if (NULL == list2)
		{
			return list1;
		}
		ListNode* head = NULL;
		ListNode* high = NULL;

		if (list2->val > list1->val)
		{
			head = list1;
			high = list2;
		} else
		{
			head = list2;
			high = list1;
		}
		ListNode* low = head;
		ListNode* temp = NULL;
		while (low->next != NULL && high != NULL)
		{
			if (low->next->val > high->val)
			{
				temp = low->next;
				low->next = high;
				high = temp;
			} else
			{
				low = low->next;
			}
		}
		if (high != NULL)
		{
			low->next = high;
		}
		return head;
	}
};
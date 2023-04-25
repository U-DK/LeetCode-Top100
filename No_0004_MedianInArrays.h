#pragma once
#include "No_0_common.h"

class No_4
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		if (nums1.size() <= 0 && nums2.size() <= 0)
		{
			return (double)0;
		}
		int count = nums1.size() + nums2.size();
		if (1==count)
		{
			return 0 == nums1.size() ? (double)nums2[0] : (double)nums1[0];
		}
		if (2==count)
		{
			if (nums1.size() <= 0)
			{
				return (double)(nums2[0] + nums2[1]) / 2;
			}
			if (nums2.size() <= 0)
			{
				return (double)(nums1[0] + nums1[1]) / 2;
			}
			return (double)(nums1[0] + nums2[0]) / 2;
		}
		bool needMore = (0 == count % 2);
		int target = count / 2;
		target = needMore ? target : target + 1;

		//vector<int> num;
		int candidate = -1;
		int totalCount = 0;
		int fast = 0, slow = 0;
		while (fast<nums1.size()&&slow<nums2.size())
		{
			if (nums1[fast] <= nums2[slow])
			{
				//num.push_back(nums1[fast]);
				candidate = nums1[fast];
				++totalCount;
				++fast;
			}
			else
			{
				//num.push_back(nums2[slow]);
				candidate = nums2[slow];
				++totalCount;
				++slow;
			}
			if (totalCount>=target)
			{
				break;
			}
		}
		if (fast>=nums1.size())
		{
			while (totalCount<target)
			{
				//num.push_back(nums2[slow]);
				candidate = nums2[slow];
				++totalCount;
				++slow;
			}
		}
		else
		{
			while (totalCount <target)
			{
				//num.push_back(nums1[fast]);
				candidate = nums1[fast];
				++totalCount;
				++fast;
			}
		}
		if (needMore)
		{
			if (fast >= nums1.size())
			{
				return (double)(candidate + nums2[slow]) / 2;
			}
			if (slow>=nums2.size())
			{
				return (double)(candidate + nums1[fast]) / 2;
			}
			return (double)(candidate + min(nums1[fast],nums2[slow])) / 2;
		}
		return (double)candidate;
	}

	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2)
	{
		/// <summary>
		/// 1, 2, 3, 4 ||20
		/// 8 || 15, 17, 21
		/// 1, 2, 3, 4, 8 || 15, 17, 20, 21
		/// </summary>
		/// 1 2||3 4 20
		/// 8 15 17||21
		/// <returns></returns>

		int n1 = nums1.size(), n2 = nums2.size();
		if (0 == n1 && 0 == n2)
		{
			return 0.0f;
		}
		if (n1>n2)
		{
			return findMedianSortedArrays2(nums2, nums1);
		}
		int totalCut = (n1 + n2 + 1) / 2;


		int cut1, cut2;
		int leftMost1, leftMost2, rightLeast1, rightLeast2;
		int low = 0, high = n1;
		while (low<=high)
		{
			cut1 = (low + high) / 2;
			cut2 = totalCut - cut1;
			leftMost1 = 0 == cut1 ? INT_MIN : nums1[cut1 - 1];
			leftMost2 = 0 == cut2 ? INT_MIN : nums2[cut2 - 1];
			rightLeast1 = cut1 >= n1 ? INT_MAX : nums1[cut1];
			rightLeast2 = cut2 >= n2 ? INT_MAX : nums2[cut2];
			if (leftMost1 <= rightLeast2 && leftMost2 <= rightLeast1)
			{
				return 0 == (n1 + n2) % 2 ? (max(leftMost1, leftMost2) + min(rightLeast1, rightLeast2)) / 2.0f : (max(leftMost1, leftMost2));
			}
			else if (leftMost1 > rightLeast2)
			{
				high = cut1 - 1;
			}
			else
				low = cut1 + 1;
		}
		return 0.0f;
	}
};
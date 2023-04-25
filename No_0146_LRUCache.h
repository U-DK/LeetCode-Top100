#pragma once
#include "No_0_common.h"
#include <unordered_map>

class No_146_LRUCache
{
	using listIter = list<pair<int, int>>::iterator;
public:
	int size;
	unordered_map<int, listIter> map;
	list<pair<int, int>> listPair;
	No_146_LRUCache(int capacity):size(capacity)
	{

	}

	int get(int key)
	{
		auto iter = map.find(key);
		if (iter!=map.end())
		{
			auto l = iter->second;
			listPair.splice(listPair.begin(), listPair, l);
			return l->second;
		}
		return -1;
	}

	void put(int key, int value)
	{
		auto iter = map.find(key);
		if (iter != map.end())
		{
			auto l = iter->second;
			l->second = value;
			listPair.splice(listPair.begin(), listPair, l);
		}
		else
		{
			if (map.size() >= size)
			{
				auto back = listPair.back();
				listPair.pop_back();
				map.erase(back.first);
			}
			listPair.push_front({ key,value });
			map[key] = listPair.begin();
		}
	}
};
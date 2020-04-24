#include "ListAndVector.h"
#include <vector>
#include <list>

void BuildVector(const int& size, std::vector<int>& v)
{
	for (int i = 0; i < size; i++)
	{
		int r = (int)rand();
		bool inserted = false;
		for (auto it = begin(v); it != end(v); it++)
		{
			if (*it > r)
			{
				v.insert(it, r);
				inserted = true;
				break;
			}
		}
		if (!inserted)
		{
			v.push_back(r);
		}
	}
}

void BuildList(const int& size, std::list<int>& l)
{
	for (int i = 0; i < size; i++)
	{
		int r = (int)rand();
		bool inserted = false;
		for (auto it = begin(l); it != end(l); it++)
		{
			if (*it > r)
			{
				l.insert(it, r);
				inserted = true;
				break;
			}
		}
		if (!inserted)
			l.push_back(r);
	}
}

#pragma once

#include <iostream>
#include <list>
#include <exception>
#include "Exception.h"

template <typename T>
struct MyComparator {
	T operator()(T a, T b) const {
		return a - b;
	}
};
//-----------------------------------
template <typename T>
class PriorityQueue
{
public:
	PriorityQueue() {}

	void push(const T& t);
	T poll();

private:
	std::list<T> m_list;
	MyComparator<T> m_comparator;
};
//------------------------------------
template<typename T>
inline void PriorityQueue<T>::push(const T& t)
{
	for (auto it = m_list.begin(); it != m_list.end(); ++it)
		if (m_comparator(t, *it) < 0) {
			m_list.insert(it, t);
			return;
		}

	m_list.push_back(t);
}
//--------------------------------
template<typename T>
inline T PriorityQueue<T>::poll()
{
	if (m_list.empty())
		throw EmptyList("PriorityQueue empty!");

	T frontT = m_list.front();
	m_list.pop_front();

	return frontT;
}

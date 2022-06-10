#pragma once
#ifndef STACK1_H
#define STACK1_H

#include <vector>
#include <cassert>
#include <iostream>

template <typename T>
class Stack
{
private:
	std::vector<T> m_elements{};

public:
	Stack(std::initializer_list<T> args)
	{
		m_elements.insert(m_elements.end(), args.begin(), args.end());
	}

	void push(T const& element);
	T pop();

	const T top() const&;

	bool empty() const { return m_elements.empty(); }
	size_t size() const { return this->m_elements.size(); }
	const T& operator[](const size_t index) const& { return this->m_elements.at(index); }

	friend std::ostream& operator << (std::ostream& out, const Stack<T>& stackObj)
	{
		out << "Top of stack: " << stackObj.top() << '\n';

		for (int i = static_cast<int>(stackObj.size() - 1); i >= 0; --i)
		{
			out << stackObj[i] << '\n';

			if (i == 0)
				out << "Bottom: " << stackObj[i];
		}

		return out;
	}
};

#endif // !STACK1

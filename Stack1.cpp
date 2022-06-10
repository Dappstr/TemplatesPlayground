#include "Stack1.h"

template <typename T>
void Stack<T>::push(T const& element)
{
	m_elements.push_back(element);
}

template <typename T>
T Stack<T>::pop()
{
	assert(!m_elements.empty());
	T elem = m_elements.back();
	m_elements.pop_back();
	return elem;
}

template <typename T>
const T Stack<T>::top() const&
{
	assert(!m_elements.empty());
	return m_elements.back();
}

template class Stack<int>;
//#include "Sequence.hpp"
//#include "DynamicArray.hpp"
//#pragma once
//
//
//template <class T>
//class Stack
//{
//private:
//	Sequence<T>* items;
//public:
//	Stack();
//	Stack(const T* items, const int count);
//	Stack(Sequence<T>* items)
//	{
//		//this->items = items;
//		this->items = new ArraySequence<T>();
//		for (int i = 0; i < items->GetLength(); i++)
//			this->items->Append(items->Get(i));
//	}
//public:
//	int GetSize()
//	{
//		return this->items->GetLength();
//	}
//	bool IsEmpty()
//	{
//		return this->items->GetLength() == 0;
//	}
//	T Peek(const int index = 0) const
//	{
//		if (index < 0 || index >= this->items->GetLength())
//			throw new Exception;
//		return items->Get(index);
//	}
//	T Pop()
//	{
//		if (this->items->GetLength() <= 0)
//			throw new Exception;
//		auto item = this->items->GetFirst();
//		this->items->RemoveAt(0);
//		return item;
//	}
//public:
//	void Push(T item)
//	{
//		this->items->Prepend(item);
//	}
//};
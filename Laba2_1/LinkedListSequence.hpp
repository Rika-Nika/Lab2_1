#pragma once
#include "Sequence.hpp"
#include "LinkedList.hpp"
#include "Exception.h"
#include <iostream>

template <class T>
class  LinkedListSequence : public Sequence<T>
{
private:
	LinkedList<T>* items;
	int count;

public:
	//Создать пустой список
	LinkedListSequence() {
		this->items = new LinkedList<T>();
		this->count = 0;
	};

	LinkedListSequence(const LinkedListSequence<T>& list) {

		this->items = list.GetSubList(0, list.GetSize() - 1);
		this->count = 0;
	};


	LinkedListSequence(T* items, int count) {

		this->items  = new LinkedList<T>(items,count);
		this->count = count;

	};
	int GetLength()const override {
		return this->count;
	} ;
	T GetFirst()const override {
		return this->items->GetFirst();
	};
	T GetLast() const override {
		return this->items->GetLast();
	};
	T Get(const int i)const override {
		return this->items->GetNth(i);
	};
	Sequence<T>* GetSubsequence(const int start, const int end) const override {
		LinkedListSequence<T> * sq = new LinkedListSequence<T>();
		sq->count = end - start;
		sq->items=this->items->GetSubList(start, end);
		return sq;
		 
	};
	void Print()const override {
		this->items->printList();
	};
	bool Equals(const Sequence<T>& sequence) const override {
		//this->items->Equals(sequence.GetFirst());
		return NULL;
	};
	void Append(T value) {
	    this->items->Append(value);
		this->count++;
	};
	void Prepend(T value)  {
		this->items->Prepend(value);
		this->count++;
	};
	void InsertAt(const int index, T value) {
		this->items->InsertAt(value, index);
		this->count++;
	};
	void RemoveAt(const int index) {
		this->items->RemoveAt(index);
		this->count--;

	};
	// Удаляет первое вхождение value
	void Remove(T value) {}; 
	void RemoveAll() {
		//this->items-> GetHead () = NULL;
		//this->items->GetTail() = NULL;
		//this->size = 0;
	};

	Sequence<T>* Concat(Sequence<T>* other) {
		int size1 = this->GetLength();
		int size2 = other->GetLength();
		Sequence<int>* seq = new LinkedListSequence <int>();
		for (int i = 0; i < size1; i++) {
			seq->Prepend(this->Get(i));
		}
		for (int i = size1; i < size1 + size2; i++) {
			seq->Prepend(other->Get(i - size1));
		}

		return seq;
	};

	~LinkedListSequence() {};

};


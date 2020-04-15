#pragma once
#include"Exception.h"
#include <string>
#include <cassert> 


template <class T>
class LinkedList
{
	struct node
	{
		T data;
		node* next;
	};
private:
	node* head, * tail;
	int size;
public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void add_node(T value)
	{
		node* tmp = new node;
		tmp->data = value;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
		size++;

	}

	node* gethead()
	{
		return head;
	}

	/*static void display(LinkedList :: head )
	{
		if (head == NULL)
		{
			std::cout << "NULL" << std::endl;
		}
		else
		{
			std::cout << head->data << std::endl;
			display(head->next);
		}
	}*/
	void printItem(int data) {
		std::cout << data << "\n";
	}
	void printItem(double data) {
		std::cout << data << "\n";
	}

	void printItem(std::string data) {
		std::cout << data << "\n";
	}
	void printList()
	{
		node* temp = this->head;
		while (temp != NULL)
		{
			printItem(temp->data);
			temp = temp->next;
		}
	}


	 bool EqualsItem(int value1, int value2) {
		return value1 == value2;
	}
	 bool EqualsItem(std::string value1, std::string value2) {
		return value1 == value2;
	}

	 bool EqualsItem(double value1, double value2) {
		return value1 == value2;
	}

	void concatenate(node* a, node* b)
	{
		if (a != NULL && b != NULL)
		{
			if (a->next == NULL)
				a->next = b;
			else
				concatenate(a->next, b);
		}
		else
		{
			std::cout << "Either a or b is NULL\n";
		}
	}

	//index>0>getsize


	int GetNth(int index)
	{
		if (index < 0 || index >size - 1)
		{
			throw Exception("IndexOutOfRange");
		}
		node* current = head;
		int count = 0;
		while (current != NULL)
		{
			if (count == index)
				return(current->data);
			count++;
			current = current->next;
		}
		//	assert(0);
	}



	T GetFirst()
	{
		if (size == 0)
		{
			throw Exception("IndexOutOfRange");
		}

		return this->head->data;

	}

	T GetLast()
	{
		if (size == 0)
		{
			throw Exception("IndexOutOfRange");
		}

		return this->tail->data;

	}

	T GetSize()
	{

		return size;
	}

	void Append(T value)
	{
		if (head == NULL)
		{
			add_node(value);
		}
		else
		{
			node* tmp = new node;
			tmp->data = value;
			tmp->next = head;
			head = tmp;
		}
		size++;
	}
	void Prepend(T value)
	{
		add_node(value);
	}
};

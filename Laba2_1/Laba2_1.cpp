// Laba2_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"ArraySequence.hpp"
#include"Sequence.hpp"
#include <iostream>
#include "DynamicArray.hpp"
#include "Exception.h"
#include "LinkedList.hpp"

void testDinArrGet() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		DynamicArray<int>* da = new DynamicArray<int>(testArr, SIZE);
		for (int i = 0; i < SIZE; i++) {
			res = res && (testArr[i] == da->Get(i));
		}
		da->Get(SIZE + 1);
	}
	catch (Exception& exception) {
		if (res) {
			std::cout << "testDinArrGet passed\n";
		}
		else {
			std::cout << "testDinArrGet failed\n";
		}
	}

}
void testDinArrGetSize() {
	const int SIZE = 3;
	DynamicArray<int>* da = new DynamicArray<int>(SIZE);
	int v = da->GetSize();
	if (v == SIZE) {
		std::cout << "testDinArrGetSize passed\n";
	}
	else {
		std::cout << "testDinArrGetSize failed\n";
	}
}

void testDinArrCreateFromArray() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222};
	try {
		DynamicArray<int>* da = new DynamicArray<int>(testArr, SIZE);
		for (int i = 0; i < SIZE; i++) {
			res = res && (testArr[i] == da->Get(i));
		}
		if (res) {
			std::cout << "testDinArrCreateFromArray passed\n";
		}
		else {
			std::cout << "testDinArrCreateFromArray failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testDinArrCreateFromArray failed\nException: " << exception.what() << "\n";
	}

}
void testDinArrCreateFromDinArr() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		DynamicArray<int>* da = new DynamicArray<int>(testArr, SIZE);
		DynamicArray<int>* da2 = new DynamicArray<int>(*da);
		if (da->Equals(*da2)) {
			std::cout << "testDinArrCreateFromDinArr passed\n";
		}
		else {
			std::cout << "testDinArrCreateFromDinArr failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testDinArrCreateFromDinArr failed\nException: " << exception.what() << "\n";
	}
}
void testDinArrResize() {
	const int SIZE = 5;
	const int SIZE1 = 7;
	const int SIZE2 = 3;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr1[SIZE1] = { 11, 112, 23, 153, 122222, 0, 0 };
	int testArr2[SIZE2] = { 11, 112, 23 };
	try {
		DynamicArray<int>* da = new DynamicArray<int>(testArr, SIZE);
		DynamicArray<int>* da1 = new DynamicArray<int>(testArr1, SIZE1);
		DynamicArray<int>* da2 = new DynamicArray<int>(testArr2, SIZE2);
		da->Resize(SIZE1);
		if (da->Equals(*da1)) {
			std::cout << "testDinArrResize to large passed\n";
		}
		else {
			std::cout << "testDinArrResize to large failed\n";
		}
		da->Resize(SIZE2);
		if (da->Equals(*da2)) {
			std::cout << "testDinArrResize to small passed\n";
		}
		else {
			std::cout << "testDinArrResize to small failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testDinArrResize failed\nexception\nException: " << exception.what() << "\n";
	}
}

void testDinArr() {
	std::cout << "________________ Start testing DynamicArray ________________\n";
	testDinArrGetSize();
	testDinArrCreateFromArray();
	testDinArrGet();
	testDinArrCreateFromDinArr();
	testDinArrResize();
	std::cout << "________________ End testing DynamicArray __________________\n";
}


void testArraySequenceCreateFromArray() {
	int const SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq2 = new ArraySequence<int>(testArr, SIZE);
		for (int i = 0; i < SIZE; i++) {
			res = res && (testArr[i] == seq2->Get(i));
		}
		if (res) {
			std::cout << "testArraySequenceCreateFromArray passed\n";
		}
		else {
			std::cout << "testArraySequenceCreateFromArray failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceCreateFromArray failed\nException: " << exception.what() << "\n";
	}
}

void testArraySequenceGetLength() {
	int const SIZE = 5;
	Sequence<int>* seq = new ArraySequence<int>(SIZE);
	int v = seq->GetLength();
	if (v == 0) {
		std::cout << "testArraySequenceGetLength passed\n";
	}
	else {
		std::cout << "testArraySequenceGetLength failed\n";
	}
}

void testArraySequenceGet() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence<int>(testArr, SIZE);
		for (int i = 0; i < SIZE; i++) {
			res = res && (testArr[i] == seq->Get(i));
		}
		seq->Get(SIZE + 1);
	}
	catch (Exception& exception) {
		if (res) {
			std::cout << "testArraySequenceGet passed\n";
		}
		else {
			std::cout << "testArraySequenceGet failed\n";
		}
	}

}
void testArraySequenceGetFirst() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int v;
	try {
		Sequence<int>* seq = new ArraySequence<int>(testArr, SIZE);
		v = seq->GetFirst();
		if (v == testArr[0]) {
			std::cout << "testArraySequenceGetFirst passed\n";
		}
		else {
			std::cout << "testArraySequenceGetFirst failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceGetFirst failed\nException: " << exception.what() << "\n";
	}
}
void testArraySequenceGetLast() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int v;
	try {
		Sequence<int>* seq = new ArraySequence<int>(testArr, SIZE);
		v = seq->GetLast();
		if (v == testArr[SIZE - 1]) {
			std::cout << "testArraySequenceGetLast passed\n";
		}
		else {
			std::cout << "testArraySequenceGetLast failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceGetLast failed\nException: " << exception.what()<<"\n";
	}
}
void testArraySequencePrepend() {
	const int SIZE = 5;
	const int START = 2;
	const int END = 4;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE+1] = { 11, 112, 23, 153, 122222, 777 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		seq->Prepend(777);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testArraySequencePrepend passed\n";
		}
		else {
			std::cout << "testArraySequencePrepend failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequencePrepend failed\nException: " << exception.what() << "\n";
	}
}

void testArraySequenceAppend() {
	const int SIZE = 5;
	const int START = 2;
	const int END = 4;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE + 1] = { 777, 11, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		seq->Append(777);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testArraySequenceAppend passed\n";
		}
		else {
			std::cout << "testArraySequenceAppend failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceAppend failed\nException: " << exception.what() << "\n";
	}
}

void testArraySequenceInsertAt() {
	const int SIZE = 5;
	const int INDEX = 2;
	bool res = true;
	int testArr[SIZE] = {11, 112, 23, 153, 122222};
	int testArr2[SIZE + 1] = {11, 112, 777, 23, 153, 122222};
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		seq->InsertAt(INDEX, 777);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testArraySequenceInsertAt passed\n";
		}
		else {
			std::cout << "testArraySequenceInsertAt failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceInsertAt failed\nException: " << exception.what() << "\n";
	}
}

void testArraySequenceRemoveAt() {
	const int SIZE = 5;
	const int INDEX = 2;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE - 1] = { 11, 112, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		seq->RemoveAt(INDEX);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testArraySequenceRemoveAt passed\n";
		}
		else {
			std::cout << "testArraySequenceRemoveAt failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceRemoveAt failed\nException: " << exception.what() << "\n";
	}
}

void testArraySequenceRemove() {
	const int SIZE = 5;
	const int item = 23;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE - 1] = { 11, 112, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		seq->Remove(item);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testArraySequenceRemove passed\n";
		}
		else {
			std::cout << "testArraySequenceRemove failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceRemove failed\nException: " << exception.what() << "\n";
	}
}
void testArraySequenceRemoveAll() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		seq->RemoveAll();

		if (seq->GetLength() == 0) {
			std::cout << "testArraySequenceRemoveAll passed\n";
		}
		else {
			std::cout << "testArraySequenceRemoveAll failed\n";
		}
}

void testArraySequenceConcat() {
	const int SIZE1 = 5;
	const int SIZE2 = 6;
	bool res = true;
	int testArr1[SIZE1] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE2] = { 77, 177, 723, 7153, 7122222, 456 };
	int testArr3[SIZE1 + SIZE2] = { 11, 112, 23, 153, 122222, 77, 177, 723, 7153, 7122222, 456};
	Sequence<int>* seq1 = new ArraySequence <int>(testArr1, SIZE1);
	Sequence<int>* seq2 = new ArraySequence <int>(testArr2, SIZE2);
	Sequence<int>* seq3 = seq1->Concat(seq2);
	seq1->PrintArray();
	seq2->PrintArray();
	seq3->PrintArray();
	if (seq3->GetLength() == SIZE1 + SIZE2) {
		for (int i = 0; i < SIZE1 + SIZE2; i++) {
			res = res && seq3->Get(i) == testArr3[i];
		}
		if (res) std::cout << "testArraySequenceConcat passed\n";
	}
	else {
		std::cout << "testArraySequenceConcat failed\n";
	}
}

void testArraySequenceGetSubsequence() {
	const int SIZE = 5;
	const int START = 2;
	const int END = 4;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		Sequence<int>* subSeq = seq->GetSubsequence(START, END);
		for (int i = 0; i < END - START+1 ; i++) {
			res = res && (subSeq->Get(i) == testArr[i + START]);
		}
		if (res) {
			std::cout << "testArraySequenceGetSubsequence passed\n";
		}
		else {
			std::cout << "testArraySequenceGetSubsequence failed\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceGetSubsequence failed\nException: " << exception.what()<<"\n";
	}
}


void testArraySequence() {
	std::cout << "________________ Start testing ArraySequence _______________\n";
	testArraySequenceGetLength();
	testArraySequenceCreateFromArray();
	testArraySequenceGet();
	testArraySequenceGetFirst();
	testArraySequenceGetLast();
	testArraySequencePrepend();
	testArraySequenceAppend();
	testArraySequenceGetSubsequence();
	testArraySequenceInsertAt();
	testArraySequenceRemoveAt();
	testArraySequenceRemove();
	testArraySequenceRemoveAll();
	testArraySequenceConcat();
	std::cout << "________________ End testing ArraySequence _________________\n";
}
void testLinkedListCreate() {
	LinkedList<std::string>* ls = new LinkedList<std::string>();
	int n = 5;
	for (int i = 0; i < n; i++) {
		ls->add_node(std::to_string(i+1.1)+ " aaaaaaaaaaaaA");
	}
	ls->printList();
};

void testLinkedListGetFirst() {

	LinkedList <int>* first = new LinkedList <int>();
	int n = 100;
	for (int i = 0; i < n; i++) {
		first->add_node(i);
	}
	int f = first->GetFirst();
	if (f == 0) {
		std::cout << "testLinkedListGetFirst passed\n";
	}
	else {
		std::cout << "testLinkedListGetFirst failed\n";
	}
};

void testLinkedListGetLast() {

	LinkedList <int>* last = new LinkedList <int>();
	int n = 100;
	for (int i = 0; i < n; i++) {
		last->add_node(i);
	}
	int l = last->GetLast();
	if (l == 99) {
		std::cout << "testLinkedListGetLast passed\n";
	}
	else {
		std::cout << "testLinkedListGetLast failed\n";
	}
};

void testLinkedListGetSize() {

	LinkedList <int>* first = new LinkedList <int>();
	int n = 100;
	for (int i = 0; i < n; i++) {
		first->add_node(i);
	}
	int f = first->GetSize();
	if (f == 100) {
		std::cout << "testLinkedListGetSize passed\n";
	}
	else {
		std::cout << "testLinkedListGetSize failed\n";
	}
};

void testLinkedListGetNth()
{
	LinkedList <int>* Nth = new LinkedList <int>();
	int n = 100;
	for (int i = 0; i < n; i++) {
		Nth->add_node(i);
	}
	int a = Nth->GetNth(10);
	if (a == 9) {
		std::cout << "testLinkedListGetNth passed\n";
	}
	else {
		std::cout << "testLinkedListGetNth failed\n";
	}

};


void testLinkedList() {
	std::cout << "________________ Start testing testLinkedList _______________\n";
	testLinkedListCreate();
	testLinkedListGetFirst();
	testLinkedListGetLast();
	testLinkedListGetSize();
	testLinkedListGetNth();
	std::cout << "________________ End testing testLinkedList _________________\n";
}




int main()
{
	testDinArr();
	testArraySequence();
	testLinkedList();

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

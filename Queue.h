#pragma once
#include "Element.h"
#include <iostream>

using namespace std;

template <typename DataType>
class Queue
{
public:
	Queue();
	~Queue();
	void Push(DataType D);
	DataType Pull();
	void PrintState();
private:
	Element<DataType> * Start;
	Element<DataType> * End;
};

template <typename DataType>
Queue<DataType>::Queue()
{
	Start = nullptr;
	End = nullptr;
}

template <typename DataType>
Queue<DataType>::~Queue()
{
	while (Start != nullptr) {
		PrintState();
		Pull();
	}
	PrintState();
}

template <typename DataType>
void Queue<DataType>::Push(DataType D) {
	Element<DataType> * NewElement = new Element<DataType>(D);
	if (Start == nullptr) {
		Start = NewElement;
	}
	else
	{
		End->Next = NewElement;
	}
	End = NewElement;
}

template <typename DataType>
DataType Queue<DataType>::Pull() {
	if (Start == nullptr) {
		throw "Queue is empty";
	}
	Element<DataType> * NewStart = Start->Next;
	DataType RetunValue = Start->Data;
	delete Start;
	Start = NewStart;
	return RetunValue;
}

template <typename DataType>
void Queue<DataType>::PrintState() {
	if (Start == nullptr) {
		cout << "Queue is empty" << endl;
		return;
	}
	Element<DataType> * Elem = Start;
	cout << "List of elements:" << endl;
	do
	{
		cout << Elem->Data << " ";
		Elem = Elem->Next;
	} while (Elem != nullptr);
	cout <<endl;
}
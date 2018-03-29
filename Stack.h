#pragma once
#include "Element.h"
#include <iostream>

using namespace std;
template<typename DataType>
class Stack
{
public:
	Stack();
	~Stack();
	void Push(DataType D);
	DataType Pull();
	void PrintState();
private:
	Element<DataType> * End; //��������� �� ��������
};

template<typename DataType>
Stack<DataType>::Stack()
{
	End = nullptr;
}

template<typename DataType>
Stack<DataType>::~Stack()
{
	while (End != nullptr) {
		Pull(); //����������� ��� �������� ���� ������ �� ���������
	}
}

template<typename DataType>
void Stack<DataType>::Push(DataType D) {
	Element <DataType>* NewElement = new Element<DataType>(D);
	if (End != nullptr) { 
		NewElement->Next = End; // ���� ���-�� � ����� ����, �� end 
	}
	End = NewElement; 
}

template<typename DataType>
DataType Stack<DataType>::Pull() { //����������
	if (End == nullptr) {
		throw "Stack is empty!";
	}
	DataType RetunValue = End->Data; //��������, ������� �����������( ���� ������� � ���� �������� ����� ��������)
	Element <DataType>* NewEnd = End->Next; //���� ��������� �������� � ����� ��� end
	delete End;
	End = NewEnd;
	return RetunValue;
}

template<typename DataType>
void Stack<DataType>::PrintState() {
	if (End == nullptr) {
		cout << "Stack is empty" << endl;
		return;
	}
	Element<DataType> * Elem = End;
	cout << "List of elements:" <<endl;
	do
	{
		cout << Elem->Data << " "; //������ �������� ��������
		Elem = Elem->Next;
	} while (Elem != nullptr);
	  cout <<endl;
}

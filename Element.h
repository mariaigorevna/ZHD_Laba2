
#pragma once

template <typename DataType>
class Element
{
public:
	Element(DataType D);
	DataType Data;
	Element<DataType> * Next; //указатель на объект класса элемент типа DT

};

template <typename DataType>
Element<DataType>::Element(DataType D)
{
	Data = D; //передаю значени в конструктор, и он записывается в это  элемент
	Next = nullptr;
}


#pragma once

template <typename DataType>
class Element
{
public:
	Element(DataType D);
	DataType Data;
	Element<DataType> * Next; //��������� �� ������ ������ ������� ���� DT

};

template <typename DataType>
Element<DataType>::Element(DataType D)
{
	Data = D; //������� ������� � �����������, � �� ������������ � ���  �������
	Next = nullptr;
}

#include "stdafx.h"
#include "Stack.h"
#include <fstream>

using namespace std;

struct Vagon
{
	char Type;
	int Number;
};

int main()
{
	ifstream infile("Input.txt");
	ofstream outfile("Output.txt");
	if ((!infile) || (!outfile)) {
		return 1;
	}

	Stack<Vagon> * Tupic = new Stack<Vagon>;
	char LastType = 0; //тип последнего вагона,записанного в выходной файл
	char StackType = 0; //тип вагонов в стэке
	while (!infile.eof()) { //не закончился
		Vagon CurrentVagon; //объявляем переменную типа вагон
		infile >> CurrentVagon.Type >> CurrentVagon.Number; //считываю из файла в эту переменную значение
		if (CurrentVagon.Type != LastType) { // если текущий тип не соответсвтует типа последнего вагона записанного в файл
			outfile << CurrentVagon.Type << " " << CurrentVagon.Number <<endl; // и записывается в файл
			LastType = CurrentVagon.Type; 
			continue;
		}
		if (StackType == CurrentVagon.Type) { // если одинаковые типы, тогда  проверяю тип в стэке, если они равны
			Tupic->Push(CurrentVagon); // засунуть текущий вагон в стек
			continue;
		}
		Vagon StackVagon; // если в стеке вагон другого типа
		try { StackVagon = Tupic->Pull(); } // пытаемся взять из стэка вагон
		catch (...) {
			Tupic->Push(CurrentVagon); // если стек пустой
			StackType = CurrentVagon.Type; // засовываем текущий вагон в стэк
			continue;
		}
		outfile << StackVagon.Type << " " << StackVagon.Number << endl; // когда взяли вагон из стека, вначала в выходной записываем вагон из стэка
		outfile << CurrentVagon.Type << " " << CurrentVagon.Number << endl; // затем записываем текущий вагон
	}
	infile.close();
	outfile.close();
	return 0;
}



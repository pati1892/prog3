// Unit_4.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
// Mat.Nr.: 511407, Henkelmann Patrick

#include "stdafx.h"
#include <iostream>
#include <crtdbg.h>
#include <stdlib.h>
using namespace std;


class CopyJaggedArray {
public:
	CopyJaggedArray::CopyJaggedArray(char *array[]) {
		length(array);
		copyArray(array);		
	}
	CopyJaggedArray::CopyJaggedArray(char *array[], int length):sizeFirstDim(length){
		copyArray(array);
	}
	CopyJaggedArray::~CopyJaggedArray() {
		for (int i = 0; i < sizeFirstDim+1; ++i) {
			delete [] bufferArray[i];
		}
		delete [] bufferArray;
	}
	char **getCopy() {
		return bufferArray;
	}
	int getLength() {
		return sizeFirstDim;
	}

	void sort() {
		auto func = [](const void *a, const void *b)  {
			char* const *ia = static_cast<char* const*>(a);
			const char *ib = *(const char **)b;
			return strcmp(*ia, ib);
		};
		qsort(bufferArray, sizeFirstDim, sizeof(char*), func);
	}



private:
	char **bufferArray;
	int sizeFirstDim;

	void copyArray(char **array) {
		bufferArray = new char*[sizeFirstDim + 1];
		for (int i = 0; i < sizeFirstDim; ++i) {
			bufferArray[i] = new char[length(array[i])+1];
			strcpy(bufferArray[i], array[i]);
		}
		bufferArray[sizeFirstDim] = nullptr;
	}

	int length(char *array) {
		int size = 0;
		while (array[size] != '\0')
			++size;
		return size;
	}

	void length(char **array) {
		sizeFirstDim = 0;
		while (array[sizeFirstDim] != '\0')
			++sizeFirstDim;
	}
};

void printArray(CopyJaggedArray &array) {
	for (int i = 0; i < array.getLength(); ++i)
		cout << array.getCopy()[i] << endl;
}

int main(int argc, char *argv[], char *envp[])
{

	CopyJaggedArray *argvpCopy = new CopyJaggedArray(argv, argc);
	CopyJaggedArray *envpCopy= new CopyJaggedArray(envp);

	cout << "Arguments before sort:" << endl;
	printArray(*argvpCopy);
	cout << "\nEnvironment parameters before sort:" << endl;
	printArray(*envpCopy);
	
	envpCopy->sort();
	argvpCopy->sort();

	cout << "\nArguments after sort:" << endl;
	printArray(*argvpCopy);
	cout << "\nEnvironment parameters after sort:" << endl;
	printArray(*envpCopy);

	delete argvpCopy;
	delete envpCopy;

	if (_CrtDumpMemoryLeaks()) {
		cout << "MEMORY LEAK PANIC" << endl;
	}
	
	return 0;
}
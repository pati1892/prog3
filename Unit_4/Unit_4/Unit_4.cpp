// Unit_4.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

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
	char** getCopy() {
		return bufferArray;
	}
	int getLength() {
		return sizeFirstDim;
	}

	void sort() {
		auto func = [](const void *a, const void *b)  {
			const char *ia = *(const char **)a;
			const char *ib = *(const char **)b;
			return strcmp(ia, ib);
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

int main(int argc, char *argv[], char *envp[])
{
	/*cout << "ARGUMENTE" << endl;
	for (int i = 0; i < argc; ++i)
		cout << argv[i] << endl;

	cout << "ENVIRONMENT" << endl;
	int i = 0;
	while (envp[i] != '\0') {
		cout << envp[i] << endl;
		++i;

	}
	int size = 0;
	while (envp[size] != nullptr )
		++size;
	char **bufferEnvp = new char*[size+1];

	for (int i = 0; i < size ; ++i) {
		int size2 = 0;
		while (envp[i][size2] != '\0')
			++size2;
		bufferEnvp[i] = new char[size2+1];
		strcpy(bufferEnvp[i], envp[i]);
	}
	bufferEnvp[size] = nullptr;

	cout << "ENVIRONMENT" << endl;
	int i = 0;
	while (bufferEnvp[i] != nullptr) {
		cout << bufferEnvp[i] << endl;
		++i; 

	}
	char **array = envp;
	cout << bufferEnvp << endl;
	cout << envp << endl;
	cout << array << endl;
	*/

	CopyJaggedArray *argvpCopy = new CopyJaggedArray(argv, argc);
	CopyJaggedArray *envpCopy= new CopyJaggedArray(envp);

	for (int i=0; i < argvpCopy->getLength(); ++i) {
		cout << argvpCopy->getCopy()[i] << endl;

	}

	for (int i = 0; i < envpCopy->getLength(); ++i) {
		cout << envpCopy->getCopy()[i] << endl;
	}
	envpCopy->sort();
	argvpCopy->sort();

	for (int i = 0; i < argvpCopy->getLength(); ++i) {
		cout << argvpCopy->getCopy()[i] << endl;

	}

	for (int i = 0; i < envpCopy->getLength(); ++i) {
		cout << envpCopy->getCopy()[i] << endl;
	}

	delete argvpCopy;
	delete envpCopy;

	if (_CrtDumpMemoryLeaks()) {
		cout << "MEMORY LEAK PANIC" << endl;
	}
	
	return 0;
}
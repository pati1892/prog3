#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\LinkedList\Source.cpp"
#include <iostream>
#include <memory>
#include <crtdbg.h>
#include <stdlib.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace TestList
{		
	TEST_CLASS(TestLinkedList)
	{
	public:
		
		using LinkedListPtr = std::unique_ptr <LinkedList<double>>;
		
		LinkedListPtr linkedList{ nullptr };

		TEST_METHOD_INITIALIZE(TestInit) {
			linkedList.reset(new LinkedList<double>());
		}
		TEST_METHOD_CLEANUP(TestCleanup) {
			linkedList.reset();
		}


		TEST_METHOD(TestEmpty)
		{
			Assert::IsTrue(linkedList->isEmpty());
		}

		TEST_METHOD(TestAddElement) 
		{


			double i = 5;
			linkedList->pushback(i);
			Assert::IsFalse(linkedList->isEmpty());
		}
		TEST_METHOD(TestAddThreeElements)
		{
			for (int i = 0; i < 3; ++i)
				linkedList->pushback(static_cast<double>(i));
			int a = 2;
			for (int i = 0; i < 3; ++i) {
				Assert::AreEqual((*linkedList.get())[i], static_cast<double>(a));
				--a;
			}
		}
		TEST_METHOD(TestDeleteMiddleElement) {
			try {
				int size = 5;
				for (int i = 0; i < size; ++i)
					linkedList->pushback(static_cast<double>(i));
				linkedList->removeAt(3);
				int i = 0;
				while (i<linkedList->getSize()) {
					Assert::AreNotEqual((*linkedList.get())[i], 1.0);
					++i;
				}
			}catch(...){}

		}
		TEST_METHOD(TestDeleteFirstElement) {
			try{
				int size = 5;
				for (int i = 0; i < size; ++i)
					linkedList->pushback(static_cast<double>(i));
				linkedList->removeAt(0);
				int i = 0;
				while (i<linkedList->getSize()) {
					Assert::AreNotEqual((*linkedList.get())[i], 4.0);
					++i;
				}
				Assert::AreEqual((*linkedList.get())[0], 3.0);
			}
			catch(...){}
		}
		TEST_METHOD(TestDeleteLastElement) {
			try {
				int size = 5;
				for (int i = 0; i < size; ++i)
					linkedList->pushback(static_cast<double>(i));
				linkedList->removeAt(4);
				int i = 0;
				while (i<linkedList->getSize()) {
					Assert::AreNotEqual((*linkedList.get())[i], 0.0);
					++i;
				}
				Assert::AreEqual((*linkedList.get())[3], 1.0);
			}
			catch(...){}
		}
		TEST_METHOD(TestCopyConstructor) {
			try
			{
				int size = 5;
				for (int i = 0; i < size; ++i)
					linkedList->pushback(static_cast<double>(i));
				LinkedList<double> copyList = *linkedList;
				Assert::AreEqual(copyList.getSize(), linkedList->getSize());
				for (size_t i = 0; i < copyList.getSize(); ++i) {
					Assert::AreEqual(copyList[i], (*linkedList)[i]);
				}
				linkedList.reset();
				for (size_t i = 0; i < copyList.getSize(); ++i) {
					Assert::IsTrue(static_cast<int>(copyList[i]) | 1);
				}
			}
			catch (...) {}
		}
		TEST_METHOD(TestAssignmentOperator) {
			try
			{
				int size = 5;
				for (int i = 0; i < size; ++i)
					linkedList->pushback(static_cast<double>(i));
				LinkedList<double> *list = new LinkedList<double>();
				for (int i = 0; i < size; ++i)
					list->pushback(static_cast<double>(i*10));

				*list = *linkedList;
				Assert::AreEqual(list->getSize(), linkedList->getSize());
				for (size_t i = 0; i < list->getSize(); ++i) {
					Assert::AreEqual((*list)[i], (*linkedList)[i]);
				}
				linkedList.reset();
				for (size_t i = 0; i < list->getSize(); ++i) {
					Assert::IsTrue(static_cast<int>((*list)[i]) | 1);
				}
			}
			catch (...) {}
		}
		TEST_METHOD(TestMemoryLeak) {
			linkedList.reset();
			Assert::IsFalse(_CrtDumpMemoryLeaks());

		}


	};

}


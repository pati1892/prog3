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
		
		using LinkedListPtr = std::unique_ptr <LinkedList>;
		
		LinkedListPtr linkedList{ nullptr };

		TEST_METHOD_INITIALIZE(TestInit) {
			linkedList.reset(new LinkedList());
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
			linkedList->pushback(5.0);
			Assert::IsFalse(linkedList->isEmpty());
		}
		TEST_METHOD(TestAddThreeElements)
		{
			for (int i = 0; i < 3; ++i)
				linkedList->pushback(static_cast<double>(i));
			int a = 2;
			for (int i = 0; i < 3; ++i) {
				Assert::AreEqual((*linkedList.get())[i]->getValue(), static_cast<double>(a));
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
				while ((*linkedList.get())[i] != nullptr) {
					Assert::AreNotEqual((*linkedList.get())[i]->getValue(), 1.0);
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
				while ((*linkedList.get())[i] != nullptr) {
					Assert::AreNotEqual((*linkedList.get())[i]->getValue(), 4.0);
					++i;
				}
				Assert::AreEqual((*linkedList.get())[0]->getValue(), 3.0);
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
				while ((*linkedList.get())[i] != nullptr) {
					Assert::AreNotEqual((*linkedList.get())[i]->getValue(), 0.0);
					++i;
				}
				Assert::AreEqual((*linkedList.get())[3]->getValue(), 1.0);
			}
			catch(...){}
		}
		TEST_METHOD(TestMemoryLeak) {
			linkedList.reset();
			Assert::IsFalse(_CrtDumpMemoryLeaks());

		}


	};

}


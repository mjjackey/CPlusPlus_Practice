// Win2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//void quickSort(int data[],int lowIndex, int highIndex)
//{
//    vector<int> a(10);
//    int pivotkey = data[lowIndex];
//    int i = lowIndex;
//    int j = highIndex;
//
//}


// This is a simple implementation of a shared pointer in C++
// It manages the lifetime of an object and ensures that it is deleted when no longer needed.
class A {
public:
    A() {
        cout << "create object of A" << endl;
    }

    ~A() {
        cout << "destroy an object A" << endl;
    }
};

template<class T> 
class SharedPtr
{
private:
    T* obj;
    int count;

public:
    SharedPtr()
    {
        obj = new T();
        count = 0;
    }

	SharedPtr(T* obj) :obj(obj)
	{
		count = 1;
	}

    // copy constructor
	SharedPtr(const SharedPtr& ptrIns)
	{
		obj = ptrIns.obj;
		count = ptrIns.count;
		count++;
	}
    

    ~SharedPtr()
    {
        count--;
		if (count == 0)
		{
			delete obj;
		}
    }
};

class B
{
public:
    B() = default;
    ~B() = default;

    // Overloading new and delete operators
    void* operator new(size_t size)
    {
        void* ptr = ::operator new(size);
        std::cout << "Allocating memory for B\n";
        return ptr;
    };
    void operator delete(void* ptr)
    {
		if (ptr != nullptr)  ::operator delete(ptr); //::operator invoke global operator, avoid recrursion invoke ovloaded delete if using delete ptr
		std::cout << "Deallocating memory for B\n";
    };
};

int main()
{
    std::cout << "Hello World!\n";
	SharedPtr<A> ptr1;
	SharedPtr<A> ptr2(ptr1);
    A* ptr3 = new A();
	SharedPtr<A> ptr4(ptr3);

    std::cin;

	B* b = new B();
	delete b; 
}


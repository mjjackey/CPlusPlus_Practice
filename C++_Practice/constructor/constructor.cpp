// constructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class A {
public:
    int x;
	A(int x) : x(x) //Initialise list constructor
    {
        cout << "Constructor" << endl;
    }
    A(A& a) : x(a.x)
    {
        cout << "Copy Constructor" << endl;
    }
    A& operator=(A& a)
    {
        x = a.x;
        cout << "Copy Assignment operator" << endl;
        return *this;
    }
    A(A&& a) noexcept : x(a.x)
    {
        cout << "Move Constructor" << endl;
    }
    A& operator=(A&& a) noexcept
    {
        x = a.x;
        cout << "Move Assignment operator" << endl;
        return *this;
    }
};

A GetA()
{
    return A(1);
}

A&& MoveA(A& a)
{
    return std::move(a);
}

#include <iostream>
#include <vector>

class B {
public:
    B() { std::cout << "Default constructor\n"; }
    B(const B&) { std::cout << "Copy constructor\n"; }
    B(B&&) noexcept { std::cout << "Move constructor\n"; }
};

int testEmplaceBack() {
    std::vector<B> vec;
	B b; //left value, default constructor called

	vec.emplace_back(b); //left value in, copy constructor called

	vec.emplace_back(std::move(b)); // convert to right value, move constructor called

	vec.emplace_back(); // default constructor called, new object created

    return 0;
}

int main()
{
    cout << "-------------------------1-------------------------" << endl;
    A a(1);  //new object
    cout << "-------------------------2-------------------------" << endl;
    A b = a;  // *******copy object 
    cout << "-------------------------3-------------------------" << endl;
    A c(a);  //copy object
    cout << "-------------------------4-------------------------" << endl;
    b = a; //assignment
    cout << "-------------------------5-------------------------" << endl;
    A d = A(1); //new object
    cout << "-------------------------6-------------------------" << endl;
    A e = std::move(a); //move object
    cout << "-------------------------7-------------------------" << endl;
    A f = GetA(); //new object
	//create a new object f, initialize it using the temporary object returned by the GetA() function. Since the temporary object is an r-value, the move constructor is called. It is worth noting that the move constructor is called twice here. The first time is before GetA() returns, where A(1) moves constructs a temporary object. The second time is when the temporary object moves constructs f.
	//move constructor called, but may be optimized by RVO, which means only one move constructor is called to directly construct f without creating a temporary object.
    cout << "-------------------------8-------------------------" << endl;
    A&& g = MoveA(f);  
	//return a right value reference to the caller, which is then bound to g. Since g is a reference, it does not involve any object creation or assignment, and thus no constructor or assignment operator is called.
    cout << "-------------------------9-------------------------" << endl;
    d = A(1); //new object, assignment

    //--------------------------------------------------------------------//
    cout << "-------------------------test emplace_back-------------------------" << endl;
    testEmplaceBack();
}


// STL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>
#include <array>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    vector<int> vecInt={ 1,2,3,4,5 };
    list<int> listInt;
    listInt.insert(listInt.begin(), vecInt.begin(), vecInt.end());
    for (const auto& obj : listInt)
    {
        cout << obj << endl;
    }
}

// C++_Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iosfwd>
#include <fstream>
#include <string>
#include <iterator>
#include <cstdio>
#include <vector>

using namespace std;


template<class T>
class MyIterator : public iterator<input_iterator_tag, T>
{
private: 
    T* _ptr;  //true pointer of elements, connect the container through the pointer
public:
    MyIterator(T* p)
    {
        _ptr = p;
    }

    MyIterator& operator=(const MyIterator& iter)
    {
        _ptr = iter._ptr;
    }

    bool operator != (const MyIterator& iter)
    {
        return _ptr != iter._ptr;
    }

    bool operator == (const MyIterator& iter)
    {
        return _ptr == iter._ptr;
    }

    MyIterator& operator++()
    {
        _ptr++;
        return *this;
    }

    MyIterator operator++(int)
    {
        MyIterator tmp = *this;
        //auto tmp = *this;
        _ptr++;
        return tmp;
    }

    T& operator*()
    {
        return *_ptr;
    }
};

template<class T>
class Solution 
{
private:
    T* _selfElems;
    int _count;

public:
    Solution(istream& s);

    //class iterator;
    typedef MyIterator<T> iterator;

    Solution(int n)
    {
        _selfElems = new T[n];
        _count = n;
        init();
    }

    bool IsdigitAll(const string& str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (i==0 && str[i] == '+' || str[i] == '-') continue;
            if (!isdigit(str[i]))
            {
                cout << str << " is not all digit" << endl;
                return false;
            }
        }
        return true;
    }


    void ClearHeadTailSpace(string& str)
    {
        if (str.empty())
        {
            return;
        }

        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
        cout << "clear space: " << str << endl;
    }

    void String2Int(const string& str, int& num);

    void init()
    {
        memset(_selfElems, 0, sizeof(T) * _count);
    }

    iterator begin()
    {
        return iterator(_selfElems);
    }

    iterator end()
    {
        return iterator(_selfElems + _count);
    }

    T& operator[](int i)
    {
        return _selfElems[i];
    }
};

template<class T>
Solution<T>::Solution(istream& s)
{
    string str;
    int n = 0;
    vector<int> numVec;

    while (!s.eof())
    {
        if (s.bad())
        {
            break;
        }
        else if (s.fail())
        {
            continue;
        }

        std::getline(s,str);
        cout << "input: " << str << endl;

        ClearHeadTailSpace(str);

        if (!IsdigitAll(str)) continue;

        int num;
        String2Int(str,num);
        numVec.emplace_back(num);
        n++;
    }

    _selfElems = new T[n];
    _count = n;
    init();
    for (size_t i = 0; i < n; i++)
    {
        _selfElems[i] = numVec.at(i);
    } 
}

template<class T>
void Solution<T>::String2Int(const string& str, int& num)
{
    //scanf_s(str.c_str(), "%D", &num);
    num = std::stoi(str);
    std::cout << "num:" << num << endl;
}

int main()
{
	//Read from file input.txt, convert digital string to int and strore to array, final display the array
    string filePath = "input.txt";
    std::filebuf inputFile;
    if (!inputFile.open(filePath,std::ios::in)) return 0;
    istream stream(&inputFile);
    Solution<int> sol(stream);
    for (Solution<int>::iterator it =sol.begin(); it!=sol.end(); ++it)
    {
        int x = *it;
        cout << x << endl;
    }
    return 1;
}



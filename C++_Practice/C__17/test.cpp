#include <iostream>
#include <vector>
#include "C__.h"


int main()
{
	std::cout << "Hello World!\n";

	templateTest();

	auto seq = std::integer_sequence<int, 1, 2, 3, 4, 5>();
	//Type is duduced to be int
	auto seq2 = MyIntegerSeq<1, 2, 3, 4, 5>();
	seq2.print();

	std::cout << std::endl;
	auto nSum = sum(1.0, 2.0f, 3);
	std::cout << nSum << std::endl;

	bool b = true;
	bool b2 = b;
	auto bRes = logicalAnd(b, b2, true);
	std::cout << bRes << std::endl;
}
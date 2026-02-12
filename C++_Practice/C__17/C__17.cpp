// C__17.cpp 
//

#include <iostream>
#include <stdexcept>

//Template argument deduction for class templates
template <typename T = float>
static void templateTest()
{
	struct MyStruct
	{
		T value;
		MyStruct() :value(0) {}
		MyStruct(T value) : value(value) {}
	};

	//int is deduced as the type of the template argument
	MyStruct myStruct1{ 1 };
	//float is deduced as the type of the template argument
	MyStruct myStruct2{ 2.0f };
}                                                                                                                               
//Declaring non-type template parameters with auto
template<auto... args>
struct MyIntegerSeq
{
	static void print()
	{
		((std::cout << args << " "), ...);
	}
};


//Folding expressions
template <typename... Args>
auto sum(Args... args)
{
	//Unary folding
	return (... + args);
}

template<typename... Args>
bool logicalAnd(Args... args)
{
	//Binary folding.
	return (true && ... && args);
}

//int main()
//{
//	std::cout << "Hello World!\n";
//	templateTest();
//    
//	auto seq = std::integer_sequence<int, 1, 2, 3, 4, 5>();
//	//Type is duduced to be int
//	auto seq2 = MyIntegerSeq<1, 2, 3, 4, 5>();
//	seq2.print();
//
//	sum(1.0, 2.0f, 3);
//	bool b = true;
//	bool b2 = b;
//	auto bRes = logicalAnd(b, b2, true);
//	std::cout << std::endl;
//	std::cout << bRes << std::endl;
//}



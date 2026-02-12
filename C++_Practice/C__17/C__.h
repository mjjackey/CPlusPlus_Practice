#ifndef C__
#define C__

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

#endif // !C__


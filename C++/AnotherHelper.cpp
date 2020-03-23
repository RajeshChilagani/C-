#include <iostream>
namespace CPP_Practise
{
	void TestingLinking();
}
void FuncDec()
{
	std::cout << "FuncDEc Callaed" << std::endl;
}
class TestTemp
{
public:
	TestTemp(int i_a) :a(i_a) {}
	void	Print() { std::cout << a << std::endl; }
private:
	char a;
};
void Call()
{
	TestTemp A(1);
	A.Print();
}
#include "Includer.h"
template<typename T>
void Tes<T>::print(T a)
{
	std::cout << "test";
	Error(a);
}
template<typename T>
void Tes<T>::Error(T a)
{
	std::cout <<a;
	
}
void Testsdsd()
{
	Tes<int> a(1);
	a.print(1);
}
int Max = INT_MAX;
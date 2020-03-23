#pragma once
template<typename T>
void PrintT(T a)
{
	std::cout << a;
}
template<typename T>
class Tes
{
public:
	Tes(T i_a) :a(i_a) {}
	void print(T a);
	void Error(T a);
private:
	T a;
};
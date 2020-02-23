#pragma once
#include <iostream>
#include <functional>
//---Functio Pointers---//
	
using FuncWithStd = std::function<void()>;                 //--using std::function wrapper--//

using Func = void(*)();
typedef void(*FuncTD)();

void PrintHello()
{
	std::cout << "Hello World" << std::endl;
}

//---Functio Pointers---//

//---enum class type & Stringify Enum type---//
enum class Color
{
	red, green, yellow
};
#define CLASS(x) Color Type(){return Color::##x;}
CLASS(red)

//---enum class type & Stringify Enum type---//
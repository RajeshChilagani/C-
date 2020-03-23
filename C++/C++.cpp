// C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CPPLearnings.h"
#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include "SmartPointers.h"
#include "WeakPtr.h"
#include <memory>
#include <string>
#include <string>
#include "EC.h"
#include "Includer.h"
class Transform : public Component
{
public:
	Transform(float i):m_position(i)
	{}
	inline float getPosition()
	{
		return m_position;
	}
	inline float& setPosition()
	{
		return m_position;
	}
	
	inline void init() override
	{

	}
	inline void update() override
	{

	}
private:
	float          m_position;
};
class Dev_Array
{
public:
	Dev_Array(size_t i_size) :size(i_size),m_Data(new int[size]) {}
	Dev_Array() {}
	int* GetData()
	{
		return m_Data;
	}
	int* & SetData()
	{
		delete m_Data;
		return m_Data;
	}
	int& operator[](size_t index)
	{
		if (index >= size)
		{
			std::cout << "Index out of bound" << std::endl;
		}
		return m_Data[index];
	}
	~Dev_Array()
	{
		delete m_Data;
	}
private:
	size_t size;
	int* m_Data;
};
namespace CPP_Practise
{
	 void TestingLinking();
}
void Test();
class GameObject
{
public:
	GameObject() :m_GridPosition(nullptr) {}
	GameObject(int* i_position) :m_GridPosition(i_position) { *m_GridPosition = 1; }
	GameObject& operator=(const GameObject& i_Rhs)
	{
		if (!m_GridPosition)
			m_GridPosition = new int;
		*m_GridPosition = *(i_Rhs.m_GridPosition);
		return *this;
	}
	void update()
	{
		(*m_GridPosition)++;
	}
	int* GetGridPosition()
	{
		return m_GridPosition;
	}
	~GameObject()
	{
		delete m_GridPosition;
	}
private:
	int* m_GridPosition;
};
struct ent
{
private:
	int x;
public:
	ent(int a):x(a)
	{

	}
	void Print() const
	{
		std::cout << x<<std::endl;
	}
	ent(const ent& i_Other) :x(i_Other.x) {}
	ent& operator=(const ent& i_Other)
	{
		x = i_Other.x;
		return *this;
	}
	int* getmem() 
	{
		return reinterpret_cast<int*>(this);
	}
	~ent()
	{
		x = 0;
	}
};

//Perfecet Singelton
class Singleton
{
public:
	static void Func()
	{
		std::cout<<Get().GetMem();
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	int  GetMem()
	{
		return a;
	}
	static Singleton& Get() { static Singleton Instance; ; return Instance; }
private:
	Singleton() {}
	int a;
};

//EntityGame& EGTes(EntityGame& E)
//{
//	std::cout << "test" << std::endl;
//	return E;
//}
#define BIT(x) (1<<x)

class Base
{
protected:
	
public:
	Base() {}
	//virtual void PrintName() const = 0;
	Base(int input) :a(input) { std::cout << "Base is called" << std::endl; }
	void PrintA()
	{
		std::cout << a;
	}
	virtual void Printname() const
	{
		std::cout << "Base" << std::endl;
	}
private:
	int a;
	static int ST;
};
int Base::ST;
class Dr: public Base
{

public:
	Dr() {}
	Dr(int i_a, int b) :Base(i_a),b{ b } 
	{ 
		
		std::cout << "Derived is called" << std::endl;
	}
	void GetData()
	{
		std::cin >> b;
	}
	void PrintV()
	{
	//	a = 2;
		//std::cout <<a<<" "<<b;
	}
	void Printname() const override
	{
		std::cout << "Derived" << std::endl;
	}
	int b;
};
class AD :public Dr
{
public:
	void Printname() const override
	{

	}
	AD(int a, int b, int i_c) :
		Dr(a, b), c(i_c) {}
	int c;
};
void CallBack(Func i_CallBack)
{
	i_CallBack();
}
class EntityGame
{
public:
	EntityGame() {}
	EntityGame(int i) :m_x(i) {}
	EntityGame(const EntityGame& i_Other) :m_x(i_Other.m_x) { std::cout << "Copy is called" << std::endl; }
	EntityGame(EntityGame&& i_Other) :m_x(i_Other.m_x) { std::cout << "Move is called" << std::endl; }
	EntityGame& operator=(const EntityGame& i_Other)
	{
		m_x = i_Other.m_x;
		return *this;
	}
	void Print() { std::cout << m_x; }
	bool operator==(const EntityGame& i_Other)
	{
		return this == &i_Other;
	}
	/*static EntityGame& getOne(EntityGame& i_Other)
	{
		return i_Other;
	}*/
	~EntityGame()
	{
		std::cout << "Destructor called " << std::endl;
	}
private:
	int m_x;
};
class Pointer
{
public:
	 Pointer(EntityGame i_Obj):Obj(i_Obj) {}
	~Pointer() {}
private:
	EntityGame Obj;
};
class GlobalSystem
{
public:
	inline static GlobalSystem& Get() { static GlobalSystem* Instance = new GlobalSystem(); return *Instance; }
	void AddGameObject(const char* name)
	{
		m_AllGameObjects.emplace(name, new Entity());
		m_AllGameObjects.insert(std::make_pair(name, SmartPtr<Entity>(new Entity())));
	}
	template<typename T, typename...Targs>
	static void AddComponent(const char* name, Targs&&...mArgs)
	{

		Get().m_AllGameObjects[name]->AddComponent(new T(std::forward<Targs>(mArgs)...));
	}
	SmartPtr<Entity>& GetObject(const char* i_name)
	{
		return m_AllGameObjects[i_name];
	}
	static void  ShutDown()
	{
		delete &Get();
	}
	GlobalSystem() {}
	std::unordered_map<const char*, SmartPtr<Entity>> m_AllGameObjects;
};
struct A
{
	int a, b;
};
struct BC
{
	int a, b, c;
};
#define CALLBACK(x) int ype(){return 1##x;}
CALLBACK(1)
#include "set"
#include <unordered_set>
void RemoveDupliactesWithSet(int a[],int size)
{
	std::unordered_set<int> uniqueElemnts;
	for (int i = 0; i < size; ++i)
	{
		uniqueElemnts.insert(a[i]);
	}
	for (std::unordered_set<int>::iterator i = uniqueElemnts.begin(); i != uniqueElemnts.end(); ++i)
	{
		std::cout << *i;
	}
}
#include <algorithm>
void RemoveDuplicates(int i_a[], int size)
{
	std::sort(i_a, i_a + size);
	int newsize = 0;
	for (int i = 0; i < size; ++i)
	{
		if (i_a[i] != i_a[i + 1])
		{
			i_a[newsize] = i_a[i];
			newsize++;
		}

	}
	for (int i = 0; i < newsize; ++i)
	{
		std::cout << i_a[i];
	}
}

class TestTemp
{
public:
	TestTemp(int i_a) :a(i_a) {
		std::cout << "const";
	}
	void	Print() { std::cout << a << std::endl; }
private:
	int a;
};
class Integer
{
public:
	Integer() {}
	Integer(const char* i_Data) : m_Data(i_Data) {}
	Integer(const Integer& i_Other) :m_Data(i_Other.m_Data) {}
	explicit Integer(Integer&& i_Other) :m_Data(i_Other.m_Data) {}
	void operator()()
	{
		std::cout << "OPerati";
	}
	Integer& operator=(const Integer& i_Other)
	{
		m_Data = i_Other.m_Data;
	}
	const char* m_Data;
	~Integer()
	{
		std::cout << "Destructor" << std::endl;
	}

};
Integer CreateInt()
{
	Integer I("hello");
	return I;
}
class B
{
public:
	B() {}
	B(int i):Bint(i) {}
	B(const B& i_Other) :Bint(i_Other.Bint) {}
	B(const B&& i_Other) :Bint(i_Other.Bint) {}
	int bint() const
	{
		return Bint;
	}
	B operator = (const B& ipiut)
	{
		Bint = ipiut.Bint;
		return *this;
	}
	B& operator+=(const B& i_Rhs)
	{
		Bint += i_Rhs.Bint;
		return *this;
	}
	~B()
	{
		Bint = INT_MIN;
		std::cout << "Destructor" << std::endl;
	}
private:
	 int Bint;
};
std::ostream& operator<<(std::ostream& s, const B& Input)
{
	s << Input.bint();
	return s;
}
class D : public B
{

public:
	D() {}
	static int Dint;
};
B& CreateB(int A)
{
	B b(10);
	return b;
}
#include "Matrix.h"
#include "Vector4.h"
void MatrixTest(int i_Mat[2][2])
{
	i_Mat[0][0] = 25;
	i_Mat[0][1] = 25;
	i_Mat[1][0] = 25;
	i_Mat[1][1] = 25;
}
int main()
{
	int Mat4[2][2];
	MatrixTest(Mat4);
	Engine::Math::Matrix4 M1(MATH_API::Vector4(1,2,3,4), MATH_API::Vector4(1, 2, 3, 4), MATH_API::Vector4(1, 2, 3, 4), MATH_API::Vector4(1, 2, 3, 4));
	Engine::Math::Matrix4 M2;
	M2.SetDiagonal(2);
	M2 *= M1;
	M2 = Engine::Math::Matrix4::Transpose(M2);
	const MATH_API::Vector4 P1(4.0f, 5.0f,6.0f,7.0f);
	MATH_API::Vector4 P2(1.0f, 2.0f,3.0f,4.0f);
	cout << "p1 is " << P1 << "P2 is " << P2 << std::endl;
	MATH_API::Vector4 P3 = P1 + P2;
	cout << "p3 is " << P3 << std::endl;
	P3 = P1 - P2;
	cout << "p3 is after sub" << P3 << std::endl;
	MATH_API::Vector4 P4 = P1 * 0.5f;
	cout << "p4 is " << P4 << std::endl;
	MATH_API::Vector4 P5 = P1 / 2.0f;
	cout << "p5 is " << P5 << std::endl;
	MATH_API::Vector4 P6 = -P4;
	cout << "p6 is " << P6 << std::endl;
	P2 *= P1;
	cout << "P2 is " << P2 << std::endl;
	P6 *= 2.0f;
	P5 /= 4.0f;
	cout << "p6 & P5 is " << P6 << " " << P5 << std::endl;
	P2 += P1;
	P3 -= P1;
	cout << "p2 & P3 is " << P2 << " " << P3 << std::endl;
	MATH_API::Vector4 P7 = (((P1 + P2) * 2.0f) - -P3) / 2.0f;
	cout << "p7 is " << P7 << std::endl;
	bool bArentEqual = P6 != P4;
	cout << bArentEqual << std::endl;
	cout << "P1 is " << P1 << "\n";
	B bb(1);
	std::cout << bb;
	int a[] = { 1,3,2,2,2 };
	Tes<int> obj(1);
	obj.print(1);
	std::cout << "\nWithSet";
	RemoveDupliactesWithSet(a, 5);
	RemoveDuplicates(a,5);
	std::cout << ype();
	Base * b = new Base;
	Component* T = new Transform(1.0f);
	Transform* AT = static_cast<Transform*>(T);
	std::cout<<"Printing "<<AT->getPosition();

	SmartPtr<Component> Test(new Transform(1.0));
	WeakPtr<Component> Temp(Test);
	WeakPtr<Transform> Testing(Temp);
	
	{
		GlobalSystem& G = GlobalSystem::Get();
		G.AddGameObject("Player");
		GlobalSystem::AddComponent<Transform>("Player", 100.0f);
		GlobalSystem::Get().AddGameObject("Zombie");
		G.AddGameObject("Enemy");
		GlobalSystem::AddComponent<Transform>("Enemy", 1.0f);
		if (G.Get().m_AllGameObjects["Enemy"] == G.Get().m_AllGameObjects["Enemy"])
		{
			std::cout << "Smae" << std::endl;
		}
	//Physics
	{
		/*std::vector<WeakPtr<GameObject>> PhysicsObjects;
		PhysicsObjects.push_back(GlobalSystem::Get().GetObject("Player"));
		PhysicsObjects[0].Acquire()->update();
		std::cout << (*PhysicsObjects[0].Acquire()->GetGridPosition());*/
	}

		//Render
		{
			/*std::vector<WeakPtr<GameObject>> RenderObjects;
			RenderObjects.push_back(GlobalSystem::Get().GetObject("Player"));*/



		}
	}
	GlobalSystem::ShutDown();
	_CrtDumpMemoryLeaks();
	
}



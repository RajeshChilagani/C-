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
	int a;
};
class Dr: public Base
{

public:
	Dr() {}
	Dr(int i_a, int b) :Base(i_a),b{ b } 
	{ 
		
		std::cout << "Derived is called" << std::endl;
	}
	void PrintV()
	{
	//	a = 2;
		std::cout <<a<<" "<<b;
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
EntityGame& returnRef(EntityGame& on)
{
	return on;
}

int main()
{
	Component* T = new Transform(1.0f);
	Transform* AT = static_cast<Transform*>(T);

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



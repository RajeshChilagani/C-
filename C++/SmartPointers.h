#pragma once
#include <sstream>
#include <iostream>
#include <string>
#define TRACE_ERROR(s){std::stringstream os;os<<"\nError:";os<<s;os<<std::endl;OutputDebugStringA( os.str().c_str() );}
template <typename T>
class WeakPtr;
struct RefCount
{
	int m_SmartPtrs;
	int m_WeakPtrs;
	RefCount(int i_SmartPtrs, int i_WeakPtrs) :m_SmartPtrs(i_SmartPtrs), m_WeakPtrs(i_WeakPtrs) {}
};
template <typename T>
class SmartPtr
{
	
	friend WeakPtr<T>;
public:
	SmartPtr() {}
	explicit SmartPtr(T* i_T) :m_T(i_T), m_RefCount(new RefCount(1, 0)) {}
	explicit SmartPtr(WeakPtr<T>& i_WeakPtr): m_T(i_WeakPtr.m_RefCount->m_SmartPtrs > 0?i_WeakPtr.m_T:nullptr),m_RefCount(i_WeakPtr.m_RefCount)
	{
		(m_RefCount->m_SmartPtrs)++;
	}
	SmartPtr(const SmartPtr& i_Other) :m_T(i_Other.m_T), m_RefCount(i_Other.m_RefCount) 
	{
		(m_RefCount->m_SmartPtrs)++;
	}
	/*template<typename U>
	SmartPtr(const SmartPtr<U>& i_Other) :m_T(i_Other.m_T), m_RefCount(i_Other.m_RefCount)
	{
		(m_RefCount->m_SmartPtrs)++;
	}*/
	SmartPtr& operator=(const SmartPtr& i_Rhs)
	{
		if (this != &i_Rhs)
		{
			Release();
			m_T = i_Rhs.m_T;
			m_RefCount = i_Rhs.m_RefCount;
			(m_RefCount->m_SmartPtrs)++;
		}
		return *this;
	}
	void operator=(std::nullptr_t i_nullptr)
	{
		Release();
	}
	T* operator->()
	{
		return m_T;
	}
	T& operator*()
	{
		return *(m_T);
	}
	operator bool()
	{
		return m_T != nullptr;
	}
	bool operator==(const SmartPtr& i_Other)
	{
		return this == &i_Other;
	}
	~SmartPtr()
	{
		Release();
		
	}
private:
	T* m_T;
	RefCount* m_RefCount;
	void Release()
	{
		if (--(m_RefCount->m_SmartPtrs) == 0)
		{
			delete m_T;
		}
		if (m_RefCount->m_WeakPtrs == 0)
		{
			delete m_RefCount;
		}
	}
};

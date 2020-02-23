#pragma once
#include "SmartPointers.h"
template <typename T>
class WeakPtr
{
	friend SmartPtr<T>;
	template <typename U>
	friend class WeakPtr;
public:
	WeakPtr() {}
 	WeakPtr(SmartPtr<T>& i_Other) :m_T(*(reinterpret_cast<T**>(&i_Other))),m_RefCount(*(reinterpret_cast<RefCount**>(reinterpret_cast<RefCount*>(&i_Other)+1)))
	{
		m_RefCount->m_WeakPtrs++;
	}
	WeakPtr(const WeakPtr& i_Other) :m_T(i_Other.m_T), m_RefCount(i_Other.m_RefCount) 
	{
		m_RefCount->m_WeakPtrs++;
	}
	template<typename U>
	WeakPtr(const WeakPtr<U>& i_Other) :m_T(static_cast<T*>(i_Other.m_T)), m_RefCount(i_Other.m_RefCount)
	{
		m_RefCount->m_WeakPtrs++;
	}
	WeakPtr& operator=(const WeakPtr& i_Rhs)
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
	SmartPtr<T> Acquire()
	{
		return SmartPtr<T>(*this);
	}
	operator bool()
	{
		return m_RefCount->m_SmartPtrs > 0;
	}
	~WeakPtr()
	{
		Release();
	}
private:
	T* m_T;
	RefCount* m_RefCount;
	void Release()
	{
		if (--(m_RefCount->m_WeakPtrs) == 0 && (m_RefCount->m_SmartPtrs==0))
		{
			delete m_RefCount;
		}
	}
};

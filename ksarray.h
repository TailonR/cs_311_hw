//ksarray.h
//Tailon Russell
//09-11-2019
//header file for ksarray

#ifndef KSARRAY_H
#define KSARRAY_H

#include <cstddef>
#include <algorithm>
#include <iostream>
#include <ostream>


template<typename ToBeNamed>
class KSArray
{
public:
	using value_type = ToBeNamed;
	using size_type = std::size_t;
public:
	KSArray<ToBeNamed>() : arrayPtr(new value_type[8]), sizeOfArray(8)
	{}
	explicit KSArray<ToBeNamed>(int size)
	{
		if (size < 0)
		{

		}
		else
		{
			arrayPtr = new value_type[size];
			sizeOfArray = size;
		}
	}
	KSArray<ToBeNamed>(int size, const ToBeNamed & type)
	{
		arrayPtr = new value_type[size];
		sizeOfArray = size;
		for (auto i = 0; i < sizeOfArray; i++)
		{
			arrayPtr[i] = type;
		}
	}
	value_type & operator[](const size_type & index)
	{
		if (index < 0 && index > sizeOfArray - 1)
		{

		}
		else
		{
			return arrayPtr[index];
		}
	}
	const value_type & operator[](const size_type & index2) const
	{
		if (index2 < 0 || index2 > sizeOfArray - 1)
		{

		}
		else
		{
			return arrayPtr[index2];
		}
	}
	size_type size()
	{
		return sizeOfArray;
	}
	const size_type size() const
	{
		return sizeOfArray;
	}
	ToBeNamed* begin()
	{
		return &arrayPtr[0];
	}
	const ToBeNamed* begin() const
	{
		return &arrayPtr[0];
	}
	ToBeNamed* end()
	{
		return &arrayPtr[sizeOfArray];
	}
	const ToBeNamed* end() const
	{
		return &arrayPtr[sizeOfArray];
	}
	bool operator<(const KSArray<ToBeNamed>& rhs) const
	{
		bool equal = false;
		for (size_t iterator = 0; iterator < size(); iterator++)
		{
			if (this[iterator] < rhs[iterator])
			{
				equal = true;
				return equal;
			}
		}
		return equal;
	}
	KSArray<ToBeNamed>& operator= (const KSArray<ToBeNamed> & original)
	{
		if (&original == this)
		{
			delete[] arrayPtr;
		}
		else
		{
			KSArray<ToBeNamed> copyOfOriginal(original);
			KSArrayswap(copyOfOriginal);
			return *this;
		}
	}
	KSArray<ToBeNamed>(const KSArray<ToBeNamed>& original): sizeOfArray(original.size())
	{
		arrayPtr = new value_type[original.size()];
		for (size_type j = 0; j < original.size(); j++)
		{
			arrayPtr[j] = original.arrayPtr[j];

		}
	}
	KSArray<ToBeNamed>(KSArray<ToBeNamed>&& original) noexcept : arrayPtr(original.arrayPtr), sizeOfArray(original.size())
	{
		original.arrayPtr = NULL;
		original.sizeOfArray = 0;
	}
	KSArray<ToBeNamed> & operator= (KSArray<ToBeNamed> && original) noexcept
	{
		KSArrayswap(original);
		return *this;
	}
	~KSArray()
	{
		delete [] arrayPtr;
		arrayPtr = NULL;
	}
	friend void swap(KSArray<ToBeNamed>& a, KSArray<ToBeNamed>& b) noexcept;
	//friend const bool operator!=(const KSArray<ToBeNamed>& lhs, const KSArray<ToBeNamed>& rhs);
private:
	ToBeNamed* arrayPtr;
	size_type sizeOfArray;
	void KSArrayswap(KSArray<ToBeNamed> & original) noexcept
	{
		using std::swap;
		swap(this->sizeOfArray, original.sizeOfArray);
		ToBeNamed* tempPtr = arrayPtr;
		arrayPtr = original.arrayPtr;
		original.arrayPtr = tempPtr;
	}
};

//template <typename ToBeNamed>



template <typename ToBeNamed>
const bool operator>(const KSArray<ToBeNamed>& lhs, const KSArray<ToBeNamed>& rhs)
{
	return !(lhs < rhs);
}

template <typename ToBeNamed>
const bool operator<=(const KSArray<ToBeNamed>& lhs, const KSArray<ToBeNamed>& rhs)
{
	return !(lhs > rhs);
}

template <typename ToBeNamed>
const bool operator>=(const KSArray<ToBeNamed>& lhs, const KSArray<ToBeNamed>& rhs)
{
	return !(lhs < rhs);
}

template <typename ToBeNamed>
const bool operator==(const KSArray<ToBeNamed> & lhs, const KSArray<ToBeNamed>& rhs)
{
	return (lhs.size() == rhs.size() && !(lhs < rhs) && !(rhs < lhs));
}


template<typename ToBeNamed>
void swap(KSArray<ToBeNamed>& a, KSArray<ToBeNamed>& b) noexcept
{
	a.KSArrayswap(b);
}

template <typename ToBeNamed>
const bool operator!=(const KSArray<ToBeNamed>& lhs, const KSArray<ToBeNamed>& rhs)
{
	return !(lhs == rhs);
}
#endif // !KSARRAY_H
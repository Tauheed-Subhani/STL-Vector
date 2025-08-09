#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>
#include <iostream>
#include <cassert>
using namespace std;
template <typename T>
class Vector
{
private:
	T* data;
	int size_;
	int capacity_;
	bool checkValidIndex(const int index) const
	{
		if (index >= 0 && index < size_)
			return true;
		assert(!"Assertion Failed!");
	}
public:
	class Iterator;
	class Reverse_Iterator;
	Vector()
	{
		data = nullptr;
		size_ = 0;
		capacity_ = 0;
	}
	Vector(initializer_list<T> list)
	{
		size_ = list.size();
		capacity_ = size_;
		data = new T[capacity_];
		int i = 0;
		for (T val : list)
			data[i++] = val;
	}
	Vector(const Vector& ref)
	{
		*this = ref;
	}
	~Vector()
	{
		delete[]data;
		data = nullptr;
		size_ = 0;
		capacity_ = 0;
	}
	T& operator [](const int index)
	{
		if (checkValidIndex(index))
		{
			return data[index];
		}
	}
	const T& operator [](const int index) const
	{
		if (checkValidIndex(index))
		{
			return data[index];
		} 
	}
	int size()const
	{
		return size_;
	}
	int capacity()const
	{
		return capacity_;
	}
	Vector& operator =(const Vector& ref)
	{
		if (this != &ref)
		{
			this->~Vector();
			if (ref.data != nullptr)
			{
				size_ = ref.size_;
				capacity_ = ref.capacity_;
				data = new T[capacity_];
				for (int i = 0; i < size_; i++)
				{
					data[i] = ref.data[i];
				}
			}
		}
		return *this;
	}
	void push_back(T n)
	{
		if (size_ < capacity_)
		{
			data[size_] = n;
			size_++;
			return;
		}
		if (capacity_)
			capacity_ *= 2;
		else
			capacity_ = 1;
		T* temp = new T[capacity_];
		for (int i = 0;i < size_;i++)
			temp[i] = data[i];
		temp[size_] = n;
		delete[]data;
		data = temp;
		size_++;
	}
	void emplace_back(T n)
	{
		if (size_ < capacity_)
		{
			data[size_] = n;
			size_++;
			return;
		}
		if (capacity_)
			capacity_ *= 2;
		else
			capacity_ = 1;
		T* temp = new T[capacity_];
		for (int i = 0;i < size_;i++)
			temp[i] = data[i];
		temp[size_] = n;
		delete[]data;
		data = temp;
		size_++;
	}
	void pop_back()
	{
		if (!data)
			assert(!"Assertion Failed!");
		size_--;
	}
	T& at(const int index)
	{
		return (*this)[index];
	}
	const T& at(const int index)const
	{
		return (*this)[index];
	}
	T& front()const
	{
		return data[0];
	}
	T& back()const
	{
		return data[size_ - 1];
	}
	Iterator begin()const
	{
		return Iterator(data);
	}
	Iterator end()const
	{
		return Iterator(data + size_);
	}
	Reverse_Iterator rbegin()const
	{
		return Reverse_Iterator(data+(size_-1));
	}
	Reverse_Iterator rend()const
	{
		return Reverse_Iterator(data - 1);
	}
	void erase(Iterator st)
	{
		if (!data)
			assert(!"Assertion Failed!");
		T* temp = new T[capacity_];
		for (int i = 0, j = 0;i < size_;i++)
		{
			if (&data[i]!=st.p)
			{
				temp[j] = data[i];
				j++;
			}
		}
		delete[]data;
		data = temp;
		size_--;
	}
	void erase(Iterator st,Iterator e)
	{
		if (!data)
			assert(!"Assertion Failed!");
		T* temp = new T[capacity_];
		int cnt = 0;
		for (Iterator i=begin();i!=end();i++)
		{
			if (i == st)
				i = e-1;
			else
				temp[cnt++] = *i;
		}
		delete[]data;
		data = temp;
		size_ = cnt;
	}
	void insert(Iterator pos, T el)
	{
		if (empty())
		{
			data = new T[1];
			data[0] = el;
			size_++;
			capacity_++;
			return;
		}
		if (pos == end())             
		{
			push_back(el);
			return;
		}
		if (size_ == capacity_)
			capacity_ *= 2;
		T* temp = new T[capacity_];
		int j = 0;
		for (Iterator i = begin();i !=end();i++)
		{
			if (i == pos)
			{
				temp[j] = el;
				j++;
			}
			temp[j] = *i;
			j++;
		}
		delete[]data;
		data = temp;
		size_++;
	}
	void clear()
	{
		this->~Vector();
	}
	bool empty()const 
	{
		return (size_==0);
	}
	class Iterator
	{
		T* p;
	public:
		friend void Vector::erase(Iterator st);
		Iterator() :p(nullptr) {}
		Iterator(T* ptr) :p{ ptr } {}
		T& operator*() const
		{
			return *p;
		}
		bool operator!=(const Iterator& other)const
		{
			return (p != other.p);
		}
		bool operator==(const Iterator& other)const
		{
			return (p == other.p);
		}
		Iterator operator+(int x)
		{
			return Iterator{ (p + x) };
		}
		Iterator operator-(int x)
		{
			return Iterator{ (p - x) };
		}
		Iterator operator++(int)
		{
			Iterator temp = *this;
			p++;
			return temp;
		}
		Iterator operator--(int)
		{
			Iterator temp = *this;
			p--;
			return temp;
		}
		Iterator operator++()
		{
			p++;
			return *this;
		}
		Iterator operator--()
		{
			p--;
			return *this;
		}
		Iterator operator+=(int n)
		{
			p = p + n;
			return *this;
		}
		Iterator operator-=(int n)
		{
			p = p - n;
			return *this;
		}
	};
	class Reverse_Iterator
	{
		T* p;
	public:
		Reverse_Iterator() :p(nullptr) {}
		Reverse_Iterator(T* ptr) :p{ ptr } {}
		T& operator*() const
		{
			return *p;
		}
		bool operator!=(const Reverse_Iterator& other)const
		{
			return (p != other.p);
		}
		bool operator==(const Reverse_Iterator& other)const
		{
			return (p == other.p);
		}
		Reverse_Iterator operator+(int x)
		{
			return Reverse_Iterator{ (p - x) };
		}
		Reverse_Iterator operator-(int x)
		{
			return Reverse_Iterator{ (p + x) };
		}
		Reverse_Iterator operator++(int)
		{
			Reverse_Iterator temp = *this;
			p = p - 1;
			return temp;
		}
		Reverse_Iterator operator--(int)
		{
			Reverse_Iterator temp = *this;
			p = p + 1;
			return temp;
		}
		Reverse_Iterator operator++()
		{
			p--;
			return *this;
		}
		Reverse_Iterator operator--()
		{
			p++;
			return *this;
		}
		Reverse_Iterator operator-=(int n)
		{
			p = p + n;
			return *this;
		}
		Reverse_Iterator operator+=(int n)
		{
			p = p - n;
			return *this;
		}
	};
};
#endif
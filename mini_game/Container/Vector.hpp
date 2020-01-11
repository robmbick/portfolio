#pragma once

#include <cstring> // std::size_t
#include <iostream>

template<class T>
class vector
{
public:
	vector();
	vector(std::size_t capacity);
	vector(vector<T> const& obj);
	~vector();

	T			&operator[](std::size_t index);
	T const		&operator[](std::size_t index) const;
	vector<T>	&operator=(vector<T> const& obj);

	void		push_back(T const& obj);
	void		erase(std::size_t index);

	std::size_t	size() const;
	bool		empty() const;
private:
	static const std::size_t _MULT;

	T			*_arr;
	std::size_t	_size;
	std::size_t	_capacity;
};

template<class T> const std::size_t vector<T>::_MULT = 2;

template<class T>
vector<T>::vector()
{
	_arr = 0;
	_size = 0;
	_capacity = 0;
}

template<class T>
vector<T>::vector(std::size_t capacity)
{
	_arr = new T[capacity];
	_size = 0;
	_capacity = capacity;
}

template<class T>
vector<T>::vector(vector<T> const& obj)
{
	_capacity = obj._size;
	_size = obj._size;
	_arr = new T[_size];
	for (std::size_t i = 0; i < obj._size; ++i)
	{
		_arr[i] = obj._arr[i];
	}
}

template<class T>
vector<T>::~vector()
{
	delete[] _arr;
}

template<class T>
T		&vector<T>::operator[](std::size_t index)
{
	return *(_arr + index);
}

template<class T>
T const	&vector<T>::operator[](std::size_t index) const
{
	return *(_arr + index);
}

template<class T>
vector<T>	&vector<T>::operator=(vector<T> const& obj)
{
	if (this == &obj)
		return *this;

	_size = obj._size;
	_capacity = _size;

	delete[] _arr;
	_arr = new T[_size];
	for (std::size_t i = 0; i < _size; ++i)
	{
		_arr[i] = obj._arr[i];
	}
	return *this;
}

template<class T>
void	vector<T>::push_back(T const& obj)
{
	if (_size < _capacity)
	{
		_arr[_size] = obj;
		++_size;
		return;
	}

	_capacity = _capacity * vector<T>::_MULT + 1;
	T *new_arr = new T[_capacity];
	for (std::size_t i = 0; i < _size; ++i)
	{
		new_arr[i] = _arr[i];
	}
	new_arr[_size] = obj;
	delete[] _arr;
	_arr = new_arr;
	++_size;
}

template<class T>
void	vector<T>::erase(std::size_t index)
{
	if (index >= _size)
		return;

	for (std::size_t i = index; i < _size - 1; ++i)
	{
		_arr[i] = _arr[i + 1];
	}
	--_size;
}

template<class T>
std::size_t	vector<T>::size() const
{
	return _size;
}

template<class T>
bool		vector<T>::empty() const
{
	return _size == 0;
}

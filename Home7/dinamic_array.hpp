/// @file dinamic_array.hpp

/// @brief Краткое описание

#pragma once

#ifndef DINAMIC_ARRAY_HPP
#define DINAMIC_ARRAY_HPP


/// @brief  шаблонный класс динамического массива
/// @tparam Type - шаблонный параметр
/// 

template<typename Type>
class DinamicArray {
public:

	/// конструктор по умолчанию
	DinamicArray() :data_{}, size_{} {}

	/// @brief конструктор с параметром, параметр - размер динамического массива
	DinamicArray(int size) :data_{}, size_(size) {
		data_ = new Type[size_]{};
	}

	/// конструктор копирования
	DinamicArray(const DinamicArray<Type>& other);

	/// оператор []
	Type& operator[](int index) noexcept;

	const Type& operator[](int index) const noexcept;
		
	/// деструктор
	~DinamicArray() {
		delete[] data_;
		size_ = {};
	}

	/// метод возвращающий размер массива
	int size() const {
		return size_;
	}

	/// метод добавления элемента к концу  массива, 
	/// при этом массив увеличивает свой размер на добавленный элемент
	void add(const Type& data);

	/// метод удаления элемента с конца массива,
	/// при этом массив уменньшает свой массив на удаленный элемент
	void remove();

	/// возвращает адрес начала массива
	Type* begin() {
		return data_;
	}


	/// @brief возвращает адрес конца массива
	/// @return 
	Type* end() {
		return data_ + size_;
	}


private:
	Type *data_;
	int size_;
};


//===================================================================
template<typename Type>
DinamicArray<Type>::DinamicArray(const DinamicArray<Type>& other)
{
	size_ = other.size_;
	data_ = new Type[size_]{};
	for (int i = 0; i < size_; ++i) {
		data_[i] = other.data_[i];
	}
}



//! ===================================================================
template<typename Type>
Type& DinamicArray<Type>::operator[](int index) noexcept
{
	return data_[index];
}


//==============================================================
template<typename Type>
const Type& DinamicArray<Type>::operator[](int index) const noexcept
{
	return data_[index];
}

template<typename Type>
inline void DinamicArray<Type>::add(const Type& data)
{
	Type* tmp = new Type[size_ + 1];
	for (int i = 0; i < size_; ++i) {
		tmp[i] = data_[i];
	}
	delete[] data_;
	data_ = tmp;
	data_[size_] = data;
	size_ += 1;
}

template<typename Type>
inline void DinamicArray<Type>::remove()
{
	--size_;
}

#endif // !DINAMIC_ARRAY_HPP

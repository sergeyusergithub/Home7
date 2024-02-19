// dinamic_array.hpp

/*
Обязятельными пунктаи задания являются следующие возможности коллекции:
-- размещение в себе элементов произвольного типа;
-- добавление и удаление элементов;
-- предоставление доступа к элементам массива;
-- возможность работы с колекцией через range based for, sdt::size;
-- корректная передача по параметру в функции.

Дополнительные возможности:
-- работа независимо с хранением данных и с выделением памяти;
-- возможность удаления и вставки новых элементов в произвольные места коллекции.

*/

#pragma once

#ifndef DINAMIC_ARRAY_HPP
#define DINAMIC_ARRAY_HPP


template<typename Type>
// шаблонный класс динамического массива
class DinamicArray {
public:

	// конструктор по умолчанию
	DinamicArray() :data_{}, size_{} {}

	// конструктор с параметром, параметр - размер динамического массива
	DinamicArray(int size) :data_{}, size_(size) {
		data_ = new Type[size_]{};
	}

	// конструктор копирования
	DinamicArray(const DinamicArray<Type>& other);

	// оператор []
	Type& operator[](int index) noexcept;

	const Type& operator[](int index) const noexcept;


	Type& Data(int index) {
		return data_[index];
	}

	const Type& Data(int index) const{
		return data_[index];
	}


	~DinamicArray() {
		delete[] data_;
		size_ = {};
	}


private:
	Type *data_;
	int size_;
};






#endif // !DINAMIC_ARRAY_HPP

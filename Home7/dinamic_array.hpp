// dinamic_array.hpp

/*
������������� ������� ������� �������� ��������� ����������� ���������:
-- ���������� � ���� ��������� ������������� ����;
-- ���������� � �������� ���������;
-- �������������� ������� � ��������� �������;
-- ����������� ������ � ��������� ����� range based for, sdt::size;
-- ���������� �������� �� ��������� � �������.

�������������� �����������:
-- ������ ���������� � ��������� ������ � � ���������� ������;
-- ����������� �������� � ������� ����� ��������� � ������������ ����� ���������.

*/

#pragma once

#ifndef DINAMIC_ARRAY_HPP
#define DINAMIC_ARRAY_HPP


template<typename Type>
// ��������� ����� ������������� �������
class DinamicArray {
public:

	// ����������� �� ���������
	DinamicArray() :data_{}, size_{} {}

	// ����������� � ����������, �������� - ������ ������������� �������
	DinamicArray(int size) :data_{}, size_(size) {
		data_ = new Type[size_]{};
	}

	// ����������� �����������
	DinamicArray(const DinamicArray<Type>& other);

	// �������� []
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

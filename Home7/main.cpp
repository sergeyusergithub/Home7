// main.cpp

#include <iostream>
#include "dinamic_array.hpp"

template <typename T>
class A {
public:

	A() {
		dat = new T[10]{};
	}


	T& operator[](int index) {
		return dat[index];
	}

	const T& operator[](int index)const {
		return dat[index];
	}

	T data() {
		return dat[0];
	}

	~A() {
		delete dat;
	}
private:
	T *dat;

};


int main() {

	DinamicArray<int> arr(10);

	A<int> aa;

	aa[1] = 5;

	//arr[3] = 15;

	std::cout << aa[1] << std::endl;
	std::cout << arr.Data(3) << std::endl;
	//std::cout << arr[3] << std::endl;

	//int a = arr[0];

	//arr[1] = 5;

	//arr[0] = 1;

	

	//arr[0] = 1;
	//arr[1] = 2;
	/*for (int i = 0; i < 10; ++i) {
		std::cout << arr.Data(i) << ", ";
	}
	std::cout << "\b\b \n\n";*/

	



	return 0;
}
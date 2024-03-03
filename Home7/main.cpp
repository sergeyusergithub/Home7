// main.cpp

#include <iostream>
#include "dinamic_array.hpp"

/// функция для проверки динамического массива типа char
void arr_char(DinamicArray<char>& str, const char* chr) {
	for (int i = 0; i < str.size(); i++) {
		str[i] = chr[i];
	}
}

int main() {
	/*!
	* \brief Проверка динамического массива
	* 
	* 
	*/
	DinamicArray<int> arr(10);

	arr[3] = 15;

	
	std::cout << arr[3] << std::endl;
	
	std::cout << "std::size() = " << std::size(arr) << '\n';

	arr.add(12);

	std::cout << "std::size() = " << std::size(arr) << '\n';

	std::cout << "arr[10] = " << arr[10] << '\n';
	std::cout << "arr[9] = " << arr[9] << '\n';


	arr.remove();

	std::cout << "std::size() = " << std::size(arr) << '\n';

	for (auto &ar : arr) {
		std::cout << ar << ' ';
	}
	std::cout << "\n";

	arr.add(9);
	for (auto& ar : arr) {
		std::cout << ar << ' ';
	}

	DinamicArray<char> str(10);

	std::cout << std::endl;

	str[0] = "HelloWorld"[0];

	std::cout << str[0] << std::endl;

	arr_char(str, "HelloWorld");

	for (auto& st : str) {
		std::cout << st;
	}

	std::cout << "\n\n";

	return 0;
}
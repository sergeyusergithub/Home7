// dinamic_array.hpp

#include "dinamic_array.hpp"

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
	return *(data_ + index * sizeof(Type));
	// TODO: insert return statement here
}


//==============================================================
template<typename Type>
const Type& DinamicArray<Type>::operator[](int index) const noexcept
{	

	return *(data_ + index * sizeof(Type));
	// TODO: insert return statement here
}

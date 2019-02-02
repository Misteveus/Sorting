#ifndef SORT_CLASS_HPP
#define SORT_CLASS_HPP

#include "i_sort.hpp"
#include "sort_class.hpp"

#include <string>
#include <iostream>
#include <iomanip>

template<class T>
class sort_class : public i_sort {
public:
	virtual ~sort_class();
	explicit sort_class(const sort_class&) = delete;
	sort_class& operator=(const sort_class&) = delete;
	explicit sort_class(sort_class && ) = delete;
	sort_class& operator=(sort_class&&) = delete;

	void reset(const int* const_array) override;
	std::string array_type() override;
	void print_array() override;
	bool verify() override;
	std::string name() override = 0;
	void sort() override = 0;
	size_t size() override;

protected:
	sort_class() = default;

	explicit sort_class(T& array, const size_t size)
	: array_to_sort_(array), array_size_(size), array_type_(typeid(T).name()) {};

	friend std::ostream& operator<<(std::ostream& os, const sort_class& rhs) {
		for(auto index{ 0 }; index < rhs.array_size_; index++) {
			os << "[" << rhs.array_to_sort_[index] << "] ";
		}
		return os;
	}


	T array_to_sort_;
	size_t array_size_;
	const char* array_type_;

};




//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\


template <class T>
sort_class<T>::~sort_class() = default;

template<class T>
void sort_class<T>::reset(const int* const_array) { 
	for(auto index{ 0 }; index < array_size_; index++) {
		 array_to_sort_[index] = const_array[index];
	}
}


template <class T>
 std::string sort_class<T>::array_type() {
	
	return std::string(array_type_);
}

template <class T>
void sort_class<T>::print_array()  {
	std::cout << *this;
}

template <class T>
 bool sort_class<T>::verify() {
	for(auto index { 0 }; index < (array_size_ - 1); index++) {
		if(array_to_sort_[index] > array_to_sort_[index + 1])
			return false;
	}
	return true;
}

template <class T>
size_t sort_class<T>::size() {
	return array_size_;
}


#endif

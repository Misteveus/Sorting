#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <algorithm>
#include <random>
#include "adt_exception.hpp"

template <class T>
class dynamic_array final {
public:
	explicit dynamic_array() noexcept(false);
	~dynamic_array() noexcept;
	explicit dynamic_array(std::size_t length, int start_index = 0) noexcept(false);
	dynamic_array(const dynamic_array<T>& array) noexcept(false);
	explicit dynamic_array(const T array[], size_t size) noexcept(false);
	explicit dynamic_array(dynamic_array<T>&& array) noexcept;

	dynamic_array<T>& operator=(const dynamic_array<T>& rhs) noexcept(false);
	dynamic_array<T>& operator=(dynamic_array<T>&& rhs) noexcept;

	T& operator[](const int index) noexcept(false);
	T operator[](const int index) const noexcept(false);
	operator bool() const noexcept;
	int get_start_index() const noexcept;
	size_t get_length() const noexcept;
	void set_start_index(int index) noexcept(false);
	void set_length(size_t new_length) noexcept(false);
	// void shuffle();

private:
	T* storage_ = nullptr;
	size_t length_ = 0;
	int start_index_ = 0;
};


template <class T>
dynamic_array<T>::dynamic_array() noexcept(false) {
	try {
		length_ = 0;
		start_index_ = 0;
		storage_ = new T[length_];
	}
	catch (std::bad_alloc& exception) {
		throw adt_exception(exception.what());
	}
}

template <class T>
dynamic_array<T>::~dynamic_array() noexcept {
	if (storage_ != nullptr) delete[] storage_;
	storage_ = nullptr;
}

template <class T>
dynamic_array<T>::dynamic_array(const dynamic_array<T>& array) noexcept(false) {
	if (this != &array)
		*this = array;
}

template <class T>
dynamic_array<T>& dynamic_array<T>::operator=(const dynamic_array<T>& rhs) noexcept(false) {
	if (this != &rhs) {
		try {
		
			if (storage_ != nullptr) delete[] storage_;
			storage_ = nullptr;
			storage_ = new T[rhs.length_];
			length_ = rhs.length_;
			start_index_ = rhs.start_index_;

		}
		catch (std::bad_alloc& exception) {
			throw adt_exception(exception.what());
		}

		for (auto i = 0; i < rhs.length_; ++i) {
			storage_[i] = rhs.storage_[i];
		}
	}
	return *this;
}

template <class T>
dynamic_array<T>::dynamic_array(dynamic_array<T>&& array) noexcept {
	*this = std::move(array);
}

template <class T>
dynamic_array<T>& dynamic_array<T>::operator=(dynamic_array<T>&& rhs) noexcept {
	if (this != &rhs) {
		length_ = rhs.length_;
		start_index_ = rhs.start_index_;

		if (storage_ != nullptr) delete[] storage_;
		storage_ = rhs.storage_;
		rhs.storage_ = nullptr;
	}
	return *this;
}

template <class T>
T& dynamic_array<T>::operator[](const int index) {
	auto actual_index = index - start_index_;

	if ((actual_index < 0) || (actual_index >= length_)) {
		throw adt_exception("Out of bounds");
	}

	return storage_[actual_index];
}

template <class T>
T dynamic_array<T>::operator[](const int index) const {
	auto actual_index = index - start_index_;

	if ((actual_index < 0) || (actual_index >= length_)) {
		throw adt_exception("Out of bounds");
	}

	return storage_[actual_index];
}

template <class T>
dynamic_array<T>::operator bool() const noexcept {
	return length_; 
}

template <class T>
int dynamic_array<T>::get_start_index() const noexcept {
	return start_index_;
}

template <class T>
size_t dynamic_array<T>::get_length() const noexcept {
	return length_;
}

template <class T>
void dynamic_array<T>::set_start_index(const int index) noexcept(false) {
	if ((index < 0) || (index > std::numeric_limits<int>::max())) {
		throw adt_exception("Out of bounds");
	}
	start_index_ = index;
}

template <class T>
void dynamic_array<T>::set_length(const size_t new_length) noexcept(false) {
	try {
		// can throw std::bad_alloc
		T* temp = new T[new_length]; 

			// if new size is larger
		if (length_ <= new_length) {
			for (int i = 0; i < length_; i++) {
				temp[i] = storage_[i];
			}
		}
			// if new size is smaller
		else if (length_ > new_length) {
			for (int i = 0; i < new_length; i++) {
				temp[i] = storage_[i];
			}
		}

		delete[] storage_;
		storage_ = temp;
		temp = nullptr;
		length_ = new_length;
	}
	catch (std::bad_alloc& exception) {
		throw adt_exception(exception.what());
	}
}

//template<class T>
//inline void dynamic_array<T>::shuffle()
//{
//	std::random_device rd;
//	std::mt19937 rng(rd());
//	std::uniform_int_distribution<T> dist_n_numbers(0, (length_ -1)); // distribution in range [1, 6] 
//	
//	for (int i = 0; i < length_; i++) {
//		std::swap(storage_[i], storage_[dist_n_numbers(rng)]);
//	};
//
//}

template <class T>
dynamic_array<T>::dynamic_array(std::size_t length, const int start_index) noexcept(false) {
	try {
		// can throw std::bad_alloc
		storage_ = new T[length]; 
		start_index_ = start_index;
		length_ = length;
	}
	catch (std::bad_alloc& exception) {
		throw adt_exception(exception.what());
	}
}

template <class T> 
dynamic_array<T>::dynamic_array(const T array[], const size_t size) noexcept(false) { 
	// this can cause memory access violations if the size is not correct
	try {
		// can throw std::bad_alloc
		storage_ = new T[size];
		length_ = size;
		start_index_ = 0;
	}
	catch (std::bad_alloc& exception) {
		throw adt_exception(exception.what());
	};
	for (auto i = 0; i < size; i++) {
		storage_[i] = array[i];
	}
}


#endif DYNAMIC_ARRAY_HPP

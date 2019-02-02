#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include "i_sort.hpp"
#include "sort_class.hpp"

template<class T>
class insertion_sort final : public sort_class<T> {
public:
	// CONSTRUCTORS / DESTRUCTOR
	~insertion_sort();
	insertion_sort() = delete;
	insertion_sort(const insertion_sort&) = delete;
	insertion_sort(insertion_sort &&) = delete;
	insertion_sort& operator=(const insertion_sort &) = delete;
	insertion_sort& operator=(insertion_sort &&) = delete;

	explicit insertion_sort(T& array, size_t size);

	// FUNCTIONS
	void sort() override;
	std::string name() override;
	
private:	
	const std::string name_{"insertion_sort"};
	void insertionSort(T& a);
};



//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

template<class T>
insertion_sort<T>::~insertion_sort() {
	
};

template<class T>
insertion_sort<T>::insertion_sort(T& array, size_t size) 
	: sort_class<T>(array, size) {	
};

 template <class T>
void insertion_sort<T>::sort() {
		
	insertionSort(sort_class<T>::array_to_sort_);
}

template <class T>
 std::string insertion_sort<T>::name() {
	return name_;
}
 
template<class T>
void insertion_sort<T>::insertionSort(T& a) { 
	 using sc = sort_class<T>;
 	for (int i = 1; i < sc::array_size_; i++) { 
	// a[i] is the next data to insert 
 		int next = a[i]; // Scan backwards to find a place. 
 		int j;
		for (j = i - 1; (j >= 0) && (a[j] > next); j--) {
			a[j + 1] = a[j]; // Now insert the value next after index j at the end of loop 
		}
 		a[j + 1] = next;  
	}
}




#endif
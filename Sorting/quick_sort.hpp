#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "i_sort.hpp"
#include "sort_class.hpp"

template<class T>
class quick_sort final : public sort_class<T> {
public:
	// CONSTRUCTORS / DESTRUCTOR
	~quick_sort();
	quick_sort() = delete;
	quick_sort(const quick_sort&) = delete;
	quick_sort(quick_sort &&) = delete;
	quick_sort& operator=(const quick_sort &) = delete;
	quick_sort& operator=(quick_sort &&) = delete;

	explicit quick_sort(T& array, size_t size);

	// FUNCTIONS
	void sort() override;
	 std::string name() override;


private:	
	const std::string name_{"quick_sort"};

	int partition(T& a, int left, int right) const;
	void quicksort(T& array, int left, int right) const;
};



//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

template<class T>
quick_sort<T>::~quick_sort() {
	
};

template<class T>
quick_sort<T>::quick_sort(T& array, size_t size) 
	: sort_class<T>(array, size) {	
};

 template <class T>
void quick_sort<T>::sort() {
	using sc = sort_class<T>;
	quicksort(sc::array_to_sort_, 0, sc::array_size_ - 1);
}

template <class T>
 std::string quick_sort<T>::name() {
	return name_;
}
 template<class T>
int quick_sort<T>::partition(T& a, int left, int right) const { 
 	int pivot = a[right]; 
 	int i = left - 1;
	for (int j = left; j <= right - 1; ++j) {
		if (a[j] <= pivot) {
			i++; 
			std::swap(a[i], a[j]);
		}
	}
	std::swap(a[i + 1], a[right]);

 	return i + 1;   
}
template<class T>
void quick_sort<T>::quicksort(T& array, int left, int right) const {
	 if (left < right) {
		 int p = partition(array, left, right); 
	 	quicksort(array, left, p - 1); 
	 	quicksort(array, p + 1, right);
	 }
 }



#endif
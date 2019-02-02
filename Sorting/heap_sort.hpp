#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include "i_sort.hpp"
#include "sort_class.hpp"

template<class T>
class heap_sort final : public sort_class<T> {
public:
	// CONSTRUCTORS / DESTRUCTOR
	~heap_sort();
	heap_sort() = delete;
	heap_sort(const heap_sort&) = delete;
	heap_sort(heap_sort &&) = delete;
	heap_sort& operator=(const heap_sort &) = delete;
	heap_sort& operator=(heap_sort &&) = delete;

	explicit heap_sort(T& array, size_t size);

	// FUNCTIONS
	void sort() override;
	 std::string name() override;
	
private:	
	const std::string name_{"heap_sort"};
	// ReSharper disable once IdentifierTypo
	void heapify(T& sort_me, size_t size, int root);
};



//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

template<class T>
heap_sort<T>::~heap_sort() {
	
};

template<class T>
heap_sort<T>::heap_sort(T& array, size_t size) 
	: sort_class<T>(array, size) {	
};

 template <class T>
void heap_sort<T>::sort() {
	using sc = sort_class<T>;

	for (int i = (sc::array_size_ / 2) - 1; i >= 0; i--) 
		heapify(sc::array_to_sort_, sc::array_size_, i);

	for (int i = sc::array_size_ - 1; i >= 0; i--) { 
		std::swap(sc::array_to_sort_[0], sc::array_to_sort_[i]);
		heapify(sc::array_to_sort_, i, 0);
	}
}

template <class T>
 std::string heap_sort<T>::name() {
	return name_;
}

template <class T>
// ReSharper disable once IdentifierTypo
void heap_sort<T>::heapify(T& sort_me, size_t size, int root) { 
 	auto largest = root; 
 	auto left_child = 2 * root + 1; 
 	auto right_child = 2 * root + 2;
	if (left_child < size && sort_me[left_child] > sort_me[largest]) 
		largest = left_child;
	if (right_child < size && sort_me[right_child] > sort_me[largest]) 
		largest = right_child;
	if (largest != root) { 
		std::swap(sort_me[root], sort_me[largest]);
	heapify(sort_me, size, largest);
	}
}


#endif
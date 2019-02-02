#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include "i_sort.hpp"
#include "sort_class.hpp"

template<class T>
class selection_sort final : public sort_class<T> {
public:
	// CONSTRUCTORS / DESTRUCTOR
	~selection_sort();
	selection_sort() = delete;
	selection_sort(const selection_sort&) = delete;
	selection_sort(selection_sort &&) = delete;
	selection_sort& operator=(const selection_sort &) = delete;
	selection_sort& operator=(selection_sort &&) = delete;

	explicit selection_sort(T& array, size_t size);

	// FUNCTIONS
	void sort() override;
	 std::string name() override;
	
private:	
	const std::string name_{"selection_sort"};
	void selectionSort(T& a);
};



//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

template<class T>
selection_sort<T>::~selection_sort() {
	
};

template<class T>
selection_sort<T>::selection_sort(T& array, size_t size) 
	: sort_class<T>(array, size) {	
};

 template <class T>
void selection_sort<T>::sort() {
	 using sc = sort_class<T>;
		selectionSort(sc::array_to_sort_);
}

template <class T>
 std::string selection_sort<T>::name() {
	return name_;
}
 template<class T>
 void selection_sort<T>::selectionSort(T& a) { 
	using sc = sort_class<T>;
 	for (int i = sc::array_size_ - 1; i >= 1; --i) { 
 		int index = i;  // i is the last item position and 
 						// index is the largest element position 
 						// loop to get the largest element 
 		for (int j = 0; j < i; j++) { 
 			if (a[j] > a[index]) 
				index = j; // j is the current largest item 
 			}		 // Swap the largest item a[index] with the last item a[i] 
 		int temp = a[index]; 
 		a[index] = a[i]; 
 		a[i] = temp; 
 	} 
 } 



#endif
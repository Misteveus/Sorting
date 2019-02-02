#ifndef FLAGGED_BUBBLE_SORT_HPP
#define FLAGGED_BUBBLE_SORT_HPP


#include "i_sort.hpp"
#include "sort_class.hpp"

template<class T>
class flagged_bubble_sort final : public sort_class<T> {
public:
	// CONSTRUCTORS / DESTRUCTOR
	~flagged_bubble_sort();
	flagged_bubble_sort() = delete;
	flagged_bubble_sort(const flagged_bubble_sort&) = delete;
	flagged_bubble_sort(flagged_bubble_sort &&) = delete;
	flagged_bubble_sort& operator=(const flagged_bubble_sort &) = delete;
	flagged_bubble_sort& operator=(flagged_bubble_sort &&) = delete;

	explicit flagged_bubble_sort(T& array, size_t size);

	// FUNCTIONS
	void sort() override;
	 std::string name() override;
	
private:	
	const std::string name_{"flagged_bubble_sort"};
	
};



//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

template<class T>
flagged_bubble_sort<T>::~flagged_bubble_sort() {
	
};

template<class T>
flagged_bubble_sort<T>::flagged_bubble_sort(T& array, size_t size) 
	: sort_class<T>(array, size) {	
};

 template <class T>
void flagged_bubble_sort<T>::sort() {
		using sc = sort_class<T>;

	for (int i = 1; i < sc::array_size_ ; i++) { 
		bool isSorted = true;												// isSorted = true if a[] is sorted 
		for (int j = 0; j < sc::array_size_-i; j++) {         
			if ((sc::array_to_sort_[j]) > (sc::array_to_sort_[j+1])) {		// the larger item bubbles up 
				int temp = sc::array_to_sort_[j];							// and isSorted is set to false, 
				sc::array_to_sort_[j] = sc::array_to_sort_[j+1];			// i.e. the data was not sorted 
				sc::array_to_sort_[j+1] = temp; 
				isSorted = false; 
			} 
		} 
		if (isSorted) return;   // Why? 
	}
}

template <class T>
 std::string flagged_bubble_sort<T>::name() {
	return name_;
}





#endif
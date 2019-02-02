#ifndef BRUTE_FORCE_BUBBLE_SORT_HPP
#define BRUTE_FORCE_BUBBLE_SORT_HPP

#include "i_sort.hpp"
#include "sort_class.hpp"

template<class T>
class brute_force_bubble_sort final : public sort_class<T> {
public:
	// CONSTRUCTORS / DESTRUCTOR
	~brute_force_bubble_sort();
	brute_force_bubble_sort() = delete;
	brute_force_bubble_sort(const brute_force_bubble_sort&) = delete;
	brute_force_bubble_sort(brute_force_bubble_sort &&) = delete;
	brute_force_bubble_sort& operator=(const brute_force_bubble_sort &) = delete;
	brute_force_bubble_sort& operator=(brute_force_bubble_sort &&) = delete;

	explicit brute_force_bubble_sort(T array, size_t size);

	// FUNCTIONS
	void sort() override;
	 std::string name() override;
	
private:	
	const std::string name_{"brute_force_bubble_sort"};
	
};



//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

template<class T>
brute_force_bubble_sort<T>::~brute_force_bubble_sort() {
	
};

template<class T>
brute_force_bubble_sort<T>::brute_force_bubble_sort(T array, size_t size) 
	: sort_class<T>(array, size) {	
};

 template <class T>
void brute_force_bubble_sort<T>::sort() {
	using sc = sort_class<T>;

	for (int i = 1; i < sc::array_size_; i++) { 
		for (int j = 0; j < sc::array_size_ - i; j++) { 
			if (sc::array_to_sort_[j] > sc::array_to_sort_[j+1]) {
				// the larger item bubbles down (swap) 
				int temp = sc::array_to_sort_[j]; 
				sc::array_to_sort_[j] = sc::array_to_sort_[j+1]; sc::array_to_sort_[j+1] = temp; 
			} 
		} 
	}
}

template <class T>
 std::string brute_force_bubble_sort<T>::name() {
	return name_;
}





#endif
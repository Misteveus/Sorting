#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include "i_sort.hpp"
#include "sort_class.hpp"

template<class T>
class shell_sort final : public sort_class<T> {
public:
	// CONSTRUCTORS / DESTRUCTOR
	~shell_sort();
	shell_sort() = delete;
	shell_sort(const shell_sort&) = delete;
	shell_sort(shell_sort &&) = delete;
	shell_sort& operator=(const shell_sort &) = delete;
	shell_sort& operator=(shell_sort &&) = delete;

	explicit shell_sort(T& array, size_t size);

	// FUNCTIONS
	void sort() override;
	 std::string name() override;
	
private:	
	const std::string name_{"shell_sort"};
	
};



//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

template<class T>
shell_sort<T>::~shell_sort() {
	
};

template<class T>
shell_sort<T>::shell_sort(T& array, size_t size) 
	: sort_class<T>(array, size) {	
};

 template <class T>
void shell_sort<T>::sort() {
	using sc = sort_class<T>;
	size_t j;

	for (size_t h = sc::array_size_/ size_t(2); h > size_t(0); h /= size_t(2)) { 
		for (size_t i = h; i < sc::array_size_; i++) { 
			int tmp = sc::array_to_sort_[i];

			for (j = i; j >= h && tmp < sc::array_to_sort_[j-h]; j -= h) {
				sc::array_to_sort_[j] = sc::array_to_sort_[j-h];
			}
			sc::array_to_sort_[j] = tmp;
		}
	}

}

template <class T>
 std::string shell_sort<T>::name() {
	return name_;
}



#endif
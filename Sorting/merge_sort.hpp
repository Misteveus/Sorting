#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include "i_sort.hpp"
#include "sort_class.hpp"

template<class T>
class merge_sort final : public sort_class<T> {
public:
	// CONSTRUCTORS / DESTRUCTOR
	~merge_sort();
	merge_sort() = delete;
	merge_sort(const merge_sort&) = delete;
	merge_sort(merge_sort &&) = delete;
	merge_sort& operator=(const merge_sort &) = delete;
	merge_sort& operator=(merge_sort &&) = delete;

	explicit merge_sort(T& array, size_t size);

	// FUNCTIONS
	void sort() override;
	 std::string name() override;
	
private:	
	const std::string name_{"merge_sort"};
	void mergeSort(T& a, int i, int j);
	void merge(T& a, int i, int mid, int j);
};



//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\

template<class T>
merge_sort<T>::~merge_sort() {
	
};

template<class T>
merge_sort<T>::merge_sort(T& array, size_t size) 
	: sort_class<T>(array, size) {	
};

 template <class T>
void merge_sort<T>::sort() {
	using sc = sort_class<T>;
 	mergeSort(sc::array_to_sort_, 0, sc::array_size_ - 1);
}

template <class T>
 std::string merge_sort<T>::name() {
	return name_;
}

 template<class T>
void merge_sort<T>::mergeSort(T& a, int i, int j) { 
 	// to sort data from a[i] to a[j], where i<j 
 	if (i < j) {
		int mid = (i + j) / 2;			// divide 
 		mergeSort(a, i, mid);		// recursion
 		mergeSort(a, mid + 1, j); 
 		merge(a, i, mid, j);			//conquer: merge a[i..mid] and //a[mid+1..j] back into a[i..j] 
	}
}

template<class T>
void merge_sort<T>::merge(T& a, int i, int mid, int j) { 
	// Merges the 2 sorted sub-arrays a[i..mid] and // a[mid+1..j] into one sorted sub-array a[i..j]

	int temp_size = j - i + 1;
	int* temp = new int[temp_size];  // temp storage 
 	int left = i;
 	int right = mid + 1;
 	int it = 0; // it = next index to store merged item in temp[] 

	while(left <= mid && right <= j) { // output the smaller 
		if (a[left] <= a[right]) 
			temp[it++] = a[left++]; 
		else temp[it++] = a[right++];
	}
	 // Copy the remaining elements into temp. 
 	while (left <= mid) 
		temp[it++] = a[left++]; 
 	while (right <= j)  
		temp[it++] = a[right++];

	// Copy the result in temp back into // the original array a 
	for (int k = 0; k < temp_size; k++) 
		a[i + k] = temp[k];
	delete[] temp;

}



#endif
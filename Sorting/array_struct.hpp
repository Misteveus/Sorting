#ifndef ARRAY_STRUCT_H
#define ARRAY_STRUCT_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <random>

#include "dynamic_array.hpp"

#include "brute_force_bubble_sort.hpp"
#include "flagged_bubble_sort.hpp"
#include "selection_sort.hpp"
#include "insertion_sort.hpp"
#include "shell_sort.hpp"
#include "heap_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "record.hpp"


using std::cin;
using std::cout;
using std::make_unique;
using std::unique_ptr;
using std::vector;
using std::chrono::high_resolution_clock;
using std::size_t;


struct struct_of_arrays_with_i_sort_objects final {
	vector<unique_ptr<i_sort>> list_of_sorting_objects;
	vector<unique_ptr<record>> list_of_records;

	vector<int> vector_array_to_sort;
	dynamic_array<int> dynamic_array_to_sort;
	const int * p_const_array;
	int * p_int_array_to_sort;
	const size_t number_of_elements;

	// CONSTRUCTOR / DESTRUCTOR
	struct_of_arrays_with_i_sort_objects() = delete;
	struct_of_arrays_with_i_sort_objects(const size_t n_elements);
	~struct_of_arrays_with_i_sort_objects();
	struct_of_arrays_with_i_sort_objects(struct_of_arrays_with_i_sort_objects&) = delete;
	struct_of_arrays_with_i_sort_objects(struct_of_arrays_with_i_sort_objects&&) = delete;
	struct_of_arrays_with_i_sort_objects& operator=(struct_of_arrays_with_i_sort_objects&) = delete;
	struct_of_arrays_with_i_sort_objects& operator=(struct_of_arrays_with_i_sort_objects&&)	= delete;

	void create_sorting_objects();
	void sort();

private:
	// static size_t get_number_to_sort();
	static const int* generate_array_of_n_integers(const size_t n);
};

inline struct_of_arrays_with_i_sort_objects::struct_of_arrays_with_i_sort_objects(size_t n_elements) 
	: number_of_elements(n_elements) {

	// set up a constant array with random numbers on instantiation
	p_const_array = generate_array_of_n_integers(n_elements);					// pointer to constant array of integers

	// create different types of arrays and initialize with the constant array
	p_int_array_to_sort = new int[n_elements];									// pointer to built-in array
	vector_array_to_sort.resize(n_elements);									// array of type std::vector<int>
	dynamic_array_to_sort = dynamic_array<int>(p_const_array, n_elements);		// array of type dynamic_array<int>		
	for (size_t index{0}; index < n_elements; index++) {
		p_int_array_to_sort[index] = p_const_array[index];
		vector_array_to_sort.at(index) = p_const_array[index];
	}
}

inline struct_of_arrays_with_i_sort_objects::~struct_of_arrays_with_i_sort_objects() {
	delete[] p_int_array_to_sort;
	delete[] p_const_array;

	p_int_array_to_sort = nullptr;
	p_const_array = nullptr;
}

inline void struct_of_arrays_with_i_sort_objects::create_sorting_objects() {
	using ia = int*;
	using da = dynamic_array<int>;
	using va = vector<int>;

	list_of_sorting_objects.emplace_back(make_unique<brute_force_bubble_sort<ia>>(p_int_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<brute_force_bubble_sort<va>>(vector_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<brute_force_bubble_sort<da>>(dynamic_array_to_sort, number_of_elements));

	list_of_sorting_objects.emplace_back(make_unique<flagged_bubble_sort<ia>>(p_int_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<flagged_bubble_sort<va>>(vector_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<flagged_bubble_sort<da>>(dynamic_array_to_sort, number_of_elements));

	list_of_sorting_objects.emplace_back(make_unique<selection_sort<ia>>(p_int_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<selection_sort<va>>(vector_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<selection_sort<da>>(dynamic_array_to_sort, number_of_elements));

	list_of_sorting_objects.emplace_back(make_unique<insertion_sort<ia>>(p_int_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<insertion_sort<va>>(vector_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<insertion_sort<da>>(dynamic_array_to_sort, number_of_elements));

	list_of_sorting_objects.emplace_back(make_unique<shell_sort<ia>>(p_int_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<shell_sort<va>>(vector_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<shell_sort<da>>(dynamic_array_to_sort, number_of_elements));

	list_of_sorting_objects.emplace_back(make_unique<heap_sort<ia>>(p_int_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<heap_sort<va>>(vector_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<heap_sort<da>>(dynamic_array_to_sort, number_of_elements));

	list_of_sorting_objects.emplace_back(make_unique<merge_sort<ia>>(p_int_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<merge_sort<va>>(vector_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<merge_sort<da>>(dynamic_array_to_sort, number_of_elements));

	list_of_sorting_objects.emplace_back(make_unique<quick_sort<ia>>(p_int_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<quick_sort<va>>(vector_array_to_sort, number_of_elements));
	list_of_sorting_objects.emplace_back(make_unique<quick_sort<da>>(dynamic_array_to_sort, number_of_elements));
}

inline void struct_of_arrays_with_i_sort_objects::sort() {

	for (auto& array : list_of_sorting_objects) {
		const auto t1 = high_resolution_clock::now();
		array->sort();
		const auto t2 = high_resolution_clock::now();
		
		const auto new_record = record(array->name(), array->array_type(),  array->size(), t1, t2, array->verify()) ;
		
		list_of_records.emplace_back(make_unique<record>(new_record));
		// cout << new_record;

		array->reset(p_const_array);
	}

}

//inline size_t struct_of_arrays_with_i_sort_objects::get_number_to_sort() {
//	size_t n{0};
//	cout << "Enter number of integers to create and sort: ";
//	cin >> n;
//	while (n <= 0 || n > std::numeric_limits<size_t>::max()) {
//		cin.clear();
//		cout << "Enter a valid number: ";
//		cin >> n;
//	}
//	return n;
//}

inline const int* struct_of_arrays_with_i_sort_objects::generate_array_of_n_integers(const size_t n) {
	const auto array_of_integers = new int[n];

	// set up random number generator
	std::random_device rd;
	std::mt19937 generator(rd());
	const std::uniform_int_distribution<int> dis(0, 100000);

	// fill array with random numbers
	for (auto index{0}; index < n; index++) { array_of_integers[index] = dis(generator); }
	return array_of_integers;
}
#endif

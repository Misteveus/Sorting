#include "pch.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>

#include "array_struct.hpp"

using std::cin;
using std::vector;
using std::string;
using std::cout;
using std::unique_ptr;
using std::make_unique;
using std::size_t;

int main(int argc, char* argv[]) {
	
	{
	using  objs = struct_of_arrays_with_i_sort_objects;

		vector<string> list_of_args;
		vector<size_t> n_numbers;
		vector<unique_ptr<objs>> list_of_array_structs;

		for (int i = 1; i < argc; ++i) {
			const auto p = argv[i];
			list_of_args.emplace_back(p);
		}
		for (const auto& arg : list_of_args) {
			const auto new_number = stoi(arg);
			if ((new_number <= 0) || (new_number > std::numeric_limits<int>::max())) {
				cout << new_number << " is not a valid number \n";
			} else {
				n_numbers.push_back(static_cast<size_t>(new_number));
			}
		}

		list_of_array_structs.reserve(n_numbers.size());
		for (const auto& number : n_numbers) {
			list_of_array_structs.emplace_back(make_unique<objs>(number));
		}
		

		cout << std::setw(25) << std::setiosflags(std::ios::internal | std::ios::fixed) << "SORT TYPE"
			<< std::setw(15) << std::right << "TIME"
			<< std::setw(15) << std::right << "ARRAY SIZE"
			<< std::setw(10) << std::right << "CHECK"
			<< std::setw(15) << std::right << "ARRAY TYPE"
			<< " \n";
		for (auto& array_struct : list_of_array_structs) {

			array_struct->create_sorting_objects();
			array_struct->sort();
				
			for(auto const& record : array_struct->list_of_records)
			cout << *record;

		}
	
	}

	cin.get();
	return 0;
}

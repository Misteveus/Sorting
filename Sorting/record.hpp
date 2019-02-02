#ifndef RECORD_HPP
#define RECORD_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <utility>

using std::string;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
struct record final {
	
	record() = delete;
	record (
		const string str1,
		const string str2,
		const size_t array_size,
		const high_resolution_clock::time_point t1, 
		const high_resolution_clock::time_point t2, 
		const bool verified
		): 
		sort_object_type_(str1), 
		array_type_(str2),
		array_size_(array_size),
		t1_(t1), 
		t2_(t2), 
		time_span_(std::chrono::duration_cast<duration<double, std::milli>>(t2_ - t1_)), 
		verified_sorted_(verified) 
	{	}

	const string sort_object_type_;
	const string array_type_;

	const high_resolution_clock::time_point t1_;
	const high_resolution_clock::time_point t2_;
	const duration<double, std::milli> time_span_;

	const size_t array_size_;
	const bool verified_sorted_;

	friend std::ostream& operator<<(std::ostream& os, const record& rhs)  {
		os << std::setw(25) << std::setiosflags(std::ios::right | std::ios::fixed) << rhs.sort_object_type_ << "  "
			<< std::setw(15) << std::fixed << std::setprecision(2)  << std::to_string(rhs.time_span_.count()) << "ms  "
			<< std::setw(15) << rhs.array_size_
			<< std::setw(10) <<  (rhs.verified_sorted_ ? "PASS" : "FAIL") << "  "
			<< std::setw(15) << rhs.array_type_
			<< " \n";


		return os;
	}



	~record() = default;
	record (const record&) = default;
	record (record&&) = default;
	record& operator=(const record&) = delete;
	record& operator=(record&&) = delete;
};




#endif
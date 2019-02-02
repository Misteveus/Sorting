#ifndef I_SORT_HPP
#define I_SORT_HPP

#include <string>

class i_sort {
public:
	virtual ~i_sort() = default;
	i_sort(const i_sort&) = delete;
	i_sort& operator=(const i_sort&) = delete;
	i_sort(i_sort && ) = delete;
	i_sort& operator=(i_sort&&) = delete;

	virtual std::string name() = 0;
	virtual void reset(const int*) = 0;
	virtual std::string array_type() = 0;
	virtual void print_array() = 0;
	virtual void sort() = 0;
	virtual bool verify() = 0;
	virtual size_t size() = 0;

protected:
	i_sort() = default;
	
};


#endif

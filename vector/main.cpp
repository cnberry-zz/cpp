#include <stdlib.h>
#include <iostream>
#include "vector.h"

void test_range_iter() {
    ds::vector<int> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    } // for

	// use explicit begin, end iteration. i is int*
	for (ds::vector<int>::iterator i = v.begin(); i < v.end(); i++) {
		std::cout << *i << " ";
	} // for 
	std::cout << std::endl;

	// use explicit begin, end iteration. i is int*
	for (auto i = v.begin(); i < v.end(); i++) {
		std::cout << *i << " ";
	} // for 
	std::cout << std::endl;

	// test iterator using range : i is int
	for (auto i : v) {
		std::cout << i << " ";
	} // for 
	std::cout << std::endl;

	// test iterator using range : i is int&
	for (auto&& i : v) {
		std::cout << i << " ";
	} // for 
	std::cout << std::endl;

}

void test_push_back() {
    ds::vector<int> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    } // for


    for (size_t i = 0; i < v.size(); i++) {
        if (i != v[i]) {
            throw "test_push_back failed";
		} // if
    } // for
}

void test_push_front()
{
    ds::vector<int> v;

    for (int i = 99; i >= 0; i--)
    {
        v.push_front(i);
    }

    if (100 != v.size())
    {
        throw "wrong size";
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        if (i != v[i])
        {
            throw "test_push_back failed";
        }
    }
}

void test_update()
{
    ds::vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] = i * 2;
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        if (i * 2 != v[i])
        {
            throw "test_update failed";
        }
    }
}

int main()
{
    test_push_front();
    test_push_back();
    test_update();
	test_range_iter();
}

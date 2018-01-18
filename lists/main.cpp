#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include "slist.h"
#include <cstdlib>
#include <ctime>


using namespace std;

void slist_demo()
{
    lists::slist<string> list;

    // 3
    list.push_front("3");
	list.print();

    // 1 -> 3
    list.push_front("1");
	list.print();

    // 1 -> 2 -> 3
    list.insert_after(list.begin(), "2");
	list.print();

    // 1 -> 3
    list.remove_after(list.begin());
	list.print();

    // 3
    list.pop_front();
	list.print();
}

int main()
{
    slist_demo();
    //dlist_demo();
    //insert_sorted_tests();

    // sort_list_demo();

    //reverse_demo();

}

 

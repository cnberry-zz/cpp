#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void printVector(vector<int> &vec) {

	for (auto i : vec) {
		cout << i <<" ";
	}
}

void join(vector<int>::iterator begin, vector<int>::iterator middle, vector<int>::iterator end) {

	vector<int> temp;

	vector<int>::iterator it1 = begin;
	vector<int>::iterator it2 = middle;

	while ( it1 != middle &&  it2 != end) {

		if ( *it1 < *it2 ) {
			temp.push_back(*it1);
			it1++;
		} else {
			temp.push_back(*it2);
			it2++;
		}
	}

	// copy over remaining from left half
	for (auto it=it1; it != middle; it++) {
		temp.push_back(*it);
	}

	// copy over remaining from right half
	for (auto it=it2; it != end; it++) {
		temp.push_back(*it);
	}

	
	// copy temp back into vector
	for (int i = 0; i<temp.size(); i++) {
		*begin = temp[i];
		begin++;
	}
}

void merge(vector<int>::iterator begin, vector<int>::iterator end) {

	// 0 or 1 element (its sorted)
	if ( begin == end || end-begin == 1) 
		return;

	// split in 2
	vector<int>::iterator middle = begin + (end-begin)/2;	

	merge(begin,middle);
	merge(middle,end);
	
	// join both 1/2's
	join(begin,middle,end);
	
}

void sort(vector<int> &vec) {

	merge(vec.begin(),vec.end());
}

int main (int argc, char **argv) {

	vector<int> test = {1,2,4,2,3,19,50,30,12,16};
		
    cout << "unsorted: ";
	printVector(test);
	cout << endl;

	sort(test);

	cout << "sorted:   ";
	printVector(test);
	cout << endl;

	return 0;
}



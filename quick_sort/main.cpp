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

void printRange(vector<int>::iterator s, vector<int>::iterator e) {

	while (s != e) {
		cout << *s<<" ";
		s++;
	}

}

vector<int>::iterator partition(vector<int>::iterator begin, vector<int>::iterator end) {

	// pick pivot, always use right
	int pivot = *(end-1);

	// 
	vector<int>::iterator left = begin-1;
	vector<int>::iterator right = end;

	while (1) {
		while ( *(++left) < pivot ) {}						// move left to the right
		while ( right > begin && *(--right) > pivot ) {}	// move right to the left
		
		// swap if iterators havent met up, otherwise you are done
		if (left < right)
			iter_swap(left,right);
		else
			break;
	}

	iter_swap(left,end-1);
	return left;

}

void quicksort(vector<int>::iterator begin, vector<int>::iterator end) {

	if ( end - begin <= 1 )
		return;

	vector<int>::iterator pivot = partition(begin,end);

	quicksort(begin,pivot);
	quicksort(pivot+1,end);

}

void sort(vector<int> &vec) {

	quicksort(vec.begin(),vec.end());
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



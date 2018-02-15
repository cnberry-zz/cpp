#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

/* Standard recursive fib program */
int64_t fibonacci(int n) {
	if (n <= 1 ) 
		return 1;
  
	return ( fibonacci(n-1) + fibonacci(n-2) );

}

/* Dynamic programming style fib */
void fast_fibonacci(int n) {
	vector<int64_t> fib(100,1);

	cout << "fst fib: " << fib[0] << " " << fib[1] << " ";
	for (int i=2; i <= n; i++) {
		fib[i] = fib[i-2] + fib[i-1];
		cout << fib[i] << " ";
	}
	cout << endl;

}

int main (int argc, char **argv) {
          
        /* get n from cmd line */
        int n = atoi(argv[1]);       

		fast_fibonacci(n);

		cout << "std fib: ";
        for(int i=0; i<=n; i++) {
           cout << fibonacci(i) << " ";
        }
		cout << endl;



}



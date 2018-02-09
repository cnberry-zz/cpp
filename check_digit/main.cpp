#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool checkDigit(int n, int d) {

	//cout << "n: " << n << " d: " << d << endl;

	// 0 is special, handled externally to this 
	if ( n == 0 ) {
		return true;
	}

	// check digit
	if ( n%10 == d )
		return false;

	return checkDigit(n/10,d);
	
}

int main (int argc, char **argv) {
 	bool ret;
          
	stringstream ssn(argv[1]);
	int n = 0;
	ssn >> n;
	
	stringstream ssd(argv[2]);
	int d = 0;
	ssd >> d;

	// 0 is special
	if ( n == 0 ) {
		if ( d == 0 ) 
			ret = false;
		else 
			ret = true;
	} else
		ret = checkDigit(n,d);

	
	if ( ret )
 		cout << "True"<<endl;
	else
		cout << "False"<<endl;

}



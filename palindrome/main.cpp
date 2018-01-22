#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool isPalindrome(string::iterator it1, string::iterator it2) {

	// String is fully checked and no false was returned, so its true
	if ( it1 > it2)
		return true;

	// Char's don't match, this is not a palindrome
	if ((*it1) != (*it2))
		return false;
  
  	// compare next set of char's
	return isPalindrome(++it1,--it2);
}

int main (int argc, char **argv) {
          
	string s(argv[1]);
	
	bool ret = isPalindrome(s.begin(),s.end()-1);

	if ( ret )
 		cout << "True"<<endl;
	else
		cout << "False"<<endl;

}



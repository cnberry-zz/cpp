#include <string>
#include <iostream>

void test_iter() {
    std::string s = "This is a test string";

	// use explicit begin, end iteration 
	for (std::string::const_iterator cp = s.begin(); cp < s.end(); cp++) {
		std::cout << *cp << " ";
	} // for 
	std::cout << std::endl;

	// test iterator using range 
	for (auto c : s) {
		std::cout << c << " ";
	} // for 
	std::cout << std::endl;

	// test iterator reverse.
	for (auto c = s.rbegin(); c < s.rend(); c++) {
		std::cout << *c << " ";
	} // for 
	std::cout << std::endl;


}

int main() {
	test_iter();
}

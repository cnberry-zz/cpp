#include <stdlib.h>
#include <iostream>

int count(int coins[], int value, int last_coin ) {

	// last subtraction worked and we are done
	if ( value == 0)
		return 1;

	// last subtraction did not work and we are done
	if ( value < 0 ) 
		return 0;
	
	// no more coins and val is not zero, so no solution exists
	if ( last_coin < 0 )	
		return 0;

	// count is sum of solution with it, and without it
	return count(coins,value-coins[last_coin], last_coin) + count(coins,value, last_coin-1);

}

int main()
{
	int coins[3] = {1,2,3};

	std::cout << "Number of ways to make 5: " << count(coins,5,2) << std::endl;
	
}

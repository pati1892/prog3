#include <iostream>
using namespace std;

int main() {
	cout << numeric_limits<int>::max() << endl;
	cout << numeric_limits<double>::max() << endl;

	static_assert( sizeof(unsigned char) == 32, "Require char smaller or even 8 bit" );
	
	return 0;
}
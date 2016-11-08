#include <ctime>
#include <iostream>

using namespace std;

int main() {

	int number = 1;
	int teilerArray[300] = { 0 };


	time_t t;
	t = time(NULL);
	while (true) {
		int teiler = 1;
		int i = 0;
		int sum = 0;
		int teilerCounter = 0;

		while (number != teiler) {
			if (!(number%teiler)) {
				sum += teiler;
				teilerArray[teilerCounter] = teiler;
				++teilerCounter;
			}
			++teiler;
		}

		if (sum == number) {
			cout << number << ": ";
			int i = 0;
			for (int i = 0; i < teilerCounter; ++i) {
				if (i != 0) cout << " + ";
				cout << teilerArray[i];
			}
			cout << endl;
			t = time(NULL);
		}

		if ((time(NULL) - t) > 60*2) {
			cout << number << endl;
			break;
		}
		++number;

	}
	cout << "Zeitüberschreitung" << endl;

}
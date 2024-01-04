#include <iostream>
using namespace std;

int tarkib(int n, int r) {
	if (n == 1 || r == 0) {
		return 1;
	}
	else {

		return tarkib(n - 1, r) + tarkib(n - 1, r - 1);
	}
}


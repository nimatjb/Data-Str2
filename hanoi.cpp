#include <iostream>
using namespace std;

void hanoi(int n, char X, char Y, char Z) {
	if (n == 1) {
		cout << X << Z;
		return;
	}
	hanoi(n - 1, X, Z, Y); 
	cout << n << X << Z;
	hanoi(n - 1, Y, X, Z);
}

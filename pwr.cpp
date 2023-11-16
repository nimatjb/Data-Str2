#include <iostream>
using namespace std;
int power(int x, int y) {
	if (y == 0) {
		return 1;
	}
	else {
		return x * power(x, y - 1);
	}
}
int main() {
	int a, b;
	int num;
	cout << " enter your number: ";
	cin >> a;
	cout << "enter your pow: ";
	cin >> b;
	num = power(a, b);
	cout << "your answer is: " << num << endl;
	return 0;
}
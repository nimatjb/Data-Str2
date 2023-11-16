#include <iostream>
using namespace std;

void hanoi(int n, char X, char Y, char Z) {
	if (n == 1) {
		cout << "move 1 disk " << X << " to " << Z << endl;
		cout << endl;
		return;
	}
	hanoi(n - 1, X, Z, Y); 
	cout << "move " << n << " disk " << X << " to " << Z << endl;
	cout << endl;
	hanoi(n - 1, Y, X, Z);
}
int main() {
	int num;
	
	int A, B, C;
	cout << "enter number disk:";
	cin >> num;
	cout << endl;
	hanoi (num, 'A','B','C');
	

	return 0;
}
#include <iostream>
using namespace std;
const int rows { 2 }, cols { 5 };

void printArray(int arr[::rows][::cols]) {
	for (int i = 0; i < ::rows; i++) {
		for (int j = 0; j < ::cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int array[::rows][::cols] { };
	int n { 0 };
	cout << "Enter a number: ";
	cin >> n;
	for (int i = 0; i < ::rows; i++) {
		for (int j = 0; j < ::cols; j++) {
			array[i][j] = n;
			n += 1;
		}
	}
	printArray(array);
	return 0;
}

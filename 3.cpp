#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int rows { 4 }, cols { 5 }, min_n { 10 }, max_n { 99 };
enum commands {
	EXIT, RIGHT, LEFT, DOWN, UP
};

void printArray(int arr[::rows][::cols]);
void fillArray(int arr[::rows][::cols]);
void shiftForward(int arr[], int shift, int size = ::cols);
void shiftBackward(int arr[], int shift, int size = ::cols);
void shiftDown(int arr[][::cols], int shift);
void shiftUp(int arr[][::cols], int shift);
void shiftRight(int arr[::rows][::cols], int shift);
void shiftLeft(int arr[::rows][::cols], int shift);

void menu() {
	cout << "Enter your command:" << endl;
	cout << "1. Shift right" << endl;
	cout << "2. Shift left" << endl;
	cout << "3. Shift down" << endl;
	cout << "4. Shift up" << endl;
	cout << "0. Exit" << endl;
}

int getShift() {
	int shift { 0 };
	cout << "Shift by how much?" << endl;
	cin >> shift;
	return shift;
}

int main() {
	int command { 0 };
	int array[::rows][::cols] { };
	fillArray(array);
	cout << endl;
	do {
		printArray(array);
		menu();
		cin >> command;
		switch (command) {
		case RIGHT:
			shiftRight(array, getShift());
			break;
		case LEFT:
			shiftLeft(array, getShift());
			break;
		case DOWN:
			shiftDown(array, getShift());
			break;
		case UP:
			shiftUp(array, getShift());
			break;
		case EXIT:
			return 0;
			break;
		default:
			cout << "Wrong command!" << endl;
		}
		cout << endl;
	} while (command);

	return 0;
}

void printArray(int arr[::rows][::cols]) {
	for (int i = 0; i < ::rows; i++) {
		for (int j = 0; j < ::cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void fillArray(int arr[::rows][::cols]) {
	srand(time(NULL));
	for (int i = 0; i < ::rows; i++) {
		for (int j = 0; j < ::cols; j++) {
			arr[i][j] = ::min_n + rand() % (::max_n - ::min_n + 1);
		}
	}
}

void shiftForward(int arr[], int shift, int size) {
	int t { 0 };
	for (int j = 0; j < shift; j++) {
		t = arr[size - 1];
		for (int i = size - 1; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = t;
	}
}

void shiftBackward(int arr[], int shift, int size) {
	int t { 0 };
	for (int j = 0; j < shift; j++) {
		t = arr[0];
		for (int i = 0; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[size - 1] = t;
	}
}

void shiftDown(int arr[][::cols], int shift) {
	int column[::rows] { };
	for (int i = 0; i < ::cols; i++) {
		for (int j = 0; j < ::rows; j++) {
			column[j] = arr[j][i];
		}
		shiftForward(column, shift, ::rows);
		for (int j = 0; j < ::rows; j++) {
			arr[j][i] = column[j];
		}
	}

}

void shiftUp(int arr[][::cols], int shift) {
	int column[::rows] { };
	for (int i = 0; i < ::cols; i++) {
		for (int j = 0; j < ::rows; j++) {
			column[j] = arr[j][i];
		}
		shiftBackward(column, shift, ::rows);
		for (int j = 0; j < ::rows; j++) {
			arr[j][i] = column[j];
		}
	}

}

void shiftRight(int arr[::rows][::cols], int shift) {
	for (int i = 0; i < ::rows; i++) {
		shiftForward(arr[i], shift);
	}
}

void shiftLeft(int arr[::rows][::cols], int shift) {
	for (int i = 0; i < ::rows; i++) {
		shiftBackward(arr[i], shift);
	}
}

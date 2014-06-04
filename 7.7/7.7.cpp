#include <iostream>
using namespace std;

union bits {
	bits(double n);
	void show_bits();
	double d;
	unsigned char c[sizeof(double)];
};

bits::bits(double n) {
	d = n;
	// здесь должен быть ваш код
}

void bits::show_bits() {
	int double_size = sizeof(double);
	for (int i = double_size - 1; i >= 0; --i) {
		cout << "Binary representation of the byte #" << i << ": ";
		unsigned char t = c[i];
		for (int j = 7; j >= 0; j--)
			cout << (t / (int)(pow(2, j))) % 2;

		// здесь должен быть ваш код
		cout << "\n";
	}
}

int main() {
	bits number(20.092013);

	number.show_bits();
	/* ≈сли данный метод реализован верно, то на экране будет выведено:

	Binary representation of the byte #7: 01000000
	Binary representation of the byte #6: 00110100
	Binary representation of the byte #5: 00010111
	Binary representation of the byte #4: 10001110
	Binary representation of the byte #3: 00101001
	Binary representation of the byte #2: 11111001
	Binary representation of the byte #1: 11001110
	Binary representation of the byte #0: 10001110
	*/

	int i;
	cin >> i;
}
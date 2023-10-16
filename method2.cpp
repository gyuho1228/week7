#include <iostream>
#include<fstream>
using namespace std;

void five(int *aa) {
	int j = 0;
	for (int i = 1000; i <= 5000; i = i + 1000, j++) {
		aa[j] = i * 5;
	}
	return;
}

void self(float *aa) {
	int j = 0;
	for (float i = -0.5; i <= 1.5; i = i + 0.5, j++) {
		aa[j] = i * i;
	}
	return;
}

int main() {
	ofstream xx;
	int a = 1234;
	
	xx.open("data.bin", ios::binary | ios::out);
	if (!xx) return 6;
	xx.write((char*)&a, 4);

	int b[5];
	float c[3];
	
	five(b);
	self(c);

	xx.write((char*)&b, sizeof(b));
	xx.write((char*)&c, sizeof(c));
	

	xx.close();
	return 1;
}

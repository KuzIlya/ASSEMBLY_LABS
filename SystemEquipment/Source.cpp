#include<iostream>

extern "C" short int Bios_11h();

int main() {
	short int a = Bios_11h();
}
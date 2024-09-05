#include <iostream>
using namespace std;

struct answer {
	answer(int* a) {
		a1 = *a;
		a2 = *(a+1);
	}
	int a1;
	int a2;
};

extern "C" bool Is_Prime(int number);
extern "C" int *Goldbah_Problem(int number);

int main() {
	answer ans = Goldbah_Problem(3000);
	cout << "a1 = " << ans.a1 << endl << "a2 = " << ans.a2;

	return 0;
}
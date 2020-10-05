#include <iostream>
#include <cmath>
#include <iomanip>
bool TD(int number) {
 double sqrt_ = sqrt(number);
	for (int i = 2; i < sqrt_; i++) {
		int result = number / i;
		std::cout << result<<"=" << number<<"%" << i;
		if ((result % 2) != 0) continue;
		else
		{
			std::cout << ": TRUE\n";
			return true;
		}
	}
}



//using namespace std;

int main() {
	TD(127);

	system("PAUSE");
	return 0;
}
#include "BoundCheck2DIntArray.h"

using namespace std;

int main() {

	BoundCheck2DIntArray arr2d(3, 4);

	/*
		Note: I changed
			
			arr2d[n][m] = n + m;

		to

			arr2d[n][m] = 10*n + m;

		to check n and m clearly.
	*/ 

	for (int n = 0; n < 3; n++)
		for (int m = 0; m < 4; m++)
			arr2d[n][m] = 10*n + m;

	for (int n = 0; n < 3; n++) {
		for (int m = 0; m < 4; m++)
			cout << arr2d[n][m] << ' ';
		cout << endl;
	}

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; 
	int m;
	cout << "Enter the size of Matrix (N - stroka, M - stolb): ";
	cin >> n;
	cin >> m;
	if (n <= 0 || m <= 0) {
		cout << "Wrong size, try new number";
		return 1;
	}

	vector<vector<int>> matrix(n, vector<int>(m));
	cout << "Enter the elements of matrix (1 or 0): \n";

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
			if (matrix[i][j] != 0 && matrix[i][j] != 1) {
				cout << "Wrong elements; \nTry write correct elements next time";
				return 1;
			}
		}
	}

	int Reflex = 1, Symm = 1, AntiSymm = 1, Transit = 1;

	if (n != m) {
		Reflex = 0;
	}

	for (int i = 0; i < n; ++i) {
		if (n == m && matrix[i][i] != 1) {
			Reflex = 0;
		}
		for (int j = 0; j < m; ++j) {
			if ( matrix[i][j] != matrix[j][i])
				Symm = 0;
			if (i != j && matrix[i][j] == 1 && matrix[i][i] == 1)
				AntiSymm = 0;
			for (int z = 0; z < m; ++z) {
				if (matrix[i][j] == 1 && matrix[j][z] == 1 && matrix[i][z] != 1) {
					Transit = 0;
				}
			}
		}
	}

	cout << "Features Ratio";

	cout << "\nReflex: ";
	if (Reflex == 1) {
		cout << "Yes";
	}
	else
		cout << "No";
	cout << "\nSymm: ";
	if (Symm == 1) {
		cout << "Yes";
	}
	else
		cout << "No";
	cout << "\nAntiSymm: ";
	if (AntiSymm == 1) {
		cout << "Yes";
	}
	else
		cout << "No";
	cout << "\nTransit: ";
	if (Transit == 1) {
		cout << "Yes";
	}
	else
		cout << "No";
}

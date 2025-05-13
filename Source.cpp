#include <iostream>
#include <vector>

using namespace std;

int Lab5() {
    int n;
    cout << "Enter the size of matrix: ";
    cin >> n;

    if (n <= 0) {
        cout << "Wrong number";
        return 1;
    }

    vector<vector<int>> Matrix(n, vector<int>(n));

    cout << "Enter the elements of matrix:";
    for (int i = 0; i < n; ++i) {
        cout << "string " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> Matrix[i][j];

            if (Matrix[i][j] != 0 && Matrix[i][j] != 1) {
                cout << "Wrong elements; \nTry write correct elements next time";
                return 1;
            }
        }
    }

    cout << "\nEnered matrix";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    vector<vector<int>>New_Matrix = Matrix;

    for (int k = 0; k < n; ++k) {
        cout << "\nPromejut point K = " << k + 1 << ":";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (New_Matrix[i][k] == 1 && New_Matrix[k][j] == 1) {
                    New_Matrix[i][j] = 1;
                }
            }
        }

        cout << "Matrix after K step = " << k + 1 << ":";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << New_Matrix[i][j] << " \n";
            }
        }
    }

    cout << "\nResult:";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << New_Matrix[i][j] << " ";

        }
    }
}
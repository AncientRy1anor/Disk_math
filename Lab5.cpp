#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;


    vector<vector<int>> matrix(n, vector<int>(n));


    cout << "Enter the matrix (1 or 0):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] != 0 && matrix[i][j] != 1) {
                cout << "Wrong number. \nTry use current number." << endl;
                return 1;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] == 1 && matrix[k][j] == 1) {
                    matrix[i][j] = 1;
                }
            }
        }
    }

    cout << "Matrix dostyajimosti:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
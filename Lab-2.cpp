#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;

    cout << "Enter the number of elements A: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter the elements of A:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Enter the number of elements B: ";
    cin >> m;
    vector<int> B(m);

    cout << "Enter the elements of B:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    cout << "Enter the number of pair: ";
    cin >> k;
    vector<pair<int, int>> Otnosh(k);

    cout << "Enter the pair (A to B):" << endl;
    for (int i = 0; i < k; i++) {
        cin >> Otnosh[i].first >> Otnosh[i].second;
    }


    cout << "\nOtnoshenie R: { ";
    for (int i = 0; i < k; i++) {
        cout << "(" << Otnosh[i].first << ", " << Otnosh[i].second << ")";
        if (i != k - 1) cout << ", ";
    }
    cout << " }" << endl;

    int function = 1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < k; j++) {
            if (Otnosh[j].first == A[i]) {
                count++;
            }
        }
        if (count > 1) {
            function = 0;
            break;
        }
    }

    if (function = 1) {
        cout << "Otnoshenie is function.";
    }
    else {
        cout << "Otnoshenie isn't function.";
    }

    return 0;
}
#include <iostream>
using namespace std;

bool Valid(char ch, char type) {
    if (type == 'c' && ch >= '0' && ch <= '9') return true;
    if (type == 'i' && ch >= '0' && ch <= '9' && (ch - '0') % 2 == 0) return true;
    if (type == 'j' && ch >= '0' && ch <= '9' && (ch - '0') % 2 != 0) return true;
    return false;
}

bool Array(char ch, char array[], int size) {
    for (int i = 0; i < size; i++)
        if (array[i] == ch) return true;
    return false;
}

int main() {
    char A[4], B[4];

    char typeA[4] = { 'i', 'j', 'c', 'c' };
    char typeB[4] = { 'i', 'j', 'c', 'c' };

    cout << "Enter 4 elements in array A: ";
    for (int i = 0; i < 4; i++) cin >> A[i];

    cout << "Enter 4 elements in array B: ";
    for (int i = 0; i < 4; i++) cin >> B[i];

    char newA[4];
    int nA = 0;
    for (int i = 0; i < 4; i++) {
        if (Valid(A[i], typeA[i]) && !Array(A[i], newA, nA)) {
            newA[nA++] = A[i];
        }
    }

    char newB[4];
    int nB = 0;
    for (int i = 0; i < 4; i++) {
        if (Valid(B[i], typeB[i]) && !Array(B[i], newB, nB)) {
            newB[nB++] = B[i];
        }
    }

    cout << "Union: ";
    for (int i = 0; i < nA; i++) cout << newA[i];
    for (int i = 0; i < nB; i++)
        if (!Array(newB[i], newA, nA)) cout << newB[i];
    cout << endl;

    cout << "Peresechenie: ";
    for (int i = 0; i < nA; i++)
        if (Array(newA[i], newB, nB)) cout << newA[i];
    cout << endl;

    cout << "A \ B: ";
    for (int i = 0; i < nA; i++)
        if (!Array(newA[i], newB, nB)) cout << newA[i];
    cout << endl;

    cout << "B \ A: ";
    for (int i = 0; i < nB; i++)
        if (!Array(newB[i], newA, nA)) cout << newB[i];
    cout << endl;


    cout << "Symm Diff: ";
    for (int i = 0; i < nA; i++)
        if (!Array(newA[i], newB, nB)) cout << newA[i];
    for (int i = 0; i < nB; i++)
        if (!Array(newB[i], newA, nA)) cout << newB[i];
    cout << endl;

    return 0;
}
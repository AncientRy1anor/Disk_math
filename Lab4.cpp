#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, start, end;
    cout << "Enter the size of matrix: ";
    cin >> n;


    if (n <= 0) {
        cout << "Wrong size. Try set other number.";
        return 0;
    }

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];

            if (matrix[i][j] < 0) {
                cout << "Elements should be positive";
                return 0;
            }
        }
    }

    cout << "Enter the point of start and end: ";
    cin >> start >> end;

    if (start < 0 || start >= n || end < 0 || end >= n) {
        cout << "Wrong chosen point";
        return 0;
    }


    vector<int> dist(n, -1); 
    vector<int> used(n, 0);   
    vector<int> prev(n, -1);  

    dist[start] = 0;


    for (int i = 0; i < n; i++) {
        int v = -1;

        for (int j = 0; j < n; j++) {
            if (!used[j] && dist[j] != -1 && (v == -1 || dist[j] < dist[v]))
                v = j;
        }

        if (v == -1) 
            break;

        used[v] = 1;

        for (int u = 0; u < n; u++) {
            if (matrix[v][u] > 0) {
                int nDist = dist[v] + matrix[v][u];
                if (dist[u] == -1 || nDist < dist[u]) {
                    dist[u] = nDist;
                    prev[u] = v;
                }
            }
        }
    }

    if (dist[end] == -1) {
        cout << "Way can't be found.";
        return 0;
    }

    vector<int> way;
    for (int v = end; v != -1; v = prev[v]) {
        way.push_back(v);
    }

    cout << "Way: ";
    for (int i = way.size() - 1; i >= 0; i--) {
        cout << way[i];
        if (i > 0)
            cout << " > ";
    }

    cout << "\nCost: " << dist[end];

    return 0;
}
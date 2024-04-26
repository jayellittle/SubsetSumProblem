//
//  main.cpp
//  SubsetSumProblem
//
//  Created by Woo Sung Jahng on 2024/04/24.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int k, n, p, b;
    vector<int> a;
    
    // Input n, a(n+1), b
    n = 5;
    a = {2, 3, 5, 7, 11, 12};
    b = a[5];

    vector<vector<int>> y(n, vector<int>(b+1));
    
    // Input : n+1 of positive integers {a[0], a[1], ..., a[n-1], b}
    // Output : If subset sum of {a[0], a[1], ..., a[n-1]} equals b, "Yes", else, "No"
    for (k=0; k<=n-1; k++) {
        for (p=0; p<=b; p++) {
            y[k][p] = 0;
        }
    }

    y[0][0] = 1;

    if (a[0] <= b) y[0][a[0]] = 1;

    for (k=1; k<=n-1; k++) {
        for (p=0; p<=b; p++) {
            if (y[k-1][p] == 1) y[k][p] = 1;
            else if ((p-a[k] >= 0) && (y[k-1][p-a[k]] == 1)) y[k][p] = 1;
        }
    }

    if (y[n-1][b] == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}

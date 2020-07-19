#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Sample Input
2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3

Sample Output
5
9
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n,q;
    cin >> n >> q;
    
    // Create an array of pointers to integer arrays 
    // (i.e., an array of variable-length arrays)
    // int** outer = new int*[n];

    vector<int> a[n];
    
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        int o;
        for(int j = 0; j < m; j++){
            cin >> o;
            a[i].push_back(o);
        }
    }

    int r, s;
    for(int k = 1; k <= q; k++){
        cin >> r >> s;
        cout << a[r][s] << endl;
    }
    return 0;
}

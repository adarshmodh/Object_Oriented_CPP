#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/*
Sample Input
5
1 6 10 8 4

Sample Output
1 4 6 8 10

*/

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num;
    cin >> num;
    vector<int> v;

    for(int i=0; i<num; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(),v.end());

    for(int i=0; i<num; i++){
        cout << v[i] << " ";
    }

    return 0;
}

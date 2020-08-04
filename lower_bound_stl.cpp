#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Sample Input
 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15

INPUT FORMAT:
The first line of the input contains the number of integers . The next line contains  integers in sorted order. The next line contains , the number of queries. Then  lines follow each containing a single integer .
Note that if the same number is present multiple times, you have to print the first index at which it occurs. Also, the input is such that you always have an answer for each query.

Sample Output
 Yes 1
 No 5
 Yes 6
 Yes 8

OUTPUT FORMAT:
For each query you have to print "Yes" (without the quotes) if the number is present and at which index(1-based) it is present separated by a space.
If the number is not present you have to print "No" (without the quotes) followed by the index of the next smallest number just greater than that number.

*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size;
    cin >> size;

    vector<int> v;

    for(int i=0; i<size; i++){
        int temp;
        cin >>temp;
        v.push_back(temp);
    }

    int queries;
    cin >> queries;

    for(int i=0; i<queries; i++){
        int q;
        cin >> q;
        vector<int>::iterator low = lower_bound(v.begin(), v.end(), q);
        if (v[low - v.begin()] == q)
           cout << "Yes " << (low - v.begin()+1) << endl;
        else
           cout << "No " << (low - v.begin()+1) << endl;
    }

    return 0;
}

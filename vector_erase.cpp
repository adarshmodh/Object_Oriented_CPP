#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Sample Input
6
1 4 6 2 8 9
2
2 4

Sample Output
3
1 8 9
Explanation

The first query is to erase the 2nd element in the vector, which is 4. 
Then, modifed vector is {1 6 2 8 9}, we want to remove the range of 2~4, which means the 2nd and 3rd elements should be removed. 
Then 6 and 2 in the modified vector are removed and we finally get {1 8 9}

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

    int del_pos1;
    cin >> del_pos1;
    v.erase(v.begin()+del_pos1-1);


    int del_pos2_0,del_pos2_1;
    cin >> del_pos2_0 >> del_pos2_1;
    v.erase(v.begin()+del_pos2_0-1,v.begin()+del_pos2_1-1);    

    cout << v.size() << endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i] <<" ";
    }

    return 0;
}

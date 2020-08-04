#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

/*
1  : Add an element  to the set.
2  : Delete an element  from the set. (If the number  is not present in the set, then do nothing).
3  : If the number  is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).

Sample Input
8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6

Sample Output
Yes
No
No
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int size;
    cin >> size;

    set<int> s;
    
    for(int i=0; i<size; i++){
        int op,q;
        cin >> op;
        cin >> q;
        
        if(op==1){
            s.insert(q);
        }
        else if (op ==2){
            s.erase(q);
        }
        else{
            set<int>::iterator itr = s.find(q);
            if(itr == s.end())
                cout << "No" <<endl;
            else
                cout << "Yes" << endl;    
        }
    }
    return 0;
}
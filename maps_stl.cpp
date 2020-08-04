#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

/*

1 : Add the marks  to the student whose name is name.

2 : Erase the marks of the students whose name is name.

3 : Print the marks of the students whose name is name. (If student didn't get any marks print 0.)

Sample Input
7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess

Sample Output
30
20
0

*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int size;
    cin >> size;
    map<string,int> m;

    for(int i=0; i<size; i++){
        int op,marks;
        string name;
        cin >> op;
        cin >> name;
        
        if(op==1){
            cin >> marks;
            if(m.find(name) == m.end())
                m.insert(make_pair(name, marks));
            else
                m[name] += marks;            
        }
        else if (op ==2)
            m.erase(name);
        else{
            // map<string,int>::iterator itr=m.find(name); 
            if (m.find(name) != m.end())
                cout << m[name] << endl;
            else
                cout << 0 << endl;

        }
    }
    return 0;
}
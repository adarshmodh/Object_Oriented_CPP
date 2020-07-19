#include <iostream>
#include <vector>
#include <unordered_set> 
#include <set> 

using namespace std;

int main()
{
    printf("Hello, World!\n");
    int a= 0, b=1;
    cout <<a <<b<<endl;
    
    vector<int> tmp{a,b,0};
    cout << tmp[0] << tmp[1] << tmp[2] << endl;

    unordered_set<int> seen;
    seen.insert(a);
    seen.insert(b);

    if (seen.find(2)!=seen.end())
    	cout << "present!"<< endl;
    else
    	cout << "absent!"<< endl;

    set<vector<int>> seen2;

    vector<int> s1{0,4};
    vector<int> s2{0,1};
    vector<int> s3{0,2};
    
    seen2.insert(s2); 
    seen2.insert(s3);
 	
    
    if (seen2.find(s1)!=seen.end())
		cout << "present!"<< endl;
	else
		cout << "absent!"<< endl;	    	


    return 0;
}



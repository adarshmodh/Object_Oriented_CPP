//Operator Overloading

#include<iostream>

using namespace std;

/*
Sample Input
3+i4
5+i6

Sample Output
8+i10
*/

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

ostream& operator<<(ostream& os, const Complex& cx)  
{  
    os <<cx.a << "+i" << cx.b;  
    return os;  
}  

Complex operator+(const Complex& cx1, const Complex& cx2)  
{  
    Complex output;
    output.a = cx1.a+cx2.a;
    output.b = cx1.b+cx2.b;
    return output;
}

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
w
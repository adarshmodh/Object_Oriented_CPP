#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*
Kristen is a contender for valedictorian of her high school. She wants to know how many students (if any) have scored higher than her in the  exams given during this semester.

Create a class named Student with the following specifications:

An instance variable named  to hold a student's  exam scores.
A void input() function that reads  integers and saves them to .
An int calculateTotalScore() function that returns the sum of the student's scores.

Sample Input
The first line contains , the number of students in Kristen's class. The  subsequent lines contain each student's  exam grades for this semester.
3
30 40 45 10 10
40 40 40 10 10
50 20 30 10 10

Sample Output
1

*/

// Write your Student class here
class Student{
    public:
        void input(){
            // cout << "Please enter scores" << endl;
            int tmp; 
            for(int i = 0; i<5; i++){
                cin >> tmp;
                scores.push_back(tmp);    
            } 
        };
        
        int calculateTotalScore(){
            int total_score=0;   
            for(int i : scores){
                total_score += i;
            } 
            // cout << total_score<< endl;
            return total_score;
        };   

    private:
        vector<int> scores;

};



int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}

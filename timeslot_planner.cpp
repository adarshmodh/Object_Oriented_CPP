/*

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> meetingPlanner( const vector<vector<int>>& slotsA, const vector<vector<int>>& slotsB, int dur) 
{ 
  // your code goes here
  int a_index = 0, b_index = 0;
  while(a_index<slotsA.size() && b_index<slotsB.size()){
    vector<int> output(2);
    int start_slot = max(slotsA[a_index][0], slotsB[b_index][0]);
    int end_slot = min(slotsA[a_index][1], slotsB[b_index][1]);
    //cout << start_slot << ", " << end_slot << endl;
    if ((end_slot-start_slot)>=dur) {
      output[0] = start_slot;
      output[1] = start_slot+dur;
      return output;
    }
    
    if (slotsA[a_index][1]<=slotsB[b_index][1])
      a_index = a_index + 1;
    else
      b_index = b_index + 1;
    
  }
  vector<int> output;
  return output;
}

int main() {
  vector<vector<int>> slotsA{{10, 50}, {60, 120}, {140, 210}};
  vector<vector<int>> slotsB{{0, 15}, {60, 70}};
  int dur = 8;
  vector<int> output = meetingPlanner(slotsA,slotsB,dur);
  
  cout << output[0] <<", " << output[1] << endl;
  
}
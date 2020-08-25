#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
arr = [4, 6, 10, 15, 16],  lim = 21

for i in 0 to arr.size():
      
    diff = lim - arr[i]

*/

vector<int> getIndicesOfItemWeights( const vector<int>& arr, int limit)
{
  // your code goes here
  int size = arr.size();
  map<int, int> dict;
  
  vector<int> output;
  
  if(size<=1)
    return output;
  
  for(int i=0; i<size; i++){
    if (dict.find(arr[i])!=dict.end()){
      output.push_back(i);  
      output.push_back(dict[arr[i]]);
      return output;
    }
    else{
      if(dict.find(limit-arr[i]) == dict.end()) 
        dict.insert({limit-arr[i],i});
        
    }
  }
  return output;
}

int main() {
  vector<int> arr {4, 6, 10, 15, 16};
  int lim = 21;
  
  vector<int> output = getIndicesOfItemWeights(arr, lim);
  cout << output[0] <<", " <<  output[1] << endl;
  
  return 0;
}
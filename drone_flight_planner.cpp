#include <iostream>
#include <vector>

using namespace std;

int calcDroneMinEnergy( const vector<vector<int>>& route ) 
{
  /*
    We basically need a variable that calculates energy needed at every step in a cumulative sense from the start
    and then a varible that stores the maximum negative that energy can go because that is the maximum we need to be on the systems
      
  largestEnergyDeficit = 0
  energyBalance = 0
  
  for i in range(1, len(route)):
    energyBalance = energyBalance + (route[i-1][2] - route[i][2])
    largestEnergyDeficit = min(largestEnergyDeficit,energyBalance)

  return -1*(largestEnergyDeficit)
  
  */
  // 
  
  int largestEnergyDeficit = 0;
  int energy_balance = 0;

  
  for (int i=1; i<route.size(); i++){
    energy_balance = energy_balance + (route[i-1][2] - route[i][2]);
    largestEnergyDeficit = min(largestEnergyDeficit,energy_balance);
  }
    
  return -1*largestEnergyDeficit;
}

int main() {
  
  vector<vector<int>> route{ { 0, 2, 10 }, 
                             { 3, 5, 0  }, 
                             { 9, 20, 6 },
                             {10, 12, 15},
                             {10, 10,  8} };
  

  int out = calcDroneMinEnergy(route);
  cout << out << endl;
  
  return 0;
}

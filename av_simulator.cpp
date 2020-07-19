///create a simulator which has three agents : car, pedestrian and truck. The simulator should step entirely in one go and should change the states of all the agents at once. The car,: drives, pedestrian: walks, truck: drives. Implement in atleast two classes with inheritence.Take care of constructors and destructors.  The simulator should have the following essential characteristics : 1. You can query the current state of any agent, 2. You can update the current state of agent, increment or decrement state by the defined action, 3. You can step the entire simulator: increment or decrement state by the defined actions. 4. You can reset the entire simulator to initial positions defined by you. 
/// walk : increment by 1 unit 
// drive_car : increment by 2 units 
// drive_truck : increment by 3 units. 
// truck: unloads 
// car : parks 
// pedestrians : run



/*

parent class agent
  public: int state 
  private: int step_size 
  
  def query_current_state
  
  def forward_step 
  
  def backward_step 
  def reset_state


child class simulator  

  agent truck; 
  
  
  
  def query_state
  def forward_step 
  def backward_step 
  def reset_state


///***************
parent class agent: 
  var state
  def query_state
      return state
  def reset
  
child truck: agent()
  def forward_step
  def backward_step

child car: agent()
  def forward_step
  def backward_step


class simulator 
  def reset 
  def step_forward
  def step_backward


*/
   
#include <iostream>


int main()
{
    std::cout << "Practice makes Perfect!" << std::endl;
    return 0;
    
}


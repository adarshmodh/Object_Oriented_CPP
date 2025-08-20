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
#include <memory>
#include <string>
#include <vector>

// -------- Base Class -----------
class Agent {
protected:
    int state;
    int init_state;
    int step_size;
    std::string name;

public:
    Agent(const std::string& n, int init, int step)
        : state(init), init_state(init), step_size(step), name(n) {
        std::cout << name << " created at position " << state << "\n";
    }

    virtual ~Agent() {
        std::cout << name << " destroyed\n";
    }

    // Query current state
    int queryState() const { return state; }

    // Move forward
    virtual void forwardStep() { state += step_size; }

    // Move backward
    virtual void backwardStep() { state -= step_size; }

    // Reset to initial state
    virtual void resetState() { state = init_state; }

    std::string getName() const { return name; }

    // Unique extra action
    virtual void extraAction() = 0;
};

// -------- Derived Classes --------
class Car : public Agent {
public:
    Car(int init) : Agent("Car", init, 2) {}

    void extraAction() override {
        std::cout << "Car parks at position " << state << "\n";
    }
};

class Pedestrian : public Agent {
public:
    Pedestrian(int init) : Agent("Pedestrian", init, 1) {}

    void extraAction() override {
        std::cout << "Pedestrian runs from position " << state
                  << " to position " << (state + 2) << "\n";
    }
};

class Truck : public Agent {
public:
    Truck(int init) : Agent("Truck", init, 3) {}

    void extraAction() override {
        std::cout << "Truck unloads at position " << state << "\n";
    }
};

// -------- Simulator ------------
class Simulator {
private:
    std::vector<std::unique_ptr<Agent>> agents;

public:
    Simulator() {
        // Add all agents
        agents.push_back(std::make_unique<Car>(0));
        agents.push_back(std::make_unique<Pedestrian>(0));
        agents.push_back(std::make_unique<Truck>(0));
    }

    ~Simulator() { std::cout << "Simulator destroyed\n"; }

    // Query all agent states
    void queryStates() const {
        for (const auto& agent : agents) {
            std::cout << agent->getName() << " is at position "
                      << agent->queryState() << "\n";
        }
    }

    // Step all agents forward
    void stepForward() {
        for (auto& agent : agents) agent->forwardStep();
    }

    // Step all agents backward
    void stepBackward() {
        for (auto& agent : agents) agent->backwardStep();
    }

    // Reset all agents
    void reset() {
        for (auto& agent : agents) agent->resetState();
    }

    // Perform extra actions
    void doExtras() {
        for (auto& agent : agents) agent->extraAction();
    }
};

// -------- Main Test ------------
int main() {
    Simulator sim;

    std::cout << "\nInitial states:\n";
    sim.queryStates();

    std::cout << "\nStep forward:\n";
    sim.stepForward();
    sim.queryStates();

    std::cout << "\nStep backward:\n";
    sim.stepBackward();
    sim.queryStates();

    std::cout << "\nExtra actions:\n";
    sim.doExtras();

    std::cout << "\nResetting:\n";
    sim.reset();
    sim.queryStates();

    return 0;
}


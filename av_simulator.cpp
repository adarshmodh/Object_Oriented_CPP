///create a simulator which has three agents : car, pedestrian and truck. The simulator should step entirely in one go and should change the states of all the agents at once. The car,: drives, pedestrian: walks, truck: drives. Implement in atleast two classes with inheritence.Take care of constructors and destructors.  The simulator should have the following essential characteristics : 1. You can query the current state of any agent, 2. You can update the current state of agent, increment or decrement state by the defined action, 3. You can step the entire simulator: increment or decrement state by the defined actions. 4. You can reset the entire simulator to initial positions defined by you. 
/// walk : increment by 1 unit 
// drive_car : increment by 2 units 
// drive_truck : increment by 3 units. 
// truck: unloads 
// car : parks 
// pedestrians : run

*/

#include <iostream>
using namespace std;

// ---- Base class ----
class Agent {
protected:
    int state, init_state, step_size;
public:
    Agent(int init, int step) : state(init), init_state(init), step_size(step) {}
    virtual ~Agent() {}

    int queryState() const { return state; }
    virtual void forwardStep() { state += step_size; }
    virtual void backwardStep() { state -= step_size; }
    virtual void resetState() { state = init_state; }

    virtual void extraAction() = 0; // pure virtual
};

// ---- Derived classes ----
class Car : public Agent {
public:
    Car(int init=0) : Agent(init, 2) {}
    void extraAction() override { cout << "Car parks\n"; }
};

class Pedestrian : public Agent {
public:
    Pedestrian(int init=0) : Agent(init, 1) {}
    void extraAction() override { cout << "Pedestrian runs\n"; }
};

class Truck : public Agent {
public:
    Truck(int init=0) : Agent(init, 3) {}
    void extraAction() override { cout << "Truck unloads\n"; }
};

// ---- Simulator ----
class Simulator {
    Car car;
    Pedestrian ped;
    Truck truck;
public:
    Simulator() : car(0), ped(0), truck(0) {}

    void query() {
        cout << "Car: " << car.queryState()
             << " Pedestrian: " << ped.queryState()
             << " Truck: " << truck.queryState() << "\n";
    }

    void stepForward() { car.forwardStep(); ped.forwardStep(); truck.forwardStep(); }
    void stepBackward(){ car.backwardStep(); ped.backwardStep(); truck.backwardStep(); }
    void reset()       { car.resetState(); ped.resetState(); truck.resetState(); }
    void extras()      { car.extraAction(); ped.extraAction(); truck.extraAction(); }
};

// ---- Main ----
int main() {
    Simulator sim;
    sim.query();

    sim.stepForward();
    sim.query();

    sim.stepBackward();
    sim.query();

    sim.extras();

    sim.reset();
    sim.query();
}

________________________________________________________________________________________________________________________________________________  
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


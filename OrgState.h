#ifndef ORGSTATE_H
#define ORGSTATE_H

#include "emp/Evolve/World_structure.hpp"
#include <cstddef>

class OrgWorld;

struct OrgState {
  OrgWorld *world;

  //Array for tracking the four most recent input values
  float last_inputs[4];
  //Index of the most recent input value in array
  size_t last_input_idx;
  //How many points this organism has currently
  double points;

  //Needs to know current location for possible reproduction
  emp::WorldPosition current_location;

  //Tracking if an organism has performed a task or not
  bool taskPerformed = false;

  //Tracking the color of an organism based on tasks; 1
  // Task 1 --> 1 = blue, Task 2 --> 2 = red, Task 3 --> 3 = yellow; Task 4 --> 4 = green; Task 5 --> 5 = purple
  int colorInt = 0;

  /**
  * Adds an input number to the tracker
  */
  void add_input(float input) {
    last_inputs[last_input_idx] = input;
    last_input_idx = (last_input_idx + 1) % 4;
  }
};

#endif
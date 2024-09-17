#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include "emp/Evolve/World.hpp"

#include "Org.h"
#include "Task.h"

class OrgWorld : public emp::World<Organism>
{
  emp::Random &random;
  std::vector<emp::WorldPosition> reproduce_queue;
  std::vector<Task *> tasks{new NewTask(), new NewTask2(), new NewTask3(), new NewTask4(), new NewTask5()};

public:
  OrgWorld(emp::Random &_random) : emp::World<Organism>(_random), random(_random) {}

  ~OrgWorld() {}

  const pop_t &GetPopulation() { return pop; }

  void Update(double percentProbability)
  {
    emp::World<Organism>::Update();

    // Process each organism
    emp::vector<size_t> schedule = emp::GetPermutation(random, GetSize());
    for (int i : schedule)
    {
      if (!IsOccupied(i))
      {
        continue;
      }
      pop[i]->Process(i);
    }

    // Time to allow reproduction for any organisms that ran the reproduce instruction
    for (emp::WorldPosition location : reproduce_queue)
    {
      if (!IsOccupied(location))
      {
        return;
      }
      std::optional<Organism> offspring =
          pop[location.GetIndex()]->CheckReproduction(percentProbability);
      if (offspring.has_value())
      {
        DoBirth(offspring.value(), location.GetIndex());
      }
    }
    reproduce_queue.clear();
  }

  void CheckOutput(float output, OrgState &state)
  {
    for (Task *task : tasks)
    {
      state.points += task->CheckOutput(output, state.last_inputs);
      if (state.points == 0.5)
      { // changing the state's boolean variable to true if the organism does actually get points for solving the task
        state.taskPerformed = true;
        state.colorInt = 1;
      }
      else if (state.points == 1)
      { // changing the state's boolean variable to true if the organism does actually get points for solving the task
        state.taskPerformed = true;
        state.colorInt = 2;
      }
      else if (state.points == 2)
      { // changing the state's boolean variable to true if the organism does actually get points for solving the task
        state.taskPerformed = true;
        state.colorInt = 3;
      }
      else if (state.points == 3)
      { // changing the state's boolean variable to true if the organism does actually get points for solving the task
        state.taskPerformed = true;
        state.colorInt = 4;
      }
      else if (state.points == 5)
      { // changing the state's boolean variable to true if the organism does actually get points for solving the task
        state.taskPerformed = true;
        state.colorInt = 5;
      }
      else {
        state.taskPerformed = false;
      }
      }
  }

  void ReproduceOrg(emp::WorldPosition location)
  {
    // Wait until after all organisms have been processed to perform
    // reproduction. If reproduction happened immediately then the child could
    // ovewrite the parent, and then we would be running the code of a deleted
    // organism
    reproduce_queue.push_back(location);
  }
};

#endif
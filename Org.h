#ifndef ORG_H
#define ORG_H

#include "CPU.h"
#include "OrgState.h"
#include "emp/Evolve/World_structure.hpp"

class Organism {
  CPU cpu;

public:
  Organism(OrgWorld *world, double points = 0.0) : cpu(world) {
    SetPoints(points);
  }

  void SetPoints(double _in) { cpu.state.points = _in; }
  void AddPoints(double _in) { cpu.state.points += _in; }
  double GetPoints() {return cpu.state.points;}

  void Reset() {
    cpu.Reset();
  }

  void Mutate(double percentProbability) {
    cpu.Mutate(percentProbability);
  }

  std::optional<Organism> CheckReproduction(double percentProbability) {
    if (GetPoints() > 20) {
      Organism offspring = *this;
      offspring.Reset();
      offspring.Mutate(percentProbability);
      AddPoints(-20);
      return offspring;
    }
    return {};
  }

  void Process(emp::WorldPosition current_location) {
    cpu.state.current_location = current_location;
    cpu.RunCPUStep(10);//Run the CPU!

  }

  void PrintGenome() {
    std::cout << "program ------------" << std::endl;
    cpu.PrintGenome();
    std::cout << "end ---------------" << std::endl;
  }

  int GetSpecies () {
      return cpu.state.colorInt; // return the species of the colorInt of the organism
  }  
};

#endif
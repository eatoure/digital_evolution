#ifndef TASK_H
#define TASK_H


#include <iostream>
#include <cmath>
#include <string>

class Task {
public:
  virtual double CheckOutput(float output, float inputs[4]) = 0;
  //virtual std::string name() const = 0;
};
/*
  Task based upon asking organisms to find the correct square
*/
class NewTask : public Task {
  public:
    double CheckOutput(float output, float inputs[4]) override {
      for (int i = 0; i < 4; i++) {
      //For each input value in the array
      //Calculate the square of it
      float square = inputs[i] * inputs[i];

      //Since these are floats, allowing for some floating point error
      if (fabs(output - square) < 0.001) {
      //They squared an input, yey!
      std::cout << "Squared!" << std::endl;
      //Give them 5 points for solving this task
      return 0.5;
    }
  }
      return 0;
    }
    

 };
/*
  Task based upon asking organisms to find the correct cube
*/
 class NewTask2 : public Task {
  public:
    double CheckOutput(float output, float inputs[4]) override {
      for (int i = 0; i < 4; i++) {
      //For each input value in the array
      //Calculate the square of it
      float cubed = inputs[i] * inputs[i]  * inputs[i];

      //Since these are floats, allowing for some floating point error
      if (fabs(output - cubed) < 0.001) {
      //They squared an input, yey!
      std::cout << "Cubed!" << std::endl;
      //Give them 5 points for solving this task
      return 1;
    }
  }
      return 0;
    }
    

 };

/*
  Task based upon asking organisms to find the correct square root
*/
 class NewTask3 : public Task {
  public:
    double CheckOutput(float output, float inputs[4]) override {
      for (int i = 0; i < 4; i++) {
      //For each input value in the array
      //Calculate the square of it
      float sqrt = sqrtf(inputs[i]);

      //Since these are floats, allowing for some floating point error
      if (fabs(output - sqrt) < 0.001) {
      //They squared an input, yey!
      std::cout << "Cubed!" << std::endl;
      //Give them 5 points for solving this task
      return 2;
    }
  }
      return 0;
    }
    

 };

/*
  Task based upon asking organisms to find the correct cubic root
*/
 class NewTask4 : public Task {
  public:
    double CheckOutput(float output, float inputs[4]) override {
      for (int i = 0; i < 4; i++) {
      //For each input value in the array
      //Calculate the square of it
      float cbrt = cbrtf(inputs[i]);

      //Since these are floats, allowing for some floating point error
      if (fabs(output - cbrt) < 0.001) {
      //They squared an input, yey!
      std::cout << "Cubed!" << std::endl;
      //Give them 5 points for solving this task
      return 3;
    }
  }
      return 0;
    }
    

 };

/*
  Task based upon asking organisms to find the correct cosine
*/
 class NewTask5 : public Task {
  public:
    double CheckOutput(float output, float inputs[4]) override {
      for (int i = 0; i < 4; i++) {
      //For each input value in the array
      //Calculate the square of it
      float cos = cosf(inputs[i]);

      //Since these are floats, allowing for some floating point error
      if (fabs(output - cos) < 0.001) {
      //They squared an input, yey!
      std::cout << "Cubed!" << std::endl;
      //Give them 5 points for solving this task
      return 5;
    }
  }
      return 0;
    }
    

 };
#endif
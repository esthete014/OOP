#include <iostream>
#include <string>
#include "CProblem.h"

int main() {
  std::string massage;
  int* mass;
  int size;

  //size = 10 + rand() % 11;
  mass = new int[100];
  mass[1] = 0;
  /*for (int i = 0; i < size; i++) {
    mass[i] = rand() % 101;
    std::cout << mass[i] << " ";
  }
  std::cout << std::endl;*/

  CProblem problem;
  problem.readFromFile(mass);
  problem.sort(problem.chooseProblem());
  problem.print();

  std::cout << std::endl;
  system("pause");
}
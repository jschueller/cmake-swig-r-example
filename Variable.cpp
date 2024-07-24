#include "Variable.h"
#include <iostream>

namespace gum
{

double randomProba()
{
  return 0.4;
}

DiscreteVariable::DiscreteVariable(const std::string name, const std::string description)
 : name_(name), desc_(description)
{
  std::cout << "DiscreteVariable::DiscreteVariable name="<<name<<std::endl;
}

}

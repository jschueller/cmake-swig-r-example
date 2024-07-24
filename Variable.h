#include <string>

namespace gum
{

double randomProba();

class DiscreteVariable
{
public:
  DiscreteVariable(const std::string name, const std::string description = "");
private:
  std::string name_;
  std::string desc_;
};

}

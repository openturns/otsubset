#include <iostream>
// OT includes
#include "OT.hxx"
#include "SubsetSampling.hxx"

using namespace OT;
using namespace OTSubset;

int main(int argc, char **argv)
{
  Distribution myDistribution = Normal();
  RandomVector vect(myDistribution);
  
  NumericalMathFunction limitState("X","Y","2*X");
  RandomVector output(limitState, vect);

  Event myEvent(output, ComparisonOperator(Less()), 0.0);
  
  SubsetSampling a(myEvent);
  std::cout << a << std::endl; 
  return 0;
}


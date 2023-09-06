#include <iostream> 
#include <math.h> 
#include <cmath> 

class Progression
{
protected: 
  long first, cur; 
public: 
  Progression(long num = 0)
  { 
    first = num; 
    cur = num; 
  }
  virtual ~Progression() { }; 
  void printProgression(int n); // Reset the progression and print the first n values
protected:
  virtual long firstValue(); // reset the progression to the first value and return it
  virtual long nextValue(); // Step the progression to the next value and return it

};

void Progression::printProgression(int n)
{
  std::cout << firstValue(); 
  for(int i = 2; i <= n; ++i)
    std::cout << ' ' << nextValue(); 
  std::cout << std::endl; 
}
long Progression::firstValue()
{
  cur = first; // starting point/reset
  return cur; 
}
long Progression::nextValue()
{
  return ++cur; // advance
}

class RootProgression : public Progression
{
public: 
  RootProgression(long f = 65536)
  {
    first = f; 
    cur = f; 
  }
protected: 
  virtual long nextValue()
  {
    cur = sqrt(cur); 
    return cur; 
  }
};
int main()
{
  RootProgression root; 
  RootProgression test(1000); 


  root.printProgression(5); 
  test.printProgression(5); 
}
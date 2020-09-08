#include <iostream>
#include <vector>
#include "food.h"
using namespace std;

int main()
{
  Food * food = new Food("kimchi", 100, 12, 3, 4);
  food -> showInfo();
  return 0;
}

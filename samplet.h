#ifndef _SAMPLET_H_
#define _SAMPLET_H_

#include <iostream>
#include <vector>
using namespace std;
#include "cityt.hh"

template <typename T>
class samplet : public cityt<T> {
  // DON'T CHANGE ANYTHING ABOVE THIS LINE!!! (You can add more includes)
  
};

/* With generic code, it's the header (.h) that includes the source (.cc), not the other way around that is the normal practice with non-generic code. */
#include "samplet.cc"
#endif

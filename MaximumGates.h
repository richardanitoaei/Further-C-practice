#ifndef MAXIMUM_GATES_H
#define MAXIMUM_GATES_H

#include <vector>
#include <algorithm>
using std::vector;

// TODO: Your answer for question 2 goes here

int maximumGates(const vector<int>& arrives, const vector<int>& departs){
  vector<int> copyOfDeparts = departs;

  std::sort(copyOfDeparts.begin(), copyOfDeparts.end());

  int i = 0;
  int j = 0;
  int max = 0;
  int nr = 0;

  while(i < arrives.size() && j < copyOfDeparts.size()){
    if(copyOfDeparts[j] > arrives[i]){
      i++;
      nr++;

      if(nr > max) max = nr;
    }
    else{
      j++;
      nr = 0;
    }
  }

  return max;
}



// Do not write any code below this line


#endif

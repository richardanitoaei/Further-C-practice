#ifndef STACK_H
#define STACK_H

#include "vector.h"
#include <sstream>
#include <string>
using pep::vector;
using std::string;
using std::stringstream;

// TODO: Your code for question 3 goes here
class Stack{
protected:
  vector<double> stack;
  double evaluate(const string& s);

public:
  bool empty(){
    return stack.empty();
  }

  double pop(){
    double copyOfPop = stack.back();
    stack.pop_back();
    return copyOfPop;
  }

  void push(const double& element){
    stack.push_back(element);
  }

};

double evaluate(const string& s){
  double evaluation = 0.0;
  Stack stack;
  stringstream convert(s);
  string segment;

  
  while(std::getline(convert, segment, ' ')){

  		double a = 0.0;
  		double b = 0.0;

  		if(segment == "+") { 
  			a = stack.pop();
  			b = stack.pop();
  			stack.push(a+b);
  		}
  		else if(segment == "-"){ 
  			a = stack.pop();
  			b = stack.pop();
  			stack.push(b-a);
  		}

  		else if(segment == "/"){ 
  			a = stack.pop();
  			b = stack.pop();
  			stack.push(b/a);
  		}

  		else if(segment == "*") { 
  			a = stack.pop();
  			b = stack.pop();
  			stack.push(b*a);
  		}

  		else if(!segment.empty()) stack.push(std::stod(segment));

  }

  return stack.pop();

}


// Do not write anything below this line

#endif

//Copyright John Murray CSCE240 2019
#include <mean.h>




  void csce240::Mean::Collect(double datum) {
    stack.push_back(datum);
  }
 

 double csce240::Mean::Calculate() const {
    double total;
    for (unsigned int i = 0; i < stack.size(); ++i) {
      total += stack.at(i);
    }
           
double avg = total/stack.size();
return avg;
}




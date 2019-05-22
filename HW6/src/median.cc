//Copyright John Murray CSCE240 2019
#include <median.h>
#include <iostream>
using std::cout;
using std::endl;





void csce240::Median::Collect(double datum) 
{
  //for (unsigned int i = 0; i < stack.size(); ++i) {
	  stack.push_back(datum);
	 //}
 bubbleSort();
 for (unsigned int i = 0; i < stack.size(); ++i) {
   cout << stack.at(i) << endl;
 }
 
}

void csce240::Median::bubbleSort() {
  double temp = 0.0;
  bool swapped = false;

  while (swapped != true) {
swapped = true;
    for (unsigned int i = 1; i < stack.size(); ++i) {
      
      if (stack.at(i - 1) > stack.at(i))
      {
        temp = stack.at(i - 1);
        stack.at(i - 1) = stack.at(i);
        stack.at(i) = temp;
        swapped = false;
      }

    }
  }
}


double csce240::Median::Calculate() const
{
  double med = 0.0;
  if (stack.size() % 2 == 0) {
    double low = stack.at((stack.size() / 2) - 1);
    double high = stack.at(stack.size() / 2);
    med = ((low + high) / 2);
  }
  else {
    med = stack.at(stack.size() / 2);
  }


  return med;
}





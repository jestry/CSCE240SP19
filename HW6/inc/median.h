//Copyright John Murray CSCE240 2019
#ifndef _MEDIAN_H_
#define _MEDIAN_H_
#include <statistic.h>
//using namespace csce240;


namespace csce240 {
 class Median : public Statistic {
 public:

  ~Median(){};
 
  void Collect(double datum);
  double Calculate() const;
  void bubbleSort();

};
}

#endif //NOLINT



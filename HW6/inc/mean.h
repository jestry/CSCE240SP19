//Copyright John Murray CSCE240 2019
#ifndef _MEAN_H_
#define _MEAN_H_
#include <statistic.h>
//using namespace csce240


namespace csce240 {
class Mean : public Statistic {
 public:
 
  ~Mean(){};

  void Collect(double datum); 
  double Calculate() const;

};
}

#endif //NOLINT


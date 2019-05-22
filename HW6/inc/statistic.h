//Copyright John Murray CSCE240 2019
#ifndef _STATISTIC_H_
#define _STATISTIC_H_
#include <vector>



namespace csce240 {
class Statistic {
 public:

  virtual ~Statistic(){};

  virtual void Collect(double) = 0;
  virtual double Calculate() const = 0;
  std::vector<double> stack;

};
}

#endif //NOLINT


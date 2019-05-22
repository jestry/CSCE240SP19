// Copyright Jesse Estry 2019

#include "gradebook.h"  // NOLINT
using std::abs;
using std::cout;
using std::endl;

void GradeBook::Add(double grade) {
  grades_.push_back(grade);
}

double GradeBook::Get(size_t index) const {
  return index < grades_.size() ? grades_[index] : NAN;
}

const GradeBook GradeBook::operator+(double rhs) const {
  GradeBook newBook;
  for (size_t i = 0; i < GetSize(); ++i) {
    newBook.Add(Get(i));
  }
  newBook.Add(rhs);
  return newBook;
}

const GradeBook GradeBook::operator+(const GradeBook& rhs) const {
  GradeBook newBook;
  for (size_t j = 0; j < GetSize(); ++j) {
    newBook.Add(Get(j));
  }
  for (size_t i = 0; i < rhs.GetSize(); ++i) {
    newBook.Add(rhs.Get(i));
  }
  return newBook;
}

bool GradeBook::operator==(const GradeBook& rhs) const {
  if (std::abs(GetAvg() - rhs.GetAvg()) <= 0.00001 &&
    std::abs(rhs.GetAvg() - GetAvg()) <= 0.00001) {
    return true;
  }
  return false;
}

bool GradeBook::operator==(double rhs) const {
  if (std::abs(GetAvg() - rhs) <= 0.00001 &&
    std::abs(rhs - GetAvg()) <= 0.00001) {
    return true;
  }
  return false;
}

bool GradeBook::operator<(const GradeBook& rhs) const {
  if (GetAvg() < rhs.GetAvg()) {
    cout << "lhs Avg: " << GetAvg() << " rhs avg: " << rhs.GetAvg() << endl;
    return true;
  } else {
    if (GetAvg() == rhs.GetAvg()) {
      double max1 = 0.0;
      double max2 = 0.0;
      for (size_t i = 0; i < GetSize(); ++i) {
        if (Get(i) > max1) {
          max1 = Get(i);
        }
      }
      for (size_t i = 0; i < rhs.GetSize(); ++i) {
        if (rhs.Get(i) > max2) {
          max2 = rhs.Get(i);
        }
      }
      if (max1 < max2) {
        cout << "lhs Avg: " << max1 << " rhs avg: " << max2 << endl;
        return true;
      } else {
        cout << "lhs Avg: " << max1 << " rhs avg: " << max2 << endl;
        return false;
      }
    }
  }
  return false;
}

bool GradeBook::operator<(double rhs) const {
  if (GetAvg() < rhs) {
    return true;
  } else {
    return false;
  }
}

double GradeBook::GetAvg() const {
  double average = 0.0;
  if (GetSize() == 0) {
    return -INFINITY;
  } else {
    for (size_t i = 0; i < GetSize(); ++i) {
      average += Get(i);
    }
    average = average / GetSize();
    return average;
  }
}

size_t GradeBook::GetSize() const {
  return grades_.size();
}

const GradeBook operator+(double lhs, const GradeBook& rhs) {
  GradeBook newBook;
  for (size_t i = 0; i < rhs.GetSize(); ++i) {
    newBook.Add(rhs.Get(i));
  }
  newBook.Add(lhs);
  return newBook;
}

bool operator==(double lhs, const GradeBook& rhs) {
  if (rhs.GetAvg() == lhs) {
    return true;
  }
  return false;
}

bool operator<(double lhs, const GradeBook& rhs) {
  if (lhs < rhs.GetAvg()) {
    cout << "lhs Avg: " << lhs << " rhs avg: " << rhs.GetAvg() << endl;
    return true;
  }
  return false;
}

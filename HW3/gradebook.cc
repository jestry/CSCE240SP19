// Copyright Jesse Estry 2019

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::nan;
using std::abs;
#include "gradebook.h"  // NOLINT

void GradeBook::Add(double grade) {
  grade_list_.push_back(grade);
}

double GradeBook::Get(size_t index) const {
  if (index < 0 || index >= GetSize()) {
    return NAN;
  } else {
    return (grade_list_.at(index));
  }
}

const GradeBook GradeBook::Add(const GradeBook& that) const {
  GradeBook newBook;
  for (unsigned int i = 0; i < GetSize(); ++i) {
    newBook.Add(grade_list_.at(i));
  }
  for (unsigned int i = 0; i < that.GetSize(); ++i) {
    newBook.Add(that.Get(i));
  }
  return newBook;
}

double GradeBook::GetGPA() const {
  double average = 0.0;
  if (grade_list_.size() == 0) {
    return NAN;
  } else {
    for (unsigned int i = 0; i < GetSize(); ++i) {
      average += Get(i);
    }
    average = average / GetSize();
    return average;
  }
}

double GradeBook::GetMax() const {
  double max = 0.0;
  if (GetSize() == 0) {
    return NAN;
  } else {
    for (unsigned int i = 0; i < GetSize(); ++i) {
      if (grade_list_.at(i) > max) {
        max = grade_list_.at(i);
      }
    }
    return max;
  }
}
const size_t GradeBook::GetSize() const {
  return grade_list_.size();
}

bool GradeBook::Equals(const GradeBook& that) const {
  if (std::abs(GetGPA() - that.GetGPA()) <= 0.00001 &&
      std::abs(that.GetGPA() - GetGPA()) <= 0.00001) {
    return true;
  }
  return false;
}

bool GradeBook::LessThan(const GradeBook & that) const {
  return true;
}

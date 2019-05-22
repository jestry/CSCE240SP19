/* Copyright 2019 Jesse Estry CSCE240 Dynamic Array */

#include <matrix.h>

template<typename T>
Matrix<T>::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

template<typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);
  assert(cols > 0);

  m_ = new T *[rows_];
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new T[cols_];
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& that) :
  rows_(that.rows_), cols_(that.cols_) {
  assert(rows_ > 0);
  assert(cols_ > 0);
  m_ = new T* [rows_];
  for (unsigned int i = 0; i < that.rows_; ++i) {
  m_[i] = new T[cols_];
  }
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      m_[i][j] = that.m_[i][j];
    }
  }
}

template<typename T>
Matrix<T>::~Matrix() {
  delete [] m_;
}

template<typename T>
T Matrix<T>::Get(unsigned int row, unsigned int col) const {
  assert(row < rows_);
  assert(col < cols_);
  T return_val = m_[row][col];
  return return_val;
}

template<typename T>
const Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
  delete [] m_;
  rows_ = rhs.rows_;
  cols_ = rhs.cols_;
  m_ = new T * [rhs.rows_];
  for (unsigned int i = 0; i < rows_; ++i) {
    m_[i] = new T[cols_];
  }
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      m_[i][j] = rhs.m_[i][j];
    }
  }
  return *this;
}

template<typename T>
const Matrix<T>& Matrix<T>::operator*=(T rhs) {
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      T temp = Get(i, j);
      m_[i][j] = temp * rhs;
    }
  }
  return *this;
}

template<typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
  assert(rows_ == rhs.rows_);
  assert(cols_ == rhs.cols_);
  Matrix newMatrix(rhs);
  for (unsigned int i = 0; i < newMatrix.rows_; ++i) {
    for (unsigned int j = 0; j < newMatrix.cols_; ++j) {
      newMatrix.m_[i][j] = Get(i, j) + rhs.Get(i, j);
    }
  }
  return newMatrix;
}

// Copyright Jesse Estry 2019
#include <matrix.h>
#include <iostream>
using std::cout;
using std::endl;

Matrix::Matrix() : m_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(unsigned int rows, unsigned int cols) :
    rows_(rows), cols_(cols) {
  assert(rows > 0);  // assert preconditions are true
  assert(cols > 0);  // assert preconditions are true

  m_ = new double *[rows_];  // create array of double pointers
  for (unsigned int i = 0; i < rows_; ++i)
    m_[i] = new double[cols_];  // create array of doubles
}

Matrix::Matrix(const Matrix& that) {
  m_ = new double* [that.rows_];
  for (unsigned int i = 0; i < that.rows_; ++i) {
    m_[i] = new double[that.cols_];
  }
  for (unsigned int i = 0; i < that.rows_; ++i) {
    for (unsigned int j = 0; j < that.cols_; ++j) {
      double temp = 0.0;
      temp = that.Get(i, j);
      m_[i][j] = temp;
    }
  }
}

Matrix::~Matrix() {
  delete [] m_;
}

double Matrix::Get(unsigned int row, unsigned int col) const {
  assert(row < rows_);
  assert(col < cols_);
  double return_Val = m_[row][col];
  return return_Val;
}

const Matrix& Matrix::operator=(const Matrix& rhs) {
  for (unsigned int i = 0; i < rhs.rows_; ++i) {
    m_ = new double* [rhs.rows_];
  }
  for (unsigned int i = 0; i < rhs.rows_; ++i) {
    m_[i] = new double[cols_];
}
  for (unsigned int i = 0; i < rhs.rows_; ++i) {
    for (unsigned int j = 0; j < rhs.cols_; ++j) {
      double temp = 0.0;
      temp = rhs.Get(i, j);
      m_[i][j] = temp;
    }
  }
  return *this;
}

const Matrix& Matrix::operator*=(double rhs) {
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < cols_; ++j) {
      double temp_val = m_[i][j];
      temp_val = temp_val * rhs;
      m_[i][j] = temp_val;
    }
  }
  return *this;
}

const Matrix Matrix::operator+(const Matrix& rhs) const {
  assert(rows_ == rhs.rows_);
  assert(cols_ == rhs.cols_);
  Matrix newMatrix(rhs.rows_, rhs.cols_);
  newMatrix.m_ = new double* [rhs.rows_];
  for (unsigned int i = 0; i < rhs.rows_; ++i) {
    newMatrix.m_[i] = new double[rhs.cols_];
    for (unsigned int j = 0; j < rhs.cols_; ++j) {
      double temp1 = Get(i, j);
      double temp2 = rhs.Get(i, j);
      temp2 = temp1 + temp2;
      newMatrix.m_[i][j] = temp2;
    }
  }
  return newMatrix;
}

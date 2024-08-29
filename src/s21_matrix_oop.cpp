#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::length_error("Lenght should be greater than 0");
  } else {
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = 0;
      }
    }
  }
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  this->matrix_ = new double *[this->rows_];
  for (int i = 0; i < this->rows_; i++) {
    this->matrix_[i] = new double[this->cols_];
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_) {
  this->matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(int new_rows) {
  if (new_rows < 1) {
    throw std::length_error("Matrix rows should be greater than 1");
  } else {
    if (new_rows != rows_) {
      S21Matrix tmp(new_rows, cols_);
      int min = std::min(rows_, new_rows);

      for (int i = 0; i < min; i++) {
        for (int j = 0; j < cols_; j++) {
          tmp.matrix_[i][j] = this->matrix_[i][j];
        }
      }
      *this = std::move(tmp);
    }
  }
}

void S21Matrix::SetCols(int n_cols) {
  if (n_cols < 1) {
    throw std::length_error("Matrix columns should be greater than 1");
  } else {
    if (n_cols != cols_) {
      S21Matrix new_matrix(rows_, n_cols);
      int min = std::min(cols_, n_cols);

      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < min; j++) {
          new_matrix.matrix_[i][j] = this->matrix_[i][j];
        }
      }
      *this = std::move(new_matrix);
    }
  }
}

bool S21Matrix::IsCorrectMatrix() const {
  return matrix_ != nullptr && cols_ > 0 && rows_ > 0;
}

double &S21Matrix::GetElement(int row, int col) {
  if ((row < 0 || row > rows_ - 1) || (col < 0 || col > cols_ - 1))
    throw std::logic_error("Invalid parameters");

  return matrix_[row][col];
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (!this->IsCorrectMatrix() || !other.IsCorrectMatrix()) {
    throw std::logic_error("Matrix is not correct");
  }
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::logic_error("Matrix is not correct");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (!this->IsCorrectMatrix() || !other.IsCorrectMatrix()) {
    throw std::logic_error("Matrix is not correct");
  }
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::logic_error("Matrix is not correct");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  if (!this->IsCorrectMatrix() || !other.IsCorrectMatrix()) {
    throw std::logic_error("Matrix is not correct");
  }
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    return false;
  }
  bool res = true;

  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (EPS < std::fabs(this->matrix_[i][j] - other.matrix_[i][j])) {
          res = false;
        }
      }
    }
  } else {
    res = false;
  }
  return res;
}

void S21Matrix::MulNumber(const double num) {
  if (!this->IsCorrectMatrix()) {
    throw std::logic_error("Matrix is not correct");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (!this->IsCorrectMatrix() || !other.IsCorrectMatrix()) {
    throw std::logic_error("Matrix is not correct");
  }
  if (this->cols_ != other.rows_) {
    throw std::logic_error("Matrix is not correct");
  }
  S21Matrix result(this->rows_, other.cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < this->cols_; k++) {
        result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  *this = std::move(result);
}

S21Matrix S21Matrix::Transpose() {
  if (!this->IsCorrectMatrix()) {
    throw std::logic_error("Matrix is not correct");
  }
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = this->matrix_[i][j];
    }
  }
  return result;
}

void S21Matrix::SquareMatrix(int rows, int cols, S21Matrix &square) {
  int m_rows = 0;
  int m_cols = 0;
  for (int i = 0; i < this->rows_; i++) {
    if (i == rows) {
      continue;
    }
    m_cols = 0;
    for (int j = 0; j < this->cols_; j++) {
      if (j == cols) {
        continue;
      }
      square.matrix_[m_rows][m_cols] = this->matrix_[i][j];
      m_cols++;
    }
    m_rows++;
  }
}

double S21Matrix::Determinant() {
  if (!this->IsCorrectMatrix())
    throw std::logic_error("matrix is not correct!");
  if (rows_ != cols_) throw std::logic_error("incorrect matrix");

  double det = 0;

  if (rows_ == 1) {
    det = this->matrix_[0][0];
  } else {
    double sub_det = .0;
    for (int i = 0; i < this->rows_; i++) {
      S21Matrix sub_matrix(this->rows_ - 1, this->cols_ - 1);
      int sub_i = 0;
      int sub_j = 0;
      for (int j = 1; j < this->rows_; ++j) {
        for (int k = 0; k < this->cols_; ++k) {
          if (k != i) {
            sub_matrix.matrix_[sub_i][sub_j++] = this->matrix_[j][k];
            if (sub_j == this->rows_ - 1) {
              sub_i++;
              sub_j = 0;
            }
          }
        }
      }
      sub_det = sub_matrix.Determinant();
      det += this->matrix_[0][i] * (i % 2 == 0 ? 1 : -1) * sub_det;
    }
  }

  return det;
}

S21Matrix S21Matrix::CalcComplements() {
  if (!this->IsCorrectMatrix()) {
    throw std::logic_error("Matrix is not correct");
  }
  if (cols_ != rows_ || (rows_ < 2 && cols_ < 2)) {
    throw std::logic_error(
        "Matrix dimensions must be equal and must be greater than 1");
  }
  S21Matrix result(rows_, cols_);

  if (rows_ == 1) {
    result.matrix_[0][0] = matrix_[0][0];
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix square(rows_ - 1, cols_ - 1);
        SquareMatrix(i, j, square);
        result.matrix_[i][j] = pow(-1, i + j) * square.Determinant();
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (!this->IsCorrectMatrix()) {
    throw std::logic_error("Invalid matrix");
  }
  if (rows_ != cols_) {
    throw std::logic_error("Matrix dimensions must be equal");
  }

  S21Matrix result(rows_, cols_);
  double det = this->Determinant();
  if (det == 0) {
    throw std::logic_error("Determinant is zero");
  } else {
    S21Matrix temp1(rows_, cols_);
    S21Matrix temp2(rows_, cols_);

    temp1 = this->Transpose();
    temp2 = temp1.CalcComplements();
    temp2.MulNumber(1 / det);
    result = temp2;
  }

  return result;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}
S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}
S21Matrix S21Matrix::operator*(double number) {
  S21Matrix res(*this);
  res.MulNumber(number);
  return res;
}
bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (!other.IsCorrectMatrix()) throw std::logic_error("Incorrect matrix");

  if (this->matrix_ != nullptr) {
    for (int i = 0; i < this->rows_; i++) {
      delete[] this->matrix_[i];
    }
    delete[] this->matrix_;
  }

  this->rows_ = other.rows_;
  this->cols_ = other.cols_;

  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }

  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(double number) {
  MulNumber(number);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

double &S21Matrix::operator()(int row, int col) { return GetElement(row, col); }
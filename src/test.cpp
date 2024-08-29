#include <gtest/gtest.h>

#include <cstdio>
#include <fstream>
#include <iostream>

#include "s21_matrix_oop.h"

TEST(TestEq, TestEq10) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};

  matrix1(0, 0) = -1;
  matrix2(0, 0) = 2;
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq9) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};

  matrix1(0, 0) = 1;
  matrix2(0, 0) = -2;
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq0) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};

  matrix1(0, 0) = -1;
  matrix2(0, 0) = 2;
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq00) {
  S21Matrix matrix1{1, 1};
  S21Matrix matrix2{1, 1};

  matrix1(0, 0) = 1;
  matrix2(0, 0) = -2;
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq1) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetRows(), 2);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 4;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 1;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result2);
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetRows(), 2);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(1, 0) = 3;
  matrix2(1, 1) = 4;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(TestEq, TestEq3) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetRows(), 2);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(TestEq, TestEq4) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix matrix2{3, 3};
  EXPECT_EQ(matrix2.GetRows(), 3);
  EXPECT_EQ(matrix2.GetRows(), 3);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result1);
  EXPECT_FALSE(matrix1 == matrix2);

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result2);
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq04) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetRows(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetRows(), 2);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result1);
  EXPECT_FALSE(matrix1 == matrix2);

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_FALSE(result2);
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TestEq, TestEq5) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetRows(), 1);

  S21Matrix matrix2{1, 1};
  EXPECT_EQ(matrix2.GetRows(), 1);
  EXPECT_EQ(matrix2.GetRows(), 1);

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  matrix1(0, 0) = 2.5;
  matrix2(0, 0) = 2.5;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);

  matrix1(0, 0) = 2.5000001;
  matrix2(0, 0) = 2.5;

  bool result3 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result3);
  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(TestEq, TestEq6) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix matrix2{2, 2};
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetRows(), 2);
  matrix2(0, 0) = 0.0000001;

  bool result1 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result1);
  EXPECT_TRUE(matrix1 == matrix2);

  matrix1(0, 0) = 0.0000001;

  bool result2 = matrix1.EqMatrix(matrix2);
  EXPECT_TRUE(result2);
  EXPECT_TRUE(matrix1 == matrix2);
};

TEST(TestConstructor, TestConstructorException1) {
  EXPECT_ANY_THROW(S21Matrix(-1, 99));
}

TEST(TestConstructor, TestConstructorException2) {
  EXPECT_ANY_THROW(S21Matrix(99, -1));
}

TEST(TestConstructor, TestConstructorException3) {
  EXPECT_ANY_THROW(S21Matrix(-1, -1));
}

TEST(TestConstructor, TestConstructorException4) {
  EXPECT_ANY_THROW(S21Matrix(-99, -99));
}

TEST(TestConstructor, TestConstructorParams1) {
  S21Matrix matrix_check(5, 4);
  EXPECT_EQ(matrix_check.GetRows(), 5);
  EXPECT_EQ(matrix_check.GetCols(), 4);
}

TEST(TestConstructor, TestConstructorParams2) {
  S21Matrix matrix_check(999, 1999);
  EXPECT_EQ(matrix_check.GetRows(), 999);
  EXPECT_EQ(matrix_check.GetCols(), 1999);
}

TEST(TestConstructor, TestConstructorCopy1) {
  S21Matrix matrix_check = S21Matrix(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  S21Matrix matrix_copy = matrix_check;

  EXPECT_EQ(matrix_check.GetCols(), 2);
  EXPECT_EQ(matrix_check.GetRows(), 2);

  EXPECT_EQ(matrix_copy.GetCols(), 2);
  EXPECT_EQ(matrix_copy.GetRows(), 2);

  EXPECT_TRUE(matrix_check == matrix_copy);
}

TEST(TestConstructor, TestConstructorCopy2) {
  S21Matrix matrix_check = S21Matrix(2, 2);

  matrix_check(0, 0) = 4.0;
  matrix_check(0, 1) = 4.0;
  matrix_check(1, 0) = 4.0;
  matrix_check(1, 1) = 4.0;

  S21Matrix matrix_copy(matrix_check);

  EXPECT_EQ(matrix_check.GetCols(), 2);
  EXPECT_EQ(matrix_check.GetRows(), 2);

  EXPECT_EQ(matrix_copy.GetCols(), 2);
  EXPECT_EQ(matrix_copy.GetRows(), 2);

  EXPECT_TRUE(matrix_check == matrix_copy);
}

TEST(CreateMatrix1, StandartConstructor) {
  S21Matrix matrix_a;
  ASSERT_TRUE(matrix_a.GetCols() == 0);
  ASSERT_TRUE(matrix_a.GetRows() == 0);
}

TEST(CreateMatrix2, ParamConstr) { ASSERT_NO_THROW(S21Matrix matrix(2, 2)); }

TEST(CreateMatrix3, ParamConstWithWrongSizes) {
  EXPECT_THROW(S21Matrix matrix(-1, 2), std::length_error);
}

TEST(CreateMatrix4, MoveConstr) {
  S21Matrix matrix_a(2, 2);
  ASSERT_NO_THROW(S21Matrix matrix_b = std::move(matrix_a));
}

TEST(CreateMatrix5, CopyConstr) {
  S21Matrix matrix_a(2, 2);
  ASSERT_NO_THROW(S21Matrix matrix_b(matrix_a));
}

TEST(CreateMatrix6, ParamConstWithWrongSizes_2) {
  EXPECT_THROW(S21Matrix matrix(-1, -2), std::length_error);
}

TEST(CreateMatrix7, ParamConstWithWrongSizes_3) {
  EXPECT_THROW(S21Matrix matrix(1, -2), std::length_error);
}

TEST(OperatorParentheses3, MatrixsetterWrongIndexes) {
  S21Matrix matrix_a(2, 2);
  EXPECT_THROW(matrix_a(3, 0) = 1, std::logic_error);
}

TEST(eqMatrix3, NonEqMatrix) {
  S21Matrix matrix_a(1, 3);
  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = 3;
  S21Matrix matrix_b(2, 2);
  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_b(1, 0) = 3;
  matrix_b(1, 1) = 4;
  ASSERT_FALSE(matrix_a == matrix_b);
}

TEST(SumMatrix2, SumNonEqMatrix) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;

  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_b(1, 0) = 3;
  matrix_b(1, 1) = 4;

  EXPECT_THROW(matrix_a.SumMatrix(matrix_b), std::logic_error);
}

TEST(SubMatrix2, SubNonEqMatrix) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  EXPECT_THROW(matrix_a.SubMatrix(matrix_b), std::logic_error);
}

TEST(MulMatrix2, MulNonEqMatrix) {
  S21Matrix matrix_a(2, 1);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(1, 0) = -6.6;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  EXPECT_THROW(matrix_a.MulMatrix(matrix_b), std::logic_error);
}

TEST(OperatorSumMatrix2, OperatorSumWithNoEqSizesMatrix) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;

  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_b(1, 0) = 3;
  matrix_b(1, 1) = 4;

  EXPECT_THROW(matrix_a += matrix_b, std::logic_error);
}

TEST(OperatorSubMatrix2, False) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  EXPECT_THROW(matrix_a -= matrix_b, std::logic_error);
}

TEST(OperatorMulMatrix2, False) {
  S21Matrix matrix_a(2, 1);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(1, 0) = -6.6;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  EXPECT_THROW(matrix_a *= matrix_b, std::logic_error);
}

TEST(OperatorEqal, Invalid) {
  S21Matrix matrix_a(2, 1);
  S21Matrix matrix_b;

  EXPECT_THROW(matrix_a = matrix_b, std::logic_error);
}

TEST(invalidmatrix, False) {
  S21Matrix matrix_a(2, 1);
  S21Matrix matrix_b;

  matrix_a(0, 0) = 3;
  matrix_a(1, 0) = -6.6;

  EXPECT_THROW(matrix_b *= matrix_a, std::logic_error);
  EXPECT_THROW(matrix_b.EqMatrix(matrix_a), std::logic_error);
  EXPECT_THROW(matrix_b.Transpose(), std::logic_error);
  EXPECT_THROW(matrix_b.InverseMatrix(), std::logic_error);
  EXPECT_THROW(matrix_b.Determinant(), std::logic_error);
  EXPECT_THROW(matrix_b.CalcComplements(), std::logic_error);
  EXPECT_THROW(matrix_b *= 2, std::logic_error);
  EXPECT_THROW(matrix_b += matrix_a, std::logic_error);
  EXPECT_THROW(matrix_b -= matrix_a, std::logic_error);
}

TEST(Inverse1, False) {
  S21Matrix matrix_a(4, 3);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = 3;
  matrix_a(1, 0) = 4;
  matrix_a(1, 1) = 5;
  matrix_a(1, 2) = 6;
  matrix_a(2, 0) = 7;
  matrix_a(2, 1) = 8;
  matrix_a(2, 2) = 9;
  matrix_a(3, 0) = 10;
  matrix_a(3, 1) = 11;
  matrix_a(3, 2) = 12;

  EXPECT_THROW(matrix_a.InverseMatrix(), std::logic_error);
}

TEST(Det52, False) {
  S21Matrix matrix_a(4, 3);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = 3;
  matrix_a(1, 0) = 4;
  matrix_a(1, 1) = 5;
  matrix_a(1, 2) = 6;
  matrix_a(2, 0) = 7;
  matrix_a(2, 1) = 8;
  matrix_a(2, 2) = 9;
  matrix_a(3, 0) = 10;
  matrix_a(3, 1) = 11;
  matrix_a(3, 2) = 12;

  EXPECT_THROW(matrix_a.Determinant(), std::logic_error);
}

TEST(calc52, False) {
  S21Matrix matrix_a(4, 3);

  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = 3;
  matrix_a(1, 0) = 4;
  matrix_a(1, 1) = 5;
  matrix_a(1, 2) = 6;
  matrix_a(2, 0) = 7;
  matrix_a(2, 1) = 8;
  matrix_a(2, 2) = 9;
  matrix_a(3, 0) = 10;
  matrix_a(3, 1) = 11;
  matrix_a(3, 2) = 12;

  EXPECT_THROW(matrix_a.CalcComplements(), std::logic_error);
}

TEST(Inverse3, False) {
  S21Matrix matrix_a(3, 3);
  matrix_a(0, 0) = 1;
  matrix_a(0, 1) = 2;
  matrix_a(0, 2) = 3;
  matrix_a(1, 0) = 4;
  matrix_a(1, 1) = 5;
  matrix_a(1, 2) = 6;
  matrix_a(2, 0) = 7;
  matrix_a(2, 1) = 8;
  matrix_a(2, 2) = 9;

  EXPECT_THROW(matrix_a.InverseMatrix(), std::logic_error);
}

TEST(Constructor, Default) {
  auto test = S21Matrix();
  EXPECT_EQ(test.GetRows(), 0);
  EXPECT_EQ(test.GetCols(), 0);
}

TEST(Constructor, By2Args) {
  auto test = S21Matrix(3, 3);
  EXPECT_EQ(test.GetRows(), 3);
  EXPECT_EQ(test.GetCols(), 3);
}

TEST(Constructor, Copy) {
  auto test = S21Matrix(3, 3);
  test(0, 0) = 1;
  auto temp = S21Matrix(test);
  EXPECT_EQ(test, temp);
}

TEST(Constructor, Move) {
  auto test1 = S21Matrix(3, 3);
  test1(1, 1) = 5;
  auto test2 = S21Matrix(test1);
  auto test3 = S21Matrix(std::move(test1));
  EXPECT_EQ(test2, test3);
}

TEST(SimpleMathOperations, EqMatrix) {
  auto test1 = S21Matrix(3, 3);
  test1(1, 2) = 5;
  auto test2 = test1;
  EXPECT_TRUE(test1.EqMatrix(test2));
  test2(1, 1) = 1;
  EXPECT_FALSE(test1.EqMatrix(test2));
  auto test3 = S21Matrix(5, 5);
  EXPECT_FALSE(test1.EqMatrix(test3));
}

TEST(SimpleMathOperations, SumMatrix) {
  auto test1 = S21Matrix(1, 1);
  test1(0, 0) = 1;
  auto test2 = test1;
  test1.SumMatrix(test2);
  EXPECT_EQ(test1(0, 0), 2);
}

TEST(SimpleMathOperations, SubMatrix) {
  auto test1 = S21Matrix(1, 1);
  test1(0, 0) = 1;
  auto test2 = test1;
  test1.SubMatrix(test2);
  EXPECT_EQ(test1(0, 0), 0);
}

TEST(SimpleMathOperations, SubMatrix1) {
  auto test1 = S21Matrix(1, 1);
  test1(0, 0) = 1;
  auto test2 = test1;
  test1 = test1 - test2;
  EXPECT_EQ(test1(0, 0), 0);
}

TEST(SimpleMathOperations, SumMatrix1) {
  auto test1 = S21Matrix(2, 2);
  auto test_res = S21Matrix(2, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      test1(i, j) = 1;
      test_res(i, j) = 2;
    }
  }
  auto test2 = test1;
  test1 = (test1 + test2);
  EXPECT_EQ(test1, test_res);
}

TEST(SimpleMathOperations, MulMatrix2) {
  auto test1 = S21Matrix(1, 1);
  test1(0, 0) = 1;
  auto test2 = test1;
  test1 = (test1 * 0);
  EXPECT_EQ(test1(0, 0), 0);
}

TEST(SimpleMathOperations, MulNumber) {
  auto test1 = S21Matrix(1, 1);
  test1(0, 0) = 5;
  test1.MulNumber(3);
  EXPECT_EQ(test1(0, 0), 15);
}

TEST(SimpleMathOperations, MulMatrix) {
  auto test1 = S21Matrix(3, 3);
  for (int i = 0; i < test1.GetRows(); i++) {
    for (int j = 0; j < test1.GetCols(); j++) {
      test1(i, j) = test1.GetRows() * i + j + 1;
    }
  }
  auto test2 = test1;
  test1.MulMatrix(test2);
  test2(0, 0) = 30;
  test2(0, 1) = 36;
  test2(0, 2) = 42;
  test2(1, 0) = 66;
  test2(1, 1) = 81;
  test2(1, 2) = 96;
  test2(2, 0) = 102;
  test2(2, 1) = 126;
  test2(2, 2) = 150;
  EXPECT_EQ(test1, test2);
}

TEST(SimpleMathOperations, MulMatrix1) {
  auto test1 = S21Matrix(3, 3);
  for (int i = 0; i < test1.GetRows(); i++) {
    for (int j = 0; j < test1.GetCols(); j++) {
      test1(i, j) = test1.GetRows() * i + j + 1;
    }
  }
  auto test2 = test1;
  test1 *= test2;

  test2(0, 0) = 30;
  test2(0, 1) = 36;
  test2(0, 2) = 42;
  test2(1, 0) = 66;
  test2(1, 1) = 81;
  test2(1, 2) = 96;
  test2(2, 0) = 102;
  test2(2, 1) = 126;
  test2(2, 2) = 150;
  EXPECT_EQ(test1, test2);
}

TEST(LinearOperations, Transpose) {
  auto test1 = S21Matrix(3, 3);
  for (int i = 0; i < test1.GetRows(); i++) {
    for (int j = 0; j < test1.GetCols(); j++) {
      test1(i, j) = test1.GetRows() * i + j + 1;
    }
  }
  test1 = test1.Transpose();
  auto test2 = S21Matrix(3, 3);
  test2(0, 0) = 1;
  test2(0, 1) = 4;
  test2(0, 2) = 7;
  test2(1, 0) = 2;
  test2(1, 1) = 5;
  test2(1, 2) = 8;
  test2(2, 0) = 3;
  test2(2, 1) = 6;
  test2(2, 2) = 9;
  EXPECT_EQ(test1, test2);
}

TEST(LinearOperations, CalcComplements) {
  auto test1 = S21Matrix(3, 3);
  test1(0, 0) = 1;
  test1(0, 1) = 2;
  test1(0, 2) = 3;
  test1(1, 0) = 0;
  test1(1, 1) = 4;
  test1(1, 2) = 2;
  test1(2, 0) = 5;
  test1(2, 1) = 2;
  test1(2, 2) = 1;
  test1 = test1.CalcComplements();
  auto test2 = S21Matrix(3, 3);
  test2(0, 0) = 0;
  test2(0, 1) = 10;
  test2(0, 2) = -20;
  test2(1, 0) = 4;
  test2(1, 1) = -14;
  test2(1, 2) = 8;
  test2(2, 0) = -8;
  test2(2, 1) = -2;
  test2(2, 2) = 4;
  EXPECT_EQ(test1, test2);
}

TEST(LinearOperations, CalcComplements1) {
  auto test1 = S21Matrix(2, 3);
  test1(0, 0) = 1;
  test1(0, 1) = 2;
  test1(0, 2) = 3;
  test1(1, 0) = 0;
  test1(1, 1) = 4;
  test1(1, 2) = 2;
  EXPECT_THROW(test1.CalcComplements(), std::logic_error);
}

TEST(LinearOperations, Determinant) {
  auto test1 = S21Matrix(3, 3);
  test1(0, 0) = 1;
  test1(0, 1) = 2;
  test1(0, 2) = 3;
  test1(1, 0) = 0;
  test1(1, 1) = 4;
  test1(1, 2) = 2;
  test1(2, 0) = 5;
  test1(2, 1) = 2;
  test1(2, 2) = 1;
  EXPECT_DOUBLE_EQ(test1.Determinant(), -40);
}

TEST(LinearOperations, Determinant1) {
  auto test1 = S21Matrix(1, 1);
  test1(0, 0) = -40;
  EXPECT_DOUBLE_EQ(test1.Determinant(), -40);
}

TEST(LinearOperations, InverseMatrix) {
  auto test1 = S21Matrix(3, 3);
  test1(0, 0) = 2;
  test1(0, 1) = 5;
  test1(0, 2) = 7;
  test1(1, 0) = 6;
  test1(1, 1) = 3;
  test1(1, 2) = 4;
  test1(2, 0) = 5;
  test1(2, 1) = -2;
  test1(2, 2) = -3;
  test1 = test1.InverseMatrix();
  auto test2 = S21Matrix(3, 3);
  test2(0, 0) = 1;
  test2(0, 1) = -1;
  test2(0, 2) = 1;
  test2(1, 0) = -38;
  test2(1, 1) = 41;
  test2(1, 2) = -34;
  test2(2, 0) = 27;
  test2(2, 1) = -29;
  test2(2, 2) = 24;
  EXPECT_EQ(test1, test2);
}

TEST(Technical, GetRows) {
  auto test1 = S21Matrix();
  EXPECT_EQ(test1.GetRows(), 0);
  auto test2 = S21Matrix(2, 2);
  EXPECT_EQ(test2.GetRows(), 2);
}

TEST(Technical, GetCols) {
  auto test1 = S21Matrix();
  EXPECT_EQ(test1.GetCols(), 0);
  auto test2 = S21Matrix(2, 2);
  EXPECT_EQ(test2.GetCols(), 2);
}

TEST(Technical, SetRows) {
  auto test1 = S21Matrix(1, 1);
  test1.SetRows(5);
  EXPECT_EQ(test1.GetRows(), 5);
}

TEST(Technical, SetRows1) {
  auto test1 = S21Matrix(1, 1);
  EXPECT_THROW(test1.SetRows(-1), std::length_error);
}

TEST(Technical, SetCols) {
  auto test1 = S21Matrix(1, 1);
  test1.SetCols(5);
  EXPECT_EQ(test1.GetCols(), 5);
}

TEST(Technical, SetCols1) {
  auto test1 = S21Matrix(1, 1);
  EXPECT_THROW(test1.SetCols(0), std::length_error);
}

TEST(TestDeterminant, TestDeterminantZero3) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  matrix1(0, 0) = -66;
  matrix1(0, 1) = -66;
  matrix1(0, 2) = -66;
  matrix1(1, 0) = -66;
  matrix1(1, 1) = -66;
  matrix1(1, 2) = -66;
  matrix1(2, 0) = -66;
  matrix1(2, 1) = -66;
  matrix1(2, 2) = -66;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_TRUE(result == result_check);
}

TEST(TestDeterminant, TestDeterminant1) {
  S21Matrix matrix1{1, 1};
  EXPECT_EQ(matrix1.GetCols(), 1);
  EXPECT_EQ(matrix1.GetRows(), 1);

  matrix1(0, 0) = 1.5;

  double result_check = 1.5;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_TRUE(result == result_check);
}

TEST(TestDeterminant, TestDeterminant2) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  matrix1(0, 0) = 5.34922476788051;
  matrix1(1, 0) = 1.65522041497752;
  matrix1(2, 0) = -8.68382598599419;
  matrix1(0, 1) = -3.25669884728268;
  matrix1(1, 1) = 10.8967615629081;
  matrix1(2, 1) = 4.55130848893896;
  matrix1(0, 2) = -2.14478276530281;
  matrix1(1, 2) = -2.7382052554749;
  matrix1(2, 2) = 5.7808097708039;

  double result_check = 138.238;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();
  const double EPS = 1e-7;

  EXPECT_TRUE(EPS < std::fabs(result - result_check));
}

TEST(TestDeterminant, TestDeterminant3) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.GetCols(), 4);
  EXPECT_EQ(matrix1.GetRows(), 4);

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(0, 3) = 1.4;
  matrix1(1, 0) = 1.5;
  matrix1(1, 1) = 1.6;
  matrix1(1, 2) = 1.7;
  matrix1(1, 3) = 1.8;
  matrix1(2, 0) = 1.9;
  matrix1(2, 1) = 2.0;
  matrix1(2, 2) = 2.1;
  matrix1(2, 3) = 2.2;
  matrix1(3, 0) = 2.3;
  matrix1(3, 1) = 2.4;
  matrix1(3, 2) = 2.5;
  matrix1(3, 3) = 2.6;

  double result_check = -5.1347814888913e-7;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();
  double EPS = 1e-7;
  EXPECT_TRUE(EPS < std::fabs(result - result_check) &&
              matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant4) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.GetCols(), 4);
  EXPECT_EQ(matrix1.GetRows(), 4);

  matrix1(0, 0) = -7.00037610391155;
  matrix1(1, 0) = -6.32839397341013;
  matrix1(2, 0) = 10.222164043691;
  matrix1(3, 0) = 7.95983747509308;
  matrix1(0, 1) = -9.82599597726949;
  matrix1(1, 1) = 3.03237457247451;
  matrix1(2, 1) = 0.587724786484614;
  matrix1(3, 1) = -3.41600720770657;
  matrix1(0, 2) = 8.27683520526625;
  matrix1(1, 2) = -4.28063526446931;
  matrix1(2, 2) = -6.93227237439714;
  matrix1(3, 2) = -10.6065054496285;
  matrix1(0, 3) = 0.586602877592668;
  matrix1(1, 3) = 10.6546861075331;
  matrix1(2, 3) = 4.33103069034405;
  matrix1(3, 3) = 8.75408579711802;

  double result_check = -6618.549571;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();
  double EPS = 1e-7;
  EXPECT_TRUE(EPS < std::fabs(result - result_check) &&
              matrix1 == matrix_before);
}

TEST(TestDeterminant, TestDeterminant5) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  matrix1(0, 0) = 5.543;
  matrix1(0, 1) = 25.425;
  matrix1(0, 2) = 24.4325;
  matrix1(0, 3) = 23.52;
  matrix1(0, 4) = 0.0;
  matrix1(1, 0) = 52.3;
  matrix1(1, 1) = 53.2;
  matrix1(1, 2) = 34.434;
  matrix1(1, 3) = 0.0;
  matrix1(1, 4) = 53.352;
  matrix1(2, 0) = 54.23512;
  matrix1(2, 1) = 34.325;
  matrix1(2, 2) = 0.0;
  matrix1(2, 3) = 24.343;
  matrix1(2, 4) = 34.422;
  matrix1(3, 0) = 36.22;
  matrix1(3, 1) = 0.0;
  matrix1(3, 2) = 32.0;
  matrix1(3, 3) = 24.432;
  matrix1(3, 4) = 43.21;
  matrix1(4, 0) = 0.0;
  matrix1(4, 1) = 23.21;
  matrix1(4, 2) = 23.234;
  matrix1(4, 3) = 12.1231;
  matrix1(4, 4) = 21.2232;

  double result_check = 74346939.8940811;

  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();
  double EPS = 1e-7;
  EXPECT_TRUE(EPS < std::fabs(result - result_check) &&
              matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements1) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.GetCols(), 2);
  EXPECT_EQ(result_check.GetRows(), 2);

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  result_check(0, 0) = 4;
  result_check(0, 1) = -3;
  result_check(1, 0) = -2;
  result_check(1, 1) = 1;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements2) {
  S21Matrix matrix1{2, 2};
  EXPECT_EQ(matrix1.GetCols(), 2);
  EXPECT_EQ(matrix1.GetRows(), 2);

  S21Matrix result_check{2, 2};
  EXPECT_EQ(result_check.GetCols(), 2);
  EXPECT_EQ(result_check.GetRows(), 2);

  matrix1(0, 0) = 12.452;
  matrix1(0, 1) = 3.34245;
  matrix1(1, 0) = 3.356;
  matrix1(1, 1) = 3.543;

  result_check(0, 0) = 3.543;
  result_check(0, 1) = -3.356;
  result_check(1, 0) = -3.34245;
  result_check(1, 1) = 12.452;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements3) {
  S21Matrix matrix1{3, 3};
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_EQ(matrix1.GetRows(), 3);

  S21Matrix result_check{3, 3};
  EXPECT_EQ(result_check.GetCols(), 3);
  EXPECT_EQ(result_check.GetRows(), 3);

  matrix1(0, 0) = 1;
  matrix1(1, 0) = 2;
  matrix1(2, 0) = 3;
  matrix1(0, 1) = 4;
  matrix1(1, 1) = 5;
  matrix1(2, 1) = 6;
  matrix1(0, 2) = 7;
  matrix1(1, 2) = 8;
  matrix1(2, 2) = 9;

  result_check(0, 0) = -3;
  result_check(1, 0) = 6;
  result_check(2, 0) = -3;
  result_check(0, 1) = 6;
  result_check(1, 1) = -12;
  result_check(2, 1) = 6;
  result_check(0, 2) = -3;
  result_check(1, 2) = 6;
  result_check(2, 2) = -3;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements4) {
  S21Matrix matrix1{4, 4};
  EXPECT_EQ(matrix1.GetCols(), 4);
  EXPECT_EQ(matrix1.GetRows(), 4);

  S21Matrix result_check{4, 4};
  EXPECT_EQ(result_check.GetCols(), 4);
  EXPECT_EQ(result_check.GetRows(), 4);

  matrix1(0, 0) = -3.86;
  matrix1(1, 0) = -8.48;
  matrix1(2, 0) = -8.36;
  matrix1(3, 0) = 2.82;
  matrix1(0, 1) = 7.02;
  matrix1(1, 1) = 7.17;
  matrix1(2, 1) = -4.87;
  matrix1(3, 1) = -1.54;
  matrix1(0, 2) = 4.23;
  matrix1(1, 2) = 7.84;
  matrix1(2, 2) = 3.56;
  matrix1(3, 2) = -8.62;
  matrix1(0, 3) = 4.82;
  matrix1(1, 3) = -7.78;
  matrix1(2, 3) = 3.62;
  matrix1(3, 3) = 3.71;

  result_check(0, 0) = 11781393.0 / 250000.0;
  result_check(1, 0) = -593383083.0 / 1000000.0;
  result_check(2, 0) = -113629541.0 / 200000.0;
  result_check(3, 0) = -187801277.0 / 250000.0;
  result_check(0, 1) = 3349777.0 / 6250.0;
  result_check(1, 1) = 1886893.0 / 6250.0;
  result_check(2, 1) = -108158171.0 / 250000.0;
  result_check(3, 1) = 44864781.0 / 125000.0;
  result_check(0, 2) = 48626797.0 / 250000.0;
  result_check(1, 2) = -46586467.0 / 100000.0;
  result_check(2, 2) = -2410461.0 / 100000.0;
  result_check(3, 2) = -18845574.0 / 15625.0;
  result_check(0, 3) = 39911437.0 / 62500.0;
  result_check(1, 3) = -253030017.0 / 500000.0;
  result_check(2, 3) = 98132137.0 / 500000.0;
  result_check(3, 3) = -16461827.0 / 250000.0;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(TestCalcComplements, TestCalcComplements5) {
  S21Matrix matrix1{5, 5};
  EXPECT_EQ(matrix1.GetCols(), 5);
  EXPECT_EQ(matrix1.GetRows(), 5);

  S21Matrix result_check{5, 5};
  EXPECT_EQ(result_check.GetCols(), 5);
  EXPECT_EQ(result_check.GetRows(), 5);

  matrix1(0, 0) = 3.3402;
  matrix1(0, 1) = -7.8838;
  matrix1(0, 2) = 1.4603;
  matrix1(0, 3) = -1.3716;
  matrix1(0, 4) = 6.0723;
  matrix1(1, 0) = -7.8846;
  matrix1(1, 1) = 7.8416;
  matrix1(1, 2) = -4.2679;
  matrix1(1, 3) = 9.8356;
  matrix1(1, 4) = -2.3961;
  matrix1(2, 0) = 4.1176;
  matrix1(2, 1) = 2.0162;
  matrix1(2, 2) = 4.7337;
  matrix1(2, 3) = 6.3434;
  matrix1(2, 4) = -9.7277;
  matrix1(3, 0) = -7.4141;
  matrix1(3, 1) = -6.0886;
  matrix1(3, 2) = 3.0417;
  matrix1(3, 3) = 4.7122;
  matrix1(3, 4) = 3.8023;
  matrix1(4, 0) = -2.4891;
  matrix1(4, 1) = -5.7155;
  matrix1(4, 2) = -1.7409;
  matrix1(4, 3) = -5.2048;
  matrix1(4, 4) = -6.8199;

  result_check(0, 0) = -1465690149213583.0 / 152587890625;
  result_check(0, 1) = 1272307326797681.0 / 122070312500;
  result_check(0, 2) = 8908235542058123.0 / 610351562500;
  result_check(0, 3) = -3051493103944107.0 / 305175781250;
  result_check(0, 4) = -6463308694007859.0 / 4882812500000;
  result_check(1, 0) = -1311111307169479.0 / 610351562500;
  result_check(1, 1) = 4013698343237797.0 / 1220703125000;
  result_check(1, 2) = 1879307039061624.0 / 152587890625;
  result_check(1, 3) = -2346277736890227.0 / 305175781250;
  result_check(1, 4) = 918022536110711.0 / 1220703125000;
  result_check(2, 0) = -2046840259044663.0 / 610351562500;
  result_check(2, 1) = 4228464572521883.0 / 2441406250000;
  result_check(2, 2) = -6621800960129521.0 / 2441406250000;
  result_check(2, 3) = -2641705482122563.0 / 610351562500;
  result_check(2, 4) = 7359340653769.0 / 1953125000;
  result_check(3, 0) = 4563655460607809.0 / 610351562500;
  result_check(3, 1) = 431856638931077.0 / 1953125000000;
  result_check(3, 2) = -6291617971140427.0 / 610351562500;
  result_check(3, 3) = 1313171371096307.0 / 1220703125000;
  result_check(3, 4) = -5390167833396221.0 / 4882812500000;
  result_check(4, 0) = 2817957903551703.0 / 2441406250000;
  result_check(4, 1) = 3526500249653419.0 / 610351562500;
  result_check(4, 2) = 414413005838107.0 / 61035156250;
  result_check(4, 3) = 348820831855181.0 / 610351562500;
  result_check(4, 4) = 327320067348047.0 / 61035156250;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

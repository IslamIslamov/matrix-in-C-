// Программа должна быть разработана на языке C++ стандарта C++17 с использованием компилятора gcc;
// Код программы должен находиться в папке src;
// При написании кода необходимо придерживаться Google Style;
// Реализуй матрицу в виде класса S21Matrix;
// Храни только приватные поля matrix_, rows_ и cols_;
// Реализуй доступ к приватным полям rows_ и cols_ через accessor и mutator. При увеличении размера матрица дополняется нулевыми элементами, при уменьшении - лишнее просто отбрасывается;
// Оформи решение как статическую библиотеку (с заголовочным файлом s21_matrix_oop.h);
// Реализуй операции, описанные выше

// Перегрузи операторы в соответствии с таблицой в разделе выше.
// Подготовь полное покрытие unit-тестами функций библиотеки c помощью библиотеки GTest;
// Предусмотри Makefile для сборки библиотеки и тестов (с целями all, clean, test, s21_matrix_oop.a).

#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

class S21Matrix {
    private: 
        int rows_;
        int cols_;
        double **matrix_;
        const double EPS = 1e-7;
    
    public:
        // constructors
        S21Matrix();
        ~S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix &&other);

        // accessors / mutators
        int GetRows();
        int GetCols();
        void SetRows(int n_rows);
        void SetCols(int n_cols);

        // extension functions
        void SquareMatrix(int rows, int cols, S21Matrix &square);
        bool IsCorrectMatrix() const;
        double &GetElement(int row, int col);
        
        // functions
        void SumMatrix(const S21Matrix &other);
        void SubMatrix(const S21Matrix &other);
        void MulNumber(const double num);
        void MulMatrix(const S21Matrix &other);

        S21Matrix Transpose();
        S21Matrix CalcComplements();
        S21Matrix InverseMatrix();

        bool EqMatrix(const S21Matrix &other) const;
        double Determinant();

        // operators
        S21Matrix operator+(const S21Matrix &other);
        S21Matrix operator-(const S21Matrix &other);
        S21Matrix operator*(double number);
        S21Matrix &operator=(const S21Matrix &other);
        S21Matrix &operator+=(const S21Matrix &other);
        S21Matrix &operator-=(const S21Matrix &other);
        S21Matrix &operator*=(const double num);
        S21Matrix &operator*=(const S21Matrix &other);

        bool operator==(const S21Matrix &other) const;
        double &operator()(int row, int col);
};

#endif  // S21_MATRIX_OOP_H_
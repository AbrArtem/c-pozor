// prog19_1
#include <iostream>
#include <queue>

int main() {
    int n;

    std::cout << "Enter number of customers:";
    std::cin >> n;

    std::queue<int> t;
    int time, i;

    for (i = 0; i < n; ++i) {
        std::cout << "Enter time of customer #" << i << ":";
        std::cin >> time;

        t.push(time);
    }

    std::queue<int> c;
    int total_time = 0;
    int k = 0, tmp, t2;

    while (!t.empty()) {
        tmp = t.front();

        t.pop();

        total_time += tmp;
        t2 = (total_time > k) ? (total_time - k) : 0;
        ++k;

        c.push(t2);
    }

    i = 0;

    while (!c.empty()) {
        std::cout << "Customer " << i << " waited " << c.front() << ";\n";

        c.pop();

        ++i;
    }
}

// prog19_2
#include <iostream>
#include <vector>
#include <cmath>

int vvod(std::vector<double>& v, int d) {
    double x;
    for (int i = 0; i < d; ++i) {
        std::cin >> x;
        v.push_back(x);
    }
    return d;
}

double norma(const std::vector<double>& v) {
    double s = 0;
    for (int i = 0; i < v.size(); ++i) {
        s += v[i] * v[i];
    }
    return sqrt(s);
}

int main() {
    int d, n;
    std::cin >> d;
    std::cin >> n;
    double s = 0;
    std::vector<double> v1;
    for (int i = 0; i < n; ++i) {
        vvod(v1, d);
        s += norma(v1);
    }
    std::cout << "s=" << s;
}
// poly.h
#pragma once
#include <iostream>
#include <fstream>
#include <initializer_list>
#include <list>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <type_traits>

template <class T>
class Poly {
private:
	std::list<T> coeffs;
public:
	Poly();
	Poly(const std::initializer_list<T>& lst);

	unsigned get_order() const;

	void output();

	Poly<T> operator+(const Poly<T>& right);
	Poly<T> operator-(const Poly<T>& right);
	Poly<T> operator*(const Poly<T>& right);
};

template<class T>
inline Poly<T>::Poly() {
	coeffs.push_back(0);
}

template<class T>
inline Poly<T>::Poly(const std::initializer_list<T>& lst) {
	std::copy(lst.begin(), lst.end(), std::back_insert_iterator<std::list<T>>(coeffs));
}

template<class T>
inline unsigned Poly<T>::get_order() const {
	return coeffs.size() - 1;
}

template<class T>
inline Poly<T> Poly<T>::operator+(const Poly<T>& right) {
	if (coeffs.size() < right.coeffs.size()) {
		Poly<T> poly = right;
		typename std::list<T>::reverse_iterator it = poly.coeffs.rbegin();
		typename std::list<T>::reverse_iterator it2 = coeffs.rbegin();

		for (; it2 != coeffs.rend(); it++, it2++)
			*it += *it2;

		return poly;
	}

	Poly<T> poly = *this;
	typename std::list<T>::reverse_iterator it = poly.coeffs.rbegin();
	typename std::list<T>::const_reverse_iterator it2 = right.coeffs.rbegin();

	for (; it2 != right.coeffs.rend(); it++, it2++)
		*it += *it2;

	return poly;
}

template<class T>
inline Poly<T> Poly<T>::operator-(const Poly<T>& right) {
	if (coeffs.size() < right.coeffs.size()) {
		Poly<T> poly = right;
		typename std::list<T>::reverse_iterator it = poly.coeffs.rbegin();
		typename std::list<T>::reverse_iterator it2 = coeffs.rbegin();

		for (; it2 != coeffs.rend(); it++, it2++)
			*it -= *it2;

		return poly;
	}

	Poly<T> poly = *this;
	typename std::list<T>::reverse_iterator it = poly.coeffs.rbegin();
	typename std::list<T>::const_reverse_iterator it2 = right.coeffs.rbegin();

	for (; it2 != right.coeffs.rend(); it++, it2++)
		*it -= *it2;

	return poly;
}

template<class T>
inline Poly<T> Poly<T>::operator*(const Poly<T>& right) {
	std::vector<T> a(coeffs.cbegin(), coeffs.cend()), b(right.coeffs.cbegin(), right.coeffs.cend());
	std::vector<T> mult(get_order() + right.get_order() + 1);
	size_t i, j;

	for (i = 0; i < coeffs.size(); i++) {
		for (j = 0; j < right.coeffs.size(); j++)
			mult[i + j] += a[i] * b[j];
	}

	Poly poly;
	poly.coeffs = std::list<T>(mult.cbegin(), mult.cend());

	return poly;
}

template <class T>
void Poly<T>::output() {
	size_t i = 0;

	for (auto& x : coeffs) {
		std::cout << x << "*x^" << i;

		++i;

		if (i < coeffs.size()) std::cout << " + ";
	}

	std::cout << "\n";
}

// prog19_3
#include "Poly.h"

int main() {

    Poly<int> a = { 1, 3, 5 }, b = { 1, 8 };
    Poly<int> c = a * b, d = a + b;
}

// prog19_12
#ifndef HOMEWORK19_MATRIX_H
#define HOMEWORK19_MATRIX_H

#include <ostream>
#include "vector"

struct MatrixSize {
    int rows;
    int columns;

    friend std::ostream& operator<<(std::ostream& os, const MatrixSize& size) {
        os << "rows: " << size.rows << " columns: " << size.columns;
        return os;
    }
};

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> mat;
    MatrixSize size = { 0,0 };

    T vecMul(std::vector<T> vec1, std::vector<T> vec2) {
        T t = 0;
        if (vec1.size() != vec2.size()) throw std::exception();
        for (int i = 0; i < vec1.size(); i++) {
            t += vec1[i] * vec2[i];
        }
        return t;
    }
public:
    explicit Matrix(std::vector<std::vector<T>> mat) {
        size.rows = mat.size();
        if (size.rows > 0) {
            size.columns = mat[0].size();
        }
        for (std::vector<T> row : mat) {
            if (row.size() != size.columns) {
                std::cout << "Input vector is not a Matrix!" << std::endl;
                throw std::exception();
            }
        }
        this->mat = mat;
    }

    const MatrixSize& getSize() const {
        return size;
    }

    const std::vector<std::vector<T>>& toVector() const {
        return mat;
    }

    bool operator==(const Matrix& other) const {
        return mat == other.mat;
    }

    bool operator!=(const Matrix& other) const {
        return other != *this;
    }

    std::vector<T>& operator[](int row_id) {
        return mat[row_id];
    };

    Matrix<T> operator+(Matrix& other) {
        std::vector<std::vector<T>> new_mat(mat);
        for (int i = 0; i < size.rows; i++) {
            for (int j = 0; j < size.columns; j++) {
                new_mat[i][j] += other[i][j];
            }
        }
        Matrix newMatrix(new_mat);
        return newMatrix;
    }

    std::vector<T> operator*(const std::vector<T> vector) {
        if (vector.size() != size.columns) {
            std::cout << "Invalid vector size" << std::endl;
            throw std::exception();
        }
        std::vector<T> mul(size.rows);
        for (int i = 0; i < size.rows; i++) {
            mul[i] = vecMul(mat[i], vector);
        }
        return mul;
    }

    Matrix<T> operator*(Matrix<T> other) {
        other.transpose();
        std::vector<std::vector<T>> new_mat(size.rows);

        std::vector<std::vector<T>> otherMat = other.toVector();

        for (int i = 0; i < otherMat.size(); i++) {
            new_mat[i] = (*this) * otherMat[i];
        }

        other.transpose();
        Matrix<T> m(new_mat);
        m.transpose();
        return m;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        os << "Matrix (" << matrix.size << "): " << std::endl;
        for (const std::vector<T> row : matrix.mat) {
            os << "[ ";
            for (const T t : row) {
                os << t << ", ";
            }
            os << "]" << std::endl;
        }
        return os;
    }

    void transpose() {
        std::vector<std::vector<T>> transposed(size.columns);
        for (int i = 0; i < size.columns; i++) {
            std::vector<T> row(size.rows);
            for (int j = 0; j < size.rows; j++) {
                row[j] = mat[j][i];
            }
            transposed[i] = row;
        }
        mat = transposed;
        MatrixSize size_new = { size.columns,size.rows };
        size = size_new;
    }
};


#endif //HOMEWORK19_MATRIX_H
// main.cpp
#include <iostream>
#include "src/main/Matrix.h"

void task19_12() {
    std::vector<std::vector<int>> mat = { {1,2,4},{3,4,5} };
    Matrix<int> m(mat);

    std::vector<std::vector<int>> mat2 = { {-1,0,4},{-4,2,8} };
    Matrix<int> m2(mat2);

    m.transpose();
    Matrix<int> mul = m * m2;

    std::cout << "even numbers: M1 = " << m << "\nM2 = " << m2 << "M1*M2 = " << mul << std::endl;

    std::vector<std::vector<float>> mat3 = { {1.3,2.0,-4.6},{0.1,0.2,-0.4} };
    Matrix<float> m3(mat3);

    std::vector<std::vector<float>> mat4 = { {-1.5,10.88,4.5},{-4.14,2.71,8.89} };
    Matrix<float> m4(mat4);

    m3.transpose();

    Matrix<float> mul2 = m4 * m3;

    std::cout << "floating-point: \n M1 = " << m4 << "\nM2 = " << m3 << "M1*M2 = " << mul2 << std::endl;
}

int main() {
    std::cout << "Task 19.12" << std::endl;
    task19_12();
    std::cout << "\n\n\n\n";
    return 0;
}
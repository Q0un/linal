#pragma once

#include <vector>
#include <iostream>

#include "fraction.h"

class MatrixRow {
public:
    MatrixRow() = default;
    MatrixRow(size_t size);
    MatrixRow(const std::vector<Fraction>& data);
    MatrixRow(std::vector<Fraction>&& data);
    MatrixRow(std::initializer_list<Fraction> data);

    size_t GetSize() const;

    Fraction& operator[](size_t ind);
    const Fraction& operator[](size_t ind) const;

    MatrixRow operator-() const;
    MatrixRow operator+(const MatrixRow& other) const;
    MatrixRow operator+(const Fraction& val) const;
    MatrixRow operator-(const MatrixRow& other) const;
    MatrixRow operator-(const Fraction& val) const;
    MatrixRow operator*(const Fraction& val) const;
    MatrixRow operator/(const Fraction& val) const;

    MatrixRow& operator+=(const MatrixRow& other);
    MatrixRow& operator+=(const Fraction& val);
    MatrixRow& operator-=(const MatrixRow& other);
    MatrixRow& operator-=(const Fraction& val);
    MatrixRow& operator*=(const Fraction& val);
    MatrixRow& operator/=(const Fraction& val);

    MatrixRow operator|(const MatrixRow& other) const;
    MatrixRow& operator|=(const MatrixRow& other);

    bool operator==(const MatrixRow& other) const;

    std::vector<Fraction>::iterator begin();
    std::vector<Fraction>::const_iterator begin() const;
    std::vector<Fraction>::iterator end();
    std::vector<Fraction>::const_iterator end() const;

private:
    std::vector<Fraction> data_;
};

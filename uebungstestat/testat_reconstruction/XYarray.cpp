/*
 * XYarray.cpp
 *
 *  Created on: 06.11.2026
 *      Author: n3034770
 */

#include "XYarray.h"
#include <stdexcept>
#include <cstddef>

XYarray::XYarray(size_t length)
    : _x(nullptr), _y(nullptr), _length(length)
{
    if (_length > 0)
    {
        _x = new int[_length];
        _y = new int[_length];
    }
}

XYarray::XYarray(const XYarray& other)
    : _x(nullptr), _y(nullptr), _length(other._length)
{
    if (_length > 0)
    {
        _x = new int[_length];
        _y = new int[_length];
    }
    for (size_t i = 0; i < _length; i++)
    {
        _x[i] = other._x[i];
        _y[i] = other._y[i];
    }
}

XYarray& XYarray::operator=(const XYarray& other)
{
    if (this != &other)
    {
        delete[] _x;
        delete[] _y;

        _length = other._length;

        if (_length > 0)
        {
            _x = new int[_length];
            _y = new int[_length];
        }
        else
        {
            _x = nullptr;
            _y = nullptr;
        }

        for (size_t i = 0; i < _length; i++)
        {
            _x[i] = other._x[i];
            _y[i] = other._y[i];
        }
    }
    return *this;
}

XYarray::~XYarray()
{
    delete[] _x;
    delete[] _y;
}

bool XYarray::exists(int x, int y) const
{
    for (size_t i = 0; i < _length; i++)
    {
        if (_x[i] == x && _y[i] == y)
        {
            return true;
        }
    }
    return false;
}

const int& XYarray::at(size_t i) const
{
    if (i >= _length)
    {
        throw std::runtime_error("index out of range!");
    }
    return _x[i];
}

int& XYarray::at(size_t i)
{
    if (i >= _length)
    {
        throw std::runtime_error("index out of range!");
    }
    return _x[i];
}

void XYarray::push_back(int x, int y)
{
    int* nx = new int[_length + 1];
    int* ny = new int[_length + 1];

    for (size_t i = 0; i < _length; i++)
    {
        nx[i] = _x[i];
        ny[i] = _y[i];
    }

    nx[_length] = x;
    ny[_length] = y;

    delete[] _x;
    delete[] _y;

    _x = nx;
    _y = ny;
    _length++;
}

void XYarray::pop_back()
{
    if (_length == 0)
    {
        throw std::runtime_error("pop_back: array is empty!");
    }

    int* nx = nullptr;
    int* ny = nullptr;
    if (_length - 1 > 0)
    {
        nx = new int[_length - 1];
        ny = new int[_length - 1];
    }

    for (size_t i = 0; i < _length - 1; i++)
    {
        nx[i] = _x[i];
        ny[i] = _y[i];
    }

    delete[] _x;
    delete[] _y;

    _x = nx;
    _y = ny;
    _length--;
}

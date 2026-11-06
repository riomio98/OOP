/*
 * XYarray.h
 *
 *  Created on: 06.11.2026
 *      Author: n3034770
 */

#ifndef XYARRAY_H_
#define XYARRAY_H_

#include <cstddef>

class XYarray {
private:
    int* _x;
    int* _y;
    size_t _length;

public:
    XYarray(size_t length = 0);
    XYarray(const XYarray& other);
    XYarray& operator=(const XYarray& other);
    ~XYarray();

    bool exists(int x, int y) const;
    const int& at(size_t i) const;
    int& at(size_t i);

    void push_back(int x, int y);
    void pop_back();
};

#endif /* XYARRAY_H_ */

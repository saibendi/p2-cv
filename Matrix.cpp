// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Matrix.hpp"

using namespace std;

// REQUIRES: mat points to a Matrix
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *mat
// EFFECTS:  Initializes *mat as a Matrix with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Matrix_init(Matrix* mat, int width, int height) {
    // check if mat points to valid matrix
    assert(0 < width && width <= MAX_MATRIX_WIDTH);
    assert(0 < height && height <= MAX_MATRIX_HEIGHT);
    
    mat->width = width;
    mat->height = height;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//             WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix* mat, std::ostream& os) {
    // check if mat points to valid matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
    
    os << mat->width << " " << mat->height << endl;
    int size = mat->width * mat->height;
    for (int i = 0; i < size; ++i) {
        os << mat->data[i] << " ";
        if ((i+1) % mat->width == 0) {
            os << endl;
        }
    }
}

// REQUIRES: mat points to an valid Matrix
// EFFECTS:  Returns the width of the Matrix.
int Matrix_width(const Matrix* mat) {
    // check if mat points to valid matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
    
    return mat->width;
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the height of the Matrix.
int Matrix_height(const Matrix* mat) {
    // check if mat points to valid matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
    
    return mat->height;
}

// REQUIRES: mat points to a valid Matrix
//           ptr points to an element in the Matrix
// EFFECTS:  Returns the row of the element pointed to by ptr.
int Matrix_row(const Matrix* mat, const int* ptr) {
    // assert() : check if mat points to valid Matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
    
    // assert() : check if ptr points to an element in the Matrix
    
    int row = 0;
    const int *firstElemPtr = mat->data;
    
    int ptr_difference = ptr - firstElemPtr;
    row = (ptr_difference / mat->width);
        
    return row;
}

// REQUIRES: mat points to a valid Matrix
//           ptr point to an element in the Matrix
// EFFECTS:  Returns the column of the element pointed to by ptr.
int Matrix_column(const Matrix* mat, const int* ptr) {
    // assert() : check if mat points to valid Matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);
    
    // assert() : check if ptr points to an element in the Matrix??
    
    int col = 0;
    const int *firstElemPtr = mat->data;
    
    int ptr_difference = ptr - firstElemPtr;
    col = (ptr_difference % mat->width);
    
    return col;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
int* Matrix_at(Matrix* mat, int row, int column) {
    // assert() : check if mat points to a valid matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);

    assert(0 <= row && row < mat->height);
    assert(0 <= column && column < mat->width);
    
    int *ptr = &mat->data[(row * mat->width) + column];
    
    return ptr;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const int* Matrix_at(const Matrix* mat, int row, int column) {
    // assert() : check if mat points to a valid matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);

    assert(0 <= row && row < mat->height);
    assert(0 <= column && column < mat->width);
    
    const int *ptr = &mat->data[(row * mat->width) + column];
    
    return ptr;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix* mat, int value) {
    // assert() : check if mat points to a valid matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);

    int size = mat->width * mat->height;
    for (int i = 0; i < size; ++i) {
        mat->data[i] = value;
    }
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix* mat, int value) {
    // assert() : check if mat points to a valid matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);

    int totalNum = mat->width * mat->height;
    int var = (totalNum / mat->width) - 1;
    // first loop: 0th element through mat->width'th element (inclusive)
    for (int i = 0; i <= mat->width; ++i) {
        mat->data[i] = value;
    }
    // second loop: [mat->width * var] + 1 : end element (inclusive)
    for (int i = ((mat->width*var) + 1); i < totalNum; ++i) {
        mat->data[i] = value;
    }
    // third loop: borders
    for (int i = var; i > 1; --i) {
        mat->data[(mat->width * i) - 1] = value;
        mat->data[mat->width * i] = value;
    }
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the value of the maximum element in the Matrix
int Matrix_max(const Matrix* mat) {
    // assert() : check if mat points to a valid matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);

    int size = mat->width * mat->height;
    int max = mat->data[0];
    if (size > 1) {
        for (int i = 1; i < size; ++i) {
            if (mat->data[i] > max) {
                max = mat->data[i];
            }
        }
    }
    return max;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the column of the element with the minimal value
//           in a particular region. The region is defined as elements
//           in the given row and between column_start (inclusive) and
//           column_end (exclusive).
//           If multiple elements are minimal, returns the column of
//           the leftmost one.
int Matrix_column_of_min_value_in_row(const Matrix* mat, int row,
                                      int column_start, int column_end) {
    // assert() : check if mat points to a valid matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);

    assert(0 <= row && row < mat->height);
    assert(0 <= column_start && column_end <= mat->width && column_start < column_end); // column_end is exclusive
    
    int rowBeginning = (row) * mat->width;
    int min = mat->data[rowBeginning + column_start];
    int min_col = column_start;
    if (column_end - column_start > 1) {
        for (int i = column_start + 1; i < column_end; ++i) {
            if (mat->data[rowBeginning + i] < min) {
                min_col = i;
            }
        }
    }
    return min_col;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the minimal value in a particular region. The region
//           is defined as elements in the given row and between
//           column_start (inclusive) and column_end (exclusive).
int Matrix_min_value_in_row(const Matrix* mat, int row,
                            int column_start, int column_end) {
    // assert() : check if mat points to a valid matrix
    assert(0 < mat->width && mat->width <= MAX_MATRIX_WIDTH);
    assert(0 < mat->height && mat->height <= MAX_MATRIX_HEIGHT);

    assert(0 <= row && row < mat->height);
    assert(0 <= column_start && column_end <= mat->width && column_start < column_end); // column_end is exclusive
    
    int rowBeginning = (row) * mat->width;
    int min = mat->data[rowBeginning + column_start];
    if (column_end - column_start > 1) {
        for (int i = column_start + 1; i < column_end; ++i) {
            if (mat->data[rowBeginning + i] < min) {
                min = mat->data[rowBeginning + i];
            }
        }
    }
    return min;
}

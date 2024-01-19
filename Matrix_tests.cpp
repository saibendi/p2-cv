// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.hpp"
#include "Matrix_test_helpers.hpp"
#include "unit_test_framework.hpp"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.


TEST(test_3_matrix_width) {
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat2 = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat3 = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat4 = new Matrix; // create a Matrix in dynamic memory

    Matrix_init(mat, 3, 5);
    Matrix_init(mat2, 1, 1);
    Matrix_init(mat3, 500, 1);
    Matrix_init(mat4, 500, 500);

    ASSERT_EQUAL(Matrix_width(mat),3);
    ASSERT_EQUAL(Matrix_width(mat2),1);
    ASSERT_EQUAL(Matrix_width(mat3),500);
    ASSERT_EQUAL(Matrix_width(mat4),500);
    
    delete mat; // delete the Matrix
    delete mat2;
    delete mat3;
    delete mat4;

}

TEST(test_4_matrix_height) {
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat2 = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat3 = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat4 = new Matrix; // create a Matrix in dynamic memory

    Matrix_init(mat, 3, 5);
    Matrix_init(mat2, 1, 1);
    Matrix_init(mat3, 500, 1);
    Matrix_init(mat4, 500, 500);

    ASSERT_EQUAL(Matrix_height(mat),5);
    ASSERT_EQUAL(Matrix_height(mat2),1);
    ASSERT_EQUAL(Matrix_height(mat3),1);
    ASSERT_EQUAL(Matrix_height(mat4),500);
    
    delete mat; // delete the Matrix
    delete mat2;
    delete mat3;
    delete mat4;
}

TEST(test_5_matrix_row) {
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat2 = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat3 = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat4 = new Matrix; // create a Matrix in dynamic memory

    Matrix_init(mat, 3, 5);             // 5 rows, 3 columns
    Matrix_init(mat2, 1, 1);            // 1 row, 1 column
    Matrix_init(mat3, 1, 500);          // 500 rows, 1 column
    Matrix_init(mat4, 500, 500);        // 500 rows, 500 columns

    int *ptr = Matrix_at(mat,1,2);
    int *ptr2 = Matrix_at(mat2,0,0);
    int *ptr3 = Matrix_at(mat3,430,0);
    int *ptr4 = Matrix_at(mat4,499,3);

    
    ASSERT_EQUAL(Matrix_row(mat,ptr),1);
    ASSERT_EQUAL(Matrix_row(mat2,ptr2),0);
    ASSERT_EQUAL(Matrix_row(mat3,ptr3),430);
    ASSERT_EQUAL(Matrix_row(mat4,ptr4),499);

    delete mat; // delete the Matrix
    delete mat2;
    delete mat3;
    delete mat4;
}

TEST(test_6_matrix_column) {
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat2 = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat3 = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat4 = new Matrix; // create a Matrix in dynamic memory

    Matrix_init(mat, 3, 5);             // 5 rows, 3 columns
    Matrix_init(mat2, 1, 1);            // 1 row, 1 column
    Matrix_init(mat3, 1, 500);          // 500 rows, 1 column
    Matrix_init(mat4, 500, 500);        // 500 rows, 500 columns

    int *ptr = Matrix_at(mat,1,2);
    int *ptr2 = Matrix_at(mat2,0,0);
    int *ptr3 = Matrix_at(mat3,0,0);
    int *ptr4 = Matrix_at(mat4,499,499);

    
    ASSERT_EQUAL(Matrix_column(mat,ptr),2);
    ASSERT_EQUAL(Matrix_column(mat2,ptr2),0);
    ASSERT_EQUAL(Matrix_column(mat3,ptr3),0);
    ASSERT_EQUAL(Matrix_column(mat4,ptr4),499);

    delete mat; // delete the Matrix
    delete mat2;
    delete mat3;
    delete mat4;
}


TEST(test_7_matrix_at) {
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat2 = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat, 1, 2);
    Matrix_init(mat2, 1, 1);
    
    Matrix_fill(mat,-10000);
    Matrix_fill(mat2, 20);

    ASSERT_EQUAL(*Matrix_at(mat2,0,0),20);
    ASSERT_EQUAL(*Matrix_at(mat,1,0),-10000);

    
    delete mat; // delete the Matrix
    delete mat2;
}

TEST(test_8_matrix_fill) {
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    const int width = 3;
    const int height = 5;
    const int value = 42;
    
    Matrix_init(mat, 3, 5);
    Matrix_fill(mat, value);

    for(int r = 0; r < height; ++r){
        for(int c = 0; c < width; ++c){
            ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
        }
    }
    
    
    Matrix *mat2 = new Matrix; // create a Matrix in dynamic memory
    const int width2 = 1;
    const int height2 = 1;
    const int value2 = -293;

    Matrix_init(mat2, 1, 1);
    Matrix_fill(mat2,value2);

    for(int r = 0; r < height2; ++r){
        for(int c = 0; c < width2; ++c){
            ASSERT_EQUAL(*Matrix_at(mat2, r, c), value2);
        }
    }
    
    Matrix *mat3 = new Matrix; // create a Matrix in dynamic memory
    const int width3 = 500;
    const int height3 = 500;
    const int value3 = -0;

    Matrix_init(mat3, 500, 500);
    Matrix_fill(mat3,value3);

    for(int r = 0; r < height3; ++r){
        for(int c = 0; c < width3; ++c){
            ASSERT_EQUAL(*Matrix_at(mat3, r, c), value3);
        }
    }

    delete mat; // delete the Matrix
    delete mat2; // delete the Matrix
    delete mat3; // delete the Matrix
}

/*
TEST(test_9_matrix_fill_border) {
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    Matrix *mat2 = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat, 1, 2);
    Matrix_init(mat2, 1, 1);
    
    
    delete mat; // delete the Matrix
    delete mat2;
}
*/

TEST(test_10_matrix_max) {
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    Matrix_init(mat, 200, 200);
    int value = 10;
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; ++j) {
            *Matrix_at(mat, i, j) = value;
        }
        value = value + 10;
    }
    
    
    ASSERT_EQUAL(Matrix_max(mat), 2000);
    delete mat; // delete the Matrix
}



// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.hpp as needed.


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here

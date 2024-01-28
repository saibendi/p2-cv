// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.hpp"
#include "Image_test_helpers.hpp"
#include "unit_test_framework.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <fstream>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.

TEST(test_init_w_h) {
    Image *img = new Image; // create an Image in dynamic memory
    Image *img2 = new Image; // create an Image in dynamic memory
    Image *img3 = new Image; // create an Image in dynamic memory

    int width = 4;          // 4 rows of pixels
    int height = 4;         // 4 columns of pixels
    int width_2 = 1;
    int height_2 = 1;
    int width_3 = 500;          // edge case
    int height_3 = 500;

    Image_init(img, width, height);
    Image_init(img2, width_2, height_2);
    Image_init(img3, width_3, height_3);

    ASSERT_EQUAL(Image_width(img), 4);
    ASSERT_EQUAL(Image_height(img), 4);
    
    ASSERT_EQUAL(Image_width(img2), 1);
    ASSERT_EQUAL(Image_height(img2), 1);
    
    ASSERT_EQUAL(Image_width(img3), 500);
    ASSERT_EQUAL(Image_height(img3), 500);
    
    delete img; // delete the Image
    delete img2;
    delete img3; 
}

TEST(test_Image_init_istream_DOG_PPM) {
    string filename = "dog.ppm";
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "open failed" << endl;
    }
    string word;
    Pixel black = {0,0,0};
    Pixel white = {MAX_INTENSITY,MAX_INTENSITY,250};
    Image *img = new Image;

    while (fin >> word) {
        Image_init(img, fin);
    }
    cout << "Image height: " << Image_height(img) << endl;
    cout << "Image width: " << Image_width(img) << endl;

    for (int row = 0; row < Image_height(img); ++row) { // every row
        for (int column = 0; column < Image_width(img); ++column) { // at each column
            cout << *Matrix_at(&img->red_channel, row, column) << " ";
            cout << *Matrix_at(&img->green_channel, row, column) << " ";
            cout << *Matrix_at(&img->blue_channel, row, column) << " ";
        }
        cout << endl;     // end of every row
    }

    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 0), black),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 1), black),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 2), white),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 3), black),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 4), black),1);

    fin.close();
}

TEST(test_Image_init_istream_CRAB_PPM) {
    string filename = "crabster.ppm";
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "open failed" << endl;
    }
    string word;
    //Pixel black = {0,0,0};
    //Pixel white = {MAX_INTENSITY,MAX_INTENSITY,250};
    Image *img = new Image;

    while (fin >> word) {
        Image_init(img, fin);
    }
    cout << "Image width: " << Image_width(img) << endl;
    cout << "Image height: " << Image_height(img) << endl;
/*
    for (int row = 0; row < Image_height(img); ++row) { // every row
        for (int column = 0; column < Image_width(img); ++column) { // at each column
            cout << *Matrix_at(&img->red_channel, row, column) << " ";
            cout << *Matrix_at(&img->green_channel, row, column) << " ";
            cout << *Matrix_at(&img->blue_channel, row, column) << " ";
        }
        cout << endl;     // end of every row
    }

    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 0), black),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 1), black),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 2), white),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 3), black),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 4), black),1);
*/
    fin.close();
}

TEST(test_Image_init_istream_HORSES_PPM) {
    string filename = "horses.ppm";
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "open failed" << endl;
    }
    string word;
    //Pixel black = {0,0,0};
    //Pixel white = {MAX_INTENSITY,MAX_INTENSITY,250};
    Image *img = new Image;

    while (fin >> word) {
        Image_init(img, fin);
    }
    cout << "Image width: " << Image_width(img) << endl;
    cout << "Image height: " << Image_height(img) << endl;
/*
    for (int row = 0; row < Image_height(img); ++row) { // every row
        for (int column = 0; column < Image_width(img); ++column) { // at each column
            cout << *Matrix_at(&img->red_channel, row, column) << " ";
            cout << *Matrix_at(&img->green_channel, row, column) << " ";
            cout << *Matrix_at(&img->blue_channel, row, column) << " ";
        }
        cout << endl;     // end of every row
    }

    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 0), black),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 1), black),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 2), white),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 3), black),1);
    ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 4), black),1);
*/
    fin.close();
}

TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);


  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(test_image_fill) {
    Image *myImg = new Image;
    Image *answerImg = new Image;
    
    Pixel black = {0,0,0};

    Image_init(answerImg, 2, 2);
    Image_set_pixel(answerImg, 0, 0, black);
    Image_set_pixel(answerImg, 0, 1, black);
    Image_set_pixel(answerImg, 1, 0, black);
    Image_set_pixel(answerImg, 1, 1, black);

    Image_init(myImg, 2, 2);
    Image_fill(myImg,black);
    
    Image_equal(myImg, answerImg);
    for (int i = 0; i <2; ++i) {
        for (int j = 0; j <2; ++j) {
            Pixel_equal(Image_get_pixel(myImg, i, j), Image_get_pixel(answerImg, i, j));
        }
    }
}


// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.hpp as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here

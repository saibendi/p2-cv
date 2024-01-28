// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Image.hpp"

using namespace std;

// REQUIRES: img points to an Image
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, int width, int height) {
    // REQUIRES: img points to an Image
    assert(0 < width && width <= MAX_MATRIX_WIDTH);
    assert(0 < height && height <= MAX_MATRIX_HEIGHT);
    
    img->width = width;
    img->height = height;
    Matrix_init(&img->red_channel, width, height);
    Matrix_init(&img->green_channel, width, height);
    Matrix_init(&img->blue_channel, width, height);
}

// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, std::istream& is) {
    // REQUIRES: img points to an Image
    //assert(0 < img->width && img->width <= MAX_MATRIX_WIDTH);
    //assert(0 < img->height && img->height <= MAX_MATRIX_HEIGHT);
    // how can you assert these ^ without initializing?? Note it doesn't say "img points to a valid Image"
    //is contains an image in PPM format without comments (any kind of whitespace is ok)
    string PPM_type;
    int width;
    int height;
    int maxRGB;
    int r;
    int g;
    int b;
    is >> PPM_type;
    is >> width >> height >> maxRGB;
    img->width = width;
    img->height = height;
    Matrix_init(&img->red_channel, width, height);
    Matrix_init(&img->green_channel, width, height);
    Matrix_init(&img->blue_channel, width, height);
    for (int row = 0; row < height; ++row) { // every row
        for (int column = 0; column < width; ++column) { // every column
            is >> r;
            *Matrix_at(&img->red_channel, row, column) = r;
            is >> g;
            *Matrix_at(&img->green_channel, row, column) = g;
            is >> b;
            *Matrix_at(&img->blue_channel, row, column) = b;
        }
    }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Writes the image to the given output stream in PPM format.
//           You must use the kind of whitespace specified here.
//           First, prints out the header for the image like this:
//             P3 [newline]
//             WIDTH [space] HEIGHT [newline]
//             255 [newline]
//           Next, prints out the rows of the image, each followed by a
//           newline. Each pixel in a row is printed as three ints
//           for its red, green, and blue components, in that order. Each
//           int is followed by a space. This means that there will be an
//           "extra" space at the end of each line. See the project spec
//           for an example.
void Image_print(const Image* img, std::ostream& os) {
    // REQUIRES: img points to a valid Image
    assert(0 < img->width && img->width <= MAX_MATRIX_WIDTH);
    assert(0 < img->height && img->height <= MAX_MATRIX_HEIGHT);
    
    string PPM_type = "P3";
    
    os << PPM_type << endl;
    os << img->width << " " << img->height << endl;
    os << MAX_INTENSITY << endl;
    for (int row = 0; row < img->height; ++row) { // every row
        for (int column = 0; column < img->width; ++column) { // at each column
            os << *Matrix_at(&img->red_channel, row, column) << " ";
            os << *Matrix_at(&img->green_channel, row, column) << " ";
            os << *Matrix_at(&img->blue_channel, row, column) << " ";
        }
        os << endl;     // end of every row
    }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image* img) {
    // REQUIRES: img points to an Image
    assert(0 < img->width && img->width <= MAX_MATRIX_WIDTH);
    assert(0 < img->height && img->height <= MAX_MATRIX_HEIGHT);
    
    return img->width;
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image* img) {
    // REQUIRES: img points to an Image
    assert(0 < img->width && img->width <= MAX_MATRIX_WIDTH);
    assert(0 < img->height && img->height <= MAX_MATRIX_HEIGHT);
    
    return img->height;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image* img, int row, int column) {
    // REQUIRES: img points to an Image
    assert(0 < Image_width(img) && Image_width(img) <= MAX_MATRIX_WIDTH);
    assert(0 < Image_height(img) && Image_height(img) <= MAX_MATRIX_HEIGHT);
    // REQUIRES: row / column conditions
    assert(0 <= row && row < Image_height(img));
    assert(0 <= column && column < Image_width(img));
    
    int r = *Matrix_at(&img->red_channel, row, column);
    int g = *Matrix_at(&img->green_channel, row, column);
    int b = *Matrix_at(&img->blue_channel, row, column);
    
    Pixel output = {r,g,b};
    return output;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// MODIFIES: *img
// EFFECTS:  Sets the pixel in the Image at the given row and column
//           to the given color.
void Image_set_pixel(Image* img, int row, int column, Pixel color) {
    // REQUIRES: img points to an Image
    assert(0 < img->width && img->width <= MAX_MATRIX_WIDTH);
    assert(0 < img->height && img->height <= MAX_MATRIX_HEIGHT);
    // REQUIRES: row / column conditions
    assert(0 <= row && row < img->height);
    assert(0 <= column && column < img->width);
    
    // Matrix_init(mat,width,height);
    
    *Matrix_at(&img->red_channel, row, column) = color.r;
    *Matrix_at(&img->green_channel, row, column) = color.g;
    *Matrix_at(&img->blue_channel, row, column) = color.b;
}


// REQUIRES: img points to a valid Image
// MODIFIES: *img
// EFFECTS:  Sets each pixel in the image to the given color.
void Image_fill(Image* img, Pixel color) {
    // REQUIRES: img points to an Image
    assert(0 < img->width && img->width <= MAX_MATRIX_WIDTH);
    assert(0 < img->height && img->height <= MAX_MATRIX_HEIGHT);
    
    
    Matrix_fill(&img->red_channel, color.r);
    Matrix_fill(&img->green_channel, color.g);
    Matrix_fill(&img->blue_channel, color.b);
}


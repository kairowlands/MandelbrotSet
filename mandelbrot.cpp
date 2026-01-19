// Kai Rowlands
// Mandelbrot Set

#include <cmath>
#include <iostream>

using namespace std;

// Define the square of the modulus of a complex number z = x + iy
double ModulusSquared(double x, double y){
    return pow(x, 2.0) + pow(y, 2.0);
}

// Function that checks to see if a complex number is an element of the Mandelbrot set
bool Mandelbrot(double Rec, double Imc, int MaxIterations){
    int iteration = 0;                                      // Initialize the number of iterations
    double Rez = 0.0;                                       // Initialize the real part of z
    double Imz = 0.0;                                       // Initialize the imaginary part of z

    // Applies the Mandelbrot set function to the complex numbers which are elements of the set
    while(ModulusSquared(Rez, Imz) <= 4.0 && iteration < MaxIterations){
        double RealImage = pow(Rez, 2.0) - pow(Imz, 2.0) + Rec;             // Mandelbrot set function applied to Rez
        double ImaginaryImage = 2.0 * Rez * Imz + Imc;                      // Mandelbrot set function applied to Imz

        Rez = RealImage;        // The image of Rez under the Mandelbrot set function
        Imz = ImaginaryImage;   // The image of Imz under the Mandelbrot set function

        iteration++;
    }
    return iteration == MaxIterations;  // If the number of iterations is equal to the maximum number of iterations, then that complex number is an element of the Mandelbrot set
}

int main(){
    int height = 55;            // Define the height of the image in the terminal
    int width = 110;            // Define the width of the image in the terminal
    int MaxIterations = 1000;   // Define the maximum number of iterations

    double xMax = 1.0;  // Define the scale of the window in the terminal
    double xMin = -2.0;
    double yMax = 1.5;
    double yMin = -1.5;

    double dx = (xMax - xMin) / (width - 1.0);  // Define the change in values along the real axis
    double dy = (yMax - yMin) / (height - 1.0); // Define the change in values along the imaginary axis

    // Check to see if each pixel in the row is an element of the Mandelbrot set
    for(int i = 0; i < height; i++){
        // Check to see if each point in the column is an element of the Mandelbrot set
        for(int j = 0; j < width; j++){
            double x = xMin + j * dx;   // Map x-value pixels to the terminal
            double y = yMin + i * dy;   // Map y-value pixeles to the terminal

            if(Mandelbrot(x, y, MaxIterations)){
                cout << "*";                        // If a pixel is in the Mandelbrot set, then mark that pixel with a "*" in the terminal
            }
            else{
                cout << " ";    // If a pixel is not in the Mandelbrot set then mark that pixel with a " " in the terminal
            }
        }
        cout << endl;   // Repeat loop for each row of pixels
    }
    return 0;
}
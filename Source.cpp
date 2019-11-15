#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

//function declaration
double Mandelbrot (complex<double> c);


const int WIDTH = 800;
const int HEIGHT= 800;


int main() {
	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);
	complex <double> c;
	int num;


	for (double i = -2; i < 2; i+= .01)
		for (double j = -2; j < 2; j+= .01) {
			c = complex<double>(i, j);//converts the ij coordiante pair to a complex number
			num = Mandelbrot(c); //runs funtion through the mandelbrot function
			al_put_pixel(i*100+400, j*100+400, al_map_rgb(num*255,num+ 0,num/ 125));//use the output of the functionto determine color
			cout << "num is " << num << " at " << i * 100 + 400 << " " << j * 100 + 400 << endl;
			al_flip_display();
		}//end for loop

		system("pause");
		al_destroy_display(display);
} //end main


//function definition goes here
double Mandelbrot(complex<double> c) {
	complex <double> z = 0;
	int count = 0;
	while (abs(z)<2 && count <80){	
		z = z * z + c;
		count++;

	}
	return count;
}

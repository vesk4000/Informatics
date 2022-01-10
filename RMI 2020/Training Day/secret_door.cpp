#include <iostream>
#include <math.h>
#include "secret_point.h"
using namespace std;

void find_secret_point() {
	double dx = -1000, dy = 1000;/// Upper left corner
	double cx = 1000, cy = 1000;/// Upper right corner
	double ax = -1000, ay = -1000;/// Down left corner
	double bx = 1000, by = -1000;/// Down righ corner

	double d_x = get_distance(dx, dy);
	double c_x = get_distance(cx, cy);
	double a_x = get_distance(ax, ay);
	double b_x = get_distance(bx, by);
	
	double a_b = bx - ax;
	double p = (a_x + b_x + a_b) / 2;
	double sabx = sqrt( p * (p - a_x) * (p - b_x) * (p - a_b) );
	double hab = sabx * 2 / a_b;


	double a_d = dy - ay;
	p = (a_x + d_x + a_d) / 2;
	double sadx = sqrt( p * (p - a_x) * (p - d_x) * (p - a_d) );
	double had = sadx * 2 / a_d;

	the_secret_point_is(had - 1000, hab - 1000);
}



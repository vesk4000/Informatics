#include <iostream>
#include <vector>
#include <math.h>
#include "nice_lines.h"
using namespace std;

struct Point{
	long double x, y;

	Point operator- (Point p) {
		Point ans = {x - p.x, y - p.y};
		return ans;
	}
};

struct Circle : Point {
	long double radius;
};

struct Line {
	long double a, b, c;
}

vector<Line> get_tangent(Point C, long double r1, long double r2) {
	long double r = r2 - r1;
	long double z = sqrt(C.x) + sqrt(C.y);
	long double d = z - sqrt(r);
	d = sqrt(abs(d));
	Line l;
	l.a = (C.x * r + C.y * d) / z;
	l.b = (C.y * r - C.x * d) / z;
	l.c = r1;
	return l;
}

vector<Line> get_tangents(Circle A, Circle B) {
	vector<Line> ans;
	for(int i = -1; i <= 1; i += 2) {
		for(int j = -1; j <= 1; j += 2) {
			ans.push_back(get_tangents(B - A, A.radius * i, B.radius * j));
		}
	}
	
	for(int i = 0; i < ans.size(); ++i) {
		ans[i].c -= ans[i].a * A.x + ans[i].b * A.y;
	}

	return ans;
}

bool check_ans(int a, int b) {
	int x = 1;
	long double y = a * x + b;
	if(query(x, y) != 0)
		return false;
	
	x = 5;
	y = a * x + b;
	if(query(x, y) != 0)
		return false;

	return true;
}

void solve(int subtask_id, int N) {
	Circle A;
	A.x = -1e12;
	A.y = -1e12;
	A.radius = query(A.x, A.y);

	Circle C;
	C.x = 1e12;
	C.y = 1e12;
	C.radius = query(C.x, C.y);

	vector<Line> tangents = get_tangents(A, C);

	for(int i = 0; i < tangents.size(); ++i) {
		Line tan = tangents[i];
		int _a[2], _b[2], _c[2];
		_a[0] = ceil(tan.a);
		_a[1] = floor(tan.a);
		_b[0] = ceil(tan.b);
		_b[1] = floor(tan.b);
		_c[0] = ceil(tan.c);
		_c[1] = floor(tan.c);
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k) {
				for(int l = 0; l < 2; ++l) {
					if(check_ans(-_a[j]/_b[k], -_c[l])) {
						vector<int> asd;
						asd.push_back(-_a[j]/_b[k]);
						vector<int> basd;
						basd.push_back( -_c[l]);
						the_lines_are(asd, basd);
						return;
					}
				}
			}
		}
	}
}
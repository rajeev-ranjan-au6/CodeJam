Problem
There are N weighted points in a plane. Point i is at (Xi, Yi) and has weight Wi.

In this problem, we need to find a special center of these points. The center is a point (X, Y) such that the sum of max(|X-Xi|, |Y-Yi|)*Wi is minimum.

Input
The input starts with one line containing exactly one integer T, which is the number of test cases. T test cases follow.

Each test case begins with one line containing one integer N. N lines follow. Each line contains three space-separated real numbers Xi, Yi, and Wi. Xi, Yi and Wi have exactly 2 digits after the decimal point.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the sum of max(|X-Xi|, |Y-Yi|)*Wi for center (X, Y).

y will be considered correct if it is within an absolute or relative error of 10-6 of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.

Limits
1 ≤ T ≤ 10.
-1000.00 ≤ Xi ≤ 1000.00.
-1000.00 ≤ Yi ≤ 1000.00.
Small dataset
1 ≤ N ≤ 100;
Wi = 1.0, for all i.
Large dataset
1 ≤ N ≤ 10000;
1.0 ≤ Wi ≤ 1000.0, for all i.
Sample

Input
 	
Output
 
3
2
0.00 0.00 1.00
1.00 0.00 1.00
4
1.00 1.00 1.00
1.00 -1.00 1.00
-1.00 1.00 1.00
-1.00 -1.00 1.00
2
0.00 0.00 1.00
1.00 0.00 2.00

Case #1: 1.0
Case #2: 4.0
Case #3: 1.0



#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int MAGIC = 80;
const double MX = 1e3 + 5;

double x[N], y[N], w[N];
int n;

void read() {
	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		cin >> x[i] >> y[i] >> w[i];
	}
}

double coba(double tx, double ty) {
	double ret = 0;
	for(int i = 0 ; i < n ; i++)
		ret += w[i] * max(fabs(tx - x[i]), fabs(ty - y[i]));
	return ret;
}

double coba(double tx) {
	double lo = -MX, hi = MX;
	for(int i = 0 ; i < MAGIC ; i++) {
		double p1 = lo + (hi - lo) / 3;
		double p2 = lo + 2 * (hi - lo) / 3;

		if(coba(tx, p1) > coba(tx, p2)) {
			lo = p1;
		} else {
			hi = p2;
		}
	}
	return coba(tx, lo);
}

double solve() {
	double lo = -MX, hi = MX;
	for(int i = 0 ; i < MAGIC ; i++) {
		double p1 = lo + (hi - lo) / 3;
		double p2 = lo + 2 * (hi - lo) / 3;

		if(coba(p1) > coba(p2)) {
			lo = p1;
		} else {
			hi = p2;
		}
	}
	return coba(lo);
}

int main() {
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		read();
		double ret = solve();
		printf("Case #%d: %.9lf\n", tc, ret);
	}
	return 0;
}

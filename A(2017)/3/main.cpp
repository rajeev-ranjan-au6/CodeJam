Problem
"Look at the stars, look how they shine for you." - Coldplay, "Yellow"

In a galaxy far, far away, there are many stars. Each one is a sphere with a certain position (in three-dimensional space) and radius. It is possible for stars to overlap each other.

The stars are so incredibly beautiful to you that you want to capture them forever! You would like to build two cubes of the same integer edge length, and place them in space such that for each star, there is at least one cube that completely contains it. (It's not enough for a star to be completely contained by the union of the two cubes.) A star is completely contained by a cube if no point on the star is outside the cube; a point exactly on a cube face is still considered to be inside the cube.

The cubes can be placed anywhere in space, but they must be placed with their edges parallel to the coordinate axes. It is acceptable for the cubes to overlap stars or each other.

What is the minimum integer edge length that allows you to achieve this goal?

Input
The input starts with one line containing exactly one integer T, which is the number of test cases. T test cases follow.

Each test case begins with a line containing an integer, N, representing the number of stars.

This is followed by N lines. On the ith line, there are 4 space-separated integers, Xi, Yi, Zi and Ri, indicating the (X, Y, Z) coordinates of the center of the ith star, and the radius of the ith star.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum cube edge length that solves the problem, as described above.

Limits
1 ≤ T ≤ 100.
-108 ≤ Xi ≤ 108, for all i.
-108 ≤ Yi ≤ 108, for all i.
-108 ≤ Zi ≤ 108, for all i.
1 ≤ Ri ≤ 108, for all i.
Small dataset
1 ≤ N ≤ 16.
Large dataset
1 ≤ N ≤ 2000.
Sample

Input
 	
Output
 
3
3
1 1 1 1
2 2 2 1
4 4 4 1
3
1 1 1 2
2 3 4 1
5 6 7 1
3
1 1 1 1
1 1 1 1
9 9 9 1

Case #1: 3
Case #2: 5
Case #3: 2
In the first test case, one solution is to place two cubes with an edge length of 3 such that their corners with minimum (x, y, z) coordinates are at (0, 0, 0) and (3, 3, 3).
In the second test case, one solution is to place two cubes with an edge length of 5 such that their corners with minimum (x, y, z) coordinates are at (-1, -1, -1) and (1, 2, 3).



#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int x[2005], y[2005], z[2005], r[2005], n;
int xs[2], ys[2], zs[2];

bool can(int v, int a, int b, int c)
{
	int xl = xs[a], yl = ys[b], zl = zs[c];
	int xh = xl, yh = yl, zh = zl;
	if (a) xl -= v; else xh += v;
	if (b) yl -= v; else yh += v;
	if (c) zl -= v; else zh += v;
	vector<int> rem;
	for (int i = 0;i < n;i++) if (x[i]-r[i] < xl || x[i]+r[i] > xh || y[i]-r[i] < yl || y[i]+r[i] > yh || z[i]-r[i] < zl || z[i]+r[i] > zh) rem.push_back(i);
	if (rem.empty()) return true;
	xl = yl = zl = 1000000000;
	xh = yh = zh = -1000000000;
	for (int i: rem)
	{
		xl = min(xl, x[i]-r[i]);
		xh = max(xh, x[i]+r[i]);
		yl = min(yl, y[i]-r[i]);
		yh = max(yh, y[i]+r[i]);
		zl = min(zl, z[i]-r[i]);
		zh = max(zh, z[i]+r[i]);
	}
	return (xh-xl <= v && yh-yl <= v && zh-zl <= v);
}

bool can(int v)
{
	if (can(v, 0, 0, 0)) return true;
	if (can(v, 0, 0, 1)) return true;
	if (can(v, 0, 1, 0)) return true;
	if (can(v, 0, 1, 1)) return true;
	if (can(v, 1, 0, 0)) return true;
	if (can(v, 1, 0, 1)) return true;
	if (can(v, 1, 1, 0)) return true;
	if (can(v, 1, 1, 1)) return true;
	return false;
}

int solve()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d%d%d%d", x+i, y+i, z+i, r+i);
	xs[0] = ys[0] = zs[0] = 1000000000;
	xs[1] = ys[1] = zs[1] = -1000000000;
	for (int i = 0;i < n;i++)
	{
		xs[0] = min(xs[0], x[i]-r[i]);
		xs[1] = max(xs[1], x[i]+r[i]);
		ys[0] = min(ys[0], y[i]-r[i]);
		ys[1] = max(ys[1], y[i]+r[i]);
		zs[0] = min(zs[0], z[i]-r[i]);
		zs[1] = max(zs[1], z[i]+r[i]);
	}
	int lo = 1, hi = 1000000000;
	while (lo+1 < hi)
	{
		int mid = (lo+hi) / 2;
		if (can(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}

int main()
{
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);
		milliseconds start_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		printf("Case #%d: %d\n", _, solve());

		milliseconds end_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long long time_used = end_ti.count() - start_ti.count();
		fprintf(stderr, " done\t% 6lldms\n", time_used); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}

Problem
You are given a rectangular grid with N rows and M columns. Each cell of this grid is painted with one of two colors: green and white. Your task is to find the number of green cells in the largest Christmas tree in this grid.

To define a Christmas tree, first we define a good triangle as follows:

A good triangle with top point at row R, column C and height h (h > 0) is an isoceles triangle consisting entirely of green cells and pointing upward. Formally, this means that: The cell (R, C) is green, and for each i from 0 to h-1 inclusive, the cells in row R+i from column C-i to column C+i are all green.

For example:

..#..
.####
#####
is a good triangle with height 3. The # cells are green and the . cells are white. Note that there is a green cell that is not part of the good triangle, even though it touches the good triangle.

..#..
.###.
####.
is NOT a good triangle with height 3, because the 5th cell in the 3rd row is white. However, there are good triangles with height 2 present.

...#.
.###.
#####.
is NOT a good triangle with height 3. However, there are good triangles with height 2 present.

A K-Christmas tree is defined as follows:

It contains exactly K good triangles in vertical arrangement.
The top cell of the i+1-th triangle must share its top edge with the bottom edge of any one of the cells at the base of the i-th triangle. This means that, if the base of the i-th triangle is at row r, from column c1 to column c2, then the top of the i+1-th triangle must be on row r+1, in a column somewhere between c1 and c2, inclusive.
For example, if K = 2:

...#...
..###..
.#####.
#######
..#....
.###...
#####..
is a valid 2-Christmas tree. Note that the height of the 2 good triangles can be different.

..#..
.###.
.#...
is also a valid 2-Christmas tree. Note that a good triangle can be of height 1 and have only one green cell.

...#...
..###..
.#####.
.......
..#....
.###...
#####..
The two good triangles with height 3 does NOT form a valid 2-Christmas tree, because the 2nd triangle must starts from the 4-th row.

...#.
..###
.#...
###..
The two good triangles with height 2 does NOT form a valid 2-Christmas tree, because the top of the 2nd triangle must be in a column between 3 and 5, inclusive.

You need to find the K-Christmas tree with the largest number of green cells.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of three lines:

The first line contains 3 space-separated integers N, M and K, where N is the number of rows of the grid, M is the number of columns of the grid and K is the number of good triangle in the desired Christmas tree.
The next N lines each contain exactly M characters. Each character will be either . or #, representing a white or green cell, respectively.
Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of green cells in the largest K-Christmas tree. If there is no K-Christmas tree, output 0.

Limits
1 ≤ T ≤ 100.
1 ≤ M ≤ 100.
1 ≤ N ≤ 100.
Each cell in the grid is either . or #.

Small dataset
K = 1.

Large dataset
1 ≤ K ≤ 100.

Sample

Input
 	
Output
 
4
3 5 1
..#..
.###.
#####
3 5 1
.....
.....
.....
4 5 1
#####
#####
#####
#####
4 5 2
#####
#####
#####
#####

Case #1: 9
Case #2: 0
Case #3: 9
Case #4: 10

In sample case #1, the largest 1-Christmas tree has 9 green cells:

..#..
.###.
#####

In sample case #2, there is no 1-Christmas tree.

In sample case #3, one largest 1-Christmas tree with 9 green cells is:

#####
#####
#####
#####

In sample case #4, one largest 2-Christmas tree with 10 green cells is:

#####
#####
#####
#####



#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 1e9;

int n, m, k;
int dp[N][N][N];
string s[N];
int psum[N][N];

void read() {
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++) {
		cin >> s[i];
		s[i] = "." + s[i];
	}
}

void prepare() {
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m; j++)
			psum[i][j] = psum[i][j-1] + (s[i][j] == '#');
}

int DP() {
	for(int it = 1 ; it <= k ; it++) {
		for(int j = 1 ; j <= m ; j++)
			dp[it][n+1][j] = -INF;

		for(int i = n ; i >= 1 ;  i--)
			for(int j = 1 ; j <= m ; j++)
				if(s[i][j] == '.') {
					dp[it][i][j] = -INF;
				} else {
					dp[it][i][j] = -INF;
					for(int lvl = 0 ; i+lvl <= n ; lvl++) {
						int row = i+lvl;
						int kiri = j-lvl;
						int kanan = j+lvl;

						if(kiri < 1 || kanan > m || psum[row][kanan]-psum[row][kiri-1] != kanan-kiri+1) {
							break;
						}

						int add = (lvl+1)*(lvl+1);

						for(int x = kiri ; x <= kanan ; x++) {
							dp[it][i][j] = max(dp[it][i][j], add + dp[it-1][row+1][x]);
						}
					}
				}
	}

	int ret = 0;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			ret = max(ret, dp[k][i][j]);

	return ret;
}

int main() {
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		read();
		prepare();
		int ret = DP();
		printf("Case #%d: %d\n", tc, ret);
	}
	return 0;
}

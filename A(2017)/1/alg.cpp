Problem
Mr. Panda has recently fallen in love with a new game called Square Off, in which players compete to find as many different squares as possible on an evenly spaced rectangular grid of dots. To find a square, a player must identify four dots that form the vertices of a square. Each side of the square must have the same length, of course, but it does not matter what that length is, and the square does not necessarily need to be aligned with the axes of the grid. The player earns one point for every different square found in this way. Two squares are different if and only if their sets of four dots are different.

Mr. Panda has just been given a grid with R rows and C columns of dots. How many different squares can he find in this grid? Since the number might be very large, please output the answer modulo 109 + 7 (1000000007).

Input
The first line of the input gives the number of test cases, T. T lines follow. Each line has two integers R and C: the number of dots in each row and column of the grid, respectively.
Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of different squares can be found in the grid.
Limits
1 ≤ T ≤ 100.
Small dataset
2 ≤ R ≤ 1000.
2 ≤ C ≤ 1000.
Large dataset
2 ≤ R ≤ 109.
2 ≤ C ≤ 109.
Sample

Input
 	
Output
 
4
2 4
3 4
4 4
1000 500

Case #1: 3
Case #2: 10
Case #3: 20
Case #4: 624937395

The pictures below illustrate the grids from the three sample cases and a valid square in the third sample case.







#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int add(int x, int y){ return (x + y < MOD ? x + y : x + y - MOD); }
int mul(int x, int y){ return 1LL * x * y % MOD; }

int main(){
  int T; scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    int R, C; scanf("%d%d", &R, &C);
    R--; C--; if(R > C) swap(R, C);

    int v1 = R, v2 = R + 1, v3 = 1;
    if(v1 % 2 == 0) v1 /= 2; else v2 /= 2;

    int S1 = mul(v1, v2);

    v1 = R; v2 = R + 1; v3 = 2 * R + 1;
    if(v1 % 2 == 0) v1 /= 2; else v2 /= 2;
    if(v1 % 3 == 0) v1 /= 3; else if(v2 % 3 == 0) v2 /= 3; else v3 /= 3;

    int S2 = mul(mul(v1, v2), v3);

    int S3 = mul(S1, S1);

    int V1 = add(add(add(mul(R, C), R), C), 1);
    int V2 = R + C + 2;
    int V3 = 1;

    int M1 = mul(S1, V1);
    int M2 = mul(S2, V2);
    int M3 = mul(S3, V3);

    int ans = add(add(M1, MOD - M2), M3);

    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}

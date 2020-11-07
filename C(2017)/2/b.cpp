Problem
The hot new toy for this year is called "X Squared". It consists of a square N by N grid of tiles, where N is odd. Exactly 2 × N - 1 of the tiles are labeled with an X, and the rest are blank (which we will represent with the . character). In each move of the game, the player can either choose and exchange two rows of tiles, or choose and exchange two columns of tiles. The goal of the game is to get all of the X tiles to be on the two main diagonals of the grid, forming a larger X shape, as in the following example for N = 5:

X...X
.X.X.
..X..
.X.X.
X...X
You are about to play with your X Squared toy, which is not yet in the goal state. You suspect that your devious younger sibling might have moved some of the tiles around in a way that has broken the game. Given the current configuration of the grid, can you determine whether it is possible to win or not?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each one begins with one line with an integer N, the size of the grid. N more lines with N characters each follow; the j-th character on the i-th of these lines is X if the tile in the i-th row and j-th column of the grid has an X, or . if that tile is blank.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is POSSIBLE if it is possible to win, and IMPOSSIBLE otherwise.

Limits
1 ≤ T ≤ 100.
N mod 2 = 1. (N is odd.)
The grid has exactly 2 × N - 1 X tiles and exactly N2 - 2 × N + 1 . tiles.
The grid is not already in the goal state, as described in the problem statement.
Small dataset
3 ≤ N ≤ 5.
Large dataset
3 ≤ N ≤ 55.
Sample

Input
 	
Output
 
2
3
..X
XX.
XX.
3
...
XXX
XX.

Case #1: POSSIBLE
Case #2: IMPOSSIBLE

In Sample Case #1, one winning strategy is:

Swap the top row with the middle row.
Swap the rightmost column with the middle column.
 ..X    XX.    X.X
 XX. -> ..X -> .X.
 XX.    XX.    X.X
In Sample Case #2, no sequence of moves can turn the grid into the desired final configuration.



//spnauT
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int _=b,i=a;i<_;++i)
#define ROF(i,b,a) for(int _=a,i=b;i>_;--i)
#define REP(n) for(int _=(n);_--;)
#define _1 first
#define _2 second
#define PB push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue<T>
#define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
#define IO {ios_base::sync_with_stdio(0);cin.tie(0);}
#define nl '\n'
#define cint1(a) int a;cin>>a
#define cint2(a,b) int a,b;cin>>a>>b
#define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
using namespace std;using LL=int64_t;using PII=pair<int,int>;
using VI=vector<int>;using VL=vector<LL>;using VP=vector<PII>;
template<class A,class B>bool mina(A&x,B&&y){return y<x?(x=forward<B>(y),1):0;}
template<class A,class B>bool maxa(A&x,B&&y){return x<y?(x=forward<B>(y),1):0;}

const int MAX_N {60};

char B[MAX_N][MAX_N];
int RN[MAX_N];
int CN[MAX_N];

int main()
{
	IO;
	cint1(QQ);
	FOR(Q,1,QQ+1)
	{
		cint1(N);
		FOR(i,0,N) cin >> B[i];
		int n {0};

		MSET(RN,0);
		MSET(CN,0);

		FOR(i,0,N) FOR(j,0,N) if(B[i][j] == 'X')
		{
			++n;
			++RN[i];
			++CN[j];
		}

		bool ok {false};

		int r1 {-1}, c1 {-1};
		if(n != 2*N - 1) goto end1;

		FOR(i,0,N)
		{
			if(RN[i] == 0 or RN[i] > 2 or CN[i] == 0 or CN[i] > 2) goto end1;
			if(RN[i] == 1) r1 = i;
			if(CN[i] == 1) c1 = i;
		}
		if(r1 == -1 or c1 == -1) goto end1;
		if(B[r1][c1] != 'X') goto end1;

		B[r1][c1] = '.';

		FOR(i,0,N) FOR(j,0,N) if(B[i][j] == 'X')
		{
			int ii {-1}, jj {-1};
			FOR(k,0,N)
			{
				if(k != i and B[k][j] == 'X') ii = k;
				if(k != j and B[i][k] == 'X') jj = k;
			}
			if(ii == -1 or jj == -1 or B[ii][jj] != 'X') goto end1;
			B[i][j] = B[i][jj] = B[ii][j] = B[ii][jj] = '.';
		}

		ok = true;
	end1:
		cout << "Case #" << Q << ": ";
		if(not ok) cout << "IM";
		cout << "POSSIBLE" << nl;
	}

	return 0;
}

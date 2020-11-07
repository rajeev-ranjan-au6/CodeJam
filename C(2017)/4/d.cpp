Problem
The 4M Corporation has hired you to organize their departments and allocate headcount. You will create at least one department, and each department will receive some positive integer number of employees. It will not be easy, though — you have four different bosses, and each has given you a different instruction:

The department with the fewest employees must have exactly MINIMUM employees.
The department with the most employees must have exactly MAXIMUM employees.
The average number of employees across all departments must be exactly MEAN.
The median of the number of employees across all departments must be exactly MEDIAN. As a reminder, the median of a list is the value that, when the list is sorted in nondecreasing order, is in the center (for a list of odd length) or is the average of the two values in the center (for a list of even length).
Moreover, for the sake of efficiency, it is best to avoid creating too many departments. What is the smallest number of departments that you can create, if it is possible to satisfy your bosses' requests?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each consists of four integers: MINIMUM, MAXIMUM, MEAN, and MEDIAN, in that order.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1), and y is either the minimum possible number of departments, or IMPOSSIBLE if it is impossible to satisfy all four bosses' requests.

Limits
1 ≤ T ≤ 100.
Small dataset
1 ≤ MINIMUM ≤ 8.
1 ≤ MAXIMUM ≤ 8.
1 ≤ MEAN ≤ 8.
1 ≤ MEDIAN ≤ 8.
The constraints for the Small dataset guarantee that the answer is either IMPOSSIBLE or is less than 14.
Large dataset
1 ≤ MINIMUM ≤ 10000.
1 ≤ MAXIMUM ≤ 10000.
1 ≤ MEAN ≤ 10000.
1 ≤ MEDIAN ≤ 10000.
Sample

Input
 	
Output
 
5
6 4 5 1
7 7 8 8
2 2 2 2
3 7 5 5
1 4 3 4

Case #1: IMPOSSIBLE
Case #2: IMPOSSIBLE
Case #3: 1
Case #4: 2
Case #5: 3

Sample Case #1 is IMPOSSIBLE because the maximum value cannot be smaller than the minimum value.

Sample Case #2 is IMPOSSIBLE because the mean and median cannot be larger than the maximum value.

In Sample Case #3, you can create a single department with 2 employees. This satisfies all four bosses: the department with the fewest employees has exactly 2, the department with the most employees has exactly 2, and the mean and median are both 2.

In Sample Case #4, you can create one department with 3 employees and another department with 7 employees. Note that it would not suffice to create only one department with 5 employees, because then the department with the fewest employees would not have exactly 3 and the department with the most employees would not have exactly 7.
For Sample Case #5, you can create one department with 1 employee and two more departments with 4 employees each.

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

const int MAX_N {4};
const int MAX_Q {52};
const string ANS {"TF"};

string A[MAX_N];
int S[MAX_N];

int dp[MAX_Q][MAX_Q][MAX_Q];

int main()
{
	IO;
	cint1(TT);
	FOR(T,1,TT+1)
	{
		cint2(xmin, xmax);
		cint2(xavg, xmed);
		int sol {0};
		if(xmin == xmax and xmin == xavg and xmin == xmed)
			sol = 1;
		else if(xmin > xmed or xmed > xmax or xavg < xmin or xavg > xmax or
		  (xmax > xmin and (xavg == xmin or xavg == xmax)))
			sol = -1;
		else
		{
			FOR(n,2,1e7)
			{
				bool ok {false};
				if(n == 2 and xmin + xmax == xmed*2 and xmed == xavg)
				{
					ok = true;
				}
				else if(n >= 3)
				{
					LL k {(n-3) / 2};
					LL need {LL(n) * xavg};
					LL sum0 {xmin + xmax + xmed * ((n & 1) ? 1 : 2)};
					LL sum_lo {sum0 + k * (xmin + xmed)};
					LL sum_hi {sum0 + k * (xmed + xmax)};
					ok = sum_lo <= need and need <= sum_hi;
				}
				if(ok)
				{
					sol = n;
					break;
				}
			}
			if(sol <= 0) cerr << "not found for #" << T << nl;
		}

		cout << "Case #" << T << ": ";
		if(sol > 0) cout << sol;
		else cout << "IMPOSSIBLE";
		cout << nl;
	}

	return 0;
}

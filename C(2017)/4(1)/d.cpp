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
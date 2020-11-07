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
		cint2(N,Q);
		FOR(i,0,N+1) cin >> A[i];
		FOR(i,0,N) cin >> S[i];
		if(N == 1)
		{
			N = 2;
			A[2] = move(A[1]);
			A[1] = A[0];
			S[1] = S[0];
		}

		MSET(dp,-1);
		dp[0][0][0] = 0;
		int v;
		FOR(q,0,Q) FOR(i,0,Q) FOR(j,0,Q) if((v = dp[q][i][j]) >= 0) for(char a: ANS)
		{
			maxa(dp[q + 1][i + (a==A[0][q])][j + (a==A[1][q])], v + (a==A[2][q]));
		}

		int sol {dp[Q][S[0]][S[1]]};
		cout << "Case #" << T << ": " << sol << nl;
	}

	return 0;
}
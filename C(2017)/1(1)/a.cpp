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

const int MAX_N {};

string S, T;

int main()
{
	IO;
	cint1(QQ);
	FOR(Q,1,QQ+1)
	{
		cin >> S;
		int N = SZ(S);
		if(N & 1) T = "AMBIGUOUS";
		else
		{
			T.resize(N);
			for(int i = 1; i < N; i += 2)
			{
				int c {S[i-1] - 'A'};
				if(i > 1) c -= T[i-2] - 'A';
				T[i] = (c + 26) % 26 + 'A';
			}

			for(int i = N-2; i >= 0; i -= 2)
			{
				int c {S[i+1] - 'A'};
				if(i < N-2) c -= T[i+2] - 'A';
				T[i] = (c + 26) % 26 + 'A';
			}
		}
		cout << "Case #" << Q << ": " << T << nl;
	}

	return 0;
}
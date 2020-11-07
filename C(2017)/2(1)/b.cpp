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
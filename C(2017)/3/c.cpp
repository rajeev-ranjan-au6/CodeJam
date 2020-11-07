Problem
You and N of your friends just took the B.A.T. (Binary Answer Test) to try to get into wizard school. The B.A.T. has Q true-false questions, and each one is worth 1 point. You have no wizard powers, so you just picked arbitrary answers and hoped for the best.

The results of the test have already been sent out by quail mail, but the quail with your results has not arrived yet. However, each of your friends has told you their list of answers and their total score. You also remember your own list of answers. You are an optimist and you think that you probably did well!

Given that there is one correct list of answers (but you do not know what those answers are), and given your friends' answers and scores, what is the highest score that you possibly could have achieved?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each begins with one line with two integers N and Q. Then, N+1 lines follow; the i-th of these lines represents the i-th examinee's list of answers Ai, and has Q characters, each of which is either T or F (representing True or False). AN+1 is your own list of answers. Finally, one line with N integers follows; the i-th of these integers, Si, represents the i-th examinee's score. (Note that your own score is not in this list, because it is unknown.)

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the highest score that you possibly could have achieved that is consistent with the given information.

Limits
1 ≤ T ≤ 100.
The length of Ai is Q, for all i.
Each character of Ai is either T or F, for all i.
0 ≤ Si ≤ Q.
It is guaranteed that there is at least one possible list of correct answers that is consistent with all of the friends' answers and scores.
Small dataset
N = 1.
1 ≤ Q ≤ 10.
Large dataset
1 ≤ N ≤ 2.
1 ≤ Q ≤ 50.
Sample

Input
 	
Output
 
3
1 2
TF
FF
1
1 3
TTT
TTF
0
2 3
TTF
FTF
TTT
1 2

Case #1: 2
Case #2: 1
Case #3: 2

Note that the last sample case would not appear in the Small dataset.

In sample case #1, your friend answered TF and you answered FF, and exactly one of your friend's answers was right. If your friend was wrong on question 1 and right on question 2, then the real set of answers is FF and you got both questions right. It is impossible to do better than this!

In sample case #2, your friend answered all Ts and got all of the questions wrong, so the real set of answers must be all Fs, which means that you got only question 3 right.

In sample case #3, the only possible real lists of answers that are consistent with the given information are FTT and FFF. (For example, the real answer list cannot be TFT; the first friend's answers and score would be consistent with that, but the second friend would have scored 0 instead of 2.) Of these two possibilities, FTT is more favorable to you and would give you a score of 2.

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

Problem
Alice likes reading and buys a lot of books. She stores her books in two boxes; each box is labeled with a pattern that matches the titles of all of the books stored in that box. A pattern consists of only uppercase/lowercase English alphabet letters and stars (*). A star can match between zero and four letters. For example, books with the titles GoneGirl and GoneTomorrow can be put in a box with the pattern Gone**, but books with the titles TheGoneGirl, and GoneWithTheWind cannot.

Alice is wondering whether there is any book that could be stored in either of the boxes. That is, she wonders if there is a title that matches both boxes' patterns.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each consists of two lines; each line has one string in which each character is either an uppercase/lowercase English letter or *.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is TRUE if there is a string that matches both patterns, or FALSE if not.

Limits
1 ≤ T ≤ 50.
Small dataset
1 ≤ the length of each pattern ≤ 200.
Each pattern contains at most 5 stars.
Large dataset
1 ≤ the length of each pattern ≤ 2000.
Sample

Input
 	
Output
 
3
****
It
Shakes*e
S*speare
Shakes*e
*peare

Case #1: TRUE
Case #2: TRUE
Case #3: FALSE


In sample case #1, the title It matches both patterns. Note that it is possible for a * to match zero characters.

In sample case #2, the title Shakespeare matches both patterns.

In sample case #3, there is no title that matches both patterns. Shakespeare, for example, does not work because the * at the start of the *peare pattern cannot match six letters.



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

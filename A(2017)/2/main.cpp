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

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

char s1[8005], s2[8005], buf[2005];
bool can[8005][8005];
int n, m;

int rd(char *ptr)
{
	int sz = 0;
	scanf("%s", buf);
	for (int i = 0;buf[i];i++)
	{
		if (buf[i] != '*') *(ptr++) = buf[i], sz++;
		else
		{
			*(ptr++) = '*';
			*(ptr++) = '*';
			*(ptr++) = '*';
			*(ptr++) = '*';
			sz += 4;
		}
	}
	*ptr = 0;
	return sz;
}

const char* solve()
{
	n = rd(s1); m = rd(s2);
	for (int i = 0;i <= n;i++) for (int j = 0;j <= m;j++) can[i][j] = false;
	can[0][0] = true;
	for (int i = 0;i <= n;i++) for (int j = 0;j <= m;j++) if (can[i][j])
	{
		if (s1[i] == s2[j] || s1[i] == '*' || s2[j] == '*') can[i+1][j+1] = true;
		if (s1[i] == '*') can[i+1][j] = true;
		if (s2[j] == '*') can[i][j+1] = true;
	}
	if (can[n][m]) return "TRUE";
	return "FALSE";
}

int main()
{
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);
		milliseconds start_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		printf("Case #%d: %s\n", _, solve());

		milliseconds end_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long long time_used = end_ti.count() - start_ti.count();
		fprintf(stderr, " done\t% 6lldms\n", time_used); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}

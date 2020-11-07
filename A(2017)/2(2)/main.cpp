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

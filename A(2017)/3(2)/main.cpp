#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int x[2005], y[2005], z[2005], r[2005], n;
int xs[2], ys[2], zs[2];

bool can(int v, int a, int b, int c)
{
	int xl = xs[a], yl = ys[b], zl = zs[c];
	int xh = xl, yh = yl, zh = zl;
	if (a) xl -= v; else xh += v;
	if (b) yl -= v; else yh += v;
	if (c) zl -= v; else zh += v;
	vector<int> rem;
	for (int i = 0;i < n;i++) if (x[i]-r[i] < xl || x[i]+r[i] > xh || y[i]-r[i] < yl || y[i]+r[i] > yh || z[i]-r[i] < zl || z[i]+r[i] > zh) rem.push_back(i);
	if (rem.empty()) return true;
	xl = yl = zl = 1000000000;
	xh = yh = zh = -1000000000;
	for (int i: rem)
	{
		xl = min(xl, x[i]-r[i]);
		xh = max(xh, x[i]+r[i]);
		yl = min(yl, y[i]-r[i]);
		yh = max(yh, y[i]+r[i]);
		zl = min(zl, z[i]-r[i]);
		zh = max(zh, z[i]+r[i]);
	}
	return (xh-xl <= v && yh-yl <= v && zh-zl <= v);
}

bool can(int v)
{
	if (can(v, 0, 0, 0)) return true;
	if (can(v, 0, 0, 1)) return true;
	if (can(v, 0, 1, 0)) return true;
	if (can(v, 0, 1, 1)) return true;
	if (can(v, 1, 0, 0)) return true;
	if (can(v, 1, 0, 1)) return true;
	if (can(v, 1, 1, 0)) return true;
	if (can(v, 1, 1, 1)) return true;
	return false;
}

int solve()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d%d%d%d", x+i, y+i, z+i, r+i);
	xs[0] = ys[0] = zs[0] = 1000000000;
	xs[1] = ys[1] = zs[1] = -1000000000;
	for (int i = 0;i < n;i++)
	{
		xs[0] = min(xs[0], x[i]-r[i]);
		xs[1] = max(xs[1], x[i]+r[i]);
		ys[0] = min(ys[0], y[i]-r[i]);
		ys[1] = max(ys[1], y[i]+r[i]);
		zs[0] = min(zs[0], z[i]-r[i]);
		zs[1] = max(zs[1], z[i]+r[i]);
	}
	int lo = 1, hi = 1000000000;
	while (lo+1 < hi)
	{
		int mid = (lo+hi) / 2;
		if (can(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}

int main()
{
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);
		milliseconds start_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		printf("Case #%d: %d\n", _, solve());

		milliseconds end_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long long time_used = end_ti.count() - start_ti.count();
		fprintf(stderr, " done\t% 6lldms\n", time_used); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}

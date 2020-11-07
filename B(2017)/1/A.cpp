Problem
Professor Math is working on a secret project and is facing a challenge where a list of numbers need to be encoded into a single number in the most efficient manner. After much research, Professor Math finds a 3 step process that can best encode the numbers:

The first step is to find all possible non-empty subsets of the list of numbers and then, for each subset, find the difference between the largest and smallest numbers (that is, the largest minus the smallest) in that subset. Note that if there is only one number in a subset, it is both the largest and the smallest number in that subset. The complete set itself is also considered a subset.
Then add up all the differences to get the final encoded number.
As the number may be large, output the number modulo 109 + 7 (1000000007).
The professor has shared an example and its explanation below. Given a list of numbers, can you help the professor build an efficient function to compute the final encoded number?

Input
The first line of the input gives the number of test cases, T. This is followed by T test cases where each test case is defined by 2 lines:

The first line gives a positive number N: the number of numbers in the list and
The second line contains a list of N positive integers Ki, sorted in non-decreasing order.
Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the final encoded number.

Since the output can be a really big number, we only ask you to output the remainder of dividing the result by the prime 109 + 7 (1000000007).

Limits
1 ≤ T ≤ 25.
1 ≤ Ki ≤ 10000, for all i.
Ki ≤ Ki+1, for all i < N - 1.
Small dataset
1 ≤ N ≤ 10.

Large dataset
1 ≤ N ≤ 10000.

Sample

Input
 	
Output
 
1
4
3 6 7 9

Case #1: 44

Explanation for the sample input
Find all subsets and get the difference between largest & smallest numbers:
[3], largest-smallest = 3 - 3 = 0.
[6], largest-smallest = 6 - 6 = 0.
[7], largest-smallest = 7 - 7 = 0.
[9], largest-smallest = 9 - 9 = 0.
[3, 6], largest-smallest = 6 - 3 = 3.
[3, 7], largest-smallest = 7 - 3 = 4.
[3, 9], largest-smallest = 9 - 3 = 6.
[6, 7], largest-smallest = 7 - 6 = 1.
[6, 9], largest-smallest = 9 - 6 = 3.
[7, 9], largest-smallest = 9 - 7 = 2.
[3, 6, 7], largest-smallest = 7 - 3 = 4.
[3, 6, 9], largest-smallest = 9 - 3 = 6.
[3, 7, 9], largest-smallest = 9 - 3 = 6.
[6, 7, 9], largest-smallest = 9 - 6 = 3.
[3, 6, 7, 9], largest-smallest = 9 - 3 = 6.
Find the sum of the differences calculated in the previous step:
3+4+6+1+3+2+4+6+6+3+6
= 44.
Find the answer modulo 109 + 7 (1000000007):
44 % 1000000007 = 44

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e4 + 5;

int po[N];
int arr[N];
int n;

void precompute() {
	po[0] = 1;
	for(int i = 1 ; i < N ; i++) {
		po[i] = 2 * po[i-1] % MOD;
	}
}

void read() {
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d", arr + i);
}

int solve() {
	int ret = 0;
	for(int i = 1 ; i <= n ; i++) {
		int kiri = i-1;
		int kanan = n-i;

		long long tambah = 1ll * po[kiri] * (arr[i]) % MOD;
		long long kurang = 1ll * po[kanan] * (-arr[i]) % MOD;

		ret = (ret + tambah) % MOD;
		ret = (ret + kurang) % MOD;
	}

	if(ret < 0) ret += MOD;
	return ret;
}

int main() {
	precompute();
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		read();
		int ret = solve();
		printf("Case #%d: %d\n", tc, ret);
	}
	return 0;
}

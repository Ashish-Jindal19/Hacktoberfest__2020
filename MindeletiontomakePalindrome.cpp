#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
int dp[102][102];

/*TOP-DOWN APPROACH
int LCS_check(string s1, string s2, int l1, int l2) {
	if (l1 == 0 || l2 == 0)
		dp[l1][l2] = 0;
	else if (dp[l1][l2] != -1)
		return dp[l1][l2];
	else if (s1[l1 - 1] == s2[l2 - 1])
		dp[l1][l2] = 1 + LCS_check(s1, s2, l1 - 1, l2 - 1);
	else
		dp[l1][l2] = max(LCS_check(s1, s2, l1 - 1, l2), LCS_check(s1, s2, l1, l2 - 1));
	return dp[l1][l2];
}*/
int main() {
	std::ios::sync_with_stdio(false);
	int T, l1;
	cin >> T;
	string s1, s2;
// cin.ignore(); must be there when using getline(cin, s)
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		cin >> s1;
		s2 = s1;
		reverse(s1.begin(), s1.end());
		l1 = s1.length();
		//BOTTOM-UP APROACH
		for (int i = 1; i <= l1; i++) {
			for (int j = 1; j <= l1; j++) {
				if (s1[i - 1] == s2[j - 1])
				{
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
		//cout << LCS_check(s1, s2, l1, l2) << '\n';
		cout << l1 - dp[l1][l1] << '\n';
	}
	return 0;
}

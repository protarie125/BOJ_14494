#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;

constexpr auto kMod = ll{1'000'000'007};

ll n, m;
vvl dp;

ll solve(ll a, ll b) {
  if (a == 1 || b == 1) {
    return 1;
  }

  if (dp[a][b] < 0) {
    dp[a][b] = solve(a - 1, b) + solve(a, b - 1) + solve(a - 1, b - 1);
    dp[a][b] %= kMod;
  }

  return dp[a][b];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;
  dp = vvl(n + 1, vl(m + 1, -1));

  cout << solve(n, m);

  return 0;
}
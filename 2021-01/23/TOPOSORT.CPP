
// https://www.spoj.com/problems/TOPOSORT/

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> v[], int a, int b) {
	v[a].push_back(b);
	// v[b].push_back(a);
}

int main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n, m, a, b;
	cin >> n >> m;

	vector<int> v[n + 1];

	while (m--) {
		cin >> a >> b;
		addEdge(v, a, b);
	}

	// for (int i = 1; i <= n; i++) {
	// 	sort(v[i].begin(), v[i].end());
	// }

	vector<int> ans, count(n + 1, 0);
	priority_queue<int, vector<int>, greater<int> > q;

	for (int i = 1; i <= n; i++) {
		for (auto j : v[i]) {
			count[j]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (count[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int temp = q.top();
		q.pop();

		ans.push_back(temp);

		for (auto i : v[temp]) {
			count[i] = max(count[i] - 1, -1);
			if (count[i] == 0) {
				q.push(i);
			}
		}
	}

	if (ans.size() != n) {
		cout << "Sandro fails.";
		return 0;
	}

	for (auto i : ans) {
		cout << i << " ";
	}

	return 0;
}
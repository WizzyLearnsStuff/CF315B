#include<iostream>
#include<vector>

using namespace std;

// Observation 1: worst case input needs 10^10 steps (2 sec time exceeded)
// Observation 2: The increment operation increments all elements (common data)
// Observation 3: Not all elements are outputted necessarily
// Conclusion: Lazy programming

int main() {
	int n, m;
	cin >> n >> m;

	long long int inc = 0;
	vector<long long int> v(n);
	for (long long int &e : v) cin >> e;

	for (int i = 0; i < m; i++) {
		char t;
		cin >> t;

		if (t == '1') {
			int idx, val;
			cin >> idx >> val;
			val -= inc;
			v[idx - 1] = val;
		} else if (t == '2') {
			int k;
			cin >> k;
			inc += k;
		} else if (t == '3') {
			int p;
			cin >> p;
			cout << v[--p] + inc << '\n';
		}
		else cerr << "Read char : '" << t << '\'';
	}
}

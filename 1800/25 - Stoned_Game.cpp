#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int &x : a) cin >> x;

		int maxPile = *max_element(a.begin(), a.end());
		int numStones = accumulate(a.begin(), a.end(), 0);

		if (maxPile * 2 > numStones || (numStones & 1)) cout << "T" << endl;
		else cout << "HL" << endl;
	}
}
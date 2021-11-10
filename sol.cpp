#include <bits/stdc++.h>

using namespace std;

struct Crew {
	string name;
	int index;
	int rank;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	// determine the rank of a person
	// note: woman and child have the same rank
	auto GetRank = [](string status) {
		status = (status == "woman" || status == "child" ? "woman/child" : status);
		string members[] = {"rat", "woman/child", "man", "captain"};
		for (int i = 0; i < 4; i++) {
			if (members[i] == status) {
				return (i + 1);
			}
		}
		return -1;
	};
	// input
	vector<Crew> vec(n);
	for (int i = 0; i < n; i++) {
		string status;
		cin >> vec[i].name >> status;
		vec[i].index = i;
		vec[i].rank = GetRank(status);
	}
	// sort the crew members based on conditions in the problem statement
	// if two people have the same rank, then compare their indices
	sort(vec.begin(), vec.end(), [](Crew a, Crew b) {
		if (a.rank == b.rank) {
			return a.index < b.index;
		} else {
			return a.rank < b.rank;
		}
	});
	// output (only the names)
	for (int i = 0; i < n; i++) {
		cout << vec[i].name << '\n';
	}
	return 0;
}

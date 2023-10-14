//https://stepik.org/lesson/13262/step/4?unit=3447

class Stairs {
private:
	struct TestCase
	{
		vector<int> inp;
		int res;
	};

	int solveBU(const vector<int>& v) {
		int sz = v.size();
		int cost1 = 0;
		int cost2 = v[0];

		for (int i = 1; i < sz; i++) {
			int mx = max(cost1, cost2) + v[i];
			cost1 = cost2;
			cost2 = mx;
		}

		return cost2;
	}

	int solveUD(const vector<int>& v, vector<int> &c, int idx) {
		if (idx < 0) {
			return 0;
		}

		if (c[idx] == -10e5) {
			int val1 = solveUD(v, c, idx - 1);
			int val2 = solveUD(v, c, idx - 2);

			c[idx] = v[idx] + max(val1, val2);
		}

		return c[idx];
	}

	int solve(const vector<int>& v) {
		int sz = v.size();
		int idx = sz - 1;
		vector<int> c(sz, -10e5);

		return solveUD(v, c, idx);
	}

public:
	void Test() {
		vector<TestCase> testCases = {
			{ { 1, 2 }, 3 },
			{ { 2, -1 } , 1 },
			{ { -1, 2, 1 }, 3 },
			{ { -2, -16, -13, -9, -48 }, -63 },
			{ { 1, 1, -2, -4, -6, 2, 2 }, 2 },
			{ { -64, -16, -13, -9, -48 }, -73 }
		};

		for (int i = 0; i < testCases.size(); i++) {
			int sol = solve(testCases[i].inp);
			if (testCases[i].res != sol) {
				cout << "UD FAIL #" << i << endl;
			}

			sol = solveBU(testCases[i].inp);
			if (testCases[i].res != sol) {
				cout << "BU FAIL #" << i << endl;
			}
		}
	}

	void IO() {
		int sz;
		cin >> sz;

		vector<int> c(sz);
		for (int i = 0; i < sz; i++) {
			cin >> c[i];
		}

		cout << solveBU(c) << endl;
	};
};
class Calculator {
	struct TestCase {
		int inp;
		int out;
	};

	vector<int> solveBU(int n) {
		vector<int> v(n + 1);
		v[0] = 10e6;
		v[1] = 0;

		for (int i = 2; i <= n; i++) {
			int i1, i2, i3;
			i % 3 == 0 ? i1 = i / 3 : i1 = 0;
			i % 2 == 0 ? i2 = i / 2 : i2 = 0;
			i3 = i - 1;

			v[i] = min(v[i1], min(v[i2], v[i3])) + 1;
		}

		vector<int> res;
		int i = n;
		res.push_back(i);
		int len = v[i] - 1;
		while (i > 1) {
			int idx1, idx2, idx3;
			i % 3 == 0 ? idx1 = i / 3 : idx1 = 0;
			i % 2 == 0 ? idx2 = i / 2 : idx2 = 0;
			idx3 = i - 1;
			if (v[idx1] == len) {
				i = idx1;
			}
			else if (v[idx2] == len) {
				i = idx2;
			}
			else {
				i = idx3;
			}
			res.push_back(i);
			len--;
		}
		reverse(res.begin(), res.end());

		return res;
	}

public:
	void Test() {
		vector<TestCase> testCases = {
			{ 1, 0 },
			{ 5, 3 },
			{ 96234, 14 }
		};

		for (auto tc : testCases) {
			cout << "inp : " << tc.inp << endl;
			cout << "out : " << tc.out << endl;
			cout << "res : " << solveBU(tc.inp).size() - 1 << endl;
			assert(solveBU(tc.inp).size() - 1 == tc.out);
		}
		cout << "Test Passes" << endl;
	}

	void IO() {
		int n;
		cin >> n;
		auto res = solveBU(n);
		cout << res.size() - 1 << endl;
		for (auto i : res) {
			cout << i << " ";
		}
	}
};
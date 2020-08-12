#include <iostream>
#include <vector>
using namespace std;

class Solver {
	string s;
	vector<long long> h1, h2;
	vector<long long> power1, power2;
	int m1 = 1000000007;
	int m2 = 1000000009;
	int x = m1-3;
public:	
	Solver(string s) : s(s) {	
		// initialization, precalculation
		h1.resize(s.size()+1);
		h2.resize(s.size()+1);
		power1.resize(s.size()+1);
		power2.resize(s.size()+1);
		h1[0] = 0;
		h2[0] = 0;
		power1[0] = 1;
		power2[0] = 1;
		for(int i=1;i<=s.size();i++) {
			h1[i] = (x*h1[i-1] + s[i-1]) % m1;
			h2[i] = (x*h2[i-1] + s[i-1]) % m2;
			power1[i] = power1[i-1]*x%m1;
			power2[i] = power2[i-1]*x%m2;
		}
		// for(auto a : h1)
		//   cout << a << " "; 

	}
	bool ask(int a, int b, int l) {
		long long h1a = (h1[a+l] - power1[l]*h1[a]%m1) % m1;
		if(h1a < 0)
		  h1a += m1;
		long long h1b = (h1[b+l] - power1[l]*h1[b]%m1) % m1;
		if(h1b < 0)
		  h1b += m1;
		if(h1a!=h1b)
		  return false;
		
		long long h2a = (h2[a+l] - power2[l]*h2[a]%m2) % m2;
		if(h2a < 0)
		  h2a += m2;
		long long h2b = (h2[b+l] - power2[l]*h2[b]%m2) % m2;
		if(h2b < 0)
		  h2b += m2;
		if(h2a!=h2b)
		  return false;
		
		return true;
		
		
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	// string s = "abcabcabc";
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}

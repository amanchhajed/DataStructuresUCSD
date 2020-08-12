#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

unsigned long long polyHash(string s, int prime, int x) {
    unsigned long long hash = 0;
    for(int i=s.size()-1; i>=0; i--) {
        hash = (hash*x + s[i])%prime;
    }
    return hash;
}

vector<unsigned long long> preComputeHash(const string& T, int slen, int prime, int x) {
    int tlen = T.size();
    vector<unsigned long long> H(tlen - slen + 1);
    string start = T.substr(tlen-slen, slen);
    H[tlen-slen] = polyHash(start, prime, x);
    long long y = 1;
    for(int i=1;i<=slen; i++)
      y = y*x%prime;
    for(int i = tlen-slen-1;i>=0;i--) {
        long long temp = (H[i+1]*x + T[i] - T[i+slen]*y)%prime;
        if(temp<0)
          temp += prime;
        H[i] = temp%prime; 
    }
    return H;
}

void print_occurrences(const vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    vector<int> ans;
    int prime = 1000000007;
    int x = rand()*(prime-1) + 1;
    unsigned long long patternHash = polyHash(s, prime, x);
    vector<unsigned long long> H = preComputeHash(t, s.size(), prime, x);
    for(size_t i=0;i<=t.size()-s.size();i++) {
        if(H[i]==patternHash) {
            if(t.substr(i, s.size()) == s) {
                ans.push_back(i);
            }
        }
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}

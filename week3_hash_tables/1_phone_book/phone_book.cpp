#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    unordered_map<int, string> result;
    vector<string> answer;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            result[queries[i].number] = queries[i].name;
        } else if (queries[i].type == "del") {
            result.erase(queries[i].number);
        } else {
            string response = "not found";
            if(result.count(queries[i].number))
              response = result[queries[i].number];
            answer.push_back(response);
        }
    return answer;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}

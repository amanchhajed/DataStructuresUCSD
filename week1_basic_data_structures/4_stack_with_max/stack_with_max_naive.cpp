#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::stack;
using std::cout;
using std::max_element;

class StackWithMax {
    stack<int> intStack;
    stack<int> maxStack;

  public:

    void Push(int value) {
        intStack.push(value);
        if(maxStack.empty())
          maxStack.push(value);
        else {
            maxStack.push(std::max(value, maxStack.top()));
        }
    }

    void Pop() {
        assert(intStack.size());
        intStack.pop();
        maxStack.pop();
    }

    int Max() const {
        assert(intStack.size());
        return maxStack.top();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
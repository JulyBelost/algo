#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

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
    vector<string> result;
    unordered_map<int, string> contacts;

    for (size_t i = 0; i < queries.size(); ++i) {
        Query q = queries[i];
        if (q.type == "add") {
            contacts[q.number] = q.name;
        } else if (q.type == "del") {
            contacts.erase(q.number);
        } else {
            string response = contacts.find(q.number) == contacts.end() ? "not found" : contacts[q.number];

            result.push_back(response);
        }
    }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}

#include <iostream>
#include <chrono>
#include <set>
#include <list>
#include <vector>
#include <fstream>
using namespace std;
using namespace std::chrono;

int main() {
    set<string> codes_set;
    vector<string> codes_vector;
    list<string> codes_list;

    auto start_list = high_resolution_clock::now();
    auto start_vector = high_resolution_clock::now();

    // Reading race
    ifstream infile("codes.txt");
    if (infile.is_open()) {
        string code;
        while (getline(infile, code)) {
            codes_vector.push_back(code);
        }
        infile.close()
    }
    auto end_list = high_resolution_clock::now();
    auto duration_list = duration_cast<milliseconds>(end_list - start_list).count();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
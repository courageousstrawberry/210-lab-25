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

    // Reading race
    ifstream infile("codes.txt");
    if (infile.is_open()) {
        string code;
        // Read vector
        auto start_vector = high_resolution_clock::now();
        while (getline(infile, code)) {
            codes_vector.push_back(code);
        }
        auto end_vector = high_resolution_clock::now();
        // Read set
        auto start_set = high_resolution_clock::now();
        while (getline(infile, code)) {
            codes_vector.push_back(code);
        }
        auto end_set = high_resolution_clock::now();
        // Read list
        auto start_list = high_resolution_clock::now();
        while (getline(infile, code)) {
            codes_vector.push_back(code);
        }
        auto end_list = high_resolution_clock::now();
        
        auto duration_vector = duration_cast<milliseconds>(end_vector - start_vector);
        auto duration_set = duration_cast<milliseconds>(end_set - start_set);
        auto duration_list = duration_cast<milliseconds>(end_set - start_set);
        
        cout << "vector: " << duration_vector.count() << ", set: " << duration_set.count() << ", list: " << duration_list.count();

        infile.close();
    }

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    int min_idx = 0;
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

class TestDataEmptyArray {
public:
    static vector<int> get_array() {
        // complete this function
        return vector <int>();
    }

};

class TestDataUniqueValues {
public:
    static vector<int> get_array() {
        // complete this function
        return vector <int>{5, 1, 2, 3, 4};
    }

    static int get_expected_result() {
        // complete this function
        static vector <int> v = get_array();
        static int minIndex = -1, minValue = numeric_limits<int>::max();
        for(int i = 0 ; i < v.size() ; ++i){
            if(minValue > v[i]){
                minValue = v[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

};

class TestDataExactlyTwoDifferentMinimums {
public:
    static vector<int> get_array() {
        // complete this function
        return vector <int>{5, 2, 2, 1, 1, 4, 3, 3};
    }

    static int get_expected_result() {
        // complete this function
        static vector <int> v = get_array();
        static int minIndex = -1, minValue = numeric_limits<int>::max();
        for(int i = 0 ; i < v.size() ; ++i){
            if(minValue > v[i]){
                minValue = v[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

};


void TestWithEmptyArray() {
    try {
        auto seq = TestDataEmptyArray::get_array();
        auto result = minimum_index(seq);
    } catch (invalid_argument& e) {
        return;
    }
    assert(false);
}

void TestWithUniqueValues() {
    auto seq = TestDataUniqueValues::get_array();
    assert(seq.size() >= 2);

    assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

    auto expected_result = TestDataUniqueValues::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

void TestWithExactlyTwoDifferentMinimums() {
    auto seq = TestDataExactlyTwoDifferentMinimums::get_array();
    assert(seq.size() >= 2);

    auto tmp = seq;
    sort(tmp.begin(), tmp.end());
    assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

    auto expected_result = TestDataExactlyTwoDifferentMinimums::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

int main() {
    TestWithEmptyArray();
    TestWithUniqueValues();
    TestWithExactlyTwoDifferentMinimums();
    cout << "OK" << endl;
    return 0;
}

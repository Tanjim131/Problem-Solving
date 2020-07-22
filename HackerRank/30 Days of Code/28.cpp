#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class Person{
    public:
        string fname, email;
        Person(){}
        Person(const string &fn, const string &em): fname(fn), email(em){}
        bool operator < (const Person &person) const{
            return fname < person.fname;
        }
};

vector <string> modify(const vector <Person> &persons){
    vector <string> modified; 
    modified.reserve(persons.size());
    for(int i = 0 ; i < persons.size() ; ++i){
        string email = persons[i].email;
        for(int j = 0 ; j < email.length() ; ++j){
            if(email[j] == '@'){
                email[j] = ' ';
                break;
            }
        }
        istringstream iss(email);
        string first, second;
        iss >> first >> second;
        if(second == "gmail.com"){
            modified.emplace_back(persons[i].fname);
        }
    }
    sort(modified.begin(), modified.end());
    return modified;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector <Person> persons;
    persons.reserve(N);

    for (int N_itr = 0; N_itr < N; N_itr++) {
        string firstNameEmailID_temp;
        getline(cin, firstNameEmailID_temp);

        vector<string> firstNameEmailID = split_string(firstNameEmailID_temp);

        string firstName = firstNameEmailID[0];

        string emailID = firstNameEmailID[1];

        persons.emplace_back(Person(firstName, emailID));
    }

    vector <string> modified = modify(persons);

    for(int i = 0 ; i < modified.size() ; ++i){
        cout << modified[i] << '\n';
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

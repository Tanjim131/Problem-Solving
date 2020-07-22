#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    
    // Print the sum of both integer variables on a new line.
    
    // Print the sum of the double variables on a new line.
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.

    int a;
    double b;
    string c;

    cin >> a >> b;
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    getline(cin, c);
    cout << i + a << '\n';
    cout << fixed << setprecision(1) << d + b << '\n';
    cout << s + c << '\n';
    

    return 0;
}
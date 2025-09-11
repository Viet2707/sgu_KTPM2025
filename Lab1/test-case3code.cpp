#include <iostream>
#include <cmath>
#include <string>  
#include <sstream> 
using namespace std;

int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) return -1;
    if (a == 0 && b == 0) return 0;
    if (a == 0) {
        double y = -c / b;
        if (y < 0) return 0;
        x[0] = sqrt(y);
        x[1] = -sqrt(y);
        return 2;
    }
    double delta = b * b - 4 * a * c;
    if (delta < 0) return 0;
    double y1 = (-b + sqrt(delta)) / (2 * a);
    double y2 = (-b - sqrt(delta)) / (2 * a);
    int count = 0;
    if (y1 >= 0) {
        x[count++] = sqrt(y1);
        x[count++] = -sqrt(y1);
    }
    if (y2 >= 0 && y2 != y1) {
        x[count++] = sqrt(y2);
        x[count++] = -sqrt(y2);
    }
    return count;
}

void testCase(double a, double b, double c, const string& expected) {
    double x[4];
    int n = solveQuartic(a, b, c, x);
    string result;
    if (n == -1) result = "Infinite solutions.";
    else if (n == 0) result = "No solution.";
    else {
        result = "The equation has " + to_string(n) + " real solution(s): ";
        for (int i = 0; i < n; i++) result += to_string(x[i]) + " ";
    }
    cout << "Test Case (a=" << a << ", b=" << b << ", c=" << c << "): "
         << (result == expected ? "TRUE" : "FALSE") << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
}

int main() {
    testCase(0, 0, 0, "Infinite solutions.");
    testCase(0, 0, 1, "No solution.");
    testCase(0, 1, 2, "No solution.");
    testCase(0, 1, -4, "The equation has 2 real solution(s): 2 -2 ");
    testCase(1, 0, -1, "The equation has 2 real solution(s): 1 -1 ");
    testCase(1, 2, 1, "No solution.");
    testCase(1, -2, 0, "The equation has 4 real solution(s): 1.41421 -1.41421 0 0 ");
    testCase(1, 0, -4, "The equation has 2 real solution(s): 1.41421 -1.41421 ");
    return 0;
}
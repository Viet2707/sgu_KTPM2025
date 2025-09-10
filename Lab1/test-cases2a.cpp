    #include <iostream>
using namespace std;

int f(int x) {
    if (x > 10) {
        return 2 * x;
    } else {
        return -x;
    }
}

int main() {
    int x ;
    cin >> x ;
    cout << "Test case  : " << f(x) << endl;
    
    return 0;
}
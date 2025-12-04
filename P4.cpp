/*
 * This program evaluates the performance of improved insertion sort.
 * ----------------------------------------------
 * Author:   Beaux Dolf, Jacob Simon
 * email:    bdolf1@uco.edu, jsimon4@uco.edu
 * ----------------------------------------------
 */


#include <iostream>
#include <cstdlib>
using namespace std;

//Euclidean Algorithm for gcd
int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//Extended Euclidean Algorithm
//Returns gcd(a,b) and sets x, y so that ax + by = gcd
int extendedEuclidean(int a, int b, int &x, int &y) 
{
    int old_x = 1, new_x = 0;
    int old_y = 0, new_y = 1;
    int temp;

    while (b != 0) 
    {
        int q = a / b;
        int r = a % b;

        a = b;
        b = r;

        temp = new_x;
        new_x = old_x - q * new_x;
        old_x = temp;

        temp = new_y;
        new_y = old_y - q * new_y;
        old_y = temp;
    }

    x = old_x;
    y = old_y;
    return a;
}

int modInverse(int a, int m) 
{
    int x, y;
    int g = extendedEuclidean(a, m, x, y);

    if (g != 1) return -1;
    else 
    {
        int res = (x % m + m) % m;
        return res;
    }
    int result = x % m;
    if (result < 0) result += m;

    return result;
}

int main(int argc, char *argv[]) 
{

    if (argc < 2) {
        cout << "Invalid input." << endl;
        return 0;
    }

    int option = atoi(argv[1]);

    if (option == 1){
        // gcd: expects 2 more args: a b
        if (argc != 4){
            cout << "Error: gcd requires 2 integer arguments." << endl;
            return 1;
        }

        int a = atoi(argv[2]);
        int b = atoi(argv[3]);

        if (a <= 0 || b <= 0){
            cout << "Error: arguments must be positive integers." << endl;
            return 1;
        }

        int result = gcd(a, b);
        cout << "gcd(" << a << ", " << b << ") = " << result << endl;
    }
    else if ( option == 2 ){
        //inverse: expects 2 more args: a m
        if (argc != 4){
            cout << "Error: modInverse requires 2 integer arguments." << endl;
            return 1;
        }
        int a = atoi(argv[2]);
        int m = atoi(argv[3]);

        if (a <= 0 || m <= 0 || a >= m){
            cout << "Error: require positive integers with a < m." << endl;
            return 1;
        }

        if (gcd(a, m) != 1) {
            cout << "Error: gcd(" << a << ", " << m 
                << ") is not 1. Modular inverse does not exist." << endl;
            return 1;
        }
        int inverseA = modInverse(a, m);
        if (inverseA == -1){
            cout << "Modular inverse does not exist for a = " << a << " and m = " << m << "." << endl;
        } else {
            cout << "Modular inverse of " << a << " modulo " << m << " is " << inverseA << "." << endl;
        }
    }

    else if (option == 3) {
        // Solve the linear congruence: a x ≡ b (mod m)
        if (argc != 5) {
            cout << "Error: functionality 3 requires three integer arguments: a b m." << endl;
            return 1;
        }

        int a = atoi(argv[2]);
        int b = atoi(argv[3]);
        int m = atoi(argv[4]);

        if (a <= 0 || b <= 0 || m <= 0 || a >= m || b >= m) {
            cout << "Error: require positive integers with a < m and b < m." << endl;
            return 1;
        }

        // gcd(a, m) must be 1 for a unique solution
        if (gcd(a, m) != 1) {
            cout << "Error: gcd(a, m) must be 1 for a unique solution." << endl;
            return 1;
        }

        int inverseC = modInverse(a, m);
        if (inverseC == -1){
            cout << "Modular inverse does not exist for a = " << a
                    << " and m = " << m << "." << endl;
            return 1;
        }
        long long temp = static_cast<long long>(b) * inverseC;
        int c = static_cast<int>(temp % m);
        if (c < 0) c += m;

        cout << "The solution for " << a << "x === " 
             << b << "(mod " << m << ") is x === " << c << "(mod " << m << ")." << endl;
    }
    else
    {
        cout << "Error: Unknown option. Use 1 for gcd or 2 for modular inverse, or 3 for solving linear congruence." << endl;
    }

    return 0;
}

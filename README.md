# P4-2025
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


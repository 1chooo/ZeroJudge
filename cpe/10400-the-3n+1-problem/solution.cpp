/*
 * Author: @1chooo
 * Title: 100 - The 3n + 1 problem
 * Required: Time limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36
 * Status: AC
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

    long long int i;
    long long int j;
    long long int temp;
    long long int n;
    long long int operation;

    while (cin >> i >> j) {
        bool change = false;

        if (i > j) {
            temp = i;
            i = j;
            j = temp;
            change = true;
        }

        long long int maxOperation = 0;

        for (int a = i; a <= j; a++) {
            n = a;
            operation = 1;

            while (n != 1) {

                if ((n & 1) == 0)
                    (n >>= 1);
                else
                    n = 3 * n + 1;
                operation++;
            }

            if (operation > maxOperation)
                maxOperation = operation;
        }

        if (change == true)
            printf("%lld %lld %lld\n", j, i, maxOperation);
        else
            printf("%lld %lld %lld\n", i, j, maxOperation);
    }

    return 0;
}

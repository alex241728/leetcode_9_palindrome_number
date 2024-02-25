#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x);

int main() {
    printf("%d\n", isPalindrome(121));
    printf("%d\n", isPalindrome(-121));
    printf("%d\n", isPalindrome(10));

    return 0;
}

bool isPalindrome(int x) {
    // if x is negative, x cannot be a palindrome
    // e.g. x = -121
    if (x < 0) {
        return false;
    }

    // if x is not 0 and x ends with 0
    // e.g. x = 10
    if (x % 10 == 0 && x != 0) {
        return false;
    }

    int rev = 0; // rev will store the half reverse of x
    // x > rev is equivalent that the number of digits of rev is less than that of x
    while (x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    // if x's digit number is odd, to return true, rev after removed last digit should equal to the remaining x
    // if x's digit number is even, to return true, rev should equal to the remaining x
    return rev / 10 == x || rev == x;
}

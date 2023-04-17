//checking if a number is pallindrome or not
bool isPalindrome(int n) {
    int temp = n, rev = 0;
    while(temp != 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return n == rev;
}

//Checking if a number is a power of 2:

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

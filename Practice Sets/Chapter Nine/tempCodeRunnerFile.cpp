// Function to calculate the cyclic shift hash code
unsigned long long cyclicShiftHash(const std::string& word, int shift) {
    unsigned long long hash = 0;
    for (char c : word) {
        hash = (hash << shift) | c;
    }
    return hash;
}
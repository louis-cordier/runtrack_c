int power(int n, int power) {
    if (power < 0) return 0; // Gestion des puissances négatives
    if (power == 0) return 1;
    
    int result = 1;
    for (int i = 0; i < power; i++) {
        result *= n;
    }
    
    return result;
}

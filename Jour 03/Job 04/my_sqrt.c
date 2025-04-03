int my_sqrt(int n) {
    if (n < 0) return 0;
    
    int i = 0;
    while (i * i <= n) {
        if (i * i == n) return i;
        i++;
    }
    
    return 0;
}

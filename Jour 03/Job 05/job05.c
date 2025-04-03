#include <unistd.h>

int my_atoi(char *str) {
    int result = 0;
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int factorial(int n) {
    if (n < 0) return 0;
    int result = 1;
    while (n > 1) {
        result *= n--;
    }
    return result;
}

void my_putnbr(int n) {
    char c;
    if (n >= 10) {
        my_putnbr(n / 10);
    }
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv) {
    if (argc == 2) {
        int num = my_atoi(argv[1]);
        my_putnbr(factorial(num));
        write(1, "\n", 1);
    }
    return 0;
}

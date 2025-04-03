#include <stdio.h>
#include <stdlib.h>

char *itoa_hex(int n);

int main()
{
    // Test 1
    char *hex_str = itoa_hex(255);
    printf("255 en hexadécimal: %s\n", hex_str);
    free(hex_str);
    
    // Test 2
    hex_str = itoa_hex(0);
    printf("0 en hexadécimal: %s\n", hex_str);
    free(hex_str);
    
    // Test 3
    hex_str = itoa_hex(-42);
    printf("-42 en hexadécimal: %s\n", hex_str);
    free(hex_str);
    
    // Test 4
    hex_str = itoa_hex(305441741);
    printf("305441741 en hexadécimal: %s\n", hex_str);
    free(hex_str);
    
    return 0;
}
#include <stdio.h>

int main() {
    float temperature;

    // Prompt the user to input the current temperature in Celsius
    printf("Enter the current temperature in Celsius: ");
    scanf("%f", &temperature);

    // Check if temperature is 25 degrees Celsius or higher
    if (temperature >= 25) {
        printf("Warm weather\n");
    } else {
        printf("Cool weather\n");
    }

    return 0;
}


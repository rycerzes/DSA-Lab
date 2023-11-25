#include <stdio.h>
typedef struct Complex {
    float real;
    float imag;
} Complex;
Complex addComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}
void multiplyComplex(Complex *a, Complex *b, Complex *result) {
    result->real = (a->real * b->real) - (a->imag * b->imag);
    result->imag = (a->real * b->imag) + (a->imag * b->real);
}
int main() {
    Complex num1, num2, result;
    int choice;
    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);
    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);
    printf("\nMenu:\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            result = addComplex(num1, num2);
            printf("Sum: %.2f + %.2fi\n", result.real, result.imag);
            break;
        case 2:
            multiplyComplex(&num1, &num2, &result);
            printf("Product: %.2f + %.2fi\n", result.real, result.imag);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
#include <stdio.h>

int main()
{
    int base, exp, mult;
    int powres = 1;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente: ");
    scanf("%d", &exp);

    for (mult = 1; mult <= exp; mult++)
    {
        powres = powres * base;
        printf("%d\n", powres); // Mostra o resultado das iterações para cada passe com base no expoente
    }

    printf("O resultado da potenciacao sera: %d", powres);

    return 0;
}
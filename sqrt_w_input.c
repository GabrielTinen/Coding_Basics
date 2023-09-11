#include <stdio.h>
#include <stdlib.h>

int abs(int v) // Função para retornar valor absoluto de (y - z) de "double findSqrt(double x)"
{
    return v * ((v > 0) - (v < 0));
}

double findSqrt(double x)
{
    // Para 0 e 1, as raizes serão elas mesmas
    if (x < 2)
        return x;

    double y = x;
    double z = (y + (x / y)) / 2;

    // Como queremos a precisão de até 5 casas decimais, o valor absoluto
    // não deve execeder 0.00001
    while (abs(y - z) >= 0.00001)
    {
        y = z;
        z = (y + (x / y)) / 2;
        printf("'z' sera: %f\n", z);
    }
    return z;
}

int main()
{
    double input;

    do
    {
        printf("\nDigite um numero para descobrir sua raiz quadrada: [0 para sair] ");

        scanf("%lf", &input);
        while ((getchar()) != '\n')
            ;

        if (input == 0)
        {
            return 0;
        }
        else
        {
            double ans = findSqrt(input);
            printf("A raiz quadrada de %.5g sera %.2g\n\n", input, ans);
        }

    } while (input != 0);

    return 0;
}
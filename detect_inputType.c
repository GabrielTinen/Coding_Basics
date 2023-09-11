#include <stdio.h>  // para usar 'printf()', fgets() e 'stdin'
#include <stdlib.h> // Para usar 'strof' e 'strol'
#include <string.h> // Para usar 'strlen()'
#include <ctype.h>  // Para usar 'toupper'

float readTypeInput()
{
    int isChar = 0;
    int isFloat = 0;
    int isInt = 0;

    float floatInput;
    int intInput;
    char charInput;

    char userInput[100];

    // Usando a função 'fgets()' ao invés de 'scanf()' podemos evitar um "buffer overflow" no qual não podemos evitar no 'scanf()' pois lê-se apenas um caractere por vez.
    fgets(userInput, 100, stdin);
    userInput[strlen(userInput) - 1] = '\0'; // Como a tecla "ENTER" também é lida pelo input necessitamos tira-lá da contagem (caso precisemos fazer a contagem de caracteres)

    // A seguir foi criado um loop for para a leitura de cada caractere inputado na array 'userInput' além de acrescentar uma contagem de tipos de caracteres.
    for (int indice = 0; indice < strlen(userInput); indice++)
    {
        userInput[indice] = toupper(userInput[indice]); // transforma as letras inseridas em 'caixa alta'.

        if (!((userInput[indice] >= '0') && (userInput[indice] <= '9')))
        {
            if ((userInput[indice] == '.') || (userInput[indice] == ','))
            {
                isFloat++;
            }
            else
            {
                isChar++;
            }
        }
        else
        {
            isInt++;
        }
    }

    // A seguir podemos ver a quantidade dos tipos de caracteres inputados:
    printf("\nisInt = %d", isInt);
    printf("\nisFloat = %d", isFloat);
    printf("\nisChar = %d\n\n", isChar);

    // A quantidade total de caracteres pode ser verificada das seguintes maneiras:
    printf("Somando os tipos de entradas, voce inseriu %d caractere(s).\n", isChar + isFloat + isInt);
    printf("Pela 'strlen()', voce inseriu %d caractere(s).\n", strlen(userInput));

    if (isChar || isFloat > 1)
    {
        charInput = toupper(userInput[0]);

        if ((isChar >= 1) && (isFloat >= 1) || (isInt >= 1) && (isChar >= 1) || (isFloat >= 1) && (isInt >= 1) || (isChar > 1))
        {
            printf("\nValor inserido do tipo 'STRING'. %s \n", userInput);
        }
        else
        {
            printf("\nValor inserido do tipo 'CARACTERE'. %c \n", charInput);
        }
        // printf("quantidade de caracteres inputados em (userInput)(readTypeInput)= %zu\n\n", strlen(x));
        return charInput;
    }
    else if ((isFloat == 1) && (!(isChar >= 1)))
    {
        floatInput = strtof(userInput, NULL);
        printf("\nValor inserido do tipo 'FLOAT'. %.2lf \n", floatInput);
        // printf("quantidade de caracteres inputados em (userInput)(readTypeInput)= %zu\n\n", strlen(userInput));
        return floatInput;
    }
    else
    {
        intInput = strtol(userInput, NULL, 10);
        printf("\nValor inserido do tipo 'INTEIRO'. %d \n", intInput);
        // printf("quantidade de caracteres inputados em (userInput)(readTypeInput)= %zu\n\n", strlen(userInput));
        return intInput;
    }
}

int main()
{
    float input;

    do
    {
        printf("Digite algo para saber o tipo da entrada: [- para sair] ");
        input = readTypeInput();

    } while (input != '-');

    return 0;
}

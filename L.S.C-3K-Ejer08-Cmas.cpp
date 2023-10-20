// L.S.C-3K-Ejer08-Cmas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Paola Jazmin Esquinca Lopez

#include <iostream>
#define MaxTamC 10

typedef int TipoDato;

int main()
{
    int frente = 0, final = 0;
    TipoDato A[MaxTamC];
    int contador = 0;

    //iniciador de cola
    frente = 0;
    final = 0;

    std::cout << "¿Desea agregar elementos a la cola? (s/n): ";
    char respuesta;
    std::cin >> respuesta;

    while ((respuesta == 's' || respuesta == 'S') && contador < 10) {
        if ((final + 1) % MaxTamC == frente) {
            std::cout << "Desbordamiento de cola" << std::endl;
            return 1;
        }

        std::cout << "Igrese un elemento para la cola: ";
        TipoDato elemento;
        std::cin >> elemento;
        final = (final + 1) % MaxTamC;
        A[final] = elemento;

        contador++;
        std::cout << "Elemento " << contador << " agregar a la cola: " << elemento << std::endl;

        if (contador < 10) {
            std::cout << "¿Desea agregar mas elementos a la cola? (s/n): ";
            std::cin >> respuesta;
        }
    }

    //valor si la cola está vacía
    if (frente == final) {
        std::cout << "La cola esta vacía." << std::endl;
        return 1;
    }

    //obtener el primer elemento de la cola
    TipoDato primerElemento = A[(frente + 1) % MaxTamC];
    std::cout << "El primer elemento de la cola es: " << primerElemento << std::endl;

    //Eliminir un elemento de la cola
    frente = (frente + 1) % MaxTamC;

    //Imprimir elementos de la cola en el orden en que fueron integrados
    std::cout << "Elementos de la cola en el orden de ingreso:" << std::endl;
    for (int i = frente + 1; i <= final; i = (i + 1) % MaxTamC) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

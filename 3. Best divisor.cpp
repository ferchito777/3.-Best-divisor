#include <stdio.h>
#include <math.h>

// Funcion para calcular la suma de los digitos de un numero
unsigned calcularSumaDigitos(unsigned numero) {
  unsigned suma = 0;
  while (numero > 0) {
    suma += numero % 10;
    numero = numero / 10;
  }
  return suma;
}

int main() {
  unsigned numero, mejorNumero, mejorSuma, limite;
  scanf("%u", &numero); // Lee el numero

  mejorNumero = numero;
  mejorSuma = calcularSumaDigitos(numero); // Calcula la suma de los digitos del numero dado
  limite = (unsigned) sqrt(numero); // Calcula la raiz cuadrada entera del numero dado

  // Itera sobre los numeros desde 1 hasta el limite
  for (unsigned i = 1; i <= limite; i++) {
    if (numero % i == 0) {
      unsigned suma = calcularSumaDigitos(i); // Calcula la suma de los digitos de i

      // Compara la suma actual con la mejor suma encontrada
      if (suma > mejorSuma || suma == mejorSuma && i < mejorNumero) {
        mejorSuma = suma;
        mejorNumero = i;
      }

      suma = calcularSumaDigitos(numero / i); // Calcula la suma de los digitos del cociente
      // Compara la suma actual con la mejor suma encontrada
      if (suma > mejorSuma || suma == mejorSuma && numero / i < mejorNumero) {
        mejorSuma = suma;
        mejorNumero = numero / i;
      }
    }
  }
  printf("%u\n", mejorNumero); // Imprime el mejor numero encontrado
  return 0;
}


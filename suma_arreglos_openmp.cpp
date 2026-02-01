#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    const int N = 1000;

    int A[N];
    int B[N];
    int C[N];

    // Inicializar generador de números aleatorios
    srand(time(NULL));

    // Llenar arreglos A y B con valores aleatorios
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    cout << "Arreglos A y B llenados con valores aleatorios" << endl;

    // Medición de tiempo
    double start, end;
    start = omp_get_wtime();

    // Suma PARALELA de los arreglos
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    end = omp_get_wtime();

    cout << "Tiempo transcurrido: " << end - start << " segundos" << endl;

    // Impresión de resultados (verificación)
    cout << "\nVerificación de los primeros 10 elementos:\n" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "A[" << i << "] = " << A[i]
             << " + B[" << i << "] = " << B[i]
             << " => C[" << i << "] = " << C[i] << endl;
    }

    return 0;
}

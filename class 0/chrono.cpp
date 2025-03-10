#include <iostream>
#include <chrono>

// Función de ejemplo
void funcionEjemplo()
{
    for (volatile int i = 0; i < 1000000; ++i)
        ; // Bucle que consume tiempo
}

int main()
{
    auto inicio = std::chrono::high_resolution_clock::now(); // Inicia el cronómetro

    funcionEjemplo(); // Llama a la función cuya ejecución quieres medir

    auto fin = std::chrono::high_resolution_clock::now(); // Detiene el cronómetro

    // Calcula la duración en milisegundos
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);

    std::cout << "Tiempo de ejecución: " << duracion.count() << " ms" << std::endl;

    return 0;
}

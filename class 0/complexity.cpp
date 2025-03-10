#include <iostream>
#include <limits.h>
#include <vector>
#include <chrono>

using namespace std;

vector<int> numeros;

bool busqueda_linear(int x)
{
    // cout << "xd" << endl;
    // cout << numeros.size() << endl;
    for (int i = 0; i <= numeros.size() - 1; i++)
    {
        if (numeros[i] == x)
        {
            // cout << "lo encontre" << endl;
            return true;
        }
    }
    return false;
}

bool busqueda_binaria(int x)
{

    // 0 al 99
    int izquierda = 0, derecha = numeros.size() - 1;
    // cout << "hola";
    // izquierda==derecha , el ultimo elemento
    while (izquierda <= derecha)
    {
        int mitad = (izquierda + derecha) / 2;
        if (numeros[mitad] == x)
        {
            return true;
        }
        if (numeros[mitad] < x)
        {
            izquierda = mitad + 1;
        }
        if (numeros[mitad] > x)
        {
            derecha = mitad - 1;
        }
    }
    return false;
}

int main()
{
    cout << INT_MAX << endl;
    cout << LLONG_MAX << endl;
    // tipo de dato, automatico
    cout << LONG_MAX << endl;
    cout << ULONG_MAX << endl;
    cout << UINT_MAX << endl;
    cout << ULLONG_MAX << endl;

    for (int i = 1; i <= int(1e6); i++)
    {
        numeros.push_back(i);
    }
    int x;
    cout << "Ingresa el numero a buscar!!!!" << endl;
    cin >> x;
    auto inicio = chrono::high_resolution_clock::now();
    if (busqueda_linear(x) == true)
    {
        auto fin = std::chrono::high_resolution_clock::now(); // Detiene el cronómetro

        cout << "linear la encontro!" << endl;
        auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);

        unsigned int dwDuration = duracion.count();

        cout << "Tiempo tomado:" << dwDuration << endl;
    }
    else
        cout << "linear nola" << endl;

    auto inicio1 = chrono::high_resolution_clock::now();

    if (busqueda_binaria(x) == true)
    {
        auto fin = std::chrono::high_resolution_clock::now(); // Detiene el cronómetro

        cout << "busqueda binaria lo encontro" << endl;
        auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio1);

        unsigned int dwDuration = duracion.count();

        cout << "Tiempo tomado:" << dwDuration << endl;
    }
    else
        cout << "F" << endl;
}

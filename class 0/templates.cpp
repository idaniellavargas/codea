#include <iostream>
#include <string>
using namespace std;
// GENERALIZACION
// Clase plantilla
template <typename T>
class Caja
{
private:
    T valor;

public:
    Caja(T v) : valor(v) {} // Constructor
    void mostrar()
    {
        std::cout << "Valor almacenado: " << valor << std::endl;
    }
};

// Función plantilla
template <typename T>
T mayor(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    // Usando la clase plantilla con un int
    Caja<int> cajaEntero(10);
    cajaEntero.mostrar();

    // Usando la clase plantilla con un string
    Caja<string> cajaTexto("Hola, Dani!");
    cajaTexto.mostrar();

    // Usando la función plantilla
    std::cout << "Mayor entre 5 y 8: " << mayor(5, 8) << std::endl;
    std::cout << "Mayor entre 3.5 y 2.7: " << mayor(3.5, 2.7) << std::endl;

    return 0;
}

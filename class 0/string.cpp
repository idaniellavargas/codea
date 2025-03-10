#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 1. Contar caracteres hasta encontrar un caracter dado.
int contarHastaCaracter(const string &cadena, char c)
{
    size_t pos = cadena.find(c);
    return (pos == string::npos) ? cadena.length() : pos;
}

// 2. Contar palabras en una cadena.
int contarPalabras(const string &cadena)
{
    istringstream iss(cadena);
    string palabra;
    int contador = 0;
    while (iss >> palabra)
        contador++;
    return contador;
}

// 3. Invertir una cadena.
string invertirCadena(string cadena)
{
    reverse(cadena.begin(), cadena.end());
    return cadena;
}

// 4. Determinar si una cadena es palíndromo.
bool esPalindromo(const string &cadena)
{
    string invertida = invertirCadena(cadena);
    return cadena == invertida;
}

// 5. Contar repeticiones de un caracter.
int contarCaracter(const string &cadena, char c)
{
    return count(cadena.begin(), cadena.end(), c);
}

// 6. Partir una cadena con un separador.
vector<string> dividirCadena(const string &cadena, char separador)
{
    vector<string> resultado;
    istringstream iss(cadena);
    string fragmento;
    while (getline(iss, fragmento, separador))
    {
        resultado.push_back(fragmento);
    }
    return resultado;
}

// 7. Convertir un número a romano.
// 7. Convertir un número a romano (simplificado).
string numeroARomano(int num)
{
    string romanos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string resultado;
    for (int i = 0; i < 13 && num > 0; i++)
    {
        while (num >= valores[i])
        {
            resultado += romanos[i];
            num -= valores[i];
        }
    }
    return resultado;
}

// 8. Formatear fecha en formato largo.
string fechaLarga(int anio, int mes, int dia)
{
    vector<string> meses = {"", "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    return to_string(dia) + " de " + meses[mes] + " del " + to_string(anio);
}

// 9. Convertir números romanos a enteros.
int romanoAEntero(const string &romano)
{
    map<char, int> valores = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int total = 0, prev = 0;
    for (char c : romano)
    {
        int actual = valores[c];
        total += (actual > prev) ? (actual - 2 * prev) : actual;
        prev = actual;
    }
    return total;
}

// 10. Convertir a mayúsculas.
string aMayusculas(string cadena)
{
    transform(cadena.begin(), cadena.end(), cadena.begin(), ::toupper);
    return cadena;
}

// 11. Convertir a minúsculas.
string aMinusculas(string cadena)
{
    transform(cadena.begin(), cadena.end(), cadena.begin(), ::tolower);
    return cadena;
}

// 12. Convertir a formato título.
string aTitulo(string cadena)
{
    bool nuevo = true;
    for (char &c : cadena)
    {
        if (nuevo && isalpha(c))
        {
            c = toupper(c);
            nuevo = false;
        }
        else if (c == ' ')
        {
            nuevo = true;
        }
    }
    return cadena;
}

// 13. Convertir número a literal (simple para demostración).
string numeroALiteral(int num)
{
    vector<string> unidades = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
    return (num >= 0 && num <= 9) ? unidades[num] : "Número no soportado";
}

// 14. Reemplazar palabra en una cadena.
string reemplazarPalabra(string cadena, const string &buscar, const string &reemplazo)
{
    size_t pos = 0;
    while ((pos = cadena.find(buscar, pos)) != string::npos)
    {
        cadena.replace(pos, buscar.length(), reemplazo);
        pos += reemplazo.length();
    }
    return cadena;
}

int main()
{
    // Pruebas de funciones
    cout << "Contar hasta X: " << contarHastaCaracter("Hola mundo", 'm') << endl;
    cout << "Contar palabras: " << contarPalabras("Hola mundo desde C++") << endl;
    cout << "Invertir cadena: " << invertirCadena("Planeta") << endl;
    cout << "Es palindromo: " << (esPalindromo("reconocer") ? "Si" : "No") << endl;
    cout << "Contar 'o': " << contarCaracter("Hola mundo", 'o') << endl;
    cout << "Numero a romano: " << numeroARomano(2024) << endl;
    cout << "Fecha larga: " << fechaLarga(2025, 3, 10) << endl;
    cout << "Romano a entero: " << romanoAEntero("MMXXIV") << endl;
    cout << "Mayusculas: " << aMayusculas("hola mundo") << endl;
    cout << "Minusculas: " << aMinusculas("HOLA MUNDO") << endl;
    cout << "Formato titulo: " << aTitulo("las cadenas en c son interesantes") << endl;
    cout << "Numero literal: " << numeroALiteral(3) << endl;
    cout << "Reemplazar: " << reemplazarPalabra("Hola mundo", "mundo", "universo") << endl;
    return 0;
}

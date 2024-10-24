#include <iostream>
#include <string>

using namespace std;

// Estructura para almacenar datos de una persona
struct Persona {
    string nombre;
    int edad;

    Persona(string n, int e) : nombre(n), edad(e) {}
};

// Template para la lista circular simplemente enlazada
template <typename T>
class ListaCircularSimple {
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(T d) : dato(d), siguiente(nullptr) {}
    };

    Nodo* ultimo;  // Ultimo nodo, que apunta al primero

public:
    ListaCircularSimple() : ultimo(nullptr) {}

    // Insertar al final de la lista
    void insertar(T dato) {
        Nodo* nuevo = new Nodo(dato);
        if (!ultimo) {
            nuevo->siguiente = nuevo;  // Si es el unico nodo, apunta a si mismo
            ultimo = nuevo;
        } else {
            nuevo->siguiente = ultimo->siguiente;
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }

    // Mostrar la lista
    void mostrar() {
        if (!ultimo) {
            cout << "La lista está vacía.\n";
            return;
        }
        Nodo* temp = ultimo->siguiente;  // Empezar desde el primer nodo
        do {
            cout << "Nombre: " << temp->dato.nombre << ", Edad: " << temp->dato.edad << endl;
            temp = temp->siguiente;
        } while (temp != ultimo->siguiente);
    }
};

int main() {
    ListaCircularSimple<Persona> listaPersonas;

    // Insertar datos de personas
    listaPersonas.insertar(Persona("Ana", 23));
    listaPersonas.insertar(Persona("Luis", 30));
    listaPersonas.insertar(Persona("Maria", 20));

    cout << "Lista simplemente enlazada circular (desordenada):\n";
    listaPersonas.mostrar();

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    int edad;

    Persona(string n, int e) : nombre(n), edad(e) {}
};

template <typename T>
class ListaCircularDoble {
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo* anterior;
        Nodo(T d) : dato(d), siguiente(nullptr), anterior(nullptr) {}
    };

    Nodo* ultimo;

public:
    ListaCircularDoble() : ultimo(nullptr) {}

    // Insertar de forma ordenada
    void insertarOrdenado(T dato) {
        Nodo* nuevo = new Nodo(dato);
        if (!ultimo) {
            nuevo->siguiente = nuevo;
            nuevo->anterior = nuevo;
            ultimo = nuevo;
        } else {
            Nodo* temp = ultimo->siguiente;
            while (temp != ultimo && temp->dato.edad < dato.edad) {
                temp = temp->siguiente;
            }

            // Insertar el nodo antes del nodo temp
            nuevo->siguiente = temp;
            nuevo->anterior = temp->anterior;
            temp->anterior->siguiente = nuevo;
            temp->anterior = nuevo;

            if (temp == ultimo->siguiente && dato.edad < temp->dato.edad) {
                ultimo->siguiente = nuevo;
            } else if (temp == ultimo) {
                ultimo = nuevo;
            }
        }
    }

    // Mostrar la lista
    void mostrar() {
        if (!ultimo) {
            cout << "La lista está vacía.\n";
            return;
        }

        Nodo* temp = ultimo->siguiente;
        do {
            cout << "Nombre: " << temp->dato.nombre << ", Edad: " << temp->dato.edad << endl;
            temp = temp->siguiente;
        } while (temp != ultimo->siguiente);
    }
};

int main() {
    ListaCircularDoble<Persona> listaPersonas;

    // Insertar personas de manera ordenada
    listaPersonas.insertarOrdenado(Persona("Ana", 23));
    listaPersonas.insertarOrdenado(Persona("Luis", 30));
    listaPersonas.insertarOrdenado(Persona("Maria", 20));

    cout << "Lista doblemente enlazada circular (ordenada por edad):\n";
    listaPersonas.mostrar();

    return 0;
}

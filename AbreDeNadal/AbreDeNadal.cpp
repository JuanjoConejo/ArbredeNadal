#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// Funció recursiva per dibuixar l'arbre de Nadal
void dibuixarArbreRecursiu(int altura, char caracter, int espais) {
    if (altura <= 0) {
        return; // La recursió acaba quan l'altura és 0 o negativa
    }

    dibuixarArbreRecursiu(altura - 1, caracter, espais + 1);

    // Crear una cadena que representi la fila actual
    std::string fila(2 * altura - 1, caracter);

    // Canviar aleatòriament un dels caràcters a "O"
    int posicioO = std::rand() % fila.length();
    fila[posicioO] = 'O';

    // Imprimir la fila amb espais abans
    for (int i = 0; i < espais; ++i) {
        std::cout << " ";
    }
    std::cout << fila << std::endl;

    // Afegir lògica del tronc només a l'última crida recursiva
    if (altura == 1 && espais == altura - 1) {
        int troncAltura = 3; // Altura del tronc
        int troncEspais = espais; // Espais abans del tronc
        for (int i = 0; i < troncAltura; ++i) {
            for (int j = 0; j < troncEspais; ++j) {
                std::cout << " ";
            }
            std::cout << "#" << std::endl;
        }
    }
}

// Funció per dibuixar l'arbre de Nadal amb bucles
void dibuixarArbreAmbBucles(int altura, char caracter) {
    for (int i = 0; i < altura; ++i) {
        // Crear una cadena que representi la fila actual
        std::string fila(2 * i + 1, caracter);

        // Canviar aleatòriament un dels caràcters a "O"
        int posicioO = std::rand() % fila.length();
        fila[posicioO] = 'O';

        // Imprimir la fila amb espais abans
        for (int j = 0; j < altura - i - 1; ++j) {
            std::cout << " ";
        }
        std::cout << fila << std::endl;
    }

    // Dibuixar el tronc centrat
    for (int i = 0; i < altura / 2; ++i) {
        for (int j = 0; j < altura - 1; ++j) {
            std::cout << " ";
        }
        std::cout << "#" << std::endl;
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(0))); // Inicialitzar la llavor per a la generació de nombres aleatoris

    int altura;
    char caracter;

    std::cout << "Aplicacio Arbre de Nadal" << std::endl;
    std::cout << "Introdueix la mida del teu arbre de Nadal: ";
    std::cin >> altura;

    std::cout << "Introdueix el caracter que vols utilitzar per a l'arbre: ";
    std::cin >> caracter;

    std::cout << "\nArbre de Nadal amb la funcio Recursiu:\n";
    dibuixarArbreRecursiu(altura, caracter, 0);

    std::cout << "\nArbre de Nadal amb la funcio bucles:\n";
    dibuixarArbreAmbBucles(altura, caracter);

    return 0;
}
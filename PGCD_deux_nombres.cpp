#include <iostream>
#include <cstdlib>
#include <limits> 

// Fonction PGCD
int calculerPGCD(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);

    while (b != 0) {
        int reste = a % b;
        a = b;
        b = reste;
    }
    return a;
}

// Vérifie si les entrées sont valides
int Nombre() {
    int nombre;
    while (true) {
        std::cin >> nombre;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break; 
        }
    }
    return nombre;
}

int main() {
    std::cout << "Calcul du PGCD de deux nombres\n";
    int a = Nombre();
    int b = Nombre();
    
    if (a == 0 && b == 0) {
        std::cout << "Le PGCD n'existe pas pour a = 0 et b = 0." << std::endl;
    } else if (a == 0) {
        std::cout << "Le PGCD de 0 et " << b << " est : " << std::abs(b) << std::endl;
    } else if (b == 0) {
        std::cout << "Le PGCD de " << a << " et 0 est : " << std::abs(a) << std::endl;
    } else {
        int pgcd = calculerPGCD(a, b);
        std::cout << "Le PGCD de " << a << " et " << b << " est : " << pgcd << std::endl;
    }

    return 0;
}

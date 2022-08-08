#include <iostream>
#include <vector>
#include <typeinfo>
#include <sstream>
#include <string>
#include <list>

using namespace std;

struct region{ // estructura de datos para cada region del mapa
    int color = 0;
    vector<int> adyacentes;
} mapa[10]; // Aquí se inicializa la cantidad de regiones del mapa.

int main(){
    int length = sizeof mapa / sizeof mapa[0]; // tamaño del array del mapa

    
    string entrada;
    for (int i = 0; i < length; i++){
        cout << "Ingrese las adyacencias de la region " << i << ": " << endl;
        while (getline(cin, entrada)){ // se leen las adyacencias de la región.
            if (entrada == "")
                break;
            int number;
            stringstream ss(entrada);
            while (ss >> number){
                mapa[i].adyacentes.push_back(number);
            }
        }
    }

    /*
    mapa[0].adyacentes = {1, 2};
    mapa[1].adyacentes = {0, 2, 3};
    mapa[2].adyacentes = {0, 1, 3, 4, 5};
    mapa[3].adyacentes = {1, 2, 4};
    mapa[4].adyacentes = {2, 3, 5, 6, 9};
    mapa[5].adyacentes = {2, 4, 6, 7};
    mapa[6].adyacentes = {4, 5, 7, 8, 9};
    mapa[7].adyacentes = {5, 6, 8};
    mapa[8].adyacentes = {7, 6, 9};
    mapa[9].adyacentes = {4, 6, 8};*/

    list<int> colores; // lista donde se almacenan los colores.

    for (int i = 0; i < length; i++){
        colores = {1, 2, 3, 4}; // se restauran los colores posibles.
        for (int j = 0; j < mapa[i].adyacentes.size(); j++){ // Se recorre por cada región adyacente.
            int adyacente = mapa[i].adyacentes.at(j); // Se almacena la región adyacente en una variable.
            colores.remove(mapa[adyacente].color); // se elimina el color de la región adyacente de la lista de colores.
            }
        auto iterador = colores.begin(); // Se obtiene un iterador que apunta hacia la primer posición de la lista de colores.
        mapa[i].color = *iterador; // se obtiene el primer color de los colores disponibles.
    }

    for (int i = 0; i < length; i++) { // Se imprimen los colores de cada región.
        cout << "Color de region " << i << " es " << mapa[i].color << endl;
    }

}
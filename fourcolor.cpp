#include <iostream>
#include <vector>
#include <typeinfo>
#include <sstream>
#include <string>
#include <list>
#include <map>

using namespace std;

struct region{ // estructura de datos para cada region del mapa
    int color = 0; // Color default. Se van a pintar con colores 1, 2, 3 y 4.

    vector<int> adyacentes; // Vector donde se almacenan los índices de las regiones adyacentes.

} mapa[10]; // Aquí se inicializa la cantidad de regiones del mapa. Cada índice va a representar a una región diferente.

int main(){
    int length = sizeof mapa / sizeof mapa[0]; // tamaño del array del mapa

    string entrada; 
    for (int i = 0; i < length; i++){
        cout << "Ingrese las adyacencias de la region " << i << ": " << endl;
        while (getline(cin, entrada)){ // se leen las adyacencias de la región.
            if (entrada == "") // Si se ingresa un string vacío, continúa con la siguiente región adyacente.
                break;
            int number;
            stringstream ss(entrada);
            while (ss >> number){
                mapa[i].adyacentes.push_back(number);
            }
        }
    }

    vector<int> sizeOrder; // vector donde se van almacenar el orden descendente de las regiones de acuerdo con su cantidad de adyacencias.

    // se van a ordernar las regiones en orden descendente de acuerdo con la cantidad de regiones adyacentes.
    for (int i = 0; i < length; i++) {
        if (sizeOrder.size() == 0){ // si el vector está vacío, se agrega la región al vector.
            sizeOrder.emplace_back(i);
            continue;
        }
        
        for (int j = 0; j < sizeOrder.size(); j++){ // se recorre el vector de sizeOrder para ir agregando las otras regiones.
            if (mapa[sizeOrder[j]].adyacentes.size() < mapa[i].adyacentes.size()){
                sizeOrder.emplace(sizeOrder.begin() + j, i);
                break;
                /* si encuentra que en algún punto, la cantidad de regiones adyacentes de un elemento en sizeOrder
                es menor la cantidad de regiones adyacentes de la región del mapa que se está revisando,
                agrega esta región en la posición donde encontró la región menor. Así, queda en orden descendiente.*/
            } else if (j == sizeOrder.size() - 1) {
                sizeOrder.push_back(i);
                break;
                /* Sí recorrió el vector y llega al último elemento y no ha encontrado una región con una cantidad de adyacencias menor
                   agrega la región al final del vector. */
            }
        }
    }

    list<int> colores; // lista donde se almacenan los colores.

    /* Se va a recorrer por el array del mapa en el orden descendiente que estipula
    sizeOrder, para que se le vayan asignando colores primero a las regiones con mayor cantidad de regiones adyacentes.
    Se priorizan estas regiones. 
    
    Se le asigna un color a una región revisando los colores de sus regiones adyacentes,
    eliminando los colores repetidos de la lista de colores, y finalmente escogiendo el primer color disponible tras eliminar los que ya
    se han utilizado. */
    for (int i = 0; i < sizeOrder.size(); i++){ // se recorre sizeOrder porque este nos va a dar el orden de las regiones a colorear.
        colores = {1, 2, 3, 4}; // se restauran los colores disponibles.

        for (int j = 0; j < mapa[sizeOrder[i]].adyacentes.size(); j++){ // Se recorre el vector que contiene las regiones adyacentes.

            int adyacente = mapa[sizeOrder[i]].adyacentes.at(j); // Se almacena el número de la región adyacente en esta variable.

            colores.remove(mapa[adyacente].color); // Se elimina el color de la región adyacente de la lista de colores disponibles.
            }
        auto iterador = colores.begin(); // se crea este puntero para acceder al primer elemento de la lista de colores.

        mapa[sizeOrder[i]].color = *iterador; // Se le asigna el color a la región.
    }

    // Se imprimen las regions con cada color.
    cout << "Regiones con color 1" << endl;
    for (int i = 0; i < length; i++) {
        if (mapa[i].color == 1){
            cout << i << ", ";
        }
    }
    cout << "\nRegiones con color 2" << endl;
    for (int i = 0; i < length; i++) {
        if (mapa[i].color == 2){
            cout << i << ", ";
        }
    }
    cout << "\nRegiones con color 3" << endl;
    for (int i = 0; i < length; i++) {
        if (mapa[i].color == 3){
            cout << i << ", ";
        }
    }
    cout << "\nRegiones con color 4" << endl;
    for (int i = 0; i < length; i++) {
        if (mapa[i].color == 4){
            cout << i << ", ";
        }
    }
}
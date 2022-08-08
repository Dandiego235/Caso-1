#include <iostream>
#include <vector>
#include <typeinfo>
#include <sstream>
#include <string>
#include <list>

using namespace std;

struct region{
    int color = 0;
    vector<int> adyacentes;
} mapa[10];

int main(){
    int length = sizeof mapa / sizeof mapa[0];

    
    string entrada;
    for (int i = 0; i < length; i++){
        cout << "Ingrese las adyacencias de la region " << i << ": " << endl;
        while (getline(cin, entrada)){
            if (entrada == "")
                break;
            int number;
            stringstream ss(entrada);
            while (ss >> number){
                mapa[i].adyacentes.push_back(number);
                cout << number << " " << typeid(number).name() << endl;
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

    list<int> colores;

    for (int i = 0; i < length; i++){
        colores = {1, 2, 3, 4};

        cout << i << "!" << endl;
        for (int j = 0; j < mapa[i].adyacentes.size(); j++){
            int adyacente = mapa[i].adyacentes.at(j);
            cout << "Adyacente: " << adyacente << " color de adyacente " << mapa[adyacente].color << endl;
            colores.remove(mapa[adyacente].color);
            }
        auto iterador = colores.begin();
        mapa[i].color = *iterador;
        cout << "Color de " << i << " es " << mapa[i].color << endl;
    }

    for (int i = 0; i < length; i++) {
        cout << "Color de region " << i << " es " << mapa[i].color << endl;
    }

}
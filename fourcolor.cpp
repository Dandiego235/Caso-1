#include <iostream>
#include <vector>
#include <typeinfo>
#include <sstream>
#include <string>
#include <list>
#include <map>

using namespace std;

struct region{
    int color = 0;
    vector<int> adyacentes;
} mapa[10];

int main(){
    int length = sizeof mapa / sizeof mapa[0];
    
    vector<int> sizeOrder;

    /*
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
    }*/

    
    mapa[0].adyacentes = {1,2,3,4,5,6};
    mapa[1].adyacentes = {0,2,7,6};
    mapa[2].adyacentes = {0,3,8,7,1};
    mapa[3].adyacentes = {0,2,8,4};
    mapa[4].adyacentes = {8,9,3,0,5};
    mapa[5].adyacentes = {0,4,6,9};
    mapa[6].adyacentes = {0,1,7,9,5};
    mapa[7].adyacentes = {6,1,2,8,9};
    mapa[8].adyacentes = {2,3,4,9,7};
    mapa[9].adyacentes = {4,5,6,7,8};

    for (int i = 0; i < length; i++) {
        cout << "i: " << i <<  endl;
        if (sizeOrder.size() == 0){
            sizeOrder.emplace_back(i);
            continue;
        }
        for (int j = 0; j < sizeOrder.size(); j++){
            cout << "j " << j << " " << mapa[sizeOrder[j]].adyacentes.size() << " i " << i << " " << mapa[i].adyacentes.size() << endl;
            if (mapa[sizeOrder[j]].adyacentes.size() < mapa[i].adyacentes.size()){
                sizeOrder.emplace(sizeOrder.begin() + j, i);
                break;
            } else if (j == sizeOrder.size() - 1) {
                sizeOrder.push_back(i);
                cout << "placed back" << endl;
                break;
            }
        }
        cout << sizeOrder.size() << endl;
    }
    
    for (int j = 0; j < sizeOrder.size(); j++){
        cout << sizeOrder[j] << "? "<< endl;
    }


    list<int> colores;

    for (int i = 0; i < sizeOrder.size(); i++){
        colores = {1, 2, 3, 4};

        cout << sizeOrder[i] << "!" << endl;
        for (int j = 0; j < mapa[sizeOrder[i]].adyacentes.size(); j++){
            int adyacente = mapa[sizeOrder[i]].adyacentes.at(j);
            cout << "Adyacente: " << adyacente << " color de adyacente " << mapa[adyacente].color << endl;
            colores.remove(mapa[adyacente].color);
            }
        auto iterador = colores.begin();
        mapa[sizeOrder[i]].color = *iterador;
        cout << "Color de " << sizeOrder[i] << " es " << mapa[sizeOrder[i]].color << endl;
    }

    for (int i = 0; i < length; i++) {
        cout << "Color de region " << i << " es " << mapa[i].color << endl;
    }

}
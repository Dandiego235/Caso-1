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
} mapa[34];

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

    
    mapa[0].adyacentes = {33,30,31,21,22,32};
    mapa[1].adyacentes = {2,3,6};
    mapa[2].adyacentes = {1,3,5};
    mapa[3].adyacentes = {1,2,4,5,6,7,8};
    mapa[4].adyacentes = {3,6,7};
    mapa[5].adyacentes = {2,3,8};
    mapa[6].adyacentes = {1,3,4,7,9,13,12,18};
    mapa[7].adyacentes = {3,4,5,6,8,10};
    mapa[8].adyacentes = {5,3,7,11,17,23};
    mapa[9].adyacentes = {6,14,15,10};
    mapa[10].adyacentes = {7,9,11,15};
    mapa[11].adyacentes = {8,10,16};
    mapa[12].adyacentes = {6,13,19,18};
    mapa[13].adyacentes = {6,12,14,19};
    mapa[14].adyacentes = {9,15,13,21};
    mapa[15].adyacentes = {10,14,21,16};
    mapa[16].adyacentes = {15,11,17,23,21,22};
    mapa[17].adyacentes = {8,16};
    mapa[18].adyacentes = {6,12,19,25,27};
    mapa[19].adyacentes = {12,13,18,26,30};
    mapa[20].adyacentes = {13,30,21};
    mapa[21].adyacentes = {15,14,13,20,30,31,0,22,16};
    mapa[22].adyacentes = {16,21,0,32,24};
    mapa[23].adyacentes = {16,24,8};
    mapa[24].adyacentes = {22,23};
    mapa[25].adyacentes = {18,26,28};
    mapa[26].adyacentes = {19,25,29};
    mapa[27].adyacentes = {18,28,30};
    mapa[28].adyacentes = {27,25,29};
    mapa[29].adyacentes = {26,28,30};
    mapa[30].adyacentes = {29,27,19,20,21,31,0,32};
    mapa[31].adyacentes = {21,30,0};
    mapa[32].adyacentes = {22,0};
    mapa[33].adyacentes = {30,0};

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
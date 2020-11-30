#include <fstream>
#include <algorithm>
#include "videogame.h"

VideoGame::VideoGame(){}

void VideoGame::setUsuario(string &u){
    usuario = u;
}

string VideoGame::getUsuario(){
    return usuario;
}

void VideoGame::agregarCivilizacion(const Civilizacion &c)
{
    civilizaciones.push_back(c);
}

void VideoGame::mostrar()
{
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(21) << "Ubicacion en X";
    cout << setw(19) << "Ubicacion en Y";
    cout << setw(16) << "Puntuacion";
    cout << endl;

    for(size_t i = 0; i < civilizaciones.size(); i++){
        Civilizacion &c = civilizaciones[i];
        cout << c;
    }
}

void VideoGame::primeraCivilizacion(){
    if(civilizaciones.empty()){
                cout << "El vector esta vacio..." << endl;
            }
            else{
                cout << "Frente: "<< civilizaciones.front() << endl;
            }
            cin.get();
}

void VideoGame::ultimaCivilizacion(){
    if(civilizaciones.empty()){
                cout << "El vector esta vacio..." << endl;
            }
            else{
                cout << "Ultimo: " << civilizaciones.back() << endl;
            }
            cin.get();
}

void VideoGame::insertar(const Civilizacion &c, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

size_t VideoGame::size()
{
    return civilizaciones.size();
}

void VideoGame::inicializar(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

void VideoGame::eliminar(const Civilizacion &c)
{
    //civilizaciones.erase(civilizaciones.begin()+pos);
    civilizaciones.erase(std::remove(civilizaciones.begin(), civilizaciones.end(), c), civilizaciones.end());
}

void VideoGame::ordenarNombre()
{
    sort(civilizaciones.begin(), civilizaciones.end());
}

void VideoGame::ordenarUbicacionX()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionEnX() < c2.getUbicacionEnX();});
}

void VideoGame::ordenarUbicacionY()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionEnY() < c2.getUbicacionEnY();});
}

void VideoGame::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() < c2.getPuntuacion();});
}

Civilizacion* VideoGame::buscar(const Civilizacion &c)
{
    //vector<Civilizacion>::iterator it
    //auto it
    vector<Civilizacion>::iterator it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}

void VideoGame::borrar_ultimo()
{
    if(civilizaciones.empty()){
                cout << "El vector esta vacio..." << endl;
            }
            else{
                civilizaciones.pop_back();
            }
}
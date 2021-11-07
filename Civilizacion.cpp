#include "Civilizacion.h"

Civilizacion::Civilizacion (){

}

void Civilizacion::setNombre (const string &value){
    nombre = value;
}

string Civilizacion::getNombre (){
    return nombre;
}

void Civilizacion::setX (size_t value){
    x = value;
}

size_t Civilizacion::getX (){
    return x;
}

void Civilizacion::setY (size_t value){
    y = value;
}

size_t Civilizacion::getY (){
    return y;
}

void Civilizacion::setPuntuacion (float value){
    puntuacion = value;
}

float Civilizacion::getPuntuacion (){
    return puntuacion;
}

void Civilizacion::agregarFinal (const Aldeano &value){
    aldeanos.push_back (value);
}

void Civilizacion::agregarInicio (const Aldeano &value){
    aldeanos.push_front (value);
}

void Civilizacion::mostrarAldeanos (){
    cout << left;
    cout << setw (20) << "Nombre";
    cout << setw (20) << "Edad";
    cout << setw (25) << "Genero";
    cout << setw (30) << "Salud";
    cout << endl;

    //Las listas no tienen sobrecargado el operador [] para acceder a cada elemento.
    //Como los elementos no estan guardados en posiciones de memoria consecutivas, tenemos que usar iteradores para ir saltando
    //entre cada nodo de la lista. Al sumarle uno a it, se dirije al siguiente nodo de la lista.
    for (auto it = aldeanos.begin (); it != aldeanos.end (); it++){
        //Como it es una direccion de memoria, tenemos que usar el operador * para imprimir el contenido.
        cout << *it << endl;
    }
}

void Civilizacion::eliminarNombre (const string &value){
    for (auto it = aldeanos.begin (); it != aldeanos.end (); it++){
        Aldeano &a = *it;

        if (a.getNombre () == value){
            aldeanos.erase (it);

            break;
        }
    }
}

void Civilizacion::eliminarSalud (size_t value){
    aldeanos.remove_if ([value](const Aldeano &a){return a.getSalud() < value;});
}

bool comparadorEdad (const Aldeano &a){
    return a.getEdad () >= 60;
}

void Civilizacion::eliminarEdad (){
    aldeanos.remove_if (comparadorEdad);
}

void Civilizacion::ordenarNombre (){
    aldeanos.sort ();
}

void Civilizacion::ordenarEdad (){
    aldeanos.sort ([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad () > a2.getEdad ();});
}

void Civilizacion::ordenarSalud (){
    aldeanos.sort ([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud () > a2.getSalud ();});
}

Aldeano* Civilizacion::buscarAldeano (const string &value){
    for (auto it = aldeanos.begin (); it != aldeanos.end (); it++){
        Aldeano &a = *it;

        if (a.getNombre () == value){
            return &a;
        }
    }

    return nullptr;
}

void Civilizacion::modificarNombre (Aldeano &value, const string &nuevoNombre){
    value.setNombre (nuevoNombre);
}

void Civilizacion::modificarEdad (Aldeano &value, size_t nuevaEdad){
    value.setEdad (nuevaEdad);
}

void Civilizacion::modificarGenero (Aldeano &value, const string &nuevoGenero){
    value.setGenero (nuevoGenero);
}

void Civilizacion::modificarSalud (Aldeano &value, float nuevaSalud){
    value.setSalud (nuevaSalud);
}
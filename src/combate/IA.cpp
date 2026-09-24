#include "IA.hpp"
#include "Personaje.hpp"
#include <cmath>
#include <iostream>

IA::IA(Personaje& yoRef, Personaje& enemigoRef) 
: 
yo(&yoRef), enemigo(&enemigoRef), distanciaRespectoJugador(0.0f)
{
    actualizarDistancia();
}

float IA::getDistanciaRespectoJugador()
{
    return distanciaRespectoJugador;
}

void IA::actualizarDistancia()
{
    //Si no hay na pues que vas a calcular...
    if (!yo || !enemigo) 
    {
        return;
    }    

    // Aqui se calcula la distancia respecto al eje x (la y todavia no la tocamos)
    distanciaRespectoJugador = enemigo->getPosicion().x - yo->getPosicion().x;
}

void IA::soltarTodo()
{
    yo->detenerAccion(Accion::ARRIBA);
    yo->detenerAccion(Accion::ABAJO);
    yo->detenerAccion(Accion::IZQUIERDA);
    yo->detenerAccion(Accion::DERECHA);
    yo->detenerAccion(Accion::ATACAR);
}

void IA::bucleIA()
{
    //Si no hay na po no hay na, pon algo!
    if (!yo || !enemigo) 
    {
        return;
    }
    //Lo suelta.
    soltarTodo();
    //Actualiza la distancia
    actualizarDistancia();
    float distancia = getDistanciaRespectoJugador();
    //std::cerr << "La distancia es: " << distancia << "\n";
    //Esto es el rango en el que puede atacar... Le pega al bicho que tengo que matar
    const float RANGO_ATAQUE = 50.0f;

    /*Solo comprueba si esta cerca para atacar, si no esta cerca se acerca.
    Como la distancia puede ser positiva o negativa, usamos esto para saber si el personaje tiene que ir a la derecha o la izquierda
    Si es positiva eso quiere decir que el jugador esta a la derecha, entonces nos movemos a la derecha
    Si es negativa pues a la izquierda
    El caso de atacar solo tenemos que calcular el valor absoluto de la distancia y si esa distancia es menor que la variable RANGO_ATAQUE 
    la IA ataca
    */
    if (std::abs(distancia) <= RANGO_ATAQUE)
    {
        yo->realizarAccion(Accion::ATACAR);
    }
    else if (distancia > 0)
    {
        yo->realizarAccion(Accion::DERECHA);
    }
    else
    {
        yo->realizarAccion(Accion::IZQUIERDA);
    }

}
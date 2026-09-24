#pragma once

#include <SFML/Graphics.hpp>
class Personaje;

class IA
{
private:
    //yo -------> yo
    Personaje* yo;
    //el bicho que tengo que matar
    Personaje* enemigo;
    //cuanta distancia me saca el bicho que tengo que matar
    float distanciaRespectoJugador;
public:
    //El obrero o como se diga (constructor)
    IA(Personaje& yo,Personaje& enemigo);
    //Para tener la distancia que me saca el bicho que tengo que matar
    float getDistanciaRespectoJugador();
    //Para actualizar la distancia respecto al bicho
    void actualizarDistancia();
    //Suelta todas las teclas, porque se queda pillao si no
    void soltarTodo();
    //Mi cerebro
    void bucleIA();
};
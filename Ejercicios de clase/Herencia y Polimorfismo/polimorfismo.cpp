#include <iostream>
using namespace std;
//Definiciòn de clase Abstracta Animal
//Caracteristicas:  No puede ser instanciada; tiene que contar con minimo un mètodo abstracto puro
//En otros lenguajes se les denomina Interfaz
class Animal
{
public:
    virtual void sonidoAnimal()=0; //está en 0 porque es abstracto
    virtual void nombreAnimal ()=0;

};

class Cerdo : public Animal
{
public:
    void sonidoAnimal() override
    {
        cout << "El cerdo dice: wee wee " << endl;
    }

    void nombreAnimal() override
    {
        cout << "El nombre del cerdo es: wee " << endl;
    }

};
class Perro : public Animal
{
public:
    void sonidoAnimal() override
    {
        cout << "El perro dice: bow bow " << endl;
    }

    void nombreAnimal() override
    {
        cout << "El nombre del perro es: bow " << endl;
    }
};
int main()
{
    //Animal miAnimal;
    Cerdo miCerdo;
    Perro miPerro;
    Cerdo suCerdo;
    Perro suPerro;

    miCerdo.sonidoAnimal();
    miPerro.sonidoAnimal();
    suCerdo.nombreAnimal();
    suPerro.nombreAnimal();
    return 0;
}

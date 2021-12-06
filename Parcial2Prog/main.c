#include <stdio.h>
#include <stdlib.h>
tpedef struct
{
    int id;
    char marca[20];
    int tipo;
    float peso;
} eVehiculo;
int main()
{
    eVehiculo* vehiculo = {1000, "Suzuki", 1234, 500};

    FILE* f;
    FILE* fb;

    f = fopen("datos.txt", "w");
    if(f!=NULL)
    {
        fprintf(f, "ID,Marca,Tipo,Peso\n");
        fprintf(f, "%d,%s,%d,%f", vehiculo->id, vehiculo->marca, vehiculo->tipo, vehiculo->peso);
    }
    fclose(f);

    fb = fopen("datos.bin", "wb");

    if(fb!=NULL)
    {
        fwrite(vehiculo, sizeof(eVehiculo), 1, fb);
    }
    fclose(fb);


    return 0;
}
eVehiculo* funcionConstructora(eVehiculo* vehiculo)
{
    if(vehiculo!=NULL)
    {
        vehiculo->id = 0;
        strcpy(vehiculo->marca, "ND");
        vehiculo->tipo = 0;
        vehiculo->peso = 0;
    }

    return vehiculo;
}

eVehiculo* funcionParam(int id; char marca[], int tipo, float peso)
{
    eVehiculo* aux;

    aux = nuevoVehiculo();

    if(aux!=NULL)
    {
        aux->id = id;
        strcpy(aux->marca, marca);
        aux->tipo = tipo;
        aux->peso = peso;
    }


    return aux;
}


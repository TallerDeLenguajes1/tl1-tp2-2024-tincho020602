#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct
{
    int velocidad;  // entre 1 y 3 GHz
    int anio;       // entre 2015 y 2024
    int cantidad;   // entre 1 y 8
    char *tipo_cpu; // valores del arreglo tipos
} typedef compu;

void mostrarPCs(compu *pCompus);
void PCmasvieja(compu *pCompus);
void PCmasVeloz(compu *pCompus);

int main()
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon",
                         "Core", "Pentium"};
    compu compus[5];
    int tipo;
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        compus[i].anio = rand() % 10 + 2015;
        compus[i].velocidad = rand() % 3 + 1;
        compus[i].cantidad = rand() % 8 + 1;
        tipo = rand() % 6;
        compus[i].tipo_cpu = tipos[tipo];
    }
    compu *pCompus = compus;
    mostrarPCs(pCompus);
    PCmasvieja(pCompus);
    PCmasVeloz(pCompus);
    return 0;
}

void PCmasvieja(compu *pCompus){
    int antiguo=2025;//declaro con 2025 ya que los modelos varian hasta 2024
    int numeroPC;
    for (int i = 0; i < 5; i++)
    {
        if (pCompus[i].anio < antiguo)
        {
            antiguo = pCompus[i].anio;
            numeroPC=i;
        }
        
    }
    printf("\n\nLa PC numero:%d es la mas vieja, es del anio: %d",numeroPC+1,pCompus[numeroPC].anio);
    
}

void PCmasVeloz(compu *pCompus){
      int masVeloz=0;
    int numeroPC;
    for (int i = 0; i < 5; i++)
    {
        if (pCompus[i].velocidad > masVeloz)
        {
            masVeloz = pCompus[i].velocidad;
            numeroPC=i;
        }
        
    }
    printf("\n\nLa PC numero:%d es la que tiene mayor velocidad, con una velocidad de: %d",numeroPC+1,pCompus[numeroPC].velocidad);
}
void mostrarPCs(compu *pCompus)
{
    for (int i = 0; i < 5; i++)
    {
        printf("\n");
        printf("-------- PC numero: %d --------\n", i + 1);
        printf("Anio:");
        printf("%d\n", pCompus[i].anio);
        printf("Cantidad de nucleos:");
        printf("%d\n", pCompus[i].cantidad);
        printf("Velocidad:");
        printf("%d\n", pCompus[i].velocidad);
        printf("Tipo de CPU:");
        printf("%s\n", pCompus[i].tipo_cpu);
    }
}

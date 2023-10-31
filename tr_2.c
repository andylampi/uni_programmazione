/*
Sviluppare una function C che, dato come parametro di input un array di tipo struct punto double x; double y;
e il suo size, determina e restituisce come parametri di output gli indici dei due punti che hanno distanza minima tra loro.
I campi x e y contengono l’ascissa e l’ordinata, rispettivamente, di un punto.
*/
#include <stdio.h>
#include <stdlib.h>

// Costruisco la struttra dei dati che andranno all'interno dell'array
struct Points
{
    int x;
    int y;
};

// Dichiaro le funzioni
struct Points *createArr(int size);

int main()
{
    struct Points *arr_points;
    int size_arr; // Grandezza dell'array
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &size_arr); // Ottengo la grandezza dell'array
    arr_points = createArr(size_arr);    // Creo l'array di punti
    printf("%d", arr_points[0].x);
}

// Funzione che mi consente di creare l'array di punti
struct Points *createArr(int size)
{

    // Creo un puntatore di tipo Struct Points
    struct Points *arr_points;
    // Assegno una dimensione al puntatore precedentemente creato
    arr_points = (struct Points *)malloc(size * sizeof(struct Points));
    // Recupero i valori dell'autente
    for (int i = 0; i < size; i++)
    {
        struct Points points;
        printf("Insersci l'ascissa: ");
        scanf("%d", &points.x);
        printf("Inserisci l'ordinata: ");
        scanf("%d", &points.x);
        arr_points[i] = points;
    }
    return arr_points;
}


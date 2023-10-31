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
void sortArr(struct Points arr[], int size_arr);
void printArr(struct Points arr[], int nmb);

int main()
{
    struct Points *arr_points;
    int size_arr; // Grandezza dell'array
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &size_arr);           // Ottengo la grandezza dell'array
    arr_points = createArr(size_arr); // Creo l'array di punti
    sortArr(arr_points, size_arr);    // Ordino l'array
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

// Funzione per riordinare l'array
void sortArr(struct Points arr[], int size_arr)
{
    // Recupero il primo punto dell'array, questa variabile conterrà il punto precedente a quello attuale
    struct Points prec = arr[0];
    for (int i = 1; i < size_arr; i++)
    {
        if (prec.x > arr[i].x)
        {
            // Recupero il valore del punto attuale
            struct Points point_mom = arr[i];
            // Sostituisco il valore del punto attuale con quello precedente
            arr[i] = prec;
            // Sostituisco il valore del punto precedente con quello attuale
            arr[i - 1] = point_mom;
        }
        prec = arr[i];
    }

    printArr(arr, size_arr);
}




// Funzione per visualizzare i valori all'interno dell'array
void printArr(struct Points arr[], int nmb)
{
    printf("La lunghezza e' %d \n", nmb);
    for (int i = 0; i < nmb; i++)
    {
        printf("%d \n", arr[i].x);
    }
}
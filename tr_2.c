/*
Sviluppare una function C che, dato come parametro di input un array di tipo struct punto double x; double y;
e il suo size, determina e restituisce come parametri di output gli indici dei due punti che hanno distanza minima inferiore alle altre.
I campi x e y contengono l’ascissa e l’ordinata, rispettivamente, di un punto.
L'algoritmo adottato per trovare la distanza minima ha una complessità temporale O(n^2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Costruisco la struttra dei dati che andranno all'interno dell'array
struct Points
{
    int x;
    int y;
};

// Dichiaro le funzioni
struct Points *createArr(int size);
struct Points *findPoints(struct Points arr[], int size_arr);
void printArr(struct Points arr[], int nmb);

int main()
{
    // Array di tutti punti acquisti
    struct Points *arr_points;
    // Array con i punti con la distanza minima inferiore alle altre
    struct Points *arr_points_with_min_dist;
    int size_arr; // Grandezza dell'array
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &size_arr);                                      // Ottengo la grandezza dell'array
    arr_points = createArr(size_arr);                            // Creo l'array dei punti
    arr_points_with_min_dist = findPoints(arr_points, size_arr); // Trova i punti con la distanza minima inferiore alle altre
    printArr(arr_points_with_min_dist, 2);                       // Stampa i valori dei punti minimi ottenuti
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
        scanf("%d", &points.y);
        arr_points[i] = points;
    }
    return arr_points;
}

// Funzione per trovare i punti con la distanza minima inferiore alle altre
struct Points *findPoints(struct Points arr[], int size_arr)
{
    // Array che contiene  i punti che hanno la distanza inferiore agli altri punti
    struct Points *arr_points;
    // Assegno una dimensione al puntatore precedentemente creato
    arr_points = (struct Points *)malloc(size_arr * sizeof(struct Points));
    // variabile che conterrà la distanza minima trovata
    int distance_min = INT_MAX;
    // Confronto ogni punto
    for (int i = 0; i < size_arr; i++)
    {
        for (int idx = 0; idx < size_arr; idx++)
        {
            // Se i punti sono uguali passo avanti
            if (arr[idx].x != arr[i].x && arr[idx].y != arr[i].y)
            {
                // calcolo la distanza
                int distance = sqrt(pow((arr[idx].x - arr[i].x), 2) + pow((arr[idx].y - arr[i].y), 2));
                // verifico se la nuova distanza sia minore di quella già registrata precedentemente
                if (distance < distance_min)
                {
                    distance_min = distance;
                    arr_points[0] = arr[i];
                    arr_points[1] = arr[idx];
                }
            }
        }
    }
    return arr_points;
}

// Funzione per visualizzare i valori all'interno dell'array
void printArr(struct Points arr[], int nmb)
{
    printf("La lunghezza e' %d \n", nmb);
    for (int i = 0; i < nmb; i++)
    {
        printf("%d %d \n", arr[i].x, arr[i].y);
    }
}
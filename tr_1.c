/* Sviluppare una function C che, dati come parametri di input un array di int e il suo
     size, determina e restituisce come parametro di output il secondo più grande
     elemento dell’array (N.B.: non bisogna seguire l’idea di ordinare prima l’array).
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Dichiaro la funzione che permette di trovare il secondo numero più grande
int findSecondNmb(int arr[], int size_arr);

int main()
{
    int size_arr;   // Dimensione dell'array
    int *arr;       // Puntatore per costruire un array dinamico
    int second_nmb; // Variabile conterrà il secondo numero più grande dell'array
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &size_arr);                      // Ottiene la grandezza dell'array
    arr = (int *)malloc(size_arr * sizeof(int)); // crea l'array con dimensione presa da input
    for (int i = 0; i < size_arr; i++)           // Popola l'array
    {
        printf("Inserisci il numero: ");
        scanf("%d", &arr[i]);
    }
    second_nmb = findSecondNmb(arr, size_arr);                  // Ritorna il secondo numero più grande
    printf("Il secondo numero piu' grande e': %d", second_nmb); // Stampa il numero trovato
    free(arr);                                                  // Libera la memoria occupata dall'array dinamico
}

int findSecondNmb(int arr[], int size_arr)
{
    int first = 0, second = 0; // first sarebbe il numero più grande, second il secondo numero più grande
    for (int i = 0; i < size_arr; i++)
    {
        /* Controlla se il numero attuale è maggiore di quello memorizzato precedentemente,
        se ciò è vero il numero precedentemente memorizzato diventa il secondo numero if (arr[i] > first)
         */
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        /*
            Controlla se il numero attuale è maggiore del secondo numero memorizzato precedentemente,
            se ciò è vero il numero attuale sarà il nuovo secondo numero più grande
        */
        else
        {
            if (arr[i] > second)
            {
                second = arr[i];
            }
        }
    }
    return second;
}

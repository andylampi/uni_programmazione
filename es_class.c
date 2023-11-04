/*
    Realizzare un main in C che legge da tastiera un array 2d
    di tipo double(insieme al numero effettivo delle colonne e righe)
    e calcola, visualizzando su schermo
    1. media di ogni riga
    2. la media di ogni colonna
    3. la somma dei quadrati degli elementi
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// dichiaro le funzioni che consentono di eseguire i compiti assegnati
double *calcMediaRig(int nmr_righe, int nmr_colonne, double **arr);
double *calcMediaCol(int nmr_righe, int nmr_colonne, double **arr);
double somElemAllaScnd(int nmr_righe, int nmr_colonne, double **arr);
void printArr(double *arr, int size);

// funzione principale
int main()
{
    int nmr_colonne, nmr_righe;          // numero di colonne e di righe che avrà la matrice
    double *medie_colonne, *medie_righe; // array contenenti le medie
    double somm_qdr_el = 0;              // contiene la somma totale degli elementi alla seconda
    // acquisisco il numero di colonne e di righe
    printf("Inserisci il numero di righe: ");
    scanf("%d", &nmr_righe);
    double **arr = (double **)malloc(nmr_righe * sizeof(double *)); // creo l'array in modo dinamico
    printf("Inserisci il numero di colonne: ");
    scanf("%d", &nmr_colonne);

    for (int i = 0; i < nmr_righe; i++)
    {
        // crea le colonne all'interno di ogni riga dinamicamente
        arr[i] = (double *)malloc(nmr_colonne * sizeof(double));
        for (int z = 0; z < nmr_colonne; z++)
        {
            printf("Inserisci il valore per la riga %d della  colonna %d: ", i, z);
            // Acquisisce il valore da assegnare ad ogni cella
            scanf("%lf", &arr[i][z]);
        }
    }
    medie_righe = calcMediaRig(nmr_righe, nmr_colonne, arr);
    medie_colonne = calcMediaCol(nmr_righe, nmr_colonne, arr);
    somm_qdr_el = somElemAllaScnd(nmr_righe, nmr_colonne, arr);

    printf("%s \n", "Righe");
    printArr(medie_righe, nmr_righe);
    printf("%s \n", "Colonne");
    printArr(medie_colonne, nmr_colonne);
    printf("La somma totale dei quadrati degli elementi: ");
    printf("%lf", somm_qdr_el);
}

// Calcolare la media di tutte le righe
double *calcMediaRig(int nmr_righe, int nmr_colonne, double **arr)
{
    // Array che contiene tutte le medie calcolate
    double *medie = (double *)malloc(nmr_righe * sizeof(double));
    // Media di ogni singola riga
    double media;
    for (int i = 0; i < nmr_righe; i++)
    {
        media = 0;
        for (int z = 0; z < nmr_colonne; z++)
        {
            media += arr[i][z];
        }
        medie[i] = media / nmr_colonne;
    }
    return medie;
}

// Calcola la media di tutte le colonne
double *calcMediaCol(int nmr_righe, int nmr_colonne, double **arr)
{
    // Array che contiene tutte le medie calcolate
    double *medie = (double *)malloc(nmr_colonne * sizeof(double));
    // Media di ogni singola colonna
    double media;
    for (int i = 0; i < nmr_colonne; i++)
    {
        media = 0;
        for (int z = 0; z < nmr_righe; z++)
        {
            media += arr[z][i];
        }
        medie[i] = media / nmr_righe;
    }
    return medie;
}

// Calcola la somma di tutti gli elementi alla seconda
double somElemAllaScnd(int nmr_righe, int nmr_colonne, double **arr)
{
    // Contiene la somma di tutti gli elementi alla seconda
    double somma = 0;
    for (int i = 0; i < nmr_righe; i++)
    {
        for (int z = 0; z < nmr_colonne; z++)
        {
            somma += pow(arr[i][z], 2);
        }
    }
    return somma;
}

// Funzione per visualizzare i valori all'interno dell'array
void printArr(double *arr, int size)
{
    printf("Le medie sono: %d \n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%lf\n", arr[i]);
    }
}

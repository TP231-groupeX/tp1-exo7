include <stdio.h>

void triTableau(int tableau[], int taille) {
    int i, j, min, temp;
    
    for(i = 0; i < taille - 1; i++) {
        min = i;
        for(j = i + 1; j < taille; j++) {
            if(tableau[j] < tableau[min]) {
                min = j;
            }
        }
        temp = tableau[i];
        tableau[i] = tableau[min];
        tableau[min] = temp;
    }
}

float calculerMediane(int tableau[], int taille) {
    triTableau(tableau, taille);
    if(taille % 2 == 1) {
        return tableau[taille / 2];
    }
    else {
        return (tableau[taille / 2 - 1] + tableau[taille / 2]) / 2.0;
    }
}

int main() {
    int taille, i;
    
    printf("Entrez la taille du tableau : ");
    scanf("%d", &taille);
    
    int tableau[taille];
    
    printf("Entrez les éléments du tableau :\n");
    for(i = 0; i < taille; i++) {
        printf("Élément %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }
    
    printf("\nTableau original :\n");
    for(i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
    
    float mediane = calculerMediane(tableau, taille);
    
    printf("\nTableau trié :\n");
    for(i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
    
    printf("\nLa médiane du tableau est : %.2f\n", mediane);
    
    return 0;
}

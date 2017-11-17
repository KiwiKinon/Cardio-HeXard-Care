#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define TAILLE_MAX 10000

int main(){
tableau valeur;
int b,a,c, stack,d,e,f, g;
int i=0, j=0, k=0;
float stock,h=0.0;

//Ouverture du fichier csv et stockage des valeurs lu dans des tableau
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";

    fichier = fopen("D:\\Cours\\Projet 1\\Programme arduino\\Processing\\Battements.csv", "r");

    if (fichier != NULL){
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) {
            sscanf(chaine, "%f;%d", &valeur.val[i], &valeur.temps[i]);
            i++;
        }
        a=i;
        fclose(fichier);
    }
    else {
        printf("Le fichier n'as pas pu etre ouvert");
    }
//Menu
printf("Menu : \n 1.Afficher les donnees dans l'ordre du fichier CSV \n 2.Afficher les donnee en ordre croissant ou decroissant ( suivant le temps ou le Poul)\n 3.Rechercher un temps particulier\n 4.Afficher la moyenne de Pouls dans une période de temps\n 5.Afficher le nombre de ligne actuellement en mémoire\n Rentrez n'importe quel autre valeur pour quitter le programme\n");
scanf("%d", &b);

switch(b){
    //affichages des donnée présente dans le fichier csv
    case 1 :
        for (i=1; i<a; i++){
            printf("valeur = %.2f \n",valeur.val[i]);
            printf("temps = %d \n\n", valeur.temps[i]);
        }
    break;

    //Algorythme de tris
    case 2 :
        printf("1.Poul : Croissant \n2.Poul : Decroissant\n3.Temps : Croissant \n4.Temps : Decroissant\n");
        scanf("%d",&c);
        switch(c){
            // poul croissant
            case 1 :

            for (j=0; j<97; j++){
                for (i=0; i<97; i++){
                    if ( valeur.val[i] > valeur.val[i+1]){
                        stock = valeur.val[i];
                        valeur.val[i] = valeur.val[i+1];
                        valeur.val[i+1] = stock;

                        stack = valeur.temps[i];
                        valeur.temps[i] = valeur.temps[i+1];
                        valeur.temps[i+1] = stack;
                    }
                }
                }
                for (i=1; i<97; i++){
                    printf("valeur = %.2f \n",valeur.val[i]);
                    printf("temps = %d \n\n", valeur.temps[i]);
                }

            break;

            //poul decroissant
            case 2 :
                for (j=0; j<97; j++){
                for (i=0; i<97; i++){
                    if ( valeur.val[i] < valeur.val[i+1]){
                        stock = valeur.val[i];
                        valeur.val[i] = valeur.val[i+1];
                        valeur.val[i+1] = stock;

                        stack = valeur.temps[i];
                        valeur.temps[i] = valeur.temps[i+1];
                        valeur.temps[i+1] = stack;
                    }
                }
                }
                for (i=1; i<97; i++){
                    printf("valeur = %.2f \n",valeur.val[i]);
                    printf("temps = %d \n\n", valeur.temps[i]);
                }

            break;

            //temps croissant
            case 3 :
                for (j=0; j<97; j++){
                for (i=0; i<97; i++){
                    if ( valeur.temps[i] > valeur.temps[i+1]){
                        stock = valeur.val[i];
                        valeur.val[i] = valeur.val[i+1];
                        valeur.val[i+1] = stock;

                        stack = valeur.temps[i];
                        valeur.temps[i] = valeur.temps[i+1];
                        valeur.temps[i+1] = stack;
                    }
                }
                }
                for (i=1; i<97; i++){
                    printf("valeur = %.2f \n",valeur.val[i]);
                    printf("temps = %d \n\n", valeur.temps[i]);
                }
            break;

            //temps decroissant
            case 4 :
                for (j=0; j<97; j++){
                for (i=0; i<97; i++){
                    if ( valeur.temps[i] < valeur.temps[i+1]){
                        stock = valeur.val[i];
                        valeur.val[i] = valeur.val[i+1];
                        valeur.val[i+1] = stock;

                        stack = valeur.temps[i];
                        valeur.temps[i] = valeur.temps[i+1];
                        valeur.temps[i+1] = stack;
                    }
                }
                }
                for (i=1; i<97; i++){
                    printf("valeur = %.2f \n",valeur.val[i]);
                    printf("temps = %d \n\n", valeur.temps[i]);
                }
            break;
        }



    break;

    //recherche valeurs suivant un temps demandé
    case 3 :
    printf("Quel temps recherchez vous ?");
    scanf("%d",&d);
    i=1;
    while (valeur.temps[i] < d){
        i++;
    }
    if ( valeur.temps[i] == d){
        printf("La valeur la plus proche de %d est %d avec une valeur de %f",d,valeur.temps[i],valeur.val[i]);
    }
    else if ( (valeur.temps[i] - d) < (valeur.temps[i-1]-d)){
        printf("La valeur la plus proche de %d est %d avec une valeur de %f",d,valeur.temps[i],valeur.val[i]);
    }
    else {
        printf("La valeur la plus proche de %d est %d avec une valeur de %f",d,valeur.temps[i-1],valeur.val[i-1]);
    }
    break;

    //Moyenne dan une plage de temps demandé
    case 4 :

    printf("Rentrez votre premier temps ?");
    scanf("%d",&e);
    i=1;
    while (valeur.temps[i] < e){
        i++;
    }
    if ( valeur.temps[i] == e || (valeur.temps[i] - e) < (valeur.temps[i-1]-e)){
    }
    else {
        i--;
    }

    printf("Rentrez votre deuxième temps ?");
    scanf("%d",&f);
    j=1;
    while (valeur.temps[j] < f){
        j++;
    }
    if ( valeur.temps[j] == f || (valeur.temps[j] - f) < (valeur.temps[j-1]-f)){
    }
    else {
        j--;
    }

    //si la première valeur de temps est supérieur à la seconde, les inverses
    if( valeur.temps[i] > valeur.temps[j]){
        g=i;
        i=j;
        j=g;
    }

    g=j-i;// calcul du nombre de valeur
    //addition des valeurs
    for(k=0; k<=g; k++){
        h = h + valeur.val[i+k];
    }
    //moyenne
    h=h/k;
    printf("La moyenne entre vos deux temps est de %f",h);

    break;

    case 5 :
        a += 2; // car on ne prend pas en compte la 1er valeur car fausse et qu'elle décalle la dernière valeur qui n'est alors plus comptabilisée
        printf("Il y a actuellement %d lignes.",a);
    break;

    default:
        return 0;
    break;
}

return 0;
}









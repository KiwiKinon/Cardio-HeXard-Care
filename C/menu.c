#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "GenerationCode.h"

int menu(){
    int choix;
    printf("Menu : \nChoisissez le mode de clignotement des LEDs :\n");
    printf("-1. Remplissage progressif\n");
    printf("-2. Clignotement total\n");
    printf("-3. Chenille\n");
    printf("-4. Une LED sur deux\n");
    printf("-5. Une LED sur trois\n");
    printf("-6. Une LED sur quatre\n");
    printf("-7. Choisir la LED %c allume\nr", 133);
    printf("-8. Roue infinie\n");
    printf("-9.Remplissage / D%cremplissage\n", 130);
    scanf("%i",&choix); // Demande à l'utilisateur le mode de clignotement
    //Permet de sélectionner le programme voulu
    switch(choix){
        //Mode 1 : Clignotement progressif
        case 1:
            printf("\nConfiguration sur le mode de clignotement : Remplissage progressif");
            break;
        //Mode 2 : Clignotement total
        case 2:
            printf("\nConfiguration sur le mode de clignotement : Clignotement total");
            break;
        //Mode 3 : Chenille
        case 3:
            printf("\nConfiguration sur le mode de clignotement : Chenille");
            break;
        //Mode 4 : Une LED sur deux
        case 4:
            printf("\nConfiguration sur le mode de clignotement : Une LED sur deux");
            break;
        //Mode 5 : Une LED sur trois
        case 5:
            printf("\nConfiguration sur le mode de clignotement : Une LED sur trois");
            break;
        //Mode 6 : Une LED sur quatre
        case 6:
            printf("\nConfiguration sur le mode de clignotement : Une LED sur quatre");
            break;
        //Mode 7 : Une LED au choix
        case 7:
            printf("\nConfiguration sur le mode de clignotement : Une LED au choix");
            break;
        //Mode 8 : Roue infinie
        case 8:
            printf("\nConfiguration sur le mode de clignotement : Roue infinie");
            break;
        //Mode 9 : Déremplissage
        case 9:
            printf("\nConfiguration sur le mode de clignotement : Remplissage & D%cremplissage", 130);
            break;
        //Autre résultat : Le programme reçoit un autre nombre que celui demandé.
        default:
            printf("\nERREUR : Le nombre entr%c n'est pas propos%c ! Merci de r%cessayer ... \n\n", 130, 130, 130);
            menu();
            break;
    }
    return choix; // Le programme renvoie la valeur du choix demandée au début du programme
}

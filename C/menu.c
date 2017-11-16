#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "GenerationCode.h"

int menu(){
    int choix;
    printf("Menu : \nChoisissez le mode de clignotement des LED :\n -1.Remplissage progressif \n -2.Clignotement total \n -3.Chenille \n -4.Une LED sur deux \n -5.Une LED sur trois \n -6.Une LED sur quatre \n -7.Choisir la LED \x85 allumer \n -8.Roue infinie \n -9.Remplissage/D\x82remplissage\n");
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
            printf("\nConfiguration sur le mode de clignotement : Remplissage & D\x82remplissage");
            break;
        //Autre résultat : Le programme reçoit un autre nombre que celui demandé.
        default:
            printf("\nERREUR : Le nombre entr\x82 n'est pas propos\x82 ! Merci de r\x82""essayer ... \n\n");
            menu();
            break;
    }
    return choix; // Le programme renvoie la valeur du choix demandée au début du programme
}

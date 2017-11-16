#include <stdio.h>
#include <stdlib.h>
#include "GenerationCode.h"

void GenCode(int Programme){
    printf("\nG\x82n\x82ration du Code en cours ...\n");
    // TODO : REALISER LE PROGRAMME DE GENERATION DU CODE !
    FILE* fichier = NULL;
    fichier = fopen("param.h", "w");
    if (fichier != NULL){
        switch(Programme){
            //Mode 1 : Clignotement progressif
            case 1:
                fputs("#ifndef PARAM_H_INCLUDED\n#define PARAM_H_INCLUDED\n\nvoid RempProgress();\n\n#endif", fichier);
                break;
            //Mode 2 : Clignotement total
            case 2:
                fputs("#ifndef PARAM_H_INCLUDED\n#define PARAM_H_INCLUDED\n\nvoid ClignoTotal();\n\n#endif", fichier);
                break;
            //Mode 3 : Chenille
            case 3:
                fputs("#ifndef PARAM_H_INCLUDED\n#define PARAM_H_INCLUDED\n\nvoid Chenille();\n\n#endif", fichier);
                break;
            //Mode 4 : Une LED sur deux
            case 4:
                fputs("#ifndef PARAM_H_INCLUDED\n#define PARAM_H_INCLUDED\n\nvoid UnsurDeux();\n\n#endif", fichier);
                break;
            //Mode 5 : Une LED sur trois
            case 5:
                fputs("#ifndef PARAM_H_INCLUDED\n#define PARAM_H_INCLUDED\n\nvoid UnsurTrois();\n\n#endif", fichier);
                break;
            //Mode 6 : Une LED sur quatre
            case 6:
                fputs("#ifndef PARAM_H_INCLUDED\n#define PARAM_H_INCLUDED\n\nvoid UnsurQuatre();\n\n#endif", fichier);
                break;
            //Mode 7 : Une LED au choix
            case 7:
                fputs("#ifndef PARAM_H_INCLUDED\n#define PARAM_H_INCLUDED\n\nvoid LEDChoix(int LED);\n\n#endif", fichier);
                break;
            //Mode 8 : Roue infinie
            case 8:
                fputs("#ifndef PARAM_H_INCLUDED\n#define PARAM_H_INCLUDED\n\nvoid Roueinfinie();\n\n#endif", fichier);
                break;
            //Mode 9 : Déremplissage
            case 9:
                fputs("#ifndef PARAM_H_INCLUDED\n#define PARAM_H_INCLUDED\n\nvoid RempDeremp();\n\n#endif", fichier);
                break;
            //Autre résultat : Le programme reçoit un autre nombre que celui demandé.
            default:
                printf("\nERREUR : Le nombre entr\x82 n'est pas propos\x82 ! Merci de r\x82""essayer ... \n\n");
                menu();
                break;
        }
        fclose(fichier);
    }
    printf("G\x82n\x82ration termin\x82""e");
}

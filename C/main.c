#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "GenerationCode.h"

int main()
{
    int choix = menu(); //On récupère la valeur du choix.
    GenCode(choix); //Génére le code à partir de ce choix.
    return 0;
}

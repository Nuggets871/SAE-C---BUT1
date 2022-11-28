#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define chemin "Promotion.txt"
#define chemin2 "PromotionTemp.txt"

typedef struct Etudiant {
int Num;
char Nom[40];
char Prenom[40];
char Filiere[40];
} Etud;

Etud E;

void ajouterEtudiant(int);
void afficherPromotion();
void modifierNomEtudiant(int);
void supprimerEtudiant(int);

void saisirNum(int*);
bool rechercherEtudiant(int);

int main(){

int choix;
int numEtudiant;


do
{
system("cls");
printf("\n ***************** MENU ***************** \n");
printf("1.Ajouter un nouvel \202tudiant\n");
printf("2.Afficher le contenu de la promotion\n");
printf("3.Modifier le nom d'un \202tudiant\n"); // ou bien \o202
printf("4.Supprimer un \202tudiant\n");
printf("5.Quitter le programme\n");
printf("\n ****************************************  \n");
printf("\nIntroduire votre choix: ");
scanf("%d",&choix);
fflush(stdin);

switch (choix)
{
case 1:
    saisirNum(&numEtudiant);
    ajouterEtudiant(numEtudiant);
break;

case 2: afficherPromotion();
break;

case 3: saisirNum(&numEtudiant);
    modifierNomEtudiant(numEtudiant);
break;

case 4: saisirNum(&numEtudiant);
    supprimerEtudiant(numEtudiant);
break;
}
printf("\n");
system("pause");
} while(choix!=5);

return 0;

}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


void saisirNum(int* numEtud){
printf("\n Saisir le numero de l'etudiant:");
 scanf("%d", numEtud);
 fflush(stdin); // libérer la zone mémoire associé au flot standard stdin pour anticiper toute nouvelle lecture
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


bool rechercherEtudiant(int NumEtud) {
    FILE* flot;
    flot=fopen(chemin,"r");
if (flot!=NULL){
    do{
        fscanf(flot, "%d ;%s ;%s ;%s \n", &E.Num, E.Nom, E.Prenom, E.Filiere);
        //fflush(stdin);
        if (E.Num == NumEtud) {
            fclose(flot);
            return true;
        }
    }
    while (!feof(flot));
}
fclose(flot);
return false;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void ajouterEtudiant(int numEtud){
FILE* flot;
flot=fopen(chemin,"a");

while (rechercherEtudiant(numEtud)){
    printf("\n Ce numero existe deja:");
    printf("\n Saisir le numero du nouveau etudiant:");
    scanf("%d", &numEtud);
}

E.Num=numEtud;
printf("\n Saisir le nom du nouvel etudiant:");
gets(E.Nom);
fflush(stdin);
printf("\n Saisir le prenom du nouvel etudiant:");
gets(E.Prenom);
fflush(stdin);
printf("\n Saisir la filiere du nouvel etudiant:");
gets(E.Filiere);
fflush(stdin);
fprintf(flot, "%d ;%s ;%s ;%s \n", E.Num, E.Nom, E.Prenom, E.Filiere);
 //fflush(stdin);
fclose(flot);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
}

void afficherPromotion(){
FILE* flot;
flot=fopen(chemin,"r");

if (flot!=NULL){

do{
    fscanf(flot, "%d ;%s ;%s ;%s \n", &E.Num, E.Nom, E.Prenom, E.Filiere);
    //fflush(stdin);
    printf("\n Num \t %d \t Nom \t %s \t Prenom \t %s Filiere \t \n", E.Num, E.Nom, E.Prenom, E.Filiere);
} while (!feof(flot));

} else {printf("Promotion vide");}
fclose(flot);
return false;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void modifierNomEtudiant(int numEtud){
char nouveauNom[40];

if (rechercherEtudiant(numEtud)){

        FILE* flot, *flot1;
        flot=fopen(chemin,"r");
        flot1=fopen(chemin2,"a");

        do{
            fscanf(flot, "%d ;%s ;%s ;%s \n", &E.Num, E.Nom, E.Prenom, E.Filiere);
            //fflush(stdin);

            if (numEtud!=E.Num) fprintf(flot1, "%d ;%s ;%s ;%s \n", E.Num, E.Nom, E.Prenom, E.Filiere);
            else{
                printf("Saisir le nouveau nom:");
                gets(nouveauNom);
                fprintf(flot1, "%d ;%s ;%s ;%s \n", E.Num, nouveauNom, E.Prenom, E.Filiere);
            }

        }while (!feof(flot));

        fclose(flot);
        fclose(flot1);

        remove(chemin);
        rename(chemin2,chemin);

        printf("Modification effectuee avec succes:\n");
}
else printf("Numero inexistant");

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


void supprimerEtudiant(int numEtud){
char rep;

if (rechercherEtudiant(numEtud)){
    printf("Voulez-vous vraiment supprimer cet etudiant o/n ?");
    scanf("%c", &rep);
    if (rep == 'o' || rep== 'O') {
        FILE* flot, *flot1;
        flot=fopen(chemin,"r");
        flot1=fopen(chemin2,"a");

        do{
           fscanf(flot, "%d ;%s ;%s ;%s \n", &E.Num, E.Nom, E.Prenom, E.Filiere);
           //fflush(stdin);
           if (numEtud!=E.Num) fprintf(flot1, "%d ;%s ;%s ;%s \n", E.Num, E.Nom, E.Prenom, E.Filiere);
        }while (!feof(flot));

        fclose(flot);
        fclose(flot1);

        remove(chemin);
        rename(chemin2,chemin);

        printf("Suppression effectuee avec succes:\n");
    }
}
else printf("Numero inexistant");
}







#include <stdio.h>
#define chemin "petitExemple.csv"

typedef struct client {
char nom[40];
char prenom[40];
char ville[10];
int CodePost;
int telephone;
char mail[20];
char profession[20];

} CLIENT;


void charger (){
FILE* flot;
CLIENT c;
flot=fopen(chemin,"r");

if (flot!=NULL){

        printf("voici le contenu du fichier\n");
do {
    fscanf(flot, "%s, %s, %s, %d, %d, %s, %s", c.nom, c.prenom, c.ville, &c.CodePost, &c.telephone, c.mail, c.profession);
    printf("\n %s; %s; %s; %d; %d; %s; %s\n",  c.nom, c.prenom, c.ville, c.CodePost, c.telephone, c.mail, c.profession);

}
while (!feof(flot));
fclose(flot);
}
}








int main () {

    charger();

return(0);


}

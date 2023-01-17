#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_LONGUEUR_CHAMP 1000
#define MAX_LONGUEUR_LIGNE 1000
#define MAX_ADRESSES_MEL 1000




char mon_annuaire[MAX_LONGUEUR_CHAMP];

void ajouter_client(char* annuaire);
void afficher_clients(char* annuaire) ;
int afficher_trier_par_nom(char* annuaire);
void afficher_donnee_manquante(char* annuaire);

int main(){
	int menu2=0,choix;
	//Choix de l'annuaire dans laguel la saisie ya s'éffectuer
    printf ("Saisissez le nom de votre annuaire (Exemple : exemple.csv)  : ");
    scanf ("%s", &mon_annuaire);
	printf("1. Ajout de nouveau client\n");
	printf("2. Modification des données sur un client\n");
	printf("3. Suppression d'un client\n");
	printf("4. Afficher tous les clients\n");
	printf("5. Afficher tous les clients triés par leur nom \n");
	printf("6. Afficher les clients filtrer par un champ\n");
	printf("7. Afficher les clients filtrer par deux champ\n");
	printf("8. Afficher les clients avec données manquantes\n");
	printf("9. Quiter\n");


	while (1) {
		if (menu2==1){
			printf("\n\n=====================================================================================================================================");
			printf("\n1.Ajout  2.Modifier  3.Supprimer  4.Afficher  5.Afficher trier  6.Filtrer 1  7.Filtrer 2  8.Afficher données manquantes  9.Quitter\n");
			printf("=========================================================================================================================================");
		}

		menu2=1;
		printf("\n Votre choix: ");
		scanf("%d",&choix);
		printf("\n\n");
		switch (choix)
		{
		case 1:
		    ajouter_client(mon_annuaire);
			printf("\nAJOUT DE CLIENT REUSSI\n\n");
			break;
		case 2:
			printf("\nMODIFICATION DES DONNEES REUSSI\n\n");
			break;
		case 3:
			printf("\nCLIENT SUPPRIME AVEC SUCCES\n\n");
			break;
		case 4:
		    afficher_clients(mon_annuaire);
			printf("\nAFFICHAGE REUSSI\n\n");
			break;
		case 5:
		    afficher_trier_par_nom(mon_annuaire);
		    printf("AFFICHAGE REUSSI\n\n");
		    break;
		case 6:
		    printf("\nFILTRAGE REUSSI\n\n");
			break;
        case 7:
            printf("\nFILTRAGE REUSSI\n\n");
			break;
        case 8:
            afficher_donnee_manquante(mon_annuaire);
            printf("\nAFFICHAGE REUSSI\n\n");
			break;
		case 9:
			printf("\nAU REVOIR!\n");
			return 0;
		default:
			printf("\nERREUR DANS LE CHOIX");
			break;
		}
	}
}


//============================================================================== AJOUT CLIENT



const char *adresses_mel_existantes[MAX_ADRESSES_MEL];
int nb_adresses_mel_utilisees = 0;

int adresse_mel_existe_deja(const char *adresse_mel) {
    for (int i = 0; i < nb_adresses_mel_utilisees; i++) {
        if (strcmp(adresses_mel_existantes[i], adresse_mel) == 0) {
            return 1;
        }
    }
    return 0;
}


void ajouter_client(char* annuaire)
{
char prenom[MAX_LONGUEUR_CHAMP], nom[MAX_LONGUEUR_CHAMP], code_postal[MAX_LONGUEUR_CHAMP], ville[MAX_LONGUEUR_CHAMP], telephone[MAX_LONGUEUR_CHAMP], adresse_mel[MAX_LONGUEUR_CHAMP], profession[MAX_LONGUEUR_CHAMP];


   // Ouvre le fichier en mode d'ajout (append)
  FILE *fic = fopen(annuaire, "a");


  // Vérifie si le fichier a été ouvert correctement
  if (fic == NULL)
  {
    perror("Erreur lors de l'ouverture du fichier");

    return;
  }

    printf("Saisissez le prenom du client ou tapez 'skip' pour passer a la suite : ");
      scanf("%s", &prenom);
      if (strcmp(prenom, "skip") == 0) { //Si "skip" est entré alors
        strcpy(prenom, ""); //prenom_p est un champ vide
      }



    printf("Saisissez le nom du client ou tapez 'skip' pour passer a la suite : ");
      scanf("%s", &nom);
      if (strcmp(nom, "skip") == 0) { //Si "skip" est entré alors
        strcpy(nom, ""); //nom_p est un champ vide
      }

    printf("Saisissez le code_p du client ou tapez 'skip' pour passer a la suite : ");
      scanf("%s", &code_postal);
      if (strcmp(code_postal, "skip") == 0) { //Si "skip" est entré alors
        strcpy(code_postal, ""); //code_p est un champ vide
      }

    printf("Saisissez la ville du client ou tapez 'skip' pour passer a la suite : ");
      scanf("%s", &ville);
      if (strcmp(ville, "skip") == 0) { //Si "skip" est entré alors
        strcpy(ville, ""); //ville est un champ vide
      }

    printf("Saisissez le numéro de téléphone du client ou tapez 'skip' pour passer a la suite : ");
      scanf("%s", &telephone);
      if (strcmp(telephone, "skip") == 0) { //Si "skip" est entré alors
        strcpy(telephone, ""); //num_telephone est un champ vide
      }

    printf("Saisissez le adresse_mel du client (obligatoire)");
      scanf("%s", &adresse_mel);

    while (adresse_mel_existe_deja(adresse_mel)) {
          printf("Cette adresse e-mail existe déjà dans l'annuaire. Impossible d'ajouter un client avec la même adresse e-mail.\n");
          printf("Saisissez une autre adresse mail : ");
          scanf("%s",&adresse_mel);
      } //vérifie que l'adresse mail n'est pas déjà utilisé
    if (strcmp(adresse_mel, "")){
        printf("L'adresse mail est obligatoire, veuillez en renseigner une : ");
        scanf("%s",&adresse_mel);
    }

    printf("Saisissez la profession du client ou tapez 'skip' pour passer a la suite : ");
       scanf("%s", &profession);
      if (strcmp(profession, "skip") == 0) { //Si "skip" est entré alors
        strcpy(profession, ""); //profession est un champ vide
      }


  // Écrit les données du client dans le fichier
  fprintf(fic, "%s,%s,%s,%s,%s,%s,%s\n", prenom, nom, code_postal, ville, telephone, adresse_mel, profession);

  // Ferme le fichier
  fclose(fic);


  // Ouvre le fichier en mode d'ajout (append)
  FILE *fic2 = fopen("resultat_ajouter.txt", "w+");
  // Vérifie si le fichier a été ouvert correctement
  if (fic2 == NULL)
  {
    perror("Erreur lors de l'ouverture du fichier");

    return;
  }

  // Écrit les données du client dans le fichier
  fprintf(fic2, "%s,%s,%s,%s,%s,%s,%s\n", prenom, nom, code_postal, ville, telephone, adresse_mel, profession);

  // Ferme le fichier
  fclose(fic2);

}


// =========================================================================================== 5. Afficher client

void afficher_clients(char* annuaire) {
    FILE* fichier = fopen(annuaire, "r");
    char ligne[MAX_LONGUEUR_LIGNE], prenom[MAX_LONGUEUR_CHAMP], nom[MAX_LONGUEUR_CHAMP], code_postal[MAX_LONGUEUR_CHAMP], ville[MAX_LONGUEUR_CHAMP], telephone[MAX_LONGUEUR_CHAMP], adresse_mel[MAX_LONGUEUR_CHAMP], profession[MAX_LONGUEUR_CHAMP];

    while (fgets(ligne, MAX_LONGUEUR_CHAMP, fichier) != NULL) {
    // lire chaque ligne du fichier
        sscanf(ligne, "%s,%s,%s,%s,%s,%s,%s", prenom, nom, code_postal, ville, telephone, adresse_mel, profession);
         // extraire les champs de la ligne
        printf("%s,%s,%s,%s,%s,%s,%s\n", prenom, nom, code_postal, ville, telephone, adresse_mel, profession);
    }
    fclose(fichier);
}


// =========================================================================================== 5. Afficher trier par nom


int afficher_trier_par_nom(char* annuaire) {
    // Déclaration d'un tableau de caractères qui contiendra les lignes du fichier
  char str[MAX_LONGUEUR_CHAMP][MAX_LONGUEUR_CHAMP];
  // Déclaration de la variable n qui servira à compter le nombre de lignes dans le fichier
  int n = 0;

// Ouverture du fichier en mode lecture
  FILE *fp = fopen(annuaire, "r");
  // Vérification si l'ouverture a échoué
  if (fp == NULL) {
    perror("Erreur lors de l'ouverture du fichier\n");// Retourne une erreur si l'ouverture a échoué
    return 1;
  }

// Boucle qui lit les lignes du fichier jusqu'à ce qu'il n'y en ait plus
  while (fgets(str[n], MAX_LONGUEUR_CHAMP, fp) != NULL) {
    str[n][strlen(str[n]) - 1] = '\0';// Remplacement du caractère de fin de ligne par une fin de chaîne de caractères
    n++;// Incrémentation de la variable n pour compter le nombre de lignes
  }

  fclose(fp);// Fermeture du fichier

// Boucle qui parcourt toutes les lignes du tableau str
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      char *nom1 = strchr(str[i], ',');// Recherche de la première virgule dans la ligne i
      char *nom2 = strchr(str[j], ',');// Recherche de la premirèe virgule dans la ligne j

      int compare = strncmp(str[i], str[j], nom1 - str[i]);// Comparaison des parties de la ligne i et j avant la première virgule

      if (compare > 0) { // Si la partie de la ligne i est plus grande que celle de la ligne j
        char temp[MAX_LONGUEUR_CHAMP];// Déclaration d'une variable temporaire pour stocker la ligne i
        strcpy(temp, str[i]); // Copie de la ligne i dans la variable temporaire
        strcpy(str[i], str[j]);//Copie de la ligne j dans la ligne i
        strcpy(str[j], temp);// Copie de la variable temporaire (qui contient la ligne i) dans la ligne j
      }
    }
  }

  for (int i = 0; i < n; i++) {// Affichage de tous les clients
    printf("%s\n", str[i]);
  }

  return 0;
}

//=========================================== 8. Afficher données manquantes

void afficher_donnee_manquante(char* annuaire) {
    FILE* fichier = fopen(annuaire, "r");
    char ligne[MAX_LONGUEUR_CHAMP], prenom[MAX_LONGUEUR_CHAMP], nom[MAX_LONGUEUR_CHAMP], code_postal[MAX_LONGUEUR_CHAMP], ville[MAX_LONGUEUR_CHAMP], telephone[MAX_LONGUEUR_CHAMP], addresse_mel[MAX_LONGUEUR_CHAMP], profession[MAX_LONGUEUR_CHAMP];
     // lire chaque ligne du fichier
    while (fgets(ligne, MAX_LONGUEUR_CHAMP, fichier) != NULL) {
    // extraire les champs de la ligne
        int nb_champs = sscanf(ligne, "%s,%s,%s,%s,%s,%s,%s", prenom, nom, code_postal, ville, telephone, addresse_mel, profession);
     // vérifier si tous les champs ont été trouvés
        if (nb_champs != 7) {
                // si des champs sont manquants, afficher "empty" pour ces champs
            printf("%s,%s,%s,%s,%s,%s,%s\n", strlen(prenom) ? prenom : "<empty", strlen(nom) ? nom : "<empty>", strlen(code_postal) ? code_postal : "<empty>", strlen(ville) ? ville : "<empty>", strlen(telephone) ? telephone : "<empty>", strlen(addresse_mel) ? addresse_mel : "<empty>", strlen(profession) ? profession : "<empty>");
        } else {
            // si tous les champs ont été trouvés, afficher les champs tels quels
            printf("%s,%s,%s,%s,%s,%s,%s\n", prenom, nom, code_postal, ville, telephone, addresse_mel, profession);
        }
    }
    fclose(fichier);
}

















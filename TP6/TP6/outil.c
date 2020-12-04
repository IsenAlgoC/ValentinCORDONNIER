#include <stdio.h>   /* pour les entr�es-sorties */
#include <string.h>  /* pour les manipulations de cha�nes de caract�res */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"

#define VERSION 3.0
#define SQUELET
/**************************************************************************/
/* Compl�ter votre nom ici                                                */
/*   Nom : Cordonnier                        Pr�nom :  Valentin           */
/**************************************************************************/

extern bool modif;


/**********************************************************************/
/*  Ajout d'un contact dans le r�pertoire stock� en m�moire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire* rep, Enregistrement enr)
{
#ifdef IMPL_TAB
	// compl�ter code ici pour tableau
	int idx=rep->nb_elts;
	//on fait attention � respecter les limitations de caract�res
	if (rep->nb_elts < MAX_ENREG)
	{
		//On ajoute � la fin du tableau l'�l�ment que l'on souhaite ajouter au r�pertoire et on augmente le nombre d'�l�ments
		rep->tab[idx]=enr;
		rep->nb_elts++;
	}
	else {
		//sinon on ne peut pas rajouter d'�l�ment
		return(ERROR);
	}
	modif = true;

#else
#ifdef IMPL_LIST
	bool inserted = false;
	//S'il n'y a pas d'�l�ment on en met un et la liste est forc�ment tri�e
	if (rep->nb_elts == 0) {
		if (InsertElementAt(rep->liste, rep->liste->size, enr) != 0) {
			rep->nb_elts += 1;
			modif = true;
			rep->est_trie = true;
			return(OK);
		}

	}
	else {//Sinon on en rajoute un en faisant attention au tri car avec les listes cha�n�es on peutt facilement intervertir deux maillons donc en profite 
		  //pour ne pas devoir cr�er une fonction de tri
		if (rep->nb_elts < MAX_ENREG) {
			//si la valeur est sup�rieure � celle contenue dans la queue on remplace la queue par la nouvelle valeur et la liste est tri�e
			if (est_sup(enr, rep->liste->tail->pers) == true) {
				if (InsertElementAt(rep->liste, rep->liste->size, enr) != 0) {
					rep->nb_elts++;
					modif = true;
					rep->est_trie = true;
				}
			}
			//Sinon on interverti en mettant le nouvel �l�ment juste avant la queue et en gardant la queue telle quelle, on assure ainsi le tri de la liste
			else {
				if (InsertElementAt(rep->liste, rep->liste->size - 1, enr) != 0) {
					rep->nb_elts++;
					modif = true;
					rep->est_trie = true;
				}

			}
		}
		else {
			return(ERROR);
		}
	}


#endif

#endif


	return(OK);

} /* fin ajout */
  /**********************************************************************/
  /* supprime du r�pertoire l'enregistrement dont l'indice est donn� en */
  /*   param�tre       et place modif = true                            */
  /**********************************************************************/
#ifdef IMPL_TAB
void supprimer_un_contact_dans_rep(Repertoire* rep, int indice) {

	// compl�ter code ici pour tableau
	if (rep->nb_elts >= 1 && 0 <= indice && indice < rep->nb_elts)		/* s'il y a au moins un element ds le tableau */
	{																	/* et que l'indice pointe a l'interieur */
		//on fait une boucle pour d�caler vers la gauche toutes les valeurs du tableau pour "supprimer" la valeur demand�e
		for (int i = indice; i < rep->nb_elts; i++) {
			rep->tab[i] = rep->tab[i + 1];
		}
		rep->nb_elts -= 1;		/* ds ts les cas, il y a un element en moins */
		modif = true;
	}

	return;
} /* fin supprimer */

#else
#ifdef IMPL_LIST
  /************************************************************************/
  /* supprime du r�pertoire l'enregistrement contenu dans le maillon elem */
  /*                   et fixe modif � vrai                              */
  /************************************************************************/
  // complet

int supprimer_un_contact_dans_rep_liste(Repertoire* rep, SingleLinkedListElem* elem) {

	int ret = DeleteLinkedListElem(rep->liste, elem);
	if (ret == 1) {
		rep->nb_elts--;
		modif = true;
	}

	return (0);
}
#endif
#endif


/**********************************************************************/
/*  fonction d'affichage d'un enregistrement sur une ligne � l'�cran  */
/* ex Dupont, Jean                 0320304050                         */
/**********************************************************************/
void affichage_enreg(Enregistrement enr)
{
	// On affiche simplement le nom, pr�nom et num�ro de t�l�phone
	printf("%s, ", enr.nom);
	printf("%s", enr.prenom);
	printf("                 %s\n", enr.tel);
} /* fin affichage_enreg */

  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement avec alignement des mots */
  /* pour les listes                                                    */
  /* ex | Dupont                |Jean                  |0320304050      */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr)
{
	// code � compl�ter ici
	// comme fonction affichage_enreg, mais avec pr�sentation align�es des informations en respectant les limites de caract�res de chaque param�tre
	printf("%-30s", enr.nom);
	printf("%-30s", enr.prenom);
	printf("%-20s\n", enr.tel);

} /* fin affichage_enreg */


  /**********************************************************************/
  /* test si dans l'ordre alphabetique, un enregistrement est apres     */
  /* un autre                                                           */
  /**********************************************************************/
bool est_sup(Enregistrement enr1, Enregistrement enr2)
{
	// code � compl�ter ici
	int tmp1 = (char)toupper(enr1.nom[0]); //on met la valeur de la lettre en majuscule pour que l'ordre alphab�tique ne soit pas influenc� par la
	int tmp2 = (char)toupper(enr2.nom[0]);//casse minuscule-majuscule
	//Ensuite on compare juste si la valeur une est plus grande que la deux ou non
	if (tmp1 < tmp2) {
		return(false);
	}
	return(true);
}

/*********************************************************************/
/*   Tri Alphabetique du tableau d'enregistrements                   */
/*********************************************************************/

void trier(Repertoire* rep)
{

#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	Enregistrement tmp;
	//pour trier un tableau on a besoin de deux indices, car quand on trouve un plus grand on s'assure qu'il est le plus grand de tout le tableau
	//sinon on prend celui qui est trouv� comme plus grand et on recommence, on d�cale au bout du tableau chaque plus grand que l'on trouve
	for (int j = 0; j <= rep->nb_elts - 2; j++) {
		for (int i = 0; i <= rep->nb_elts - 2; i++) {
			if (est_sup(rep->tab[i], rep->tab[i + 1]) == true) {
				tmp = rep->tab[i + 1];
				rep->tab[i + 1] = rep->tab[i];
				rep->tab[i] = tmp;
			}
		}
	}


#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	// rien � faire !
	// la liste est toujours tri�e
#endif
#endif


	rep->est_trie = true;

} /* fin trier */

  /**********************************************************************/
  /* recherche dans le r�pertoire d'un enregistrement correspondant au  */
  /*   nom � partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au crit�re ou*/
  /*   un entier n�gatif si la recherche est n�gative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire* rep, char nom[], int ind)
{
	int i = ind;		    /* position (indice) de d�but de recherche dans tableau/liste rep */
	int ind_fin;			/* position (indice) de fin de tableau/liste rep */

	char tmp_nom[MAX_NOM];	/* 2 variables temporaires dans lesquelles */
	char tmp_nom2[MAX_NOM];	/* on place la chaine recherchee et la chaine lue dans le */
							/* tableau, afin de les convertir en majuscules et les comparer */
	bool trouve = false;

	ind_fin = rep->nb_elts - 1; // indice de fin � ne pas d�passer
	strncpy_s(tmp_nom, _countof(tmp_nom), nom, _TRUNCATE); //copie du nom � rechercher
	int j = 0;
	//On met tout le mot en majuscule pour ne pas avoir de probl�me de casse
	while (tmp_nom[j] != '\0') {
		tmp_nom[j] = (char)toupper(tmp_nom[j]);
		j++;
	}


#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	while ((i <= ind_fin) && (!trouve))
	{
		strncpy_s(tmp_nom2, _countof(tmp_nom2), rep->tab[i].nom, _TRUNCATE);//copie de la cha�ne lue
		j = 0;
		//On met tout le mot en majuscule pour ne pas avoir de probl�me de casse
		while (tmp_nom2[j] != '\0') {
			tmp_nom2[j] = (char)toupper(tmp_nom2[j]);
			j++;
		}
		//Si on trouve l'�l�ment on garde la valeur de l'indice sinon on incr�mente, et si on ne le trouve pas du tout return -1
		if (strcmp(tmp_nom, tmp_nom2) == 0) {
			trouve = true;
		}
		else {
			i++;
		}
	}
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	SingleLinkedListElem* currentElement = GetElementAt(rep->liste, ind);
	while ((i <= ind_fin) && (!trouve))
	{
		
		while ((currentElement != NULL) && (!trouve)) {

			strncpy_s(tmp_nom2, _countof(tmp_nom2), currentElement->pers.nom, _TRUNCATE);

			j = 0;
			//On met tout le mot en majuscule pour ne pas avoir de probl�me de casse
			while (tmp_nom2[j] != '\0') {
				tmp_nom2[j] = (char)toupper(tmp_nom2[j]);
				j++;
			}
			if (strcmp(tmp_nom, tmp_nom2) == 0)
				trouve = true;
			else {
				// si pas trouv�, on passe au suivant
				currentElement = currentElement->next;
				i++;
			}
		}
	}
#endif
#endif

	return((trouve) ? i : -1);
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caracteres non num�riques de la chaines        */
  /*********************************************************************/
void compact(char* s)
{
	// compl�ter code ici
	unsigned int j = 0;

	while (s[j] != '\0') {
		if (s[j] == '-' || s[j] == ' ') {
			for ( unsigned int i = j; i < strlen(s); i++) {
				s[i] = s[i + 1];//on d�cale tous les caract�res vers la gauche � chaque fois qu'on trouve un �l�ment non d�sir�
			}
			j--;//cela permet de s'occuper du cas �ventuel o� la personne metterait deux espaces ou tir�s � la suite de revenir sur le m�me rang
		}
		j++;
	}
	return;
}

/**********************************************************************/
/* sauvegarde le r�pertoire dans le fichier dont le nom est pass� en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionn� ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire* rep, char nom_fichier[])
{
	FILE* fic_rep;					/* le fichier */
#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	//On ouvre le fichier en �criture pour pouvoir �crire ce que l'on souhaite sauvegarder � l'int�rieur
	errno_t err = fopen_s(&fic_rep, nom_fichier, "w"); 
	//Si le fichier s'est ouvert correctement alors on passe � la suite
	if (err == 0 && fic_rep != NULL) {
		//On construit un pointeur de caract�re qui va contenir ce que l'on veut �crire dans le fichier, une ligne � la fois
		char* buffer[sizeof(Enregistrement) + 1];
		
		for (int idx = 0; idx < rep->nb_elts; idx++) {
			//On copie d'abord ce que l'on veut dans le buffer
			sprintf_s(buffer, sizeof(Enregistrement) + 1, "%s;%s;%s\n", rep->tab[idx].nom, rep->tab[idx].prenom, rep->tab[idx].tel);
			//Et ensuite on l'�crit dans le fichier
			fputs(buffer, fic_rep);
		}
	}
	else {
		return ERROR;
	}
	fclose(fic_rep);//on ferme le fichier
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	errno_t err = fopen_s(&fic_rep, nom_fichier, "w");
	int idx = 0;
	int i = 0;
	if (err == 0 && fic_rep != NULL) {
		SingleLinkedListElem* currentElement = rep->liste->head;
		char buffer[sizeof(Enregistrement) + 1];


		for (idx = 0; idx < rep->nb_elts; idx++) {
			//On copie d'abord ce que l'on veut dans le buffer
			sprintf_s(buffer, sizeof(Enregistrement) + 1, "%s;%s;%s", currentElement->pers.nom, currentElement->pers.prenom,
				currentElement->pers.tel);
			//Et ensuite on l'�crit dans le fichier
			fputs(buffer, fic_rep);
			currentElement = currentElement->next;
		}
	}
	else {
		return ERROR;
	}
	fclose(fic_rep);
#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le r�pertoire le contenu du fichier dont le nom est  */
  /*   pass� en argument                                                */
  /*   retourne OK si le chargement a fonctionn� et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire* rep, char nom_fichier[])
{
	FILE* fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char* char_nw_line;
	_set_errno(0);
	if (((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0) || (fic_rep == NULL))
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{
			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					*char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;								/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element � priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
														// ajouter code implemention liste
				//On cr�� un �l�ment qui va contenir ce que la fonction "lire_champ" va lire
				SingleLinkedListElem currentElement;
				if (lire_champ_suivant(buffer, &idx, currentElement.pers.nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, currentElement.pers.prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, currentElement.pers.tel, MAX_TEL, SEPARATEUR) == OK) {
							//On ins�re cet �l�ment au r�pertoire les uns apr�s les autres
							InsertElementAt(rep->liste, num_rec, currentElement.pers);
							num_rec++;		/* element � priori correct, on le comptabilise */
							
						}
					}
				}
				
#endif
#endif




			}
			
		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */
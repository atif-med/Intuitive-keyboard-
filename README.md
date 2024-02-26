# Intuitive-keyboard-
This is a Intutive keyboard programmed using C programming langage and GTK


				SAISIE INTUITIVE 2.0
  Ce programme permet d'avoir une saisie intuitive et propose3 prédictions poissbles. 
  Il permet aussi d'interagir avec les dictionnaires et les mots stocké
  
  le dossier contient deux fichiers/les deux fichier #projet_interface# et #projet menu# sont le meme projet de saisie intuitive mais avec une difference:
  
  le premier # projet_menu # contient le code du programme et utilise le terminal pour communiquer avec l'utilisateur
  
  le deuxieme # projet_interface # contient le code du programme et utilise une interface graphique pour communiquer avec l'utilisateur

				


				INSTALLATION ET DÉMARRAGE
  Avant d'utiliser le programme dans le fichier projet_interface il faut installer certaines librairies et paquets :
	+ gtk3
	+ pkg-config
	+ make
	+ gcc
  Pour les installer taper la commande : "sudo apt install libgtk-3-dev pkg-config make gcc"
  Pour démarrer le programme dans les deux fichiers il faut les compiler avec "make mon_exe" puis l'exécuter 
  avec la commande "./mon_exe"
# ATTENTION : lors de la compilation on aura énormement de warnings, ces warnings ne sont pas 
#   		à prendre en considération car ils sont une conséquence de l'utilisation de gtk3.

				
				
            
            LE PROGRAMME

           +  Dans le dossier "projet_interface" :
  Le programme présente une interface graphique avec laquelle l'utilisateur peut effectuer 
  la totalité de ses actions, il intéragit que avec cette dernière.
  Au démarrage le programme charge automatiquement les données à partir des fichiers "doss_comp.txt"
  et "dictiofarnc.txt".
				

          +  Dans le dossier "projet_menu"
           Le programme présente un menu dans le terminal avec laquelle l'utilisateur peut effectuer 
  la totalité de ses actions, il intéragit que avec cette dernière.
  Au démarrage le programme charge automatiquement les données à partir des fichiers "doss_comp.txt"
  et "dictiofarnc.txt".



				FONCTIONNALITÉS
   PARAMÈTRES
+  le mode de prédiction qu'on a utilise est le mode fréquentiel qui sélectionne les mots
   les plus utilisés .

   INTERAGIR AVEC LES DICTIONNAIRES
+  Pour l'interface il y a un probleme dans les trois bouttons en haut "activer/desactiver/dictionnary, il ne sont pas connecte au code pour cela ils ne marche pas 



   CHANGER LES DONNÉES
+  Ajouter un mot : l'ajout d'un mots ce fait automatiquement si l'utilisateur choisit un mots qui n'existe pas dans le dictionnaire de prediction mais existe dans le sictionnaire francais.

+  Supprimer un mot : le mot entré dans la zone de texte sera supprimé du dictionnaire de prediction sous 
   résèrve d'existence

+  Modifier un mot : l'utilisateur doit tapper le mot qu'il doit modifier et apres il tappe le nouveau mot, le mot se modifie directement dans le dictionnaire de prediction.

#  ATTENTION: seulement dans le code utilisant l'interface les fonction modifer et ajout d'un mot ne sont pas disponible seule la foncion supprimer est valable.

   ECRITURE INTUITIVE

+  en utilisant le programme qui utilise l'interface:
    Dans cette partie l'utilisateur peut écrire le mot qu'il veut et automatiquement le programme 
   recupère le contenu et génère trois prédictions possibles.Ces prédictions se trouvent à l'intérieur des labels au dessous de la barre 
   d'ecriture. 


+  en utilisant le programme qui utilise le terminal:
    Dans cette partie l'utilisateur peut écrire le mot qu'il veut et automatiquement le programme 
   recupère le contenu et affiche dans le teminal trois prédictions possibles.l'utilisateur peut choisir l'un des mots et si le mot n'existe pas dans le dictionnaire de prediction il est ajouté directement à ce dernier avec un nombre d'occurence égale à 1
  

#  ATTENTION : - si on écris entre un espace en premier caractère le programme crash
#	       - l'utilisation de caractères spéciaux peut mener au crash du programme
#              - il se peut que certains mots atypiques fassent buguer le programme
#   	  - si on utilise un mot qui n'exixte pas dans le dictionnaire francais le programme crash
#       - le code crache quand on utilise un mot qui commence par majuscule


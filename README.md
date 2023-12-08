# TPsynthese : ENSEA in the shell

Lotfi HENNI

Rayen BEN AMAR

### Question 1 : 
      Nous affichons un message d'accueil simple à l'aide de la fonction write. 
      Celle-ci est utlisée pour écrire des données, elle remplace la fonction printf.
      Elle affiche la chaîne de caractères "buffer".
      "STDOUT_FILENO" est le descripteur de fichier standard associé à la console.


### Question 2 : 
      Le shell est désormais capable d'exécuter n'importe quellle commande simple saisie (sans arguement).
      Création d'une boucle "while(1)" pour demander continuellement une commande.
      Création d'un processus fils en utilisant la fonction "fork()".  
      Celui-ci va exécuter la commande à l'aide de "execlp".
      Le processus père attend que le fils termine avant de demander la prochaine commande.


### Question 3 : 
      Nous gérons désormais la sortie du shell avec la commande "exit".
      Avant cela, il n'était possible d'arrêter le shell qu'avec un contrôle C.
      Si la commande de l'utilisateur est "exit", le shell est quitté avec succès.


### Question 4 : 
      Le shell affiche maintenant le code de retour de la commande précédente.
      Nous vérifions si le processus enfant s'est terminé normalement avec "WIFEXITED(status)", on affiche alors le statut de sortie.
      Si le processus enfant a été interrompu par un signal (WIFSIGNALED), on affiche le signal et le numéro associé. 
      Cela permet de capturer des informations sur le signal qui a provoqué l'interruption.


### Question 5 : 
      Nous mesurons le temps d'exécution de la commande saisie.
      Il correspond au temps écoulé entre deux points dans le temps.
      Il est mesuré en utilisant la structure "timespec" de la bibliothèque "<time.h>".
      Par exemple, la commande "fortune" prend plus de temps qu'un simple "pwd".


### Question 6 : 
      Le shell est désormais capable d'exécuter n'importe quellle commande saisie, même complexe avec des arguements.
      Le code commence par prendre une commande stockée dans le buffer.
      Il la découpe ensuite en arguments distincts grace à la fonction "strtok".
      Enfin, il exécute la commande à l'aide de la fonction execvp. 
      
      Exemple d'exécution de commande complexe : mkdir nouveau.
      Le shell crée alors un dossier "nouveau" à l'emplacement indiqué dans le terminal.

### Question 7 : 
      
      Le shell a été étendu pour prendre en charge la redirection des flux d'entrée et de sortie. 
      Lorsqu'une commande est saisie, le programme analyse les arguments pour détecter la présence des symboles de redirection '<' et '>'. 
      Si '<' est trouvé, le shell redirige l'entrée standard "STDIN" vers le fichier spécifié. 
      De même, si '>', le shell redirige la sortie standard "STDOUT" vers le fichier indiqué. 
      Par exemple, la commande "wc -l < filetext.txt" compte les lignes du contenu du fichier "filetext.txt".



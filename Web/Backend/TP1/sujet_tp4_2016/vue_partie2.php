<?php
// Ce fichier permet de tester les fonctions développées dans le fichier controleur.php (première partie)

include_once "modele.php"; 
include_once "maLibForms.php"; 

?>

<h1>Administration du site</h1>

<h2>Liste des utilisateurs de la base </h2>

<?php

echo "liste des utilisateurs autorises de la base :"; 
$users = listerUtilisateurs("nbl");
mkTable($users);	// utiliser le second argument pour n'afficher que 'pseudo', 'couleur', 'connecte' 
			// dans cet ordre 

echo "<hr />";

echo "liste des utilisateurs non autorises de la base :"; 
$users = listerUtilisateurs("bl");
mkTable($users);	// utiliser le second argument pour n'afficher que 'pseudo', 'couleur', 'connecte' 
			// dans cet ordre 
?>


<hr />

<h2>Changement de statut des utilisateurs</h2>

<form>

<?php
$users = listerUtilisateurs("both");
mkSelect("idUser",$users,"id","pseudo");	// améliorer pour que l'utilisateur qui vient d'être mis à jour 
						// soit automatiquement sélectionné

mkInput("submit","action","Interdire");
mkInput("submit","action","Autoriser");
?>

</form>

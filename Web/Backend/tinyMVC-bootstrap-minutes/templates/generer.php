<?php

//C'est la propriété php_self qui nous l'indique : 
// Quand on vient de index : 
// [PHP_SELF] => /chatISIG/index.php 
// Quand on vient directement par le répertoire templates
// [PHP_SELF] => /chatISIG/templates/accueil.php

// Si la page est appelée directement par son adresse, on redirige en passant pas la page index
// Pas de soucis de bufferisation, puisque c'est dans le cas où on appelle directement la page sans son contexte
if (basename($_SERVER["PHP_SELF"]) != "index.php")
{
	header("Location:../index.php?view=accueil");
	die("");
}

$idUSER = $_SESSION["idUser"];
$idProjet = valider("idProjet", "GET");

// Si l'utilisateur n'est pas connecté on le redirige vers la page d'accueil
include_once "libs/maLibSecurisation.php"; 
securiser("index.php"); 

// S'il n'est pas membre du projet ont le redirige vers la page d'accueil
$estMembre = estMembre($idUSER,$idProjet);
if($estMembre == 0){
    rediriger("index.php");
}

?>

    <div class="page-header">
      <h1>Saisie du document (non terminé)</h1>
    </div>

<?php

//Todo : 
/*
Page de saisie de document minutes] L’objectif de cette page est de générer, pour
un projet donné, à partir du template associé à ce projet, le formulaire HTML
permettant de saisir, pour chacune des informations recensées dans le template
(hormis l’auteur), la valeur à enregistrer
○ Cette page ne doit pas pouvoir être affichée si le template du projet n’a pas
été créé
○ Les informations saisies dans un document minutes ne peuvent être
modifiées
○ Un document minutes peut être supprimé uniquement par son auteur
*/

?>
















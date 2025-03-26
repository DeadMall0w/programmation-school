<style>
body {
background-color: linen;
}
h1 {
color: maroon;
margin-left: 40px;
}

table {
    width: 100%;
    border-collapse: collapse;
    border-radius: 8px;
    overflow: hidden;
    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
}

th, td {
    border: 1px solid #ddd;
    padding: 10px;
    text-align: left;
}

th {
    background-color: #f4f4f4;
    font-weight: bold;
}

tr:nth-child(even) {
    background-color: #f9f9f9;
}

tr:hover {
    background-color: #f1f1f1;
}
</style>

<?php
// Ce fichier permet de tester les fonctions développées dans le fichier controleur.php (première partie)
session_start();

include_once "modele.php"; 
include_once "maLibUtils.php"; 
include_once "maLibForms.php";
include_once "maLibSecurisation.php";


// Traiter l'action demandée
$action = valider('action', 'GET');
$idUser = valider('idUser', 'GET');
$col = valider('idColor', 'GET');
if ($action == "Interdire") {
  interdireUtilisateur($idUser);
}
if ($action == "Autoriser") {
  autoriserUtilisateur($idUser);
}
if ($action == "changerCouleur"){
	echo "changement couleur !!";
}
if ($action == "déconnexion"){
	// echo "changement couleur !!";
	session_destroy();
	rediriger("login.php");
}
?>

<h1>Administration du site</h1>

<h2>Liste des utilisateurs de la base </h2>

<?php

echo "liste des utilisateurs autorises de la base :"; 
$users = listerUtilisateurs("nbl");
mkTable($users, ['pseudo', 'couleur', 'connecte']);

echo "<hr />";

echo "liste des utilisateurs non autorises de la base :"; 
$users = listerUtilisateurs("bl");
mkTable($users, ['pseudo', 'couleur', 'connecte']);
?>


<hr />

<h2>Changement de statut des utilisateurs</h2>

<?php

$users = listerUtilisateurs("both");
mkForm();
  mkSelect("idUser", $users, "id", "pseudo", $idUser, "couleur");
  mkInput("submit", "action", "Interdire");
  mkInput("submit", "action", "Autoriser");


$color = [
	["nom" => "bleu", "valeur" => "blue"],
	["nom" => "rouge", "valeur" => "red"],
	["nom" => "vert", "valeur" => "green"]
];

  mkSelect("idColor", $color, "valeur", "nom", $col);
  mkInput("submit", "action", "changerCouleur");
endForm();

?>

<h2> Connexion ! </h2> 
<?php
tprint($_SESSION);

mkForm();
mkInput("submit", "action", "déconnexion");
endForm();

// verifUser("Adrien", "123");
?>

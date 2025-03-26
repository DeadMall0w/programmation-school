<style>
  table, table th, table td {
    border: 1px solid black;
  }
  
  table th {
    font-weight: normal;
    text-align: left;
    background-color: lightgray;
  }
  
  #message {
    background-color: lightblue;
    padding: 10px;
    margin: 10px;
    border: 2px solid blue;
    text-align: center;
  }
</style>

<?php
// Ce fichier permet de tester les fonctions développées dans le fichier controleur.php (première partie)

session_start();

include_once "modele.php"; 
include_once "maLibUtils.php"; 
include_once "maLibForms.php";
include_once "maLibSecurisation.php";

securiser("login.php");

// Traiter l'action demandée
$action = valider('action', 'GET');
$idUser = valider('idUser', 'GET');
$couleur = valider('couleur', 'GET');
$message = valider('message', 'GET');

if ($message) {
  echo "<div id=\"message\">$message</div>\n";
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

$tabCouleurs = [
  ["nom" => "Bleu", "valeur" => "blue"],
  ["nom" => "Vert", "valeur" => "green"],
  ["nom" => "Rouge", "valeur" => "red"],
  ["nom" => "Noir", "valeur" => "black"],
  ["nom" => "Gris", "valeur" => "#333"]
];

mkForm();
  mkSelect("idUser", $users, "id", "pseudo", $idUser, "couleur");
  mkInput("submit", "action", "Interdire");
  mkInput("submit", "action", "Autoriser");
  //mkSelect("couleur", $users, "couleur", "couleur", $couleur);
  mkSelect("", $tabCouleurs, "valeur", "nom", $couleur);
  mkInput("submit", "action", "Changer couleur");
endForm();

mkForm();
  mkInput("submit", "action", "Déconnexion");
endForm();

tprint($_SESSION);

?>















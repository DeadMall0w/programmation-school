<style>
  #message {
    background-color: lightblue;
    padding: 10px;
    margin: 10px;
    border: 2px solid blue;
    text-align: center;
  }
</style>

<?php
// Formulaire de connexion + vérification connexion

session_start();

include_once "modele.php"; 
include_once "maLibUtils.php"; 
include_once "maLibForms.php";
include_once "maLibSecurisation.php";

// La logique métier : vérifier qu'on peut se connecter avec
// l'identifiant et le mot de passe fournis
$message = valider("message", "GET");

if ($message) {
  echo "<div id=\"message\">$message</div>\n";
}

// Le formulaire de connexion
mkForm("controleur.php");
  mkInput("text", "login");
  mkInput("password", "passe");
  mkInput("submit", "action", "Se connecter");
endForm();

tprint($_SESSION);

?>















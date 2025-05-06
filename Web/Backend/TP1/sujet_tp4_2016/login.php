<?php
session_start();

include_once "modele.php"; 
include_once "maLibUtils.php"; 
include_once "maLibForms.php";
include_once "maLibSecurisation.php";


$action = valider('action', 'GET');
$login = valider('login', 'GET');
$password = valider('password', 'GET');

if ($action == "Se connecter" && $login && $password){
    if (verifUser($login, $password)){
        echo "Bien connecté !!!";
        rediriger("vue_partie1.php");
    }else{
        echo "Echec de l’authentification !";
    }
}

mkForm();
    mkInput("text", "login");
    mkInput("password", "password");
    mkInput("submit", "action", "Se connecter");
endForm();


?>
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
      <h1>Edition de template</h1>
    </div>

<?php

$listeTemplate = ListerTemplate($idProjet);

  foreach ($listeTemplate as $key => $value) {
    // regarde si c'est un champ qu'on peut supprimer
    if ($value["nom"] == "auteur" || $value["nom"] == "date" || $value["nom"] == "duree"){
        mkDivSimple($value["nom"] . " - Impossible à supprimer", 0, $value["id"]);
    }else{
        mkDivSimple($value["nom"], 1, $value["id"]);
    }
}



// tous les types autorisée de champs (inspiré du code pour les couleurs du TNE 2025)
$tabType= [
    ["nom" => "Chaîne", "valeur" => "chaine"],
    ["nom" => "Date", "valeur" => "date"],
    ["nom" => "Nombre (entier)", "valeur" => "numerique"],
  ];

mkForm("controleur.php");
    mkInput("text", "nomChamp", "");
    mkInput("submit", "action", "Ajouter champ");
    mkSelect("type", $tabType, "valeur", "nom");
    mkInput("hidden", "projetID", $idProjet); // champ caché pour avoir l'id du projet
endForm();

?>
















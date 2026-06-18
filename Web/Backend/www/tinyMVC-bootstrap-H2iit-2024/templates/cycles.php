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


include_once "libs/maLibSecurisation.php"; 


securiser("index.php"); 

// tprint($_SESSION);

    // mkLien("","Super secret btn !", "view=
    // ");

    // $idUSER = verifUserBdd($_COOKIE["login"], $_COOKIE["passe"]);
    $idUSER = $_SESSION["idUser"];
    if (isCoach($idUSER)){

        // echo "c'est un coach wowoo";
        mkForm("controleur.php");
            mkInput("text", "idCycle", "id cycle");
            mkInput("text", "nom", "nom cycle");
            mkInput("text", "description", "description");
            mkInput("text", "rep", "répétition");
            mkInput("text", "repEntreCycle", "rep entre cycle");
            mkInput("text", "repEntreExo", "rep entre exo");

            mkInput("submit", "action", "AjouterCycle");
            mkInput("hidden", "idCoach", $idUSER);
        endForm();
    }

?>
    

    <div class="page-header">
      <h1>Liste des cycles</h1>
    </div>

<?php
    $cycles = listerCycles();
    foreach ($cycles as $key => $value) {
        mkLien("", $value["nom"] . " - " . $value["description"], "view=deroulCycle&id=" . $value["id"]);
        if ($value["idCoach"] == $idUSER){
            mkLien("", "Modifier : " . $value["nom"], "view=modifCycle&id=" . $value["id"]);
            
        }
        echo "<br>";
    }
    // mkLiens($cycles);
    // tprint($cycles);



?>






















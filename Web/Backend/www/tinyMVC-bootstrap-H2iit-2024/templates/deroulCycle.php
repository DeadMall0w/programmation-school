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

?>


    <div class="page-header">
      <h1>Vu du cycles</h1>
    </div>

<?php
    $idCycle = valider("id", "GET");
    $cycles = recupCycleData($idCycle);
    $idCycle = 1;
    foreach ($cycles as $key => $value) {
        // mkDivSimple($value["nom"] . " - " . $value["description"]);
        mkDivSimple($value["nom"] . " - " . $value["description"]);
        $nomCoach = GetCoachName($value["idCoach"]);
        $idCycle = $value["id"];
        echo "<br>";
    }
    // mkLiens($cycles);

    $compoCycle = getCompositionCycles($idCycle);
    
    for($i = 0; $i < $cycles[0]["repetitions"]; $i++){

        foreach ($compoCycle as $key => $value) {
            $exo = getExercice($value["idExercice"])[0];
            
            mkDivSimple($value["duree"] . "sec. - " . $exo["nom"] . " : " .  $exo["description"]);
            
        }
    }
    
    // tprint($cycles);

    // $nomCoach = getCoach($value[0]["idCoach"]);
    
    echo "<p>Cycle fait par " . $nomCoach . "</p>";




?>






















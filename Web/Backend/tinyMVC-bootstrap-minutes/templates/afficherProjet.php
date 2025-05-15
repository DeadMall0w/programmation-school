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
      <h1>Voir le projet</h1>
    </div>

<?php

$template = ListerTemplate($idProjet); // obtention de la template
$champs = ListerChampsMinute($idProjet); // obtention des valeurs de la template
$nombreTemplate = NombreTemplate($idProjet); // Obtention du nombre d'élément dans la template du projet


// affichage en tableau
echo "<table border=\"1\">\n";

// première ligne du tableau (en partant de la template)
echo "\t<tr>\n";
foreach ($template as $value)	
{
    $v = $value["nom"];
    echo "\t\t<th>$v</th>\n";
}


$i=0;
foreach ($champs as $data)	
{
    // i = 0 => premier élément de la ligne
    // i = nombreTemplate => dernier élément de la ligne
    if($i == 0){
        echo "\t</tr>\n";
    }

    $i=$i+1;
    $d = $data["valeur"];
    echo "\t\t<td>$d</td>\n";

    if ($i== $nombreTemplate){ // on a attend la fin de la ligne
        $i=0;
        echo "\t</tr>\n";
    }
}

// fin du tableau
echo "</table>\n";



?>
















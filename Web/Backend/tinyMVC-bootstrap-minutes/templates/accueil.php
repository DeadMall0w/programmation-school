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

// récupère l'id de l'utilisateur
$idUSER = $_SESSION["idUser"];

?>


    <div class="page-header">
      <h1>Minute</h1>
    </div>

    <p class="lead">Site de création/édition de document minute.</p>


<?php

if (valider("connecte","SESSION")){
  // echo "<h1>Liste de vos documents (propriétaire)</h1>";

  // $listeProjetsProp = ListerProprietaireProjets($idUSER);


  // foreach ($listeProjetsProp as $key => $value) {
  //   mkLien("", $value["nom"], "view=projet&idProjet=2");// . $value["id"]);
    
  //   echo "<br>";
  // }
  
  
  echo "<h1>Liste de vos documents</h1>";
  $listeProjetsMembre = ListerMembreProjets($idUSER);
  
  foreach ($listeProjetsMembre as $key => $value) {
    mkLien("", $value["nom"], "view=afficherProjet&idProjet=" . $value["id"]);// . $value["id"]);
    echo "<br>";
    // Rajouter une petite marge au debut, provient de : https://www.developpez.net/forums/d129005/webmasters-developpement-web/balisage-x-html-validation-w3c/faire-tabulation-espace-html/
    mkLien("","&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Saisir document", "view=generer&idProjet=" . $value["id"]);// . $value["id"]);

    mkLien("","&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Modifier template", "view=editionTemplate&idProjet=" . $value["id"]);// . $value["id"]);

    
    echo "<br>";
  }





}else{
  echo "<p>Veuillez vous connecter pour voir vos documents</p>";
}



?>
















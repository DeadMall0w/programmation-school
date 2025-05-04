<?php

  include_once "libs/maLibUtils.php";
  include_once "libs/maLibSQL.pdo.php";
  include_once "libs/modele.php"; 
  
  // On réutilise la query string pour la renvoyer à la prochaine page
  // Le tableau $qs peut être complété pour être renvoyé à la page de destination
  $qs = $_GET;
  // On peut aussi définir une query_string sous forme de chaîne de caractères
  //$qs = "";

  if ($action = valider("action"))
  {
    ob_start ();
    echo "Action = '$action' <br />";
    // ATTENTION : le codage des caractères peut poser PB si on utilise des actions comportant des accents... 
    // A EVITER si on ne maitrise pas ce type de problématiques
    
    // Un paramètre action a été soumis, on fait le boulot...
    switch($action)
    {
      // TODO
      case 'TODO' :
        // Traitements métier...
      break;
      
      // TODO
      case 'TODO2' :
        // Traitements métier...
      break;
      
      
      
      
      
    }
  }

  // On redirige toujours vers la page index, mais on ne connait pas le répertoire de base
  // On l'extrait donc du chemin du script courant : $_SERVER["PHP_SELF"]
  // Par exemple, si $_SERVER["PHP_SELF"] vaut /chat/data.php, dirname($_SERVER["PHP_SELF"]) contient /chat
  $urlBase = dirname($_SERVER["PHP_SELF"]) . "/index.php";

  // On redirige vers la page index avec les bons arguments
  rediriger($urlBase, $qs);

  // On écrit seulement après cette entête
  ob_end_flush();
  
?>

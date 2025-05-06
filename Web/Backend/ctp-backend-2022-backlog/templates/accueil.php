<?php

// Si la page est appelée directement par son adresse, on redirige en passant par la page index
if (basename($_SERVER["PHP_SELF"]) != "index.php")
{
  header("Location:../index.php");
  die("");
}

?>

<h2>Contenu du backlog</h2>

<?php

/* //TODO :
- Recup la liste des tâches
- Les afficher
- Changer la couleur selon l'avancement

*/
// $filtres = "";

$taches = ListeTaches($filtres); // fonction présente dans modele et qui fait une requête à la base de donnée

foreach ($taches as $index => $tache) {
  if ($tache["statut"] == 0){
    mkDiv($tache["nom"] . " - non commencé", "white");
  }else if ($tache["statut"] == 1){
    mkDiv($tache["nom"] . " - commencé", "orange");
  }else if ($tache["statut"] == 2){
    mkDiv($tache["nom"] . " - terminé", "green");
  }else if ($tache["statut"] == 3){
    mkDiv($tache["nom"] . " - abandonné", "black");
  }
}

tprint($taches);


?>


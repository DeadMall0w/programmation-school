<?php

/*
Partie modèle : on effectue ici tous les traitements sur la base de données (lecture, insertion, suppression, mise à jour).

Quelques squelettes de fonctions vous sont donnés, à titre purement indicatif.
Il n'est pas nécessaire de les respecter, et cette liste n'est pas exhaustive.
*/

include_once("maLibSQL.pdo.php");

// Liste les tâches existantes en fonction d'un filtre
function listeTaches() {
    $resultat = parcoursRs(SQLSelect("
    SELECT *
    FROM Tache;
  "));


  return $resultat;
}

// Nouvelle caractéristique
function ajouterCarac($type, $label, $name) {
  
}

// Nouveau choix
function ajouterChoix($name_carac, $value, $label) {
  
}

// Récupère les valeurs et lables des caractéristiques d'une tâche
function getValeurs($id_tache) {
  
}

// Récupère le label d'un choix à partir du nom de sa caractéristique et de sa valeur
function getLabelChoix($name_carac, $value) {
  
}



// ...



?>

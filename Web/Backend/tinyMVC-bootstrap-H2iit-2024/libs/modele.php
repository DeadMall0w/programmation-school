<?php

/*
Partie modèle : on effectue ici tous les traitements sur la base de données (lecture, insertion, suppression, mise à jour).

Des fonctions sont déjà présentes : vous avez le droit de les modifier ou d'en ajouter à votre guise. Des indications sont données en commentaires.
*/

include_once("maLibSQL.pdo.php");

//*** Il est recommandé de ne pas modifier les fonctions suivantes, utilisées pour l'identification ***

function verifUserBdd($login,$passe)
{
	// Vérifie l'identité d'un utilisateur 
	// dont les identifiants sont passes en paramètre
	// renvoie faux si user inconnu
	// renvoie l'id de l'utilisateur si succès

	$SQL="SELECT id FROM Users WHERE pseudo='$login' AND pass='$passe';";

	return SQLGetChamp($SQL);
	// si on avait besoin de plus d'un champ
	// on aurait du utiliser SQLSelect
}

function isAdmin($idUser)
{
	// Vérifie si l'utilisateur est un administrateur
	$SQL ="SELECT id FROM Users WHERE id='$idUser' AND role='admin';";
	return SQLGetChamp($SQL); 
}

function isCoach($idUser)
{
	// Vérifie si l'utilisateur est un coach (ou un admin)
	$SQL ="SELECT id FROM Users WHERE id='$idUser' AND role IN ('admin', 'coach');";
	return SQLGetChamp($SQL); 
}

//*** Fin des fonctions fournies avec le sujet ***

// TODO : D'autres fonctions peuvent être ajoutées à la suite


function listerCycles(){
	$sql = "
    SELECT * FROM Cycles
	;";
  //echo $sql;
  return parcoursRs(SQLSelect($sql));
}


function recupCycleData($id){
	
	// attention au injection SQL !!!
	
	$sql = "
    SELECT * FROM Cycles WHERE id=" . $id .
	";";
  return parcoursRs(SQLSelect($sql));

}


function GetCoachName($id)
{
	$SQL="SELECT pseudo FROM Users WHERE id=". $id .";";

	return SQLGetChamp($SQL);
}

function getCompositionCycles($idCycle){
	$SQL="SELECT * FROM Composition_Cycles WHERE idCycle=". $idCycle .";";
	// die($SQL);
	return parcoursRs(SQLSelect($SQL));
}

function getExercice($id){
	$SQL="SELECT * FROM Exercices WHERE id=". $id .";";

	return parcoursRs(SQLSelect($SQL));

}


function AjouterCycle($id, $nom, $description, $idCoach, $repetition, $repos1, $repos2){
	$SQL = "INSERT INTO Cycles 
(`id`, `nom`, `description`, `idCoach`, `repetitions`, `reposEntreCycles`, `reposEntreExercices`)
VALUES ('$id', '$nom', '$description', '$idCoach', '$repetition', '$repos1', '$repos2')";


	SQLUpdate($SQL);
}
?>

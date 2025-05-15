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

	$SQL="SELECT id FROM users WHERE pseudo='$login' AND pass='$passe';";

	return SQLGetChamp($SQL);
	// si on avait besoin de plus d'un champ
	// on aurait du utiliser SQLSelect
}


// liste les propriétaire du projet (NON UTILISEE)
function ListerProprietaireProjets($idUSER){
	$sql = " SELECT * FROM projets WHERE idCreateur=$idUSER;";

	return parcoursRs(SQLSelect($sql));
}


// Liste les membres d'un projet
function ListerMembreProjets($idUSER){
	$sql = "SELECT * FROM `projets` JOIN membres ON projets.id = membres.idProjet WHERE membres.idMembre = $idUSER";
	return parcoursRs(SQLSelect($sql));
}


// Liste les templates
function ListerTemplate($id){
	$sql = " SELECT * FROM  champs_templates WHERE idProjet=$id;";
	return parcoursRs(SQLSelect($sql));
}


// Permet de supprimer un champ de la template
function supprimerChamp($id){
	$sql = "DELETE FROM champs_templates 
	WHERE id=$id";
	SQLDelete($sql); // meme chose qu'un Update
	
}

// Permet d'ajouter un champ dans la template 
function ajouterChamp($projet, $type, $nom){
	$sql = "INSERT INTO champs_templates (id, idProjet, nom, type, possibles) VALUES (NULL, $projet, '$nom', '$type', NULL);";
	
	SQLSelect($sql);

}

// Liste tous les champs minute du projet
function ListerChampsMinute($idProjet){
	$sql = "SELECT * FROM `minutes` JOIN champs_minutes ON champs_minutes.idMinutes = minutes.id WHERE minutes.idProjet = $idProjet ORDER BY idMinutes, idChamp;";

	return parcoursRs(SQLSelect($sql));
}

// renvoie le nombre d'élément dans la template du projet
function NombreTemplate($idProjet){
	$SQL="SELECT COUNT(*) FROM champs_templates WHERE idProjet=$idProjet;";

	return SQLGetChamp($SQL);
}

// renvoie 1 ou 0 selon s'il est membre
function estMembre($idUser, $idProjet){
	$sql = "SELECT COUNT(*) FROM `membres` WHERE id = $idProjet AND idMembre = $idUser;";

	return SQLGetChamp($sql);
}
?>

<?php
// Ce fichier permet de tester les fonctions développées dans le fichier controleur.php (première partie)

include_once "modele.php"; 
include_once "maLibUtils.php"; 
include_once "maLibForms.php"; 


//* TRAITER LES ACTIONS DEMANDE
// valider("idUser");
//! NE PAS UTILISER LE CODE SUIVANT A CAUSE DES IN
// $action = $_GET['action'];
// $idUser = $_GET['idUser'];

$action = valider('action');
$idUser = valider('idUser');

if ($action == "Interdire"){
	echo "Interdiction...";
	interdireUtilisateur("$idUser");
}else if($action == "Autoriser"){
	echo "autorisation...";	
	autoriserUtilisateur("$idUser");
}


?>

<h1>Administration du site</h1>

<h2>Liste des utilisateurs de la base </h2>

<?php

echo "liste des utilisateurs autorises de la base :"; 
$users = listerUtilisateurs("both");
?>

<?php
foreach ($users as $dataUser)
{
	echo "<p";
	//echo "style=\"color:red;\";
	if ($dataUser['blacklist']){
		echo " style=\"color:red;\"";
	}

	// echo $dataUser['blacklist'];

	echo ">";
	$nom = $dataUser["pseudo"];
	echo  "$nom";
	echo "</p>";
}

?>


<?php

// tprint($users);	// préférer un appel à mkTable($users);

echo "<hr />";

echo "liste des utilisateurs non autorises de la base :"; 
$users = listerUtilisateurs("");

echo "<h1>MK TABLE</h1>";
mkTable($users, ["pseudo","id"]);	// préférer un appel à mkTable($users);
?>


<hr />

<h2>Changement de statut des utilisateurs</h2>

<form>

<select name="idUser">
<?php
// echo "value=\"$idUser\"";
$users = listerUtilisateurs("both");

// préférer un appel à mkOptions($users, ...)
foreach ($users as $dataUser)
{
	if ($idUser == $dataUser["id"]){
		echo "<option value=\"$dataUser[id]\" selected=\"selected\">";
	}else{
		echo "<option value=\"$dataUser[id]\">";
	}

	echo  $dataUser["pseudo"];
	echo "</option>"; 
}

?>
</select>

<input type="submit" name="action" value="Interdire" />
<input type="submit" name="action" value="Autoriser" />
</form>

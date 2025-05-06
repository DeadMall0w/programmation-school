<?php


/*
Ce fichier d�finit diverses fonctions permettant de faciliter la production de mises en formes complexes : 
tableaux, formulaires, ...
*/

function mkLigneEntete($tabAsso,$listeChamps=false)
{
	// Fonction appel�e dans mkTable, produit une ligne d'ent�te
	// contenant les noms des champs � afficher dans mkTable
	// Les champs � afficher sont d�finis � partir de la liste listeChamps 
	// si elle est fournie ou du tableau tabAsso
	echo "  <tr>\n";
	if ($listeChamps) {
	  foreach ($listeChamps as $champ) {
	    echo "    <th>$champ</th>\n";
	  }
  } else {
	  foreach ($tabAsso as $cle => $champ) {
	    echo "    <th>$cle</th>\n";
	  }
  }
	echo "  </tr>\n";
}

function mkLigne($tabAsso,$listeChamps=false)
{
	// Fonction appel�e dans mkTable, produit une ligne 
	// contenant les valeurs des champs � afficher dans mkTable
	// Les champs � afficher sont d�finis � partir de la liste listeChamps 
	// si elle est fournie ou du tableau tabAsso
	echo "  <tr>\n";
	if ($listeChamps) {
	  foreach ($listeChamps as $cle) {
	    echo "    <td>$tabAsso[$cle]</td>\n";
	  }
  } else {
	  foreach ($tabAsso as $champ) {
	    echo "    <td>$champ</td>\n";
	  }
  }
	echo "  </tr>\n";
}

function mkTable($tabData,$listeChamps=false)
{
	// Produit un tableau affichant les donn�es pass�es en param�tre
	// Si listeChamps est vide, on affiche toutes les donn�es de $tabData
	// S'il est d�fini, on affiche uniquement les champs list�s dans ce tableau, 
	// dans l'ordre du tableau
	echo "<table>\n";
	  if (count($tabData) > 0) {
	    mkLigneEntete($tabData[0], $listeChamps);
    } else {
	    mkLigneEntete(array(), $listeChamps);
    }
	  foreach($tabData as $tabAsso) {
	    mkLigne($tabAsso, $listeChamps);
	  }
	echo "</table>\n";
}

function mkSelect($nomChampSelect, $tabData,$champValue, $champLabel,$selected=false,$champLabel2=false)
{
	// Produit un menu d�roulant portant l'attribut name = $nomChampSelect
	// TNE: Si cette variable se termine par '[]', il faudra affecter l'attribut multiple � la balise select

	// Produire les options d'un menu d�roulant � partir des donn�es pass�es en premier param�tre
	// $champValue est le nom des cases contenant la valeur � envoyer au serveur
	// $champLabel est le nom des cases contenant les labels � afficher dans les options
	// $selected contient l'identifiant de l'option � s�lectionner par d�faut
	// si $champLabel2 est d�fini, il indique le nom d'une autre case du tableau 
	// servant � produire les labels des options
	echo "<select name=\"$nomChampSelect\">\n";
	foreach ($tabData as $u) {
	  $strSelected = "";
	  if ($u[$champValue] == $selected) {
	    $strSelected = "selected=\"selected\"";
	  }
	  echo "  <option value=\"$u[$champValue]\" $strSelected>";
	  echo "$u[$champLabel]";
	  if ($champLabel2) {
	    echo " ($u[$champLabel2])";
	  }
	  echo "</option>\n";
	}
	echo "</select>\n";
}

function mkForm($action="controleur.php",$method="get")
{
	// Produit une balise de formulaire NB : penser � la balise fermante !!
	echo "<form action=\"$action\" method=\"$method\">\n";
}
function endForm()
{
	// produit la balise fermante
	echo "</form>\n";
}

function mkInput($type,$name,$value="")
{
	// Produit un champ formulaire
	mkRadioCb($type, $name, $value, false);
	//echo "<input type=\"$type\" name=\"$name\" value=\"$value\" />\n";
}

function mkRadioCb($type,$name,$value,$checked=false)
{
	// Produit un champ formulaire de type radio ou checkbox
	// Et s�lectionne cet �l�ment si le quatri�me argument est vrai
  if ($checked) {
    $strChecked = "checked=\"checked\"";
  } else {
    $strChecked = "";
  }
	echo "<input type=\"$type\" name=\"$name\" value=\"$value\" $strChecked />\n";
}
?>


















<?php


/*
Ce fichier définit diverses fonctions permettant de faciliter la production de mises en formes complexes : 
tableaux, formulaires, ...
*/

function mkLigneEntete($tabAsso,$listeChamps=false)
{
	// Fonction appelée dans mkTable, produit une ligne d'entête
	// contenant les noms des champs à afficher dans mkTable
	// Les champs à afficher sont définis à partir de la liste listeChamps 
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
	// Fonction appelée dans mkTable, produit une ligne 
	// contenant les valeurs des champs à afficher dans mkTable
	// Les champs à afficher sont définis à partir de la liste listeChamps 
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
	// Produit un tableau affichant les données passées en paramètre
	// Si listeChamps est vide, on affiche toutes les données de $tabData
	// S'il est défini, on affiche uniquement les champs listés dans ce tableau, 
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
	// Produit un menu déroulant portant l'attribut name = $nomChampSelect
	// TNE: Si cette variable se termine par '[]', il faudra affecter l'attribut multiple à la balise select

	// Produire les options d'un menu déroulant à partir des données passées en premier paramètre
	// $champValue est le nom des cases contenant la valeur à envoyer au serveur
	// $champLabel est le nom des cases contenant les labels à afficher dans les options
	// $selected contient l'identifiant de l'option à sélectionner par défaut
	// si $champLabel2 est défini, il indique le nom d'une autre case du tableau 
	// servant à produire les labels des options
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

function mkForm($action="",$method="get")
{
	// Produit une balise de formulaire NB : penser à la balise fermante !!
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
	// Et sélectionne cet élément si le quatrième argument est vrai
  if ($checked) {
    $strChecked = "checked=\"checked\"";
  } else {
    $strChecked = "";
  }
	echo "<input type=\"$type\" name=\"$name\" value=\"$value\" $strChecked />\n";
}
?>

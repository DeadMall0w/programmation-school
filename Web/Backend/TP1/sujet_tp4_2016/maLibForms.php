<html>
<head>
<style>
body {
background-color: linen;
}
h1 {
color: maroon;
margin-left: 40px;
}

table {
    width: 100%;
    border-collapse: collapse;
    border-radius: 8px;
    overflow: hidden;
    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
}

th, td {
    border: 1px solid #ddd;
    padding: 10px;
    text-align: left;
}

th {
    background-color: #f4f4f4;
    font-weight: bold;
}

tr:nth-child(even) {
    background-color: #f9f9f9;
}

tr:hover {
    background-color: #f1f1f1;
}
</style>
</head>

<?php


/*
Ce fichier d�finit diverses fonctions permettant de faciliter la production de mises en formes complexes : 
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
	// Produit un menu d�roulant portant l'attribut name = $nomChampSelect
	// TNE: Si cette variable se termine par '[]', il faudra affecter l'attribut multiple � la balise select

	// Produire les options d'un menu d�roulant � partir des donn�es pass�es en premier param�tre
	// $champValue est le nom des cases contenant la valeur � envoyer au serveur
	// $champLabel est le nom des cases contenant les labels � afficher dans les options
	// $selected contient l'identifiant de l'option � s�lectionner par d�faut
	// si $champLabel2 est d�fini, il indique le nom d'une autre case du tableau 
	// servant � produire les labels des options
}

function mkForm($action="",$method="get")
{
	// Produit une balise de formulaire NB : penser � la balise fermante !!
}
function endForm()
{
	// produit la balise fermante
}

function mkInput($type,$name,$value="")
{
	// Produit un champ formulaire
}

function mkRadioCb($type,$name,$value,$checked=false)
{
	// Produit un champ formulaire de type radio ou checkbox
	// Et s�lectionne cet �l�ment si le quatri�me argument est vrai
}
?>


















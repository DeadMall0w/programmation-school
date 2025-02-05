<?php

function show($tab)
{
	echo "<table border=\"1\"><tr><td>Nom</td><td>Valeur</td></tr>";
	foreach( $tab as $cle => $val)
	{
		echo "<tr><td>$cle</td><td>";
		if (is_array($val))
			show($val);
		else 
			echo "$val"; 
		echo "</td></tr>";
	}
	echo "</table>";
}

echo "Donn&eacute;es envoy&eacute;es par GET: <br />";
show($_GET);
 

echo "<hr />Donn&eacute;es envoy&eacute;es par POST: <br />";
show($_POST);

?>

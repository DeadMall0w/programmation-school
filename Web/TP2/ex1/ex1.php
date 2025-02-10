<?php
if ($_SERVER["REQUEST_METHOD"] == "GET") 
{	
	echo "Cette page a été appelée par la méthode GET <br />"; 
	$tab=$_GET;
}
else 
{
	echo "Cette page a été appelée par la méthode POST <br />";
	$tab=$_POST;
}

if (count($tab)>0)
{ 
	echo "Données reçues : <pre>";
	print_r($tab);
	echo "</pre><br />";
}
else
{
	echo "Aucune donnée reçue";
}

// pour éviter les soucis avec des configurations de php utilisant les tags courts
echo "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";
?>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<!-- **** H E A D **** -->
<head>	
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
</head>
<!-- **** F I N **** H E A D **** -->


<!-- **** B O D Y **** -->
<body>

<form action="" method="">
<input type="text" name="champ_texte"/>
<input type="submit" />
</form>
  
</body>
<!-- **** F I N **** B O D Y **** -->

</html>

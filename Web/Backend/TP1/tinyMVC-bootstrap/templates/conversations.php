<?php

//C'est la propriété php_self qui nous l'indique : 
// Quand on vient de index : 
// [PHP_SELF] => /chatISIG/index.php 
// Quand on vient directement par le répertoire templates
// [PHP_SELF] => /chatISIG/templates/accueil.php

// Si la page est appelée directement par son adresse, on redirige en passant pas la page index
// Pas de soucis de bufferisation, puisque c'est dans le cas où on appelle directement la page sans son contexte
if (basename($_SERVER["PHP_SELF"]) != "index.php")
{
	header("Location:../index.php?view=conversations");
	die("");
}

$idConv = valider("idConv", "GET");

?>


<div class="page-header">
  <h1>Conversations</h1>
</div>

<h2>Conversation actives</h2>

<?php
$conversations = listerConversations("actives");
mkLiens($conversations, "theme", "id", "index.php?view=messages","idConv");
?>

<h2>Conversation inactives</h2>

<?php
$conversations = listerConversations("inactives");
mkLiens($conversations, "theme", "id", "index.php?view=messages","idConv");
?>


<?php

if (valider("admin", "SESSION")) {
  echo "<h2>Gestion des conversations</h2>\n";

  $conversations = listerConversations("toutes");

  mkForm();
    mkSelect("idConv", $conversations, "id", "theme", $idConv, "active");
    mkInput("submit", "action", "Archiver");
    mkInput("submit", "action", "Reactiver");
    mkInput("submit", "action", "Supprimer");
    mkInput("hidden", "view", "conversations");
  endForm();

  mkForm();
    mkInput("text", "theme", "");
    mkInput("submit", "action", "Nouvelle conversation");
    mkInput("hidden", "view", "conversations");
  endForm();
}




?>










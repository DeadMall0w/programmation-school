<?php

	include_once "modele.php"; 
	include_once "maLibUtils.php";
	include_once "maLibSecurisation.php"; 

	// Cette page recoit des demandes de traitement de base de données 
	// Elle est sécurisée, et ne doit pouvoir être utilisée que si l'utilisateur connecté est un administrateur
	// Si ce n'est pas le cas, elle redirige vers la page appelante si elle existe ou le formulaire de login sinon

	// Toute demande contient un champ 'action' indiquant l'action à réaliser
	// Une fois le traitement effectué, la page redirige vers la page appelante 
	// en renvoyant les données les plus pertinentes transmises et un message de feedback

	// veiller à vérifier les données transmises à l'aide de la fonction valider()
	// et à vous prémunir des injections SQL

	securiser("a completer avec l'url de la page appelante ou de la page de login"); 

	if ($action = valider("action"))
	{
		// Un paramètre action a été soumis, on fait le boulot...

		switch($action)
		{
			case 'todo' : 
	
			break;

			case 'tada' : 

			break;			
		}
	}

	// On redirige vers la page appelante 
	header("Location:" . $_SERVER["HTTP_REFERER"]);$
	
?>

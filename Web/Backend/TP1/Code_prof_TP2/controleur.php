<?php

  session_start();

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
  
  // Routine de connexion
  if (valider("action") == "Se connecter") {
    $login = valider("login", "GET");
    $passe = valider("passe", "GET");
    if ($login && $passe) {
      if (verifUser($login, $passe)) {
        // Rediriger vers vue_partie1.php
        rediriger("vue_partie1.php",
                  ["message" => "Connexion réussie, bienvenue " . $_SESSION["pseudo"] . " !"]);
      } else {
        // Message d'erreur
        $_SESSION["tentatives"] = valider("tentatives", "SESSION") + 1;
        rediriger("login.php", ["message" => "Connexion échouée !"]);
      }
    }
  }
  
  // fait un retour à la page de connexion si l'utilisateur n'est pas connecté
	securiser("login.php"); 
  
  // On reproduit la querystring dans la redirection
  $qs = $_GET;

	if ($action = valider("action"))
	{
		// Un paramètre action a été soumis, on fait le boulot...

		switch($action)
		{
			case 'Interdire' : 
			  if (($idUser = valider("idUser", "GET")) &&
			      valider("admin", "SESSION")) {
		      interdireUtilisateur($idUser);
			  } else {
		      $qs["message"] = "Opération échouée";
			  }
			break;

			case 'Autoriser' : 
			  if (($idUser = valider("idUser", "GET")) &&
			      valider("admin", "SESSION")) {
		      autoriserUtilisateur($idUser);
			  } else {
		      $qs["message"] = "Opération échouée";
			  }
			break;

			case 'Changer couleur' : 
			  if (($idUser = valider("idUser", "GET")) &&
			      ($couleur = valider("couleur", "GET")) &&
			      valider("admin", "SESSION")) {
		      changerCouleur($idUser, $couleur);
			  } else {
		      $qs["message"] = "Opération échouée";
			  }
			break;

			case 'Déconnexion' : 
        session_destroy();
        $_SESSION = [];
        rediriger("login.php",
          ["message" => "Déconnexion réussie !"]);
			break;			
		}
	}

	// On redirige vers la page appelante 
	$url = explode("?", $_SERVER["HTTP_REFERER"])[0];
	rediriger($url, $qs);
	
?>

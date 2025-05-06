<?php

  session_start();

	include_once "libs/modele.php"; 
	include_once "libs/maLibUtils.php";
	include_once "libs/maLibSecurisation.php"; 

	// Cette page recoit des demandes de traitement de base de données 
	// Elle est sécurisée, et ne doit pouvoir être utilisée que si l'utilisateur connecté est un administrateur
	// Si ce n'est pas le cas, elle redirige vers la page appelante si elle existe ou le formulaire de login sinon

	// Toute demande contient un champ 'action' indiquant l'action à réaliser
	// Une fois le traitement effectué, la page redirige vers la page appelante 
	// en renvoyant les données les plus pertinentes transmises et un message de feedback

	// veiller à vérifier les données transmises à l'aide de la fonction valider()
	// et à vous prémunir des injections SQL
  
  // Routine de connexion
  if (valider("action") == "Connexion") {
    $login = valider("login", "GET");
    $passe = valider("passe", "GET");
    if ($login && $passe) {
      if (verifUser($login, $passe)) {
        // Rediriger vers l'accueil
        rediriger("index.php",
                  ["view" => "accueil",
                   "message" => "Connexion réussie, bienvenue " . $_SESSION["pseudo"] . " !"]);
      } else {
        // Message d'erreur
        $_SESSION["tentatives"] = valider("tentatives", "SESSION") + 1;
        rediriger("index.php",
                  ["view" => "login",
                   "message" => "Connexion échouée !"]);
      }
    }
  }
  
	securiser("index.php",
	          ["view" => "login",
	           "message" => "Connexion requise !"]); 
  
  // On reproduit la querystring dans la redirection
  $qs = $_GET;

	if ($action = valider("action"))
	{
		// Un paramètre action a été soumis, on fait le boulot...

		switch($action)
		{
		  // Actions sur les utilisateurs
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

			case 'Ajouter admin' : 
			  if (($idUser = valider("idUser", "GET")) &&
			      valider("admin", "SESSION")) {
		      promouvoirAdmin($idUser);
			  } else {
		      $qs["message"] = "Opération échouée";
			  }
			break;

			case 'Retirer admin' : 
			  if (($idUser = valider("idUser", "GET")) &&
			      valider("admin", "SESSION")) {
		      retrograderUser($idUser);
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

			case 'Changer pseudo' : 
			  if (($idUser = valider("idUser", "GET")) &&
			      ($pseudo = valider("pseudo", "GET")) &&
			      valider("admin", "SESSION")) {
		      changerPseudo($idUser, $pseudo);
			  } else {
		      $qs["message"] = "Opération échouée";
			  }
			break;

		  // Actions sur les conversations
			case 'Archiver' : 
			  if (($idConv = valider("idConv", "GET")) &&
			      valider("admin", "SESSION")) {
		      archiverConversation($idConv);
			  } else {
		      $qs["message"] = "Opération échouée";
			  }
			break;

			case 'Reactiver' : 
			  if (($idConv = valider("idConv", "GET")) &&
			      valider("admin", "SESSION")) {
		      reactiverConversation($idConv);
			  } else {
		      $qs["message"] = "Opération échouée";
			  }
			break;

			case 'Supprimer' : 
			  if (($idConv = valider("idConv", "GET")) &&
			      (valider("view", "GET") == "conversations") &&
			      valider("admin", "SESSION")) {
		      supprimerConversation($idConv);
			  } else {
		      $qs["message"] = "Opération échouée";
			  }
			break;

			case 'Nouvelle conversation' : 
			  if (($theme = valider("theme", "GET")) &&
			      valider("admin", "SESSION")) {
		      creerConversation($theme);
			  } else {
		      $qs["message"] = "Opération échouée";
			  }
			break;

		  // Logout
			case 'Logout' : 
        session_destroy();
        $_SESSION = [];
        rediriger("index.php",
                  ["view" => "login",
                   "message" => "Déconnexion réussie !"]);
			break;			
		}
	}

	// On redirige vers la page appelante 
	$url = explode("?", $_SERVER["HTTP_REFERER"])[0];
	rediriger($url, $qs);
	
?>

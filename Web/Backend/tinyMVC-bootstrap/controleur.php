<?php
session_start();

	include_once "libs/maLibUtils.php";
	include_once "libs/maLibSecurisation.php"; 
	include_once "libs/modele.php"; 


	//  // Routine de connexion
	 if (valider("action") == "Connexion") {
		$login = valider("login", "GET");
		$passe = valider("passe", "GET");
		if ($login && $passe) {
		  if (verifUser($login, $passe)) {
			// tout s'est bien passé, doit-on se souvenir de la personne ? 
			if (valider("remember")) {
				setcookie("login",$login , time()+60*60*24*30);
				setcookie("passe",$password, time()+60*60*24*30);
				setcookie("remember",true, time()+60*60*24*30);
				
			} else {
				setcookie("login","", time()-3600);
				setcookie("passe","", time()-3600);
				setcookie("remember",false, time()-3600);
			}

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
	  
	// 	securiser("index.php",
	// 			  ["view" => "login",
	// 			   "message" => "Connexion requise !"]); 
	  
	//   // On reproduit la querystring dans la redirection
	  $qs = $_GET;

if ($action = valider("action"))
	{
		// Un paramètre action a été soumis, on fait le boulot...

		switch($action)
		{
		  // Actions sur les utilisateurs
			case 'Interdire' : 
				// die("id : " . $_GET["idUser"]);
				if (($idUser = valider("idUser", "GET")) && valider("admin", "SESSION")) {
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
	// die(tprint($qs));
	// rediriger("index.php",["view" => "admin"]);
	rediriger("index.php",$qs);

	// 				   "message" => "Connexion échouée !"] );
	
?>




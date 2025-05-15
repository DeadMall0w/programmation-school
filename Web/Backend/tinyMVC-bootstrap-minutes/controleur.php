<?php
session_start();

	include_once "libs/maLibUtils.php";	
	include_once "libs/modele.php"; 
	include_once "libs/maLibSecurisation.php"; 
	// cf. injection de dépendances 


	// $qs = "";
	$qs = $_GET;
	$dataQS = array(); 
	
	// voir les entetes HTTP venant du client : 
	// tprint($_SERVER);
	// die("");

	if ($action = valider("action"))
	{
		ob_start ();
		echo "Action = '$action' <br />";
		// ATTENTION : le codage des caractères peut poser PB si on utilise des actions comportant des accents... 
		// A EVITER si on ne maitrise pas ce type de problématiques

		// Un paramètre action a été soumis, on fait le boulot...
		switch($action)
		{
			
			// Connexion //////////////////////////////////////////////////
			case 'Connexion' :
				// On verifie la presence des champs login et passe
				if ($login = valider("login"))
				if ($passe = valider("passe"))
				{
					// On verifie l'utilisateur, 
					// et on crée des variables de session si tout est OK
					// Cf. maLibSecurisation
					if (verifUser($login,$passe)) {
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
				    // On redirigera vers la page index automatiquement, avec la vue d'accueil
				    $qs = array("view" => "accueil",
				                "msg" => "Connexion réussie, bienvenue $login !");
					} else {
				    $qs = array("view" => "login",
				                "msg" => "Erreur de connexion, veuillez réessayer");
					}
				}
			break;
			case "Supprimer champ":
				//TODO : RAJOUTER DES SECURITE POUR NE PAS QUE TOUT LE MONDE PUISSE UTILISER CETTE REQUETE
				if ($champID = valider("champID", "GET")){
					if ($champID <= 2){
						// On ne peut pas supprimer
						//TODO : prevenir l'utilsateur que ce n'est pas possible
					}else{
						// TODO : Ramener à la bonne vue
						// $qs["view"] = "editionTemplate"; 
						// $qs["champID"] = $champID; 

						supprimerChamp($champID);
					}
				}

				break;
			case "Ajouter champ":
				//TODO : RAJOUTER DES SECURITE POUR NE PAS QUE TOUT LE MONDE PUISSE UTILISER CETTE REQUETE
				if (($projetID = valider("projetID", "GET")) &&
					($nomChamp = valider("nomChamp", "GET")) &&
					($type = valider("type", "GET")) 
				){
					// TODO : Ramener à la bonne vue
					ajouterChamp($projetID, $type, $nomChamp);

				}

				break;
			case 'Logout' :
			case 'logout' :
				session_destroy();
				$qs = array("view" => "login",
				            "msg" => "Déconnexion réussie");
			break;
			
		}
	}

	// On redirige toujours vers la page index, mais on ne connait pas le répertoire de base
	// On l'extrait donc du chemin du script courant : $_SERVER["PHP_SELF"]
	// Par exemple, si $_SERVER["PHP_SELF"] vaut /chat/data.php, dirname($_SERVER["PHP_SELF"]) contient /chat

	$urlBase = dirname($_SERVER["PHP_SELF"]) . "/index.php";
	// On redirige vers la page index avec les bons arguments
	
	if ($qs == "") {
		// On renvoie vers la page précédente en se servant de HTTP_REFERER
		// attention : il peut y avoir des champs en + de view...
		$qs = parse_url($_SERVER["HTTP_REFERER"]. "&cle=val", PHP_URL_QUERY);
		$tabQS = explode('&', $qs);
		array_map('parseDataQS', $tabQS);
		$qs = "?view=" . $dataQS["view"];
	}

	rediriger($urlBase, $qs);

	// On écrit seulement après cette entête
	ob_end_flush();

	function parseDataQS($qs) {
		global $dataQS; 
		$t = explode('=',$qs);
		$dataQS[$t[0]]=$t[1]; 
	}
	
?>











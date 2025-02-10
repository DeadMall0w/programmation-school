/* Gestion du Workflow ***********************************************/

	var workflow = 
	{
		etapes : [
			{	"id":"etape1", 
				"label": "Veuillez saisir vos coordonnées personnelles", 
				"btnActiver":"Saisir vos identifiants",
				"champsAValider" : ["txtNom","txtPrenom","txtDateNaissance"],
				"display" : "block"
			},
			{	"id":"etape2", 
				"label": "Veuillez saisir vos identifiants", 
				"btnActiver":"Saisir vos données personnelles",
				"champsAValider" : ["txtLogin","txtPasse"],
				"display" : "block"
			},
			{
				"id":"etape3", 
				"label": "Veuillez saisir vos données personnelles", 
				"btnActiver":"Soumettre le formulaire",
				"champsAValider" : [],
				"display" : "block"
			},
			{	"id":"etape4", 
				"label": "Vérifiez une dernière fois votre formulaire", 
				"btnActiver":false,
				"display" : "inline"
			},
		]	
	};
s

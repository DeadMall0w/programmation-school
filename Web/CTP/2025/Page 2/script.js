let importTxtArea; // Référence au textarea ou l'utilisateur entre le json
let exportTxtArea; // Référence au textarea ou l'utilisateur récupère le nouveau json
let container; // Référence vers le conteneur des champs

// Permet de dire si les champs ont fini d'être généré
// Peut cause certain problème si on clique et que les champs ne sont pas tous généré
let finishLoading = true;

let data; // Variable contenant la template
let exportData = []; // Variable stockant les données qui vont être exporté
// Initialisé comme une liste pour pouvoir ajouter un objet par champ créé

// Fonction appelé une fois que la page à fini de charger
function init(){
    // initialisation des références vers les éléments de la page HTML
    importTxtArea = document.getElementById("import");
    exportTxtArea = document.getElementById("export");
    
    container = document.getElementById("container");
}

// Fonction appelé par le bouton "import"
function Import(){
    console.log("IMPORTING DATA...");
    data = JSON.parse(importTxtArea.value); // transforme le text en json
    
    // met à jour les champs
    UpdateFields();
}


function UpdateFields(){
    finishLoading = false; // Au début de cette fonction, le chargement n'est pas fini
    
    exportData = []; // Réinitialise exportData afin de ne pas laisser des anciens éléments 

    // D'abord enlève tous les éléments déjà présent 
    while (container.children.length > 0) {
        container.removeChild(container.firstChild);
    }

    // pour chaque champ, créé un objet label et input avec le bon type
    for (let i = 0; i < data.length; i++) {
        // Création de l'élément label
        const label = document.createElement('label');

        // Relie le label avec l'objet input (pas encore créé, mais aura l'id = i)
        label.htmlFor = i; // Provient de la réponse de : https://stackoverflow.com/questions/15750290/setting-the-html-label-for-attribute-in-javascript
        label.textContent = data[i]["nom"]; // Initialise le label avec le bon texte
        
        // Créé une variable stockant l'objet input (cette objet sera créé selon le type d'input dictée par la template)
        let input;

        if (data[i]["type"] == "string"){ // Si le type est une chaîne de caractères
            input = document.createElement("input"); // De base un input contient des chaînes de caractères
        }else if (data[i]["type"] == "number"){ // Si le type est un nombre (entier ou flottant)
            input = document.createElement("input");
            input.type="number"; // Provient de https://www.w3schools.com/tags/att_input_type_number.asp
        }else if(data[i]["type"] == "multiple"){ // Si le type est une sélection multiple (ctrl+clique pour en sélectionner plusieurs)
            input = document.createElement("select"); // utilisation du type select
            input.multiple = "multiple"; // Permet de sélectionner plusieurs champs
            
            const fields = data[i]["valeurs"].split(","); // Divise la chaîne de caractère en tableau à chaque ","
            
            // Pour chaque option créer un élément option avec le bon text
            for (let j = 0; j < fields.length; j++) {
                const option = document.createElement("option"); 
                option.value = fields[j]; // initialise la valeur 
                option.textContent = fields[j]; // Initialise le texte

                option.id = i; // permet d'avoir le bon id quand on clique dessus

                input.appendChild(option); // Ajout l'élément aux options
            }

        }else if(data[i]["type"] == "select"){ // Si l'utilisateur doit choisir un élément parmi ceux proposé (dit : dropdown) 
            // meme chose que avant mais sans le tag multiple
            input = document.createElement("select");
            const fields = data[i]["valeurs"].split(",");
            for (let j = 0; j < fields.length; j++) {
                const option = document.createElement("option");
                option.value = fields[j]; // initialise la valeur 
                option.textContent = fields[j]; // Initialise le texte

                option.id = i; // permet d'avoir le bon id quand on clique dessus

                input.appendChild(option); // Ajout l'élément aux options
            }
        }else if(data[i]["type"] == "booléen"){ // Si le type est booléen : soit vrai, soit faux
            input = document.createElement("select"); // meme élément que utilisé avant (dropdown)
            const option1 = document.createElement("option");
            option1.value = "1"; // 1 = true
            option1.textContent = "VRAI";

            const option2 = document.createElement("option");
            option2.value = "0"; // 0 = false
            option2.textContent = "FAUX";

            // ajout les 2 options
            input.appendChild(option1);
            input.appendChild(option2);
            
        }else{
            console.error("Le type : " + data[i]["type"] + " n'est pas supporté !");
            continue; // permet de zapper l'élément actuel mais sans arrêter la boucle
        }

        input.id = i; // ajout le bon id
        // l'id permet de savoir quel est l'indice dans le tableau des valeurs à exporté, afin de mettre à jour les données
        

        // ajout les différents éléments aux container
        container.appendChild(label);
        container.appendChild(input);

        container.appendChild(document.createElement("br")); // permet de passer une ligne entre chaque champ
        
        // initialise exportData
        let newExportData = {
            "nom": data[i]["nom"],
            "valeur":input.value // prend la valeur de base (utile pour les select pour ne pas se retrouver avec des champs vides si on laisse la valeur par défaut)
        } 

        exportData.push(newExportData);
        
        // ajoute la classe input, permet de faire des vérifications
        input.classList.add("input");

        // S'abonne au clic de la souris 
        input.addEventListener('click', function(event) {
            FieldClicked(event);// appelle la fonction pour modifier les valeurs
            event.stopPropagation(); // Permet d'empêcher la propagation vers un parent (non nécessaire dans notre cas)
        });
        
        // S'abonne au touche du clavier relevé
        input.addEventListener('keyup', function(event) {
            FieldClicked(event); // appelle la fonction pour modifier les valeurs
            event.stopPropagation(); // Permet d'empêcher la propagation vers un parent (non nécessaire dans notre cas)
        });
    }

    finishLoading = true; // Indique qu'il a fini de charger
}

function FieldClicked(event){
    let evt; // permet de rendre plus facile l'accès aux valeur
    if (finishLoading){ // permet de ne pas pouvoir cliquer si les champs n'ont pas fini d'apparaître

        if (data[event.target.id]["type"] != "multiple"){ // Vérifie si ce n'est pas à champs multiples
            evt = event.target.value;

            // Change la valeur dans le tableau, par celle entrée par l'utilisateur
            exportData[event.target.id]["valeur"] = evt;
        }else{
            exportData[event.target.id]["valeur"] ="";

            // Si on selection 2 elements, la variable event retourné est le parent, sinon la variable event est l'objet lui même
            if (event.target.classList.contains("input")){ //https://stackoverflow.com/questions/5898656/check-if-an-element-contains-a-class-in-javascript
                evt = event.target; // prend l'objet lui même
            }else{
                evt = event.target.parentElement; // prend le parent
            }

            // Pour chaque option sélectionné
            for (let i = 0; i < evt.selectedOptions.length; i++) {
                exportData[event.target.id]["valeur"] += evt.selectedOptions[i].value + ","; // ajout chaque valeur, séparé par une virgule                
            }
        }

    }
}


// Fonction appelé par le bouton "export"
function Export(){
    console.log("EXPORTING DATA...");

    exportTxtArea.value = JSON.stringify(exportData); // Transforme le JSON en texte
}
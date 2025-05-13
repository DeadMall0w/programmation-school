let importTxtArea; // Référence au textarea ou l'utilisateur entre le json
let exportTxtArea; // Référence au textarea ou l'utilisateur récupère le nouveau json
let container; // Référence vers le conteneur des champs

// Permet de dire si les champs ont fini d'être généré
// Peut cause certain problème si on clique et que les champs ne sont pas tous généré
let finishLoading = true;

let data; // Variable contenant la template

// Nous devons utiliser des listes de listes dans notre cas, c'est pourquoi je créé deux variables
let exportDataList = [];// Variable stockant les données qui vont être exporté
// Initialisé comme une liste pour pouvoir ajouter un objet par champ créé
let exportData = []; // initialise en tant que liste 

// permet de compte le nombre de document minute ajouté
let idCount = 0;

// Fonction appelé une fois que la page à fini de charger
function init(){
    // initialisation des références vers les éléments de la page HTML
    importTxtArea = document.getElementById("import");
    exportTxtArea = document.getElementById("export");
    
    container = document.getElementById("container");
}


function Import(){
    console.log("IMPORTING DATA...");
    data = JSON.parse(importTxtArea.value); // transforme le text en json

    // Créer une nouvelle partie document minute
    UpdateFields(idCount);
    idCount += 1;
}


// Fonction pour ajouter un document minute
function UpdateFields(id){
    finishLoading = false;
    exportData = [];

    // Création du fieldset et de sa légende
    const fieldSet = document.createElement("fieldset");
    const legend = document.createElement("legend");
    legend.textContent = "Document minutes";
    fieldSet.id = id; // Configure le bon id (celui fourni en paramètre)


    // Plus besoin de supprimer les éléments
    // while (container.children.length > 0) {
    //     container.removeChild(container.firstChild);
    // }

    // pour chaque champ, créé un objet label et input avec le bon type
    for (let i = 0; i < data.length; i++) {
        // Création de l'élément label
        const label = document.createElement('label');

        label.htmlFor = i; // Provient de la reponse de : https://stackoverflow.com/questions/15750290/setting-the-html-label-for-attribute-in-javascript
        label.textContent = data[i]["nom"];
        
        // Même chose que pour la page 2
        let input;
        if (data[i]["type"] == "string"){
            input = document.createElement("input");
        }else if (data[i]["type"] == "number"){
            input = document.createElement("input");
            input.type="number"; // Provient de https://www.w3schools.com/tags/att_input_type_number.asp
        }else if(data[i]["type"] == "multiple"){
            input = document.createElement("select");
            input.multiple = "multiple"; // Permet de sélectionner plusieurs champs
            const fields = data[i]["valeurs"].split(",");
            for (let j = 0; j < fields.length; j++) {
                const option = document.createElement("option");
                option.value = fields[j];
                option.textContent = fields[j];

                option.id = i; // permet d'avoir le bon id quand on clique dessus

                input.appendChild(option);
            }

        }else if(data[i]["type"] == "select"){ // meme chose que avant mais sans le tag multiple
            input = document.createElement("select");
            const fields = data[i]["valeurs"].split(",");
            for (let j = 0; j < fields.length; j++) {
                const option = document.createElement("option");
                option.value = fields[j];
                option.textContent = fields[j];

                option.id = i; // permet d'avoir le bon id quand on clique dessus

                input.appendChild(option);
            }
        }else if(data[i]["type"] == "booléen"){
            input = document.createElement("select");
            const option1 = document.createElement("option");
            option1.value = "1"; // 1 = true
            option1.textContent = "VRAI";

            const option2 = document.createElement("option");
            option2.value = "0"; // 0 = false
            option2.textContent = "FAUX";

            input.appendChild(option1);
            input.appendChild(option2);
            
        }else{
            console.error("Le type : " + data[i]["type"] + " n'est pas supporté !");
            continue;
        }

        input.id = i;
        
        // ajout les différents éléments au fieldSet
        fieldSet.appendChild(legend);
        fieldSet.appendChild(label);
        fieldSet.appendChild(input);
        fieldSet.appendChild(document.createElement("br")); // permet de passer une ligne entre chaque champ
        
        // ajout le filedSet au container
        container.appendChild(fieldSet);

        let newExportData = {
            "nom": data[i]["nom"],
            "valeur":input.value
            //TODO : Il y a un bug, par défaut un booléen prend la valeur de 1, mais il faudrait mettre la valeur de true ou false
        } 
        
        // ajoute les données dans la liste
        exportData.push(newExportData);
        
        // ajoute la classe input, permet de faire des vérifications
        input.classList.add("input");

        // S'abonne au clic de la souris 
        input.addEventListener('click', function(event) {
            FieldClicked(event);
            event.stopPropagation(); // Permet d'empêcher la propagation vers un parent (non nécessaire dans notre cas)
        });

        // S'abonne aux touches du clavier relevé
        input.addEventListener('keyup', function(event) {
            FieldClicked(event);
            event.stopPropagation(); // Permet d'empêcher la propagation vers un parent (non nécessaire dans notre cas)
        });
    }

    // Ajoute la liste de donnée dans la liste de liste de donnée (exportDataList)
    exportDataList.push(exportData);
    finishLoading = true; // A fini de charger
}

function FieldClicked(event){
    let evt; // permet de rendre plus facile l'accès aux valeur
    if (finishLoading){ // permet de ne pas pouvoir cliquer si les champs n'ont pas fini d'apparaître

        evt = event.target.value;
        if (data[event.target.id]["type"] == "booléen"){

            // Change la valeur dans le tableau, par celle entrée par l'utilisateur
            if (evt == 1){
                exportDataList[event.target.parentElement.id][event.target.id]["valeur"] = "true";
            }else if(evt == 0){
                exportDataList[event.target.parentElement.id][event.target.id]["valeur"] = "false";
            }else{
                console.error("Valeur invalide !!");
                exportData[event.target.id]["valeur"] = evt; // ajout quand meme la valeur
            }
        }else if (data[event.target.id]["type"] != "multiple"){ // Vérifie si ce n'est pas à champs multiples

            // Nous utilisons l'id du parent comme indice dans exportDataList
            exportDataList[event.target.parentElement.id][event.target.id]["valeur"] = evt;
        }else{
            
            // Si on selection 2 elements, la variable event retourné est le parent, sinon l'objet cliqué
            if (event.target.classList.contains("input")){ //https://stackoverflow.com/questions/5898656/check-if-an-element-contains-a-class-in-javascript
                evt = event.target; // prend l'objet lui même
            }else{
                evt = event.target.parentElement; // prend le parent
            }

            // Pour enlever les valeurs précédentes
            exportDataList[evt.parentElement.id][event.target.id]["valeur"] ="";

            // Pour chaque option sélectionné
            for (let i = 0; i < evt.selectedOptions.length; i++) {
                const element = evt.selectedOptions[i];

                // Nous utilisons l'id du parent comme indice dans exportDataList
                exportDataList[evt.parentElement.id][event.target.id]["valeur"] += element.value + ",";                
            }
        }
    }
}

// Fonction appelé par le bouton "export"
function Export(){
    console.log("EXPORTING DATA...");

    exportTxtArea.value = JSON.stringify(exportDataList); // transforme le JSON en texte
}
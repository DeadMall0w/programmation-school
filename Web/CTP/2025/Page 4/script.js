let importTxtArea;
let container;

// let data = [[{"nom":"Auteur","valeur":"raph"},{"nom":"Durée","valeur":"1"},{"nom":"Catégorie","valeur":"ise,"},{"nom":"Niveau","valeur":"LE1"},{"nom":"Validé","valeur":"1"}],
// [{"nom":"Auteur","valeur":"martin"},{"nom":"Durée","valeur":"3"},{"nom":"Catégorie","valeur":"ise,sia,"},{"nom":"Niveau","valeur":"LE2"},{"nom":"Validé","valeur":"1"}],
// [{"nom":"Auteur","valeur":"Adrien"},{"nom":"Durée","valeur":""},{"nom":"Catégorie","valeur":"sia,"},{"nom":"Niveau","valeur":"LE3"},{"nom":"Validé","valeur":"0"}]];

let data;

// fonction appellé quand la page à fini de charger
function init(){
    // Récupère les différents élements
    importTxtArea = document.getElementById("import");
    container = document.getElementById("container");
}

// Fonction appellé par le bouton "import"
function Import(){
    console.log("IMPORTING DATA...");
    data = JSON.parse(importTxtArea.value);

    UpdateTable();
}


function UpdateTable(){
    // Supprimer l'ancien tableau
    while (container.children.length > 0) {
        container.removeChild(container.firstChild);
    }

    // créer un nouveau tableau


    // On commencer par créer le header du tableau
    // C'est à dire la premier ligne en haut qui donne le nom de chaque champ
    const table = document.createElement("table");

    var keys = Object.keys(data[0]);

    const header = document.createElement("tr");
    for(var i=0;i<keys.length;i++){
        var key = keys[i];
        const headerEl = document.createElement("th");
        headerEl.textContent = data[0][key]["nom"];

        header.appendChild(headerEl);
    }

    // une fois le header finit, on l'ajoute au tableau
    table.appendChild(header);

    // on va boucler sur chaque document minute
    keys = Object.keys(data);
    for(var i=0;i<keys.length;i++){
        var key = keys[i];
        
        // on créer une nouvelle ligne 
        const line = document.createElement("tr");
        
        for (let i = 0; i < data[key].length; i++) {
            // On ajoute dans cette ligne tous les champs
            const field = document.createElement("td");
            field.textContent = data[key][i]["valeur"]; // on met la bonne valeur de texte

            line.appendChild(field); // On ajoute le champ dans la ligne
        }

        table.appendChild(line); // On ajoute cette ligne dans le tableau

    }

    container.appendChild(table); // On ajoute le tableau dans le conteneur dédié

}
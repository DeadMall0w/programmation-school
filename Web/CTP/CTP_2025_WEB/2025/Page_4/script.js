let importTxtArea; // Référence au textearea dans lequel l'utilisateur entre le json
let container; // Conteneur dans lequel sera ajouté le tableau

// la variable contenant le json importé
let data;

// fonction appelé quand la page à fini de charger
function init(){
    // Récupère les différents éléments
    importTxtArea = document.getElementById("import");
    container = document.getElementById("container");
}

// Fonction appelé par le bouton "import"
function Import(){
    console.log("IMPORTING DATA...");
    data = JSON.parse(importTxtArea.value); // transforme le text en json

    // Met à jour le tableau
    UpdateTable();
}

// Fonction pour mettre à jour le tableau
function UpdateTable(){
    // Supprimer l'ancien tableau
    while (container.children.length > 0) {
        container.removeChild(container.firstChild);
    }

    // créer un nouveau tableau
    const table = document.createElement("table");

    // On commencer par créer le header du tableau
    // C'est à dire la premier ligne en haut qui donne le nom de chaque champ

    let keys = Object.keys(data[0]); // On suppose que chaque document minute provient de la meme template
    const header = document.createElement("tr");
    for(let i=0;i<keys.length;i++){
        let key = keys[i];
        const headerEl = document.createElement("th"); // Créer un champ header
        headerEl.textContent = data[0][key]["nom"];  // On prend le nom du champs (pas la valeur)

        header.appendChild(headerEl); // On ajoute le champ au header
    }

    // une fois le header finit, on l'ajoute au tableau
    table.appendChild(header);

    // on va boucler sur chaque document minute
    keys = Object.keys(data);
    for(let i=0;i<keys.length;i++){
        let key = keys[i];
        
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
let listContainer;
let nameText;
let dropDown;
let filter;

let add_titre;
let add_album;
let add_artiste;
let add_image;
let add_lien;

let jsonContainer;

let data = {
    "createur": "Maxime Folschette",
    "nom": "Mon best-of perso",
    "date": "17/03/2022",
    "liste_lecture": [
      { "titre": "Trains",
        "artiste": "Porcupine Tree",
        "album": "In Absentia",
        "image": "ressources/porcupine-tree_in-absentia.jpg",
        "lien": "https://www.youtube.com/watch?v=ut3OQzfaeSw"
      },
      { "titre": "Black Dog",
        "artiste": "Led Zeppelin",
        "album": "Led Zeppelin IV",
        "lien": "https://www.youtube.com/watch?v=yBuub4Xe1mw"
      }
    ]
  };
  
function init(){
    // Initialisation de toutes les variables
    listContainer = document.getElementById("list-container");
    nameText = document.getElementById("playlist-name");
    dropDown = document.getElementById("search-type");
    filter = document.getElementById("search-value");

    add_titre = document.getElementById("titre");
    add_album = document.getElementById("album");
    add_artiste = document.getElementById("artiste");
    add_image = document.getElementById("image");
    add_lien = document.getElementById("lien");

    jsonContainer = document.getElementById("json-container");

    // Met a jour une premiere fois
    Update();
}

// fonction pour mettre à jour tous les affichages dynamiques
function Update(){
    UpdateName();
    UpdateListe();
    UpdateJson();
}

// Fonction pour mettre à jour le nom de la playliste
function UpdateName(){
    nameText.innerText = data["nom"];
}

function UpdateListe(){
    // D'abord enlever tous les élements déjà présent 
    while (listContainer.children.length > 0) {
        listContainer.removeChild(listContainer.firstChild);
    }

    var keys = Object.keys(data["liste_lecture"]);
    for(var i=0;i<keys.length;i++){
        var key = keys[i];

        // filtres (le continue permet de zapper l'élement acutel de la boucle)
        if (dropDown.value == "title" && !data["liste_lecture"][key]["titre"].toLowerCase().includes(filter.value.toLowerCase())){
            continue;
        }else  if (dropDown.value == "artiste" && !data["liste_lecture"][key]["artiste"].toLowerCase().includes(filter.value.toLowerCase())){
            continue;
        }else if (dropDown.value == "album" && !data["liste_lecture"][key]["album"].toLowerCase().includes(filter.value.toLowerCase())){
            continue;
        }

        // créér les élements qui vont être ajouté
        const div = document.createElement('div');
        const image = document.createElement('img');
        const title = document.createElement('p');
        const album = document.createElement('p');

        const cross = document.createElement('img');

        
        // Ajoute les bonnes classes
        div.classList.add("music");
        image.classList.add("image");
        title.classList.add("title");
        album.classList.add("title");

        cross.classList.add("cross");


        // Permet d'aller sur la page si on clique sur la musique
        div.addEventListener('click', function() {
            loadURL(data["liste_lecture"][key]["lien"]);
        });

        cross.id = i;
        cross.addEventListener('click', function(event) {
            Remove(event);
            event.stopPropagation();
        });

        // Regarde si l'image n'est pas définie et met l'image par défaut
        if ( data["liste_lecture"][key]["image"] == undefined){
            image.src = "ressources/music.png";
        }else{
            image.src = data["liste_lecture"][key]["image"];
        }

        // met a jour les textes
        title.innerHTML = data["liste_lecture"][key]["artiste"] + " - <b>" + data["liste_lecture"][key]["titre"];
        album.textContent = data["liste_lecture"][key]["album"];

        cross.src = "ressources/cross.png"
        
        div.appendChild(image);
        div.appendChild(title);
        div.appendChild(album);

        div.appendChild(cross);

        
        listContainer.appendChild(div);
    }
}

function AddTitle(){
    // TODO : Rajouter des vérifications (text null, lien qui ne fonctionne pas, chemin d'image incorecte, texte trop long)

    // on regarde si une image a été ajouté
    let image = add_image.value;
    if(image == ""){
        image = undefined;
    }

    // Nouveau titre
    let newTitle = {
        "titre": add_titre.value,
        "artiste": add_artiste.value,
        "album": add_album.value,
        "image": image,
        "lien": add_lien.value
    }
    data["liste_lecture"].push(newTitle);

    // Mettre à jour l'affichage après avoir rajouté l'élement
    UpdateListe();
    
    // met à jour l'affichage JSON
    UpdateJson();

}


// fonction pour mettre à jour l'affichage du json
function UpdateJson(){
    jsonContainer.value = JSON.stringify(data);
}


// Fonction appellé quand le text du json est changé par l'utilisateur
function ChangeJSON(event){
    if(event.code == "Enter"){
        data = JSON.parse(jsonContainer.value);
        Update();
    }
}


// Fonction appellé pour charger un URL dans une autre page 
function loadURL(url){
    window.location.replace(url);
}

// Fonction pour supprimer une musique de la playliste
function Remove(event){
    // dans l'image croix, l'id associé est l'id de la postion de l'élement dans la hiérarchie du conteneur des musiques
    data["liste_lecture"].splice(event.target.id, 1);

    Update();
}
let importTxtArea;
let exportTxtArea;

let finishLoading = true;
let container;

let data;
let exportDataList = [];
let exportData = []; // initialise en tant que liste 

let evt;

let idCount = 0;
function init(){
    importTxtArea = document.getElementById("import");
    exportTxtArea = document.getElementById("export");
    
    container = document.getElementById("container");
}


function Import(){
    console.log("IMPORTING DATA...");
    data = JSON.parse(importTxtArea.value);

    UpdateFields(idCount);
    idCount += 1;
}


// Fonction pour ajouter un document minute
function UpdateFields(id){
    exportData = [];
    const fieldSet = document.createElement("fieldset");
    fieldSet.id = id;
    const legend = document.createElement("legend");
    legend.textContent = "Document minutes";

    finishLoading = false;
    // Plus besoin de supprimer les élements
    // while (container.children.length > 0) {
    //     container.removeChild(container.firstChild);
    // }
    for (let i = 0; i < data.length; i++) {
        const element = data[i];
        const label = document.createElement('label');

        label.htmlFor = i; // Provient de la reponse de : https://stackoverflow.com/questions/15750290/setting-the-html-label-for-attribute-in-javascript
        label.textContent = data[i]["nom"];
        
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
        
        
        // input.onclick = FieldClicked(event);
        fieldSet.appendChild(legend);
        fieldSet.appendChild(label);
        fieldSet.appendChild(input);
        fieldSet.appendChild(document.createElement("br")); // permet de passer une ligne entre chaque champ
        
        container.appendChild(fieldSet);
        let newExportData = {
            "nom": data[i]["nom"],
            "valeur":input.value
        } 
        
        exportData.push(newExportData);
        input.classList.add("input");

        input.addEventListener('click', function(event) {
            FieldClicked(event);
            event.stopPropagation(); // Permet d'empécher la propagation vers un parent (non nécéssaire dans notre cas)
        });
        

        input.addEventListener('keyup', function(event) {
            FieldClicked(event);
            event.stopPropagation(); // Permet d'empécher la propagation vers un parent (non nécéssaire dans notre cas)
        });
    }

    exportDataList.push(exportData);
    finishLoading = true;
}

function FieldClicked(event){
    //console.log(event);
    if (finishLoading){ // permet de ne pas pouvoir cliquer si les champs n'ont pas fini d'apparaître

    //    console.log(event.target.parentElement);
        if (data[event.target.id]["type"] != "multiple"){
            evt = event.target.value;

            exportDataList[event.target.parentElement.id][event.target.id]["valeur"] = evt;
        }else{
            
            // Si on selection 2 elements, la variable event retourné est le parent, sinon l'objet cliqué
            if (event.target.classList.contains("input")){ //https://stackoverflow.com/questions/5898656/check-if-an-element-contains-a-class-in-javascript
                evt = event.target;
            }else{
                
                evt = event.target.parentElement;
            }
            exportDataList[evt.parentElement.id][event.target.id]["valeur"] ="";

            console.log(evt);
            for (let i = 0; i < evt.selectedOptions.length; i++) {
                const element = evt.selectedOptions[i];

                exportDataList[evt.parentElement.id][event.target.id]["valeur"] += element.value + ",";                
            }
        }

    }
}

function Export(){
    console.log("EXPORTING DATA...");

    exportTxtArea.value = JSON.stringify(exportDataList);
}
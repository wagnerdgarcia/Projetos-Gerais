const options = {
    dragging: false,
    touchZoom: false,
    doubleClickZoom: false,
    scrollWheelZoom: false,
    zoomControl: false
}

const map = L.map('mapid', options).setView([-6.5099465,-36.35635259], 15); 

L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png').addTo(map);


const icon = L.icon({
    iconUrl: "./public/images/map-marker.svg",
    iconSize: [58,68],
    iconAnchor: [29,68],
    popupAnchor: [170,2]
})

L.marker([-6.5093601,-36.3615097],{icon}).addTo(map);

/* Galeria de Imagem */

function selectImage(event){
    const button = event.currentTarget;
    
    //Remove todas as Classes .Ative
    const buttons = document.querySelectorAll(".images button");
    buttons.forEach(removeActiveClass);

    function removeActiveClass(button) {
        button.classList.remove("active");
    }

    // Pegar a Imagem Clicada
    const image = button.children[0];
    const imageContainer = document.querySelector(".orphanage-details > img");

    //Atualizar o Container de Imagem

    imageContainer.src = image.src;

    //Atualiza o Botão Ativo

    button.classList.add("active");
}

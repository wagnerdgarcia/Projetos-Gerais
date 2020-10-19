const options = {
    dragging: false,
    touchZoom: false,
    doubleClickZoom: false,
    scrollWheelZoom: false,
    zoomControl: false
}

const lat = document.querySelector('span[data-lat]');
const lng  = document.querySelector('span[data-lng]');

const map = L.map('mapid', options).setView([lat.dataset.lat, lng.dataset.lng], 16); 

L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png').addTo(map);


const icon = L.icon({
    iconUrl: "/images/map-marker.svg",
    iconSize: [58,68],
    iconAnchor: [29,68],
    popupAnchor: [170,2]
})


L.marker([lat.dataset.lat, lng.dataset.lng],{icon}).addTo(map);

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

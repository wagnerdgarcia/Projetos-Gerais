// Importando as Bibliotecas
const express = require('express');
const path  = require('path');
const pages = require('./pages.js');

//Iniciando a Biblioteca
const server = express();
server
    // Utilizar o Body do Req
    .use(express.urlencoded({ extended: true }))
    // Criando Arquivos estáticos
    .use(express.static('public'))

    //Configurar Template Engine
    .set('views', path.join(__dirname, "views"))
    .set('view engine', 'hbs')

    //Criar Rotas 
    .get('/', pages.index)
    .get('/orphanage', pages.orphanage)
    .get('/orphanages', pages.orphanages)
    .get('/create-orphanage', pages.createOrphanage)
    .post('/save-orphanage', pages.saveOrphanage)


// Iniciando um Servidor

server.listen('5500');
import express, { request, response } from 'express'

const app = express();

/***************************
 * GET      =>  Buscar
 * POST     =>  Salvar
 * PUT      =>  Alterar
 * DELETE   =>  Deletar
 * PATCH    =>  Alteração Especifica
 */


/**********     GET     **********/

/**
 * 1 param => Rota (Recurso da API)
 * 2 param => (request, response)
 */

 // http://localhost:3333/

app.get("/", (request, response) => {
    return response.json({message:"NLW 4.0"});
});

/**********     POST     **********/

/**
 * 1 param => Rota (Recurso da API)
 * 2 param => (request, response)
 */

 app.post("/", (request, response) => {
     return response.json({ message: "Os dados foram salvos com sucesso!"});
 });

app.listen(3333, () => console.log("Server is Running!"));
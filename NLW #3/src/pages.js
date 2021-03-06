const orphanages = require("./database/fakedata.js");
const Database = require("./database/db");
const saveOrphanage = require("./database/saveOrphanage");


module.exports = {
    index(req, res) {
        return res.render('index')
    },

    async orphanage(req, res) {
        const id = req.query.id
        try {
            const db = await Database;
            const results = await db.all(`SELECT * FROM orphanages WHERE id = "${id}"`)
            const orphanage = results[0];

            

            orphanage.images = orphanage.images.split(",");
            orphanage.fristImages = orphanage.images[0];

            if(orphanage.open_on_weekends == '0') orphanage.open_on_weekends = false;
            else orphanage.open_on_weekends = true;
            
            return res.render('orphanage', {orphanage})
        } catch (error) {
            console.log(error);
            return res.send("Erro no Banco de Dados!");
        }
    },

    async orphanages(req, res) {
        try {
            const db = await Database;
            const orphanages = await db.all("SELECT * FROM orphanages")
            return res.render('orphanages',{orphanages})
        } catch (error) {
            console.log(error);
            return res.send("Erro no Banco de Dados!");
        }
        
    },
    
    createOrphanage(req, res) {
        return res.render('create-orphanage')
    },

    async saveOrphanage(req, res){
        const field = req.body;

        if(Object.values(field).includes('')){
            return res.send("Todos os Campos devem ser Preenchidos!")
        }
        try {
            const db = await Database
            await saveOrphanage(db, {
                lat: field.lat,
                lng: field.lng,
                name: field.name,
                about: field.about,
                whatsapp: field.whatsapp,
                images: field.images.toString(),
                instructions: field.instructions,
                opening_hours: field.opening_hours,
                open_on_weekends: field.open_on_weekends,
            })

            return res.redirect('/orphanages');
        } catch (error) {
            console.log(error)
            return res.send("Erro no Banco de Dados!")
        }
        
    }
}
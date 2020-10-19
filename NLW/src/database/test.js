const Database = require('./db')
const saveOrphanage = require('./saveOrphanage')

Database.then(async db => {
    //Inserir dados na Tabela

    await saveOrphanage(db, {
        lat: "-6.5093601",
        lng: "-36.3415097",
        name: "Lar dos Meninos",
        about: "Presta assistência a crianças de 05 a 15 anos que se encontre em situação de risco e/ou vulnerabilidade social.",
        whatsapp: "00 1 2345 - 6789",
        images:[
            "https://files.agoramt.com.br/2017/05/Crian%C3%A7as-brincando-de-bola.jpg",

            "https://diadeaprenderbrincando.org.br/wp-content/uploads/sites/6/2017/04/12238241_1168798136481088_5616285463412913012_o.jpg"

        ].toString(),
        instructions:"Venha como se sentir a vontade e traga muito amor e paciência para dar.",
        opening_hours: "Horário de visitas Das 18h até 8h",
        open_on_weekends: "0"
    })

    //Consultar dados na Tabela
    const selectOrphanages = await db.all("SELECT * FROM orphanages")
    console.log(selectOrphanages)

    //Consultar Um orfanato pelo ID
    //const orphanage = await db.all('SELECT * FROM orphanages WHERE id = "6"');
    //console.log(orphanage);

    //Deletar um dado Especifico
    //await db.run('DELETE FROM orphanages WRERE id = "4"')

})
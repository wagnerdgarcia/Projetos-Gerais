import 'reflect-metadata'
import './database'
import { request, response } from 'express'
import { router } from './routes';
import express from 'express';

const app = express();

app.use(express.json());
app.use(router);

app.listen(3333, () => console.log("Server is Running!"));
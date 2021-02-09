
const express = require("express");
const bodyParser = require("body-parser");
const codeRouter = express.Router();
const code = require("../controller/codeController");

codeRouter.use(bodyParser.urlencoded({
    extended: true
}));

codeRouter.use(bodyParser.json());

codeRouter.route("/").post(code.getOutput);

module.exports = codeRouter;
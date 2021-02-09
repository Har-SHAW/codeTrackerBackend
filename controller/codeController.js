const { exec, execFile } = require('child_process');
fs = require('fs');

const compiler = "g++";
const version = "-std=c++11";
const out = "-o";
const infile = "code-runner.cpp";
const outfile = "code-runner.out";
const inputFile = "input.txt";

exports.getOutput = (req, res) => {
    fs.writeFile(infile, req.body.code, function (err) {
        if (err) {
            res.status(500).send({
                message: "cannot write the file"
            })
        };
    });
    fs.writeFile(inputFile, req.body.input, function (err) {
        if (err) {
            res.status(500).send({
                message: "cannot write the file"
            })
        };
    });
    execFile(compiler, [version, infile, out, outfile], (err, stdout, stderr) => {
        if (err) {
            res.status(500).send({
                message: "cannot compile code",
                error: err
            })
        } else {
            let executable = `./${outfile} < input.txt`;
            exec(executable, (err, stdout, stderr) => {
                if (err) {
                    res.status(500).send({
                        message: "cannot run code",
                        error: err
                    })
                } else {
                    res.status(200).send({
                        message: "successfully executed",
                        output: stdout
                    })
                }
            })
        }
    })
}
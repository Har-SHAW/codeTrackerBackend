const { exec, execFile } = require('child_process');
fs = require('fs');

const compiler = "g++";
const version = "-std=c++11";
const out = "-o";
const infile = "code-runner.cpp";
const outfile = "code-runner.out";
const inputFile = "input.txt";

exports.getOutput = (req, res) => {
    let str = req.body.code;
    let it = -1;
    let line = 1;
    let i = 0;
    while(i < str.length){
        
        if(str[i] == "\n"){
            line++;
        }
        if(str[i] == ";" && str[i+1] == "\n"){
            
            if(it == 0){
                str = str.substring(0, i+1) + "cout<<"+"\"<"+line+">\""+";" + str.substring(i+1);
                it--;
            }else{
                it++;
            }
        }
        i++;
    }
    fs.writeFile(infile, str, function (err) {
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
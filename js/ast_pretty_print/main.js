const babylon = require('babylon');
const printAST = require('ast-pretty-print');

const ast = babylon.parse('1 + 2 * (3 + 4)');
console.log(printAST(ast, true));
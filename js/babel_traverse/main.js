const babylon = require('babylon');
const traverse = require('@babel/traverse').default;

const src = '1 + 2';

const ast = babylon.parse(src);

const visitor = {
    enter(nodePath) {
        console.log(`enter: ${nodePath.type}`);
    },
    exit(nodePath) {
        console.log(`exit: ${nodePath.type}`);
    },
    NumericLiteral: {
        enter(nodePath) {
            console.log(`enter: ${nodePath.type}`);
        },
        exit(nodePath) {
            console.log(`exit: ${nodePath.type}`);
        }
    },
    BinaryExpression: (nodePath) => {
        console.log(nodePath.node);
    }
};

traverse(ast, visitor);
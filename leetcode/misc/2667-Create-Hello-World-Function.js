/**
 * @return {Function}
 */
var createHelloWorld = function() {
    const gretting = "Hello World";
    return function(...args) { //Nested functions remeber variables from outer function even after it has return its value this is because function has access to variables in outer function lexical scope 
        return gretting;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
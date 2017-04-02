if ( typeof require === "function"){
   var fibonacci = require('./fib.js');
}
var main = function(){
    var num = 9;
    console.log("fib 9: " + fibonacci.fib(num)+" - should be 34");
};
main()

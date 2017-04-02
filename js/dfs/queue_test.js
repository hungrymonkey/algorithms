if ( typeof require === "function"){
   var Queue = require('./Queue.js').Queue;
}
var main = function(){
    q = new Queue();
    console.log(" :" + q.pop());
    q.push(3);
    q.push(2);
    q.push(5);
    console.log(" :" + q.pop());
    console.log(" :" + q.pop());
    console.log(" :" + q.pop());
    console.log(" :" + q.pop());
};
main()


if ( typeof require === "function"){
   var Queue = require('./Queue.js').Queue;
}

var DFS = function(graph){
   this.g = graph;
};
// returns a set
DFS.prototype.vertices = function(){
    var s = new Set();
    for( k in this.g ){
        s.add(k);
        this.g[k].forEach(function(e){
            s.add(e);
        });
    }
    return s;
};
DFS.prototype.find = function( start, end ){
    var verts = this.vertices();
    if( !verts.has(start) || !verts.has(end) ){
        return [];
    }
    var visited = new Map();
    verts.forEach((e)=> (visited.set(e, false)));
};
(function(exports){

  exports.DFS = DFS; 

}(typeof exports === 'undefined' ? this.DFS = {} : exports));


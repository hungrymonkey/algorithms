"use strict";
if ( typeof require === "function"){
   var Queue = require('./Queue.js').Queue;
}

var BFS = function(graph){
   this.g = graph;
};
// returns a set
BFS.prototype.vertices = function(){
    var s = new Set();
    for( var k in this.g ){
        s.add(k);
        this.g[k].forEach((e)=>( s.add(e)));
    }
    return s;
};
BFS.prototype.backtrack = function( parents, start, end ){
    var path = [end];
    while( path[path.length -1 ] !== start){
        path.push(parents.get(path[path.length -1 ]));
    }
    return path.reverse();
};
BFS.prototype.find = function( start, end ){
    var verts = this.vertices();
    if( !verts.has(start) || !verts.has(end) ){
        return [];
    }
    var parents = new Map();
    verts.forEach((e)=> (parents.set(e, false)));
    parents.set(start,start);
    var queue =  new Queue();
    queue.push(start);
    while( !queue.is_empty() ){
        var n = queue.pop();
        if( n === end ){
            return this.backtrack(parents, start, end);
        }
        var neighbors = this.g[n];
        if( neighbors !== undefined ){
                neighbors.forEach( 
                    function(e){ 
                        if(parents.get(e) === false){
                            queue.push(e);
                            parents.set(e,n); 
                        }
                    });
        }
    }
    return [];
};
(function(exports){

  exports.BFS = BFS; 

}(typeof exports === 'undefined' ? this.BFS_lib = {} : exports));



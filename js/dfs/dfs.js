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
        this.g[k].forEach((e)=>( s.add(e)));
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
    var stack = [start];
    var path = [];
    while( stack.length > 0 ){
        var n = stack.pop();
        path.push(n);
        if( n === end ){
            return path;
        }
        visited.set(n,true);
        if( !visited[n] ){
            visited.set(n,true);
            var neighbors = this.g[n];
            if( neighbors !== undefined ){
                neighbors.forEach( function(e){ if(!visited[e])
                                             {stack.push(e);}});
            }else{
                path.pop();
            }
        }else{
            path.pop();
        }
    }
    return [];
};
(function(exports){

  exports.DFS = DFS; 

}(typeof exports === 'undefined' ? this.DFS = {} : exports));


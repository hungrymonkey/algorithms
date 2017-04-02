var Queue = function(){
    this.queue  = [];
};
Queue.prototype.push = function(it){
    this.queue.push(it);
};
Queue.prototype.is_empty = function(){
    return this.queue.length === 0;
};
Queue.prototype.pop = function(){
    if(!this.is_empty()){
        return this.queue.shift();
    }else{
      return undefined;
    }
};
Queue.prototype.peek = function(){
    if(!this.is_empty()){
        return this.queue[0];
    }else{
        return undefined;
    }
};
Queue.prototype.length = function(){
    return this.queue.length;
};

(function(exports){

  exports.Queue = Queue; 

}(typeof exports === 'undefined' ? this.Queue = {} : exports));

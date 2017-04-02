


var fib_iter = function ( num ){
   if( num <= 1 ){
       return num;
   }
   var l = [0,1]; 
   for ( i = 2; i < num+1; i++){
      l.push(l[i-1]+l[i-2]);
   }
   return l[num];
};
(function(exports){

  exports.fib = function(num){ return fib_iter(num); };

}(typeof exports === 'undefined' ? this.fibonacci = {} : exports));

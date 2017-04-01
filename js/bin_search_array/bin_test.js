const bin_search = require('./bin.js');



var main = function(){
    var test_array = [];
    for ( i = 0; i < 20; i++){
        if( i === 10 ){
            continue;
        }
        test_array.push(i);
    }
    //console.log("Hello, world!" + parseInt(1/2));
    console.log("Cannot find 10: " + bin_search(test_array,10) );
    console.log("found  0: " + bin_search(test_array,0));
    console.log("found  9: " + bin_search(test_array,9));
};
main()

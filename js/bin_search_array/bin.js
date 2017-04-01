
var bin_search_rec = function ( arr, val, lo, hi ){
    var mid = parseInt((hi+lo)/2);
    var ele = arr[mid];
    if ( lo > hi ){
        return -1;
    }
    if ( ele === val ){
        return mid;
    }else if ( ele  > val ) {
        return bin_search( arr, val, lo, mid-1);
    }else if ( ele < val ){
        return bin_search( arr, val, mid+1, hi);
    }
};
var bin_search_iter = function( arr, val ){
    var lo = 0;
    var hi = arr.length - 1;
    while( lo <= hi ){
        var mid = parseInt((hi+lo)/2);
        if( arr[mid] > val ){
            hi = mid - 1;
        } else if (arr[mid] < val ){
            lo = mid + 1;
        }else{
            return mid
        }
    }
    return -1;
};

var bin_search = function (arr, val){
    return bin_search_iter(arr, val, 0, arr.length);
};

module.exports = bin_search;

"use strict";

function Node( val, idx ) {
   this.value = val;
   this.indexList = [idx];
   this.parent = null;
   this.left = null;
   this.right = null;
};
Node.prototype.getValue = function(){
  return this.value;
};
//Iterator next
Node.prototype.next = function(){
  if( this.right ){
    var n = this.right;
    while(n.left) {
      n = n.left;
    }
    return n;
  } else {
    var n = this.parent;
    while(n){
      if( this.value < n.value){
        break;
      }
      n = n.parent;
    }
    return n;
  }
};
//Reverse Iterator
Node.prototype.rnext = function(){
  if( this.left ){
    var n = this.left;
    while(n.right) {
      n = n.right;
    }
    return n;
  } else {
    var n = this.parent;
    while(n){
      if( this.value > n.value){
        break;
      }
      n = n.parent;
    }
    return n;
  }
};
Node.prototype.getIndexes = function(){
  return this.indexList.map((obj) => obj.clone)
}
function BinarySearchTree(){
  this.treeRoot = null;
  this.isize = 0;
};
BinarySearchTree.prototype.size = function(){
  return this.isize;
};

BinarySearchTree.prototype.rbegin = function() {
  var n = this.treeRoot;
  while( n ){
    if( n.right === null)
      return n;
    n = n.right;
  }
  return null;
};

BinarySearchTree.prototype.begin = function() {
  var n = this.treeRoot;
  while( n ){
    if( n.left === null)
      return n;
    n = n.left;
  }
  return null;
};

BinarySearchTree.prototype.insert = function(val, idx){
  if( !this.treeRoot){
    this.treeRoot = new Node(val, idx);
    this.isize += 1;
    return this.treeRoot;
  }
  var n = this.treeRoot;
  //insert value into the tree
  var leaf = new Node(val, idx);

  //finish binary search until empty position is found
  while( n ) {
    leaf.parent = n;
    if( n.value > val) {
      n = n.left;
    } else {
      if( n.value === val ){
        n.indexList.push(idx);
        return n;
      } else {
        n = n.right;
      }
    }
  }
  //Use the set leaf to set the parent node.
  if(leaf.parent.value > val){
    leaf.parent.left = leaf;
  } else {
    leaf.parent.right = leaf;
  }
  this.isize += 1;
  return leaf;
};



(function(exports){

  exports.BinarySearchTree = BinarySearchTree;

}(typeof exports === 'undefined' ? this.BinaryTreeLib = {} : exports));



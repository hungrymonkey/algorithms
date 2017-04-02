if ( typeof require === "function"){
   var DFS = require('./dfs.js').DFS;
}
// I am lazy on creating test for dfs because,
// I realize I do not want to create a test and
// debug it too. A nice advantage of getting graph
// online is that they have nice pretty pictures
//http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/Graph/dfs.html

var graph1_txt = '{ "0" : [ 1, 3, 8],' +
		'"1": [0, 7],' +
		'"2": [3, 5, 7],' +
		'"3": [0, 2, 4],' +
		'"4": [3, 8],' +
		'"5": [2, 6],' +
		'"6": [5],' +
		'"7": [1, 2],' +
		'"8": [0, 4]}'

//http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
var graph2_txt = '{ "0": [1,2],' +
		'"1": [2],' +
		'"2": [0,3],' +
		'"3": [3]}' +
		
var main = function(){
   
};
main()

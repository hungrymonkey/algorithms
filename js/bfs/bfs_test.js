if ( typeof require === "function"){
   var BFS_lib = require('./bfs.js');
}
// I am lazy on creating test for dfs because,
// I realize I do not want to create a test and
// debug it too. A nice advantage of getting graph
// online is that they have nice pretty pictures
//http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/Graph/dfs.html

var graph1_txt = '{ "0" : [ "1", "3", "8"],' +
    '"1": ["0", "7"],' +
    '"2": ["3", "5", "7"],' +
    '"3": ["0", "2", "4"],' +
    '"4": ["3", "8"],' +
    '"5": ["2", "6"],' +
    '"6": ["5"],' +
    '"7": ["1", "2"],' +
    '"8": ["0", "4"]}'

//http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
var graph2_txt = '{ "0": ["1","2"],' +
            '"1": ["2"],' +
            '"2": ["0","3"],' +
            '"3": ["3"]}'

//https://qph.ec.quoracdn.net/main-qimg-0a231e2af88a88c5244e7bb5201aec43
var graph3_txt = '{ "3": ["8","10"],'+
                '"5": ["11"],' +
                '"7": ["8", "11"],' +
                '"8": ["9"],' +
                '"11": ["2","9","10"]}'
		
var main = function(){
   var g1 = JSON.parse(graph1_txt); 
   var g2 = JSON.parse(graph2_txt); 
   var g3 = JSON.parse(graph3_txt); 
   var d3 = new BFS_lib.BFS(g3);
   var d2 = new BFS_lib.BFS(g2);
   var d1 = new BFS_lib.BFS(g1);
   console.log("Test start not in graph: " + ( [].toString() === d3.find('4','3').toString() ));
   console.log("Test end not in graph: " + ([].toString() === d3.find('5','6').toString() ));
   console.log("g3 5->9: " + d3.find('5','9').toString());
   console.log("g2 0->3: " + d2.find('0','3').toString());
   console.log("g2 1->3: " + d2.find('1','3').toString());
   console.log("g1 0->6: " + d1.find('0','6').toString());
};
main()

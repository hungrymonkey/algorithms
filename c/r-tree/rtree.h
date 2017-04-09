#ifndef R_TREE_H_
#define R_TREE_H_
#include <stdbool.h>

struct RTree_Leaf{

    int boundary[4];
};
struct Point{
    int x,y;
};
struct Box{
   /* box format is (x,y,width,height) 
    * where x,y is the lower left corner
    */
    int x,y,w,h;
};
struct RTree_Branch{
};

bool rt_check_bounds(struct Box b, struct Point p);
#endif

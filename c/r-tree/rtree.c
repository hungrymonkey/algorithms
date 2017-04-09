#include "rtree.h"


bool rt_check_bounds(struct Box b, struct Point p){
    return(  b.w   >= (unsigned) ( p.x - b.x ) &&
         b.h   >= (unsigned) ( p.y  - b.y ));
}


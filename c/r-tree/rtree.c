#include <stdio.h>
#include <stdlib.h>
#include "rtree.h"

bool rt_check_bounds_point(const struct Reactangle b, const struct Point p){
    return(  b.w   >= (unsigned) ( p.x - b.x ) &&
         b.h   >= (unsigned) ( p.y  - b.y ));
}
bool rt_check_bounds_rectangle(const struct Reactangle bigger, const struct Reactangle smaller){
    return false;
}
bool rt_check_bounds(const struct RTree_Data larger, const struct RTree_Data smaller){
    switch( smaller.ty ){
        case POINT: return rt_check_bounds_point( larger.d.r, smaller.d.p);
        case RECTANGLE:  return rt_check_bounds_rectangle( larger.d.r, smaller.d.r);
            
        default: return false;
    }
    return false;
}
struct RTree_Node *rt_new_node(){
    struct RTree_Node  *x;
    x = rt_new_node();
    x->depth = 0; /* leaf */
    return x;
}
void RTree_free(struct RTree_Node *n){
    if(n!=NULL){
        free(n);
    }else{
        fprintf(stderr, "RTree_Error: freeing a null pointer");
    }
}

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
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
    struct RTree_Node *n = (struct RTree_Node *) malloc (sizeof(struct RTree_Node));
    
}
struct RTree_Node *rt_new_root(){
    struct RTree_Node  *x;
    x = rt_new_node();
    x->depth = 0; /* leaf */
    return x;
}
void rt_copy_range(struct RTree_Node *dst, struct RTree_Node *src, int start, int end){
    struct RTree_Branch *b_src = &(src->b[start]);
    struct RTree_Branch *b_dst = src->b;
    /* potential off by one error 
     * if multiply end - start, it will leave out the last addr
     * unless, I pass start index and count
     */
    memcpy(b_dst, b_src, (end-start+1) * sizeof( struct RTree_Branch ));
}
void rt_free(struct RTree_Node *n){
    if(n!=NULL){
        free(n);
    }else{
        fprintf(stderr, "RTree_Error: freeing a null pointer");
    }
}
void rt_clear(struct RTree_Node *n){
    for( int i = 0; i < n -> count; i++){
       if( (n->b[i]).c != NULL){
           rt_clear((n->b[i]).c);
       }
    }
    rt_free( n );
}

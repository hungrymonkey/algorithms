#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "rtree.h"

bool rt_contains_point(const struct Reactangle b, const struct Point p){
    return(  b.w   >= (unsigned) ( p.x - b.x ) &&
         b.h   >= (unsigned) ( p.y  - b.y ));
}
bool rt_contains_rectangle(const struct Reactangle bigger, const struct Reactangle smaller){
    return false;
}
bool rt_contains_data(const struct RTree_Data larger, const struct RTree_Data smaller){
    switch( smaller.ty ){
        case POINT: return rt_contains_point( larger.d.r, smaller.d.p);
        case RECTANGLE:  return rt_contains_rectangle( larger.d.r, smaller.d.r);
            
        default: return false;
    }
    return false;
}
bool rt_equals_point(const struct Point l, const struct Point r){
    return (l.x == r.x) && (l.y == r.y);
}
bool rt_equals_rectangle(const struct Reactangle l, const struct Reactangle r){
    return (l.x == r.x) && (l.y == r.y) && (l.w == r.w) && (l.h == r.h);
}

bool rt_equals_data(const struct RTree_Data left, const struct RTree_Data right){
    if( right.ty != left.ty ) return false;
    switch( right.ty ){
        case POINT: return rt_equals_point( left.d.p, right.d.p);
        case RECTANGLE:  return rt_equals_rectangle( left.d.r, right.d.r);
            
        default: return false;
    }
    return false;
}
//https://gamedev.stackexchange.com/questions/586/what-is-the-fastest-way-to-work-out-2d-bounding-box-intersection?rq=1
bool rt_overlaps_rectange(const struct Reactangle a, const struct Reactangle b){
    return (abs(a.x - b.x) * 2 < (a.w + b.w)) &&
            (abs(a.y - b.y) * 2 < (a.h + b.h));
}
bool rt_overlaps_data(const struct RTree_Data left, const struct RTree_Data right){
    if( right.ty != left.ty ) return false;
    switch( right.ty ){
        case POINT: return false;
        case RECTANGLE:  return rt_overlaps_rectange( left.d.r, right.d.r);
            
        default: return false;
    }
    return false;
    
}
void rt_init_data( struct RTree_Data *d){
    d->ty = NONE;
    d->id = -1;
    memset(&(d->d), 0, sizeof(union RTree_Data_p));
}
void rt_init_branch( struct RTree_Branch *b){
    b-> c = NULL;
    rt_init_data(&(b->d));
    
}
void rt_init_node( struct RTree_Node *n ){
    n->depth = -1;
    n->count = 0;
    for( int i = 0; i < M; i++){
        rt_init_branch(&(n->b[i]));
    }
}

struct RTree_Node *rt_new_node(){
    struct RTree_Node *n = (struct RTree_Node *) malloc (sizeof(struct RTree_Node));
    rt_init_node(n);
    return n;
}
struct RTree_Node *rt_new_root(){
    struct RTree_Node  *x;
    x = rt_new_node();
    x->depth = 0; /* leaf */
    return x;
}
void rt_mcopy_r(struct RTree_Node *dst, struct RTree_Node *src, int start, int len){
    struct RTree_Branch *b_src = &(src->b[start]);
    struct RTree_Branch *b_dst = src->b;
    /* potential off by one error 
     * if multiply end - start, it will leave out the last addr
     * unless, I pass start index and count
     */
    memcpy(b_dst, b_src, (len) * sizeof( struct RTree_Branch ));
}
//TODO: mmove is wrong. fix later when i understand rtree insert algo
void rt_mmove_r(struct RTree_Node *dst, struct RTree_Node *src, int start, int len){
    struct RTree_Branch *b_src = &(src->b[start]);
    struct RTree_Branch *b_dst = src->b;
    /* potential off by one error 
     * if multiply end - start, it will leave out the last addr
     * unless, I pass start index and count
     */
    memmove(b_dst, b_src, (len) * sizeof( struct RTree_Branch ));
}
void rt_free(struct RTree_Node *n){
    assert(n);
    free(n);
}
void rt_clear(struct RTree_Node *n){
    for( int i = 0; i < n -> count; i++){
       if( (n->b[i]).c != NULL){
           rt_clear((n->b[i]).c);
       }
    }
    rt_free( n );
}
void rt_insert( struct RTree_Node *n, struct RTree_Data d){
    
}

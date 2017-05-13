#ifndef R_TREE_H_
#define R_TREE_H_
#include <stdbool.h>
/* result of getconf PAGE_SIZE*/
//#define PAGE_SIZE 4096
#define PAGE_SIZE 512

struct Point{
    int x,y;
};
struct Reactangle{
   /* reactangle format is (x,y,width,height) 
    * where x,y is the lower left corner
    */
    int x,y,w,h;
};
//always add none type because I been spoiled by fp languages
enum Data_Type { RECTANGLE, POINT, NONE }; 
union RTree_Data_p {
    struct Reactangle r;
    struct Point p;
};
struct RTree_Data {
    int id; //negative id for all non leaf nodes
    enum Data_Type ty;
    union RTree_Data_p d;
};
struct RTree_Node;
struct RTree_Leaf{
    int id;
    struct Point p;
};
struct RTree_Branch{
    struct RTree_Data d;
    struct RTree_Node *c; //chidren node pointer
};
#define M (int)((PAGE_SIZE-(2*sizeof(int))) / sizeof(struct RTree_Branch))
struct RTree_Node{
    int count;
    int depth;
    struct RTree_Branch b[M];
};
bool rt_contains_point(const struct Reactangle b, const struct Point p);
bool rt_contains_data(const struct RTree_Data bigger, const struct RTree_Data smaller);
bool rt_contains_rectangle(const struct Reactangle bigger, const struct Reactangle smaller);
bool rt_equals_rectangle(const struct Reactangle l, const struct Reactangle r);
bool rt_equals_point(const struct Point l, const struct Point r);
bool rt_equals_data(const struct RTree_Data l, const struct RTree_Data r);
bool rt_overlaps_data(const struct RTree_Data l, const struct RTree_Data r);

void rt_init_data( struct RTree_Data *d );
void rt_init_branch( struct RTree_Branch *b);
void rt_init_node( struct RTree_Node *n );
struct RTree_Node *rt_new_node();
struct RTree_Node *rt_new_root();
void rt_mcopy_r( struct RTree_Node *dst, struct RTree_Node *src, int start, int len);
void rt_mmove_r( struct RTree_Node *dst, struct RTree_Node *src, int start, int len);

void rt_free( struct RTree_Node *n);
void rt_clear( struct RTree_Node *n);
void rt_search( struct RTree_Node *n, struct Point p);
void rt_insert( struct RTree_Node *root, struct RTree_Data d);
#endif

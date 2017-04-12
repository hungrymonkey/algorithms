#ifndef R_TREE_H_
#define R_TREE_H_
#include <stdbool.h>
/* result of getconf PAGE_SIZE*/
#define PAGE_SIZE 4096

struct Point{
    int x,y;
};
struct Reactangle{
   /* reactangle format is (x,y,width,height) 
    * where x,y is the lower left corner
    */
    int x,y,w,h;
};
enum Data_Type { RECTANGLE, POINT };
union RTree_Data_p {
    struct Reactangle r;
    struct Point p;
};
struct RTree_Data {
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
    struct RTree_Node *c;
};
#define M (int)((PAGE_SIZE-(2*sizeof(int))) / sizeof(struct RTree_Branch))
struct RTree_Node{
    int count;
    int depth;
    struct RTree_Branch b[M];
};

bool rt_check_bounds(const struct RTree_Data bigger, const struct RTree_Data smaller);
bool rt_check_bounds_rectangle(const struct Reactangle bigger, const struct Reactangle smaller);
bool rt_check_bounds_point(const struct Reactangle b, const struct Point p);
struct RTree_Node *rt_new_node();
struct RTree_Node *rt_new_root();
void rt_copy_range( struct RTree_Node *dst, struct RTree_Node *src, int start, int end);
void rt_free( struct RTree_Node *n);
void rt_clear( struct RTree_Node *n);
#endif

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../rtree.h"

void print_incorrect( bool result, bool expected, struct Reactangle b, struct Point p){
    if( result != expected )
        printf( "Box %d %d %d %d does not contain point %d,%d\n", b.x, b.y, b.w, b.h, p.x, p.y);
}

int main(){
    struct Point p = { .x = 2, .y = 4};
    struct Reactangle b = { .x = 1, .y = 2, .w = 4, .h = 4};
    bool result = rt_check_bounds_point(b,p);
    //printf( "%d %d %d\n" , result, 1==1,1==0);
    print_incorrect( result, true, b, p);
}

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../rtree.h"

void print_incorrect( int expected, struct RTree_Data d1, struct RTree_Data d2){
    int result = rt_overlaps_data(d1,d2);
    if( result != expected )
        printf( "Result: %d Expected: %d\n",result, expected);
}


int main(){
    struct Reactangle b1 = { .x = 1, .y = 1, .w = 4, .h = 4};
    struct Reactangle b2 = { .x = 6, .y = 6, .w = 4, .h = 4};
    struct Reactangle b3 = { .x = 2, .y = 2, .w = 4, .h = 4};
    struct RTree_Data d1 = { .id = 1, .ty = RECTANGLE, .d = {b1} };
    struct RTree_Data d2 = { .id = 2, .ty = RECTANGLE, .d = {b2} };
    struct RTree_Data d3 = { .id = 3, .ty = RECTANGLE, .d = {b3} };
    print_incorrect( 16, d1, d1);
    print_incorrect( 0, d1, d2);
    print_incorrect( 9, d1, d3);
}

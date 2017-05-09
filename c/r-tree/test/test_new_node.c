#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../rtree.h"

bool check_branch( struct RTree_Branch *b ){
    if( b->c != NULL)
        return false;
    if( (b->d).ty != NONE)
        return false;
    return true;
}

bool check_node( struct RTree_Node *n ){
    if( n != NULL ){
        if ( n-> depth != -1 || n-> count != 0 )
            return false;
        bool b_flag = true;
        for( int i = 0; i<M; i++){
            b_flag &= check_branch(&(n->b[i]));
        }
        return b_flag;
    }else
        return false;
}

int main(){
    
    struct RTree_Node *n = rt_new_node();
    printf("%d\n",check_node(n));
    if( check_node(n) )
        printf("passed new node test\n");
    else
        printf("failed new node test\n");
    
}

//
//  JS_memory.c
//  MemoryCTRL
//
//  Created by Tony on 14-2-21.
//  Copyright (c) 2014年 Tony. All rights reserved.
//

#include "../header/JS_Memory_CTRL.h"
List JS_InitializeMemoryList(char * Init_address,int block_size){
    if(NULL==Init_address)
        return NULL;
    List Init_list=(List)Init_address;
    Init_list->block_size=block_size;
    Init_list->nextblock=NULL;
    return Init_list;
    

}
int JS_InsertMemoryList(const List list,const Position insert_position,const Position insert_block){
    if(NULL==list)
        return -1;
    Position node=list;
    
    while(insert_position!=node){
        node=node->nextblock;
    }
    Position temp=node->nextblock;
    node->nextblock=insert_block;
    insert_block->nextblock=temp;
    return 1;

}
int JS_DeleteMemoryList(List list,const Position delete_position){
    if(NULL==list)
        return -1;
    Position node=list;
    if(node==delete_position)
        list=list->nextblock;
    while(delete_position!=node->nextblock){
        node=node->nextblock;
        if(node==NULL)
            return 0;
    }
    node->nextblock=node->nextblock->nextblock;
    return 1;



}
int JS_BreakMemoryBlock(const List list,const Position Father_node,const int Child_size){
    if(NULL==list)
        return -1;
    Position node=list;
    
    while(node->nextblock!=Father_node){
        if(node==Father_node)
            break;
        node=node->nextblock;
        if(node==NULL)
            return 0;
    }
    node->block_size-=Child_size;
    return 1;
}
int JS_FoldMemoryBlock(const List list,Position new_block){
    if(NULL==list)
        return -1;
    Position node=list;
    if(node==new_block){
        if((node->nextblock+node->block_size)==(node->nextblock)){
            node->block_size+=node->nextblock->block_size;
            JS_DeleteMemoryList(list, new_block);
        }
    }
    while(node->nextblock!=new_block){
        node=node->nextblock;
        if(node==NULL)
            return 0;
    }
    if(((int)node+node->block_size)==(int)node->nextblock){
        node->block_size+=node->nextblock->block_size;
        JS_DeleteMemoryList(list, new_block);
        if((int)node+node->block_size==(int)node->nextblock){
            node->block_size+=node->nextblock->block_size;
            JS_DeleteMemoryList(list, new_block);
            return 1;
        }
    }
    node=node->nextblock;
    if(((int)node+node->block_size)==(int)node->nextblock){
        node->block_size+=node->nextblock->block_size;
        JS_DeleteMemoryList(list, new_block);
        return 1;
    }
    return 0;

}
//
//  JS_Memory_CTRL.h
//  MemoryCTRL
//
//  Created by Tony on 14-2-21.
//  Copyright (c) 2014年 Tony. All rights reserved.
//

#ifndef MemoryCTRL_JS_Memory_CTRL_h
#define MemoryCTRL_JS_Memory_CTRL_h
typedef struct JS_Memory_List * Position;
typedef struct JS_Memory_List * List;
struct JS_Memory_List{
    int block_size;
    Position nextblock;
};

List JS_InitializeMemoryList(char * Init_address,int block_size);
int JS_InsertMemoryList(const List list,const Position insert_position,const Position insert_block);
int JS_DeleteMemoryList(List list,const Position delete_position);
int JS_BreakMemoryBlock(const List list,const Position Father_node,const int Child_size);
int JS_FoldMemoryBlock(const List list,Position new_block);

#endif

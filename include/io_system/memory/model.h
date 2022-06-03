#pragma once
#include <stdint.h>

typedef struct synapse_iosys_memory_model
{
	size_t(*copy_from)(void*, void*, size_t);
	size_t(*copy_to)  (void*, void*, size_t);

	void* entity;
} synapse_iosys_memory_model;

typedef struct synapse_iosys_uncontinuous_memory_model_node
{
	size_t node_size;
	void*  node_ptr ;
} synapse_iosys_uncontinuous_memory_model_node;

typedef struct synapse_iosys_uncontinuous_memory_model
{
	synapse_iosys_memory_model mmodel;
	synapse_iosys_uncontinuous_memory_model_node*
		(*iterate)(void*);

	synapse_iosys_uncontinuous_memory_model_node*
		(*iterate_next)(void*, synapse_iosys_uncontinuous_memory_model_node*);

	void (*deallocate)		
		(void*, synapse_iosys_uncontinuous_memory_model_node*);
	void (*deallocate_back) 
		(void*, synapse_iosys_uncontinuous_memory_model_node*);
	void (*deallocate_front)
		(void*, synapse_iosys_uncontinuous_memory_model_node*);

	synapse_iosys_uncontinuous_memory_model_node* 
		(*allocate)		 (void*, size_t);
	synapse_iosys_uncontinuous_memory_model_node* 
		(*allocate_back) (void*);
	synapse_iosys_uncontinuous_memory_model_node*
		(*allocate_front)(void*);

	size_t(*total_size)    (void*);
} synapse_iosys_uncontinuous_memory_model;

typedef struct synapse_iosys_continuous_memory_model
{
	synapse_iosys_memory_model mmodel;
	void*				     (*address)(void*);
	size_t					 (*resize) (void*, size_t);
} synapse_iosys_continuous_memory_model;
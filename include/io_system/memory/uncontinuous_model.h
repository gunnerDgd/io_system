#pragma once
#include <io_system/memory/base_model.h>

typedef struct synapse_iosys_uncontinuous_memory_model_node
{
	size_t   node_size;
	uint8_t* node_ptr ;
} synapse_iosys_uncontinuous_memory_model_node;

typedef struct synapse_iosys_uncontinuous_memory_model
{
	synapse_iosys_memory_model mmodel;

	synapse_iosys_uncontinuous_memory_model_node*
		(*iterate_at)(void*, size_t);
	synapse_iosys_uncontinuous_memory_model_node*
		(*iterate)	 (void*);
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

	size_t
		(*total_size)    (void*);
} synapse_iosys_uncontinuous_memory_model;

#define synapse_iosys_uncontinuous_memory_model_itereate_at(pMmodel, pIteratePointer)\
	pMmodel.iterate_at(pMmodel.mmodel.entity, pIteratePointer)

#define synapse_iosys_uncontinuous_memory_model_iterate(pMmodel)\
	pMmodel.iterate(pMmodel.mmodel.entity)

#define synapse_iosys_uncontinuous_memory_model_iterate_next(pMmodel, pNode)\
	pMmodel.iterate_next(pMmodel.mmodel.entity, pNode)

#define synapse_iosys_uncontinuous_memory_model_allocate(pMmodel, pSize)\
	pMmodel.allocate(pMmodel.mmodel.entity, pSize)

#define synapse_iosys_uncontinuous_memory_model_allocate_back(pMmodel)\
	pMmodel.allocate_back(pMmodel.mmodel.entity)

#define synapse_iosys_uncontinuous_memory_model_allocate_front(pMmodel)\
	pMmodel.allocate_front(pMmodel.mmodel.entity)

#define synapse_iosys_uncontinuous_memory_model_deallocate(pMmodel, pNode)\
	pMmodel.allocate(pMmodel.mmodel.entity, pNode)

#define synapse_iosys_uncontinuous_memory_model_deallocate_back(pMmodel)\
	pMmodel.deallocate_back(pMmodel.mmodel.entity)

#define synapse_iosys_uncontinuous_memory_model_deallocate_front(pMmodel)\
	pMmodel.deallocate_front(pMmodel.mmodel.entity)

#define synapse_iosys_uncontinuous_memory_model_total_size(pMmodel)\
	pMmodel.total_size(pMmodel.mmodel.entity)
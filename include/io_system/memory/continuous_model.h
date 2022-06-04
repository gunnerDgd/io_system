#pragma once
#include <io_system/memory/base_model.h>

typedef struct synapse_iosys_continuous_memory_model
{
	synapse_iosys_memory_model mmodel;
	void*				     (*address)(void*);
	size_t					 (*resize) (void*, size_t);
} synapse_iosys_continuous_memory_model;
 
#define synapse_iosys_continuous_memory_model_copy_from(pMmodel, pReadPointer, pReadSize, pReadFilePointer)\
	pMmodel.mmodel.copy_from(pMmodel.mmodel.entity, pReadPointer, pReadSize, pReadFilePointer)

#define synapse_iosys_continuous_memory_model_copy_to(pMmodel, pWritePointer, pWriteSize, pWriteFilePointer)\
	pMmodel.mmodel.copy_to(pMmodel.mmodel.entity, pWritePointer, pWriteSize, pWriteFilePointer)

#define synapse_iosys_continuous_memory_model_address(pMmodel)\
	pMmodel.address(pMmodel.mmodel.entity)

#define synapse_iosys_continuous_memory_model_resize(pMmodel, pResized)\
	pMmodel.resize(pMmodel.mmodel.entity, pResized)
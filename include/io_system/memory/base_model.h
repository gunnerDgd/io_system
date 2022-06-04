#pragma once
#include <stdint.h>

typedef struct synapse_iosys_memory_model
{
	size_t(*copy_from)(void*, void*, size_t, size_t);
	size_t(*copy_to)  (void*, void*, size_t, size_t);

	void* entity;
} synapse_iosys_memory_model;

#define synapse_iosys_memory_model_copy_from(pMmodel, pReadPointer, pReadSize, pReadFilePointer)\
	pMmodel.copy_from(pMmodel.entity, pReadPointer, pReadSize, pReadFilePointer);

#define synapse_iosys_memory_model_copy_to(pMmodel, pWritePointer, pWriteSize, pWriteFilePointer)\
	pMmodel.copy_to  (pMmodel.entity, pWritePointer, pWriteSize, pWriteFilePointer);
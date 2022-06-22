#pragma once
#include <Windows.h>
#include <stdbool.h>

typedef struct __synapse_iosys_file_native
{
	HANDLE     hnd_file;
} __synapse_iosys_file_native;

typedef struct __synapse_iosys_file_native_vector
{
	size_t				  cnt_vector,
						  cnt_occupied_vector;

	FILE_SEGMENT_ELEMENT* ptr_vector;
} __synapse_iosys_file_native_vector;
#pragma once

#include "Types.h"

class ByteBuffer
{
private:
	uint8* m_Buffer;
	uint64 m_Capacity;
	uint64 m_Size;

public:
	explicit ByteBuffer(uint64 capacity = 32);
	ByteBuffer(const ByteBuffer& buffer);
	~ByteBuffer();

	void Add(void* source, uint64 size);
	void Resize(uint64 capacity);

	uint64 GetSize() const { return m_Size; }
	uint64 GetCapacity() const { return m_Capacity; }

	ByteBuffer& operator=(const ByteBuffer& buffer);
};


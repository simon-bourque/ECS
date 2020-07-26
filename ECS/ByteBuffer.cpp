#include "ByteBuffer.h"

#include <cstring>
#include <iostream>

ByteBuffer::ByteBuffer(uint64 capacity) : m_Capacity(capacity), m_Size(0)
{
	m_Buffer = new uint8[capacity];
}

ByteBuffer::ByteBuffer(const ByteBuffer& buffer) : m_Capacity(buffer.m_Capacity), m_Size(buffer.m_Size)
{
	m_Buffer = new uint8[m_Capacity];
	memcpy(m_Buffer, buffer.m_Buffer, m_Size);

	std::cout << "COPY CONSTRUCTOR" << std::endl;
}

ByteBuffer::~ByteBuffer()
{
	delete[] m_Buffer;
}

void ByteBuffer::Add(void* source, uint64 size)
{
	uint64 newSize = m_Size + size;
	if (newSize > m_Capacity)
	{
		Resize(2 * newSize);
	}

	memcpy((m_Buffer + m_Size), source, size);
	m_Size = newSize;
}

void ByteBuffer::Resize(uint64 capacity)
{
	m_Capacity = capacity;
	uint8* buffer = new uint8[capacity];

	if (m_Size > m_Capacity)
	{
		m_Size = m_Capacity;
	}

	memcpy(buffer, m_Buffer, m_Size);
	
	delete[] m_Buffer;
	m_Buffer = buffer;
}

ByteBuffer& ByteBuffer::operator=(const ByteBuffer& buffer)
{
	if (&buffer == this)
	{
		return *this;
	}

	delete[] m_Buffer;
	m_Capacity = buffer.m_Capacity;
	m_Size = buffer.m_Size;

	m_Buffer = new uint8[m_Capacity];
	memcpy(m_Buffer, buffer.m_Buffer, m_Size);

	std::cout << "ASSIGNMENT OPERATOR" << std::endl;

	return *this;
}
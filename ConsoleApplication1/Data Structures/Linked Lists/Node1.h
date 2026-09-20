#pragma once
class Node1
{
public:
	Node1* Next{ nullptr };
private:
	int m_Data;

public:
	Node1(int data) : m_Data(data) {};
	
	inline int Data() const { return m_Data; }
};


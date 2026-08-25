#pragma once
class Node2
{
public:
	Node2* Next{ nullptr };
	Node2* Prev{ nullptr };

private:
	int m_Data;

public:
	Node2(int data) : m_Data(data) {};

	inline int Data() const { return m_Data; }
};


#pragma once

template <typename TData>
class NodeTemplate
{
public:
	TData value;
	NodeTemplate* next;

	NodeTemplate(TData inVal)
	{
		value = inVal;
		next = nullptr;
	}
};


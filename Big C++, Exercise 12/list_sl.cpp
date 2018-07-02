#include "list_sl.h"

List_SL::List_SL()
{
	first = NULL;
	last = NULL;
	size = 0;
}

void List_SL::push_back(int data)
{
	Node_SL* new_node = new Node_SL(data);
	if (last == NULL) // List_SL is empty
	{
		first = new_node;
		last = new_node;
	}
	else
	{
		last->next = new_node;
		last = new_node;
	}
	size++;
}

void List_SL::push_front(int data)
{
	Node_SL* new_node = new Node_SL(data);
	if (last == NULL) // List_SL is empty
	{
		first = new_node;
		last = new_node;
	}
	else
	{
		new_node->next = first;
		first = new_node;
	}
	size++;
}

void List_SL::insert(Iterator_SL iter, int n)
{
	size++;
	if (iter.position == NULL)
	{
		push_back(n);
		return;
	}

	Node_SL* after = iter.position;
	Node_SL* before = iter.predecessor;
	Node_SL* new_node = new Node_SL(n);
	iter.predecessor = before;
	new_node->next = after;
	iter.next();
	iter.predecessor = new_node;
	if (before == NULL) // Insert at beginning
		first = new_node;
	else
		before->next = new_node;
}

Iterator_SL List_SL::erase(Iterator_SL iter)
{
	assert(iter.position != NULL);

	Node_SL* remove = iter.position;
	Node_SL* before = iter.predecessor;
	Node_SL* after = remove->next;
	if (remove == first)
		first = after;
	else
		before->next = after;
	if (remove == last)
		last = before;
	else
	{
		iter.next();
		iter.predecessor = before;
	}
	delete remove;
	Iterator_SL r;
	r.position = after;
	r.container = this;

	size--;
	return r;
}

Iterator_SL List_SL::begin()
{
	Iterator_SL iter;
	iter.position = first;
	iter.container = this;
	return iter;
}

Iterator_SL List_SL::end()
{
	Iterator_SL iter;
	iter.position = NULL;
	iter.container = this;
	return iter;
}

size_t List_SL::get_size()
{
	return size;
}

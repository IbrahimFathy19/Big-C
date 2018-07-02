#include "circular_list.h"

Circular_List::Circular_List()
{
	first = NULL;
	size = 0;
}

void Circular_List::push_back(int data)
{	
	Node* new_node = new Node(data);
	if (first == NULL)
	{
		first = new_node;
		first->next = first->previous = first;
	}
	else
	{
		Node* last = first->previous;

		new_node->next = first;
		new_node->previous = last;

		first->previous = new_node;
		last->next = new_node;
	}
	size++;
}

void Circular_List::push_front(int data)
{
	Node* new_node = new Node(data);
	if (first == NULL)
	{
		first = new_node;
		first->next = first->previous = first;
	}

	else
	{
		Node* last = first->previous;

		new_node->next = first;
		new_node->previous = last;

		first->previous = new_node;
		last->next = new_node;

		first = new_node;
	}
	size++;
}

void Circular_List::insert(Circ_Iterator iter, int n)
{
	size++;
	if (iter.position == NULL)
	{
		push_back(n);
		return;
	}

	Node* after = iter.position;
	Node* before = after->previous;
	Node* new_node = new Node(n);
	new_node->previous = before;
	new_node->next = after;
	after->previous = new_node;
	before->next = new_node;
	if (after == first) // Insert at beginning
		first = new_node;
	else
		before->next = new_node;
}

Circ_Iterator Circular_List::erase(Circ_Iterator iter)
{
	assert(iter.position != NULL);

	Node* last = first->previous;
	
	Node* remove = iter.position;
	Node* before = remove->previous;
	Node* after = remove->next;

	if (remove == first)
		first = after;
	if (last == first) // one node
		first = NULL;
	after->previous = before;
	before->next = after;

	delete remove;
	Circ_Iterator r;
	r.position = after;
	r.container = this;

	size--;
	return r;
}

Circ_Iterator Circular_List::begin()
{
	Circ_Iterator iter;
	iter.position = first;
	iter.container = this;
	return iter;
}

void Circular_List::reverse()
{
	Node* last = first;
	this->first = first->previous;
	this->first->previous = last;
}

size_t Circular_List::get_size()
{
	return size;
}

bool Circular_List::empty() const
{
	if (size == 0)
		return true;
	return false;
}

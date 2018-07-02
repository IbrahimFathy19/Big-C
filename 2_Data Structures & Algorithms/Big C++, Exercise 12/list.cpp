#include "list.h"

List::List()
{
	first = NULL;
	last = NULL;
	size = 0;
}

void List::push_back(int data)
{
	Node* new_node = new Node(data);
	if (last == NULL) // List is empty
	{
		first = new_node;
		last = new_node;
	}
	else
	{
		new_node->previous = last;
		last->next = new_node;
		last = new_node;
	}
	size++;
}

void List::push_front(int data)
{
	Node* new_node = new Node(data);
	if (last == NULL) // List is empty
	{
		first = new_node;
		last = new_node;
	}
	else
	{
		new_node->next = first;
		new_node->previous = NULL;
		first = new_node;
	}
	size++;
}

void List::insert(Iterator iter, int n)
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
	if (before == NULL) // Insert at beginning
		first = new_node;
	else
		before->next = new_node;
}

Iterator List::erase(Iterator iter)
{
	assert(iter.position != NULL);

	Node* remove = iter.position;
	Node* before = remove->previous;
	Node* after = remove->next;
	if (remove == first)
		first = after;
	else
		before->next = after;
	if (remove == last)
		last = before;
	else
		after->previous = before;
	delete remove;
	Iterator r;
	r.position = after;
	r.container = this;

	size--;
	return r;
}

Iterator List::begin()
{
	Iterator iter;
	iter.position = first;
	iter.container = this;
	return iter;
}

Iterator List::end()
{
	Iterator iter;
	iter.position = NULL;
	iter.container = this;
	return iter;
}

void List::reverse()
{
	Iterator iter = this->begin();
	while (iter.position != NULL)
	{
		//swap the next and previous of each node
		Node* temp_iter = iter.position->next;
		iter.position->next = iter.position->previous;
		iter.position->previous = temp_iter;
	
		iter.position = temp_iter;
	}

	//swap first and last of the list
	Node* temp = this->first;
	this->first = this->last;
	this->last = temp;
}

void List::swap(List & other)
{
	//we just swap both first and last of the two lists
	Node* temp = this->first;
	this->first = other.first;
	other.first = temp;

	temp = this->last;
	this->last = other.last;
	other.last = temp;
}

size_t List::get_size()
{
	/** OLD IMPLEMENTATION
	int s = 0;
	Iterator i;
	for (i = this->begin(); !i.equals(this->end()); i.next())
		s++;
	return s;
	*/

	return size;
}

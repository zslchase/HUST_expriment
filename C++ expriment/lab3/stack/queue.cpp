#include "def.h"

QUEUE::QUEUE(int m) :elems(new int[m]), max(m)
{
	if (elems == NULL) {
		throw("malloc failed");
	}
	tail = 0;
	head = 0;
}
QUEUE::QUEUE(const QUEUE& q) :elems(new int[q.max]),max(q.max)
{
	if (elems == NULL) {
		throw("malloc failed");
	}
	for (int i = 0; i < q.max; i++) {
		elems[i] = q.elems[i];
	}
	head = q.head;
	tail = q.tail;
}
QUEUE::QUEUE(QUEUE&& q)noexcept :elems(q.elems), max(q.max)
{

	head = q.head;
	tail = q.tail;
	*(int**)&q.elems = NULL;
	*(int*)&q.max = 0;
	q.head = 0;
	q.tail = 0;
}
QUEUE::operator int() const noexcept
{
	if (elems == NULL) return 0;
	else {
		return (tail - head + max) % max;
	}
}
int QUEUE::size() const noexcept
{
	return max;
}
QUEUE& QUEUE::operator<<(int e)
{
	if ((tail+1)%max==head) {
		throw("QUEUE is full!");
		return *this;
	}
	else {
		(*(int**)&elems)[tail] = e;
		tail = (tail + 1) % max;
		return *this;
	}
}
QUEUE& QUEUE::operator>>(int& e)
{
	if (head == tail)
	{
		throw("QUEUE is empty!");
		return *this;
	}
	e = elems[head];
	head = (head + 1) % max;
	return *this;
}
QUEUE& QUEUE::operator=(const QUEUE& q)
{
	if (this == &q)
	{
		return *this;
	}
	if (elems != NULL) {
		delete[] elems;
	}
	*(int**)&elems = new int[q.max];

	for (int i = 0; i < q.max; i++) {
		(*(int**)&elems)[i] = q.elems[i];
	}
	*(int*)&max = q.max;
	head = q.head;
	tail = q.tail;
	return *this;
}
QUEUE& QUEUE::operator=(QUEUE&& q)noexcept
{
	if (this == &q)
	{
		return *this;
	}
	if (elems != NULL) {
		delete[] elems;
	}
	*(int**)&elems = q.elems;
	*(int*)&max = q.max;
	head = q.head;
	tail = q.tail;
	*(int**)&q.elems = NULL;
	*(int*)&q.max = 0;
	q.head = q.tail = 0;
	return *this;
}
char* QUEUE::print(char* s)const noexcept
{
	int i = head;
	int x = 0;
	while (i != tail) {
		x = x + sprintf(s + x, ",%d", elems[i]);
		i = (i + 1) % max;
	}
	strcpy(s, s + 1);
	return s;
}
QUEUE::~QUEUE()
{
	if (elems != NULL)
	{
		delete[] elems;
		*(int**)&elems = NULL;
		*(int*)&max = 0;
		head = 0;
		tail = 0;
	}
}

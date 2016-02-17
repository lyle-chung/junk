#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ring.h"

int init_ring_buffer(ring_s * ring, int size)
{
	int i;

	ring->head = 0;
	ring->tail = 0;
	ring->count = 0;
	ring->ring_size = size;

	for (i = 0; i < ring->ring_size; i++) {
		//create ring item buffer
		ring->item[i] = (ring_item_s *) malloc(sizeof(ring_item_s));
		//set init value
		ring->item[i]->size = 0;
		ring->item[i]->buffer = (char *)malloc(512);	//item buffer length
	}
	printf("initialized ring buffer <%d>\n", size);

	return ring->ring_size;
}

int is_empty(ring_s * ring)
{
	if (ring->count == 0)
		return (1);
	else
		return (0);
}

int push_item(ring_s * ring, ring_item_s * item)
{
	if (ring->count >= ring->ring_size) {
		printf("The queue is full\n");
		printf("You cannot add items\n");
		return (-1);
	} else {
		ring->count++;
		ring->item[ring->head]->size = item->size;
		strcpy((char *)ring->item[ring->head]->buffer, item->buffer);
    //set next
		ring->head = (ring->head + 1) % ring->ring_size;
	}

	return ring->count;
}

int pop_item(ring_s * ring, ring_item_s * item)
{
	if (is_empty(ring)) {
		printf("isempty\n");
		return (-1);
	} else {
		item->size = ring->item[ring->tail]->size;
		strcpy(item->buffer, (char *)ring->item[ring->tail]->buffer);
		ring->tail = (ring->tail + 1) % ring->ring_size;
		ring->count--;
		return (0);
	}

	return ring->count;
}

int print_ring(ring_s * ring)
{
	int tail, count;

	tail = ring->tail;
	count = ring->count;
	while (count > 0) {
		printf("Element #%d = <%s>\n", tail, (char *)ring->item[tail]->buffer);
		tail = (tail + 1) % ring->ring_size;
		count--;
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "ring.h"
#include "ring_ext.h"

int main(void)
{
	int i = 0;
	int sw;
	int ret;
	char buffer[512];
	ring_s *ring;
	struct timeval tv;
	ring_item_s item;

	//init ring buffer
	ring = (ring_s *) malloc(sizeof(ring_s));
	init_ring_buffer(ring, 10);

	//init item buffer
	item.buffer = buffer;

	//set random seed
	gettimeofday(&tv, NULL);
	srand((unsigned int)tv.tv_usec);

	while (i < 100) {
		sw = rand();
		sw = (sw == 0) ? 1 : sw;

		if (sw % 2 == 0) {
			//make message
			sprintf(buffer, "item %d", i);
			//push
			item.size = strlen(buffer);
			strcpy(item.buffer, buffer);
			ret = push_item(ring, &item);
			if (ret < 0)
				continue;
			printf("%d=push item = %s\n", i, buffer);
		} else {
			//pop
			ret = pop_item(ring, &item);
			if (ret < 0)
				continue;
			printf("%d=pop item(%d) = <%s>\n", i, item.size, item.buffer);
		}

		i++;
	}

	//print
	print_ring(ring);

	exit(0);
}

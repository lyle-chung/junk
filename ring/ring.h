#ifndef __ring_h__
#define __ring_h__

#define MAX_RING_SIZE       (1024)

struct ring_item_s {
  int size;
  char *buffer;
  //
  //..
};

struct ring_s {
  int head;         //push
  int tail;         //pop
  int count;        //allocated item count
  //items
  int ring_size;    //real ring size
  ring_item_s *item[MAX_RING_SIZE];
};


















#endif

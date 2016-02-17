#ifndef __ring_ext_h__
#define __ring_ext_h__


extern int init_ring_buffer(ring_s *ring, int size);
extern int is_empty(ring_s *ring);
extern int pop_item(ring_s *ring, ring_item_s *item);
extern int print_ring(ring_s *ring);
extern int push_item(ring_s *ring, ring_item_s *item);










#endif

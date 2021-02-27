#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "Segment_Pcfg.h"
#include "StdTypes.h"

typedef enum {first,second,both}Flash_type;
	
	
// void Seg_1Display(u8 num);
void Seg_2Display(u8 num,u8 point_mode);
void Seg_Toggle(Flash_type seg);




#endif /* SEGMENT_H_ */
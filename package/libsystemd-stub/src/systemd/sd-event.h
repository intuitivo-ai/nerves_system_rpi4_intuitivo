#ifndef SD_EVENT_H_STUB
#define SD_EVENT_H_STUB

#include <stdint.h>

typedef struct sd_event sd_event;

int sd_event_new(sd_event **e);
int sd_event_run(sd_event *e, uint64_t usec);
int sd_event_get_fd(sd_event *e);

#endif

#ifndef SD_BUS_H_STUB
#define SD_BUS_H_STUB

#include <stdint.h>
#include <sys/types.h>

typedef struct sd_bus sd_bus;
typedef struct sd_bus_message sd_bus_message;
typedef struct sd_bus_slot sd_bus_slot;

typedef struct sd_bus_error {
    const char *name;
    const char *message;
    int _need_free;
} sd_bus_error;

#define SD_BUS_ERROR_NULL ((sd_bus_error) {NULL, NULL, 0})

typedef int (*sd_bus_message_handler_t)(
    sd_bus_message *m, void *userdata, sd_bus_error *ret_error
);

static inline void sd_bus_error_free(sd_bus_error *e) {
    if (e) { e->name = NULL; e->message = NULL; e->_need_free = 0; }
}

int sd_bus_default_system(sd_bus **ret);
sd_bus *sd_bus_unref(sd_bus *bus);
void sd_bus_unrefp(sd_bus **busp);

sd_bus_message *sd_bus_message_unref(sd_bus_message *m);
void sd_bus_message_unrefp(sd_bus_message **mp);

sd_bus *sd_bus_message_get_bus(sd_bus_message *m);
const char *sd_bus_message_get_path(sd_bus_message *m);
int sd_bus_message_read_basic(sd_bus_message *m, char type, void *p);

int sd_bus_call_method(
    sd_bus *bus,
    const char *destination, const char *path, const char *interface,
    const char *member, sd_bus_error *ret_error,
    sd_bus_message **reply, const char *types, ...
);

int sd_bus_get_property_trivial(
    sd_bus *bus,
    const char *destination, const char *path, const char *interface,
    const char *member, sd_bus_error *ret_error,
    char type, void *ret_ptr
);

int sd_bus_get_property_string(
    sd_bus *bus,
    const char *destination, const char *path, const char *interface,
    const char *member, sd_bus_error *ret_error,
    char **ret
);

int sd_bus_match_signal(
    sd_bus *bus, sd_bus_slot **ret,
    const char *sender, const char *path, const char *interface,
    const char *member, sd_bus_message_handler_t callback,
    void *userdata
);

sd_bus_slot *sd_bus_slot_unref(sd_bus_slot *slot);

int sd_bus_error_set_errno(sd_bus_error *e, int error);

struct sd_event;
int sd_bus_attach_event(sd_bus *bus, struct sd_event *event, int priority);

#endif

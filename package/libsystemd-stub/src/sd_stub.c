/*
 * libsystemd-stub: Minimal stub library providing libsystemd symbols
 * for linking greengrass-lite on systems without systemd (e.g. Nerves/erlinit).
 *
 * All functions return error codes or no-ops. The greengrass-lite code
 * already handles failures from these calls gracefully.
 */

#include <errno.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include "systemd/sd-bus.h"
#include "systemd/sd-daemon.h"
#include "systemd/sd-event.h"
#include "systemd/sd-login.h"

/* sd-daemon */

int sd_notify(int unset_environment, const char *state) {
    (void)unset_environment;
    (void)state;
    return 0; /* same as real sd_notify when NOTIFY_SOCKET is unset */
}

/* sd-login */

int sd_pid_get_unit(pid_t pid, char **unit) {
    (void)pid;
    (void)unit;
    return -ENOSYS;
}

/* sd-bus */

int sd_bus_default_system(sd_bus **ret) {
    (void)ret;
    return -ENOSYS;
}

sd_bus *sd_bus_unref(sd_bus *bus) {
    (void)bus;
    return NULL;
}

void sd_bus_unrefp(sd_bus **busp) {
    (void)busp;
}

sd_bus_message *sd_bus_message_unref(sd_bus_message *m) {
    (void)m;
    return NULL;
}

void sd_bus_message_unrefp(sd_bus_message **mp) {
    (void)mp;
}

sd_bus *sd_bus_message_get_bus(sd_bus_message *m) {
    (void)m;
    return NULL;
}

const char *sd_bus_message_get_path(sd_bus_message *m) {
    (void)m;
    return NULL;
}

int sd_bus_message_read_basic(sd_bus_message *m, char type, void *p) {
    (void)m;
    (void)type;
    (void)p;
    return -ENOSYS;
}

int sd_bus_call_method(
    sd_bus *bus,
    const char *destination, const char *path, const char *interface,
    const char *member, sd_bus_error *ret_error,
    sd_bus_message **reply, const char *types, ...
) {
    (void)bus; (void)destination; (void)path; (void)interface;
    (void)member; (void)ret_error; (void)reply; (void)types;
    return -ENOSYS;
}

int sd_bus_get_property_trivial(
    sd_bus *bus,
    const char *destination, const char *path, const char *interface,
    const char *member, sd_bus_error *ret_error,
    char type, void *ret_ptr
) {
    (void)bus; (void)destination; (void)path; (void)interface;
    (void)member; (void)ret_error; (void)type; (void)ret_ptr;
    return -ENOSYS;
}

int sd_bus_get_property_string(
    sd_bus *bus,
    const char *destination, const char *path, const char *interface,
    const char *member, sd_bus_error *ret_error,
    char **ret
) {
    (void)bus; (void)destination; (void)path; (void)interface;
    (void)member; (void)ret_error; (void)ret;
    return -ENOSYS;
}

int sd_bus_match_signal(
    sd_bus *bus, sd_bus_slot **ret,
    const char *sender, const char *path, const char *interface,
    const char *member, sd_bus_message_handler_t callback,
    void *userdata
) {
    (void)bus; (void)ret; (void)sender; (void)path; (void)interface;
    (void)member; (void)callback; (void)userdata;
    return -ENOSYS;
}

sd_bus_slot *sd_bus_slot_unref(sd_bus_slot *slot) {
    (void)slot;
    return NULL;
}

int sd_bus_error_set_errno(sd_bus_error *e, int error) {
    (void)e;
    return -error;
}

int sd_bus_attach_event(sd_bus *bus, sd_event *event, int priority) {
    (void)bus; (void)event; (void)priority;
    return -ENOSYS;
}

/* sd-event */

int sd_event_new(sd_event **e) {
    (void)e;
    return -ENOSYS;
}

int sd_event_run(sd_event *e, uint64_t usec) {
    (void)e; (void)usec;
    return -ENOSYS;
}

int sd_event_get_fd(sd_event *e) {
    (void)e;
    return -1;
}

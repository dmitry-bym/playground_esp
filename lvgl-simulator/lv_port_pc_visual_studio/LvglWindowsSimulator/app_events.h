#ifndef APP_EVENTS_H
#define APP_EVENTS_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    EVENT_SRC_UNKNOWN,
    EVENT_SRC_STATE,
    EVENT_SRC_PC,
    EVENT_SRC_UI,
    EVENT_SRC_CONTROL
} app_event_source_t;

typedef void (*app_volume_callback_t)(int32_t value, app_event_source_t source);
typedef void (*app_brightness_callback_t)(int32_t value, app_event_source_t source);

// Public API
void app_subscribe_volume(app_volume_callback_t cb);
void app_publish_volume(int32_t value, app_event_source_t src);

void app_subscribe_brightness(app_brightness_callback_t cb);
void app_publish_brightness(int32_t value, app_event_source_t src);

#endif

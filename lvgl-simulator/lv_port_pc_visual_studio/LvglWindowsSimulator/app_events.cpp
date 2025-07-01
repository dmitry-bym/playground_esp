#ifdef __cplusplus
extern "C" {
#endif

#include "app_events.h"

#define MAX_SUBSCRIBERS_PER_EVENT 8

    typedef enum {
        EVENT_VOLUME_CHANGED,
        EVENT_FAN_SPEED_CHANGED,
        EVENT_BRIGHTNESS_CHANGED,
        EVENT_COUNT
    } app_event_t;

    typedef void (*app_event_callback_t)(app_event_t event, void* value, app_event_source_t source);

    static void* subscribers[EVENT_COUNT][MAX_SUBSCRIBERS_PER_EVENT] = { 0 };

    static void sendCallback(void* clb, app_event_t event, void* value, app_event_source_t source) {
        if (event == EVENT_VOLUME_CHANGED) {
            app_volume_callback_t callback = (app_volume_callback_t)clb;
            int32_t volume = *(int32_t*)value;
            callback(volume, source);
        }

        if (event == EVENT_BRIGHTNESS_CHANGED) {
            app_brightness_callback_t callback = (app_brightness_callback_t)clb;
            int32_t volume = *(int32_t*)value;
            callback(volume, source);
        }
    }

    /********** PRIVATE API **********/
    static void app_subscribe(app_event_t event, void * cb)
    {
        if (event >= EVENT_COUNT) return;
        for (int i = 0; i < MAX_SUBSCRIBERS_PER_EVENT; i++) {
            if (subscribers[event][i] == NULL) {
                subscribers[event][i] = cb;
                return;
            }
        }
    }

    static void app_publish(app_event_t event, void* value, app_event_source_t source)
    {
        if (event < 0 || event >= EVENT_COUNT) return;
        for (int i = 0; i < MAX_SUBSCRIBERS_PER_EVENT; i++) {
            if (subscribers[event][i]) {
                sendCallback(subscribers[event][i], event, value, source);
            }
        }
    }

    /********** TYPE SAFE PUBLIC API **********/

    // Volume
    void app_subscribe_volume(app_volume_callback_t cb)
    {
        app_subscribe(EVENT_VOLUME_CHANGED, cb);
    }

    void app_publish_volume(int32_t value, app_event_source_t src)
    {
        app_publish(EVENT_VOLUME_CHANGED, &value, src);
    }

    // Brightness
    void app_subscribe_brightness(app_brightness_callback_t cb)
    {
        app_subscribe(EVENT_BRIGHTNESS_CHANGED, cb);
    }

    void app_publish_brightness(int32_t value, app_event_source_t src)
    {
        app_publish(EVENT_BRIGHTNESS_CHANGED, &value, src);
    }

#ifdef __cplusplus
}
#endif

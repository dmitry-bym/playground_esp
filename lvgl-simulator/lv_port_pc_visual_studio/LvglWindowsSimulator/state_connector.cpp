#ifdef __cplusplus
extern "C" {
#endif

#include "app_events.h"
#include "app_state.h"
#include "state_connector.h"
#include "log.h"

#define MY_EVENT_SRC EVENT_SRC_STATE

void state_on_volume_changed(int32_t value, app_event_source_t source) {
    if (source == MY_EVENT_SRC) {
        return;
    }

    g_app_state.volume = value;
    APP_LOG_INFO("Volume = %d", value);
}

void state_on_brightness_changed(int32_t value, app_event_source_t source) {
    if (source == MY_EVENT_SRC) {
        return;
    }

    g_app_state.brightness = value;
}

void state_connector_init(void) {
    app_subscribe_volume(state_on_volume_changed);
    app_subscribe_brightness(state_on_brightness_changed);
}

#ifdef __cplusplus
}
#endif

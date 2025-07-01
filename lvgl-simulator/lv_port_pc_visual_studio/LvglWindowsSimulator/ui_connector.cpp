#ifdef __cplusplus
extern "C" {
#endif

#include "app_events.h"
#include "ui/ui.h"

#define MY_EVENT_SRC EVENT_SRC_UI

void ui_on_volume_changed(int32_t value, app_event_source_t source) {
    if (source == MY_EVENT_SRC) {
        return;
    }

    lv_slider_set_value(ui_Fan_Speed_Control, value, LV_ANIM_OFF);
}

void ui_on_brightness_changed(int32_t value, app_event_source_t source) {
    if (source == MY_EVENT_SRC) {
        return;
    }

    //not implemented
}

void ui_connector_init(void) {
    app_subscribe_volume(ui_on_volume_changed);
    app_subscribe_brightness(ui_on_brightness_changed);
}

#ifdef __cplusplus
}
#endif

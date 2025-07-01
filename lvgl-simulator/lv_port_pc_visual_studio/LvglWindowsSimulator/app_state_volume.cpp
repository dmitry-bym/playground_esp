#include "app_state.h"
#include "app_events.h"
#include "app.h"
#include "ui/ui.h"
#include "log.h"

#define MAX_VOLUME 100
#define MIN_VOLUME 0

void app_volume_set(int32_t value, app_event_source_t source)
{
    value = LV_CLAMP(MIN_VOLUME, value, MAX_VOLUME);
    if (value == g_app_state.volume) {
        return;
    }

    g_app_state.volume = value;
    app_publish_volume(value, source);
}

void app_volume_change(int32_t diff, app_event_source_t source)
{
    int32_t value = g_app_state.volume + diff;
    app_volume_set(value, source);
}

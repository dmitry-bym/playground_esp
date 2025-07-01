#ifdef __cplusplus
extern "C" {
#endif

#include "app_events.h"
#include "app_state.h"
#include "app_events_helpers.h"

void app_publish_volume_change(int32_t diff, app_event_source_t source) {
    int32_t value = g_app_state.volume + diff;
    app_publish_volume(value, source);
}

#ifdef __cplusplus
}
#endif


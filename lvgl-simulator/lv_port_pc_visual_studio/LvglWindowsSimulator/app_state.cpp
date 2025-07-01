#ifdef __cplusplus
extern "C" {
#endif

#include "app_state.h"
#include "app_events.h"

#define MY_EVENT_SOURCE EVENT_SRC_STATE

app_state_t g_app_state = {
    .volume = 10,
    .brightness = 10
};

void initAppState(const app_state_t* app_state)
{ 
    if (!app_state) {
        return;
    }

    g_app_state = *app_state;

    app_publish_volume(g_app_state.volume, MY_EVENT_SOURCE);
    app_publish_brightness(g_app_state.brightness, MY_EVENT_SOURCE);
}

#ifdef __cplusplus
}
#endif

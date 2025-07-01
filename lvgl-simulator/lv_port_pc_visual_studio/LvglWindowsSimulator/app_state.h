// app_state.h

#ifndef APP_STATE_H
#define APP_STATE_H

#include <cstdint>

typedef struct {
    int32_t volume;
    int32_t brightness;
} app_state_t;

extern app_state_t g_app_state;

void initAppState(const app_state_t* app_state);

void app_volume_set(int32_t value);

void app_volume_change(int32_t diff);

#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <Windows.h>

#include <LvglWindowsIconResource.h>

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "ui/ui.h"
#include "app_events_helpers.h"
#include "connectors.h"

void my_key_event_cb(lv_event_t* e)
{
    uint32_t key = lv_event_get_key(e);

    switch (key)
    {
    case 'u':
        app_publish_volume_change(1, EVENT_SRC_CONTROL);
        break;
    case 'd':
        app_publish_volume_change(-1, EVENT_SRC_CONTROL);
        break;
    }
}

void ui_disable_focus(void)
{
    lv_group_t* g = lv_group_get_default();
    if (g) {
        lv_group_remove_all_objs(g);
    }

    // отключим фокус для конкретных объектов
    lv_obj_clear_flag(ui_Fan_Speed_Control, LV_OBJ_FLAG_CLICK_FOCUSABLE);
}


void sub_to_key_events() {
    ui_disable_focus();

    lv_obj_t* dummy = lv_btn_create(lv_scr_act());
    lv_obj_set_size(dummy, 1, 1);
    lv_obj_add_event_cb(dummy, my_key_event_cb, LV_EVENT_KEY, NULL);
    lv_group_focus_obj(dummy);
}

int main()
{
    lv_init();

    /*
     * Optional workaround for users who wants UTF-8 console output.
     * If you don't want that behavior can comment them out.
     *
     * Suggested by jinsc123654.
     */
#if LV_TXT_ENC == LV_TXT_ENC_UTF8
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    int32_t zoom_level = 100;
    bool allow_dpi_override = false;
    bool simulator_mode = true;
    lv_display_t* display = lv_windows_create_display(
        L"LVGL Windows Simulator Display 1",
        480,
        800,
        zoom_level,
        allow_dpi_override,
        simulator_mode);
    if (!display)
    {
        return -1;
    }

    HWND window_handle = lv_windows_get_display_window_handle(display);
    if (!window_handle)
    {
        return -1;
    }

    HICON icon_handle = LoadIconW(
        GetModuleHandleW(NULL),
        MAKEINTRESOURCE(IDI_LVGL_WINDOWS));
    if (icon_handle)
    {
        SendMessageW(
            window_handle,
            WM_SETICON,
            TRUE,
            (LPARAM)icon_handle);
        SendMessageW(
            window_handle,
            WM_SETICON,
            FALSE,
            (LPARAM)icon_handle);
    }

    lv_indev_t* pointer_indev = lv_windows_acquire_pointer_indev(display);
    if (!pointer_indev)
    {
        return -1;
    }

    lv_indev_t* keypad_indev = lv_windows_acquire_keypad_indev(display);
    if (!keypad_indev)
    {
        return -1;
    }


    lv_indev_t* encoder_indev = lv_windows_acquire_encoder_indev(display);
    if (!encoder_indev)
    {
        return -1;
    }

    connectors_init();
    ui_init();

    sub_to_key_events();

    //lv_demo_widgets();
    //lv_demo_benchmark();

    while (1)
    {
        uint32_t time_till_next = lv_timer_handler();
        lv_delay_ms(time_till_next);
    }

    return 0;
}

#ifdef __cplusplus
}
#endif

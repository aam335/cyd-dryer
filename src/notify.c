#include "dryer.h"
#include <ui/ui.h>

int failure;

void set_failure(int fail_id)
{
    failure = fail_id;
    if (fail_id!=FAIL_NONE){
        apply_emergency_stop();
    }
}

void show_notify_on_failure()
{
    const char *notify = "unknown failure";
    switch (failure)
    {
    case FAIL_NONE:
        lv_obj_add_flag(ui_errormodal, LV_OBJ_FLAG_HIDDEN);
        return;
    case FAIL_DOOR_OPENED:
        notify = "unable to reach target\ntemperature [door opened]";
        break;
    case FAIL_SENSOR:
        notify = "sensor error";
        break;
    case FAIL_PREHEAT:
        notify = "unable to reach target\ntemperature [preheating]";
        break;
    }
    lv_obj_clear_flag(ui_errormodal, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text_fmt(ui_errortext, "%s", notify);
}

void reset_failure()
{
    set_failure(FAIL_NONE);
}
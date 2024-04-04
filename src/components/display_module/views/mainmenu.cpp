#include "mainmenu.h"
#include <core/globals.h>

void MainMenu::HandleAnimations(unsigned long Millis, unsigned long LastTick)
{
    
}

void MainMenu::Render()
{
    status_bar = create_status_bar(lv_scr_act());
}

void MainMenu::UpdateWifiChannelStatus(int Channel)
{
    lv_label_set_text(WifiChannelLabel, String("CH: " + Channel).c_str());
}

void MainMenu::HandleTouch(TS_Point P)
{

}

lv_obj_t * MainMenu::add_battery_module(lv_obj_t * status_bar) {
    lv_obj_t * battery_icon = lv_label_create(status_bar);
    lv_label_set_text(battery_icon, LV_SYMBOL_BATTERY_FULL);
    lv_obj_set_style_transform_angle(battery_icon, 900, 0);
    lv_obj_set_style_transform_pivot_x(battery_icon, lv_obj_get_width(battery_icon) / 2, 0);
    lv_obj_set_style_transform_pivot_y(battery_icon, lv_obj_get_height(battery_icon) / 2, 0);   
    lv_obj_set_pos(battery_icon, 8, 200);
    lv_obj_set_style_text_color(battery_icon, lv_color_hex(0x89C289), LV_STATE_DEFAULT);
    flashIcon = lv_label_create(status_bar);
    lv_label_set_text(flashIcon, LV_SYMBOL_CHARGE);
    lv_obj_set_style_transform_angle(flashIcon, 900, 0);
    lv_obj_set_style_transform_pivot_x(flashIcon, lv_obj_get_width(flashIcon) / 2, 0);
    lv_obj_set_style_transform_pivot_y(flashIcon, lv_obj_get_height(flashIcon) / 2, 0);   
    lv_obj_set_pos(flashIcon, 8, 185);
    lv_obj_set_style_text_color(flashIcon, lv_color_hex(0x89C289), LV_STATE_DEFAULT);
    return battery_icon;
}

lv_obj_t* MainMenu::add_version_module(lv_obj_t * status_bar)
{
    lv_obj_t * version = lv_label_create(status_bar);
    lv_label_set_text(version, "V-1.5A");
    lv_obj_set_style_transform_angle(version, 900, 0);
    lv_obj_set_style_transform_pivot_x(version, lv_obj_get_width(version) / 2, 0);
    lv_obj_set_style_transform_pivot_y(version, lv_obj_get_height(version) / 2, 0);   
    lv_obj_set_pos(version, 8, 0);
    lv_obj_set_style_text_font(version, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(version, lv_color_hex(0x89C289), LV_STATE_DEFAULT);
    return version;
}

lv_obj_t * MainMenu::create_status_bar(lv_obj_t * parent) {
    lv_obj_t * status_bar = lv_obj_create(parent);
    lv_obj_set_height(status_bar, LV_PCT(100));
    lv_obj_set_width(status_bar, LV_DPX(35));
    lv_obj_set_style_border_width(status_bar, 0, LV_PART_MAIN);
    lv_obj_set_style_outline_width(status_bar, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(status_bar, lv_color_hex(0x2A2A2A), 0);
    lv_obj_set_style_bg_opa(status_bar, LV_OPA_COVER, 0);
    lv_obj_set_scrollbar_mode(status_bar, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_layout(status_bar, LV_LAYOUT_NONE);

    lv_obj_align(status_bar, LV_ALIGN_RIGHT_MID, 0, 0);

    versionlabel = add_version_module(status_bar);
    batteryversion = add_battery_module(status_bar);

     int xOffset = 185;

#ifdef HAS_BT
    lv_obj_t* bt_icon = lv_label_create(status_bar);
    SBIcons.add(bt_icon);
    lv_label_set_text(bt_icon, LV_SYMBOL_BLUETOOTH);
    lv_obj_set_style_transform_angle(bt_icon, 900, 0);
    lv_obj_set_style_transform_pivot_x(bt_icon, lv_obj_get_width(bt_icon) / 2, 0);
    lv_obj_set_style_transform_pivot_y(bt_icon, lv_obj_get_height(bt_icon) / 2, 0);   
    lv_obj_set_pos(bt_icon, 8, xOffset -= 16);
    lv_obj_set_style_text_color(bt_icon, lv_color_hex(0x89C289), LV_STATE_DEFAULT);
#endif

#ifdef SD_CARD_CS_PIN
    lv_obj_t* sd_icon = lv_label_create(status_bar);
    SBIcons.add(sd_icon);
    lv_label_set_text(sd_icon, LV_SYMBOL_SD_CARD);
    lv_obj_set_style_transform_angle(sd_icon, 900, 0);
    lv_obj_set_style_transform_pivot_x(sd_icon, lv_obj_get_width(sd_icon) / 2, 0);
    lv_obj_set_style_transform_pivot_y(sd_icon, lv_obj_get_height(sd_icon) / 2, 0);   
    lv_obj_set_pos(sd_icon, 8, xOffset -= 20);
    lv_obj_set_style_text_color(sd_icon, lv_color_hex(0x89C289), LV_STATE_DEFAULT);
#endif

    lv_obj_t* wifi_icon = lv_label_create(status_bar);
    SBIcons.add(wifi_icon);
    lv_label_set_text(wifi_icon, LV_SYMBOL_WIFI);
    lv_obj_set_style_transform_angle(wifi_icon, 900, 0);
    lv_obj_set_style_transform_pivot_x(wifi_icon, lv_obj_get_width(wifi_icon) / 2, 0);
    lv_obj_set_style_transform_pivot_y(wifi_icon, lv_obj_get_height(wifi_icon) / 2, 0);   
    lv_obj_set_pos(wifi_icon, 8, xOffset -= 23);
    lv_obj_set_style_text_color(wifi_icon, lv_color_hex(0x89C289), LV_STATE_DEFAULT);
    return status_bar;
}
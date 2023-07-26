#pragma once

// VIAが0xFEEDを許容しなくなっていたので、自分用だし適当に変更
#undef VENDOR_ID
#define VENDOR_ID 0xBEEF

// WindowsのリモートデスクトップにShiftが送られていないので、
// 1000Hz -> 100Hz に戻す
// https://github.com/qmk/qmk_firmware/blob/master/docs/ja/keycodes_us_ansi_shifted.md
#define USB_POLLING_INTERVAL_MS 10

// 安物のUSBハブ付きテンキーでバスパワー不測の警告が出たので、
// デフォルト値500mA -> 100mA に変更
// ※実測はしていないが、LED付き75%キーボードのMD770が警告なしで動いているのだから、
// 　LEDなし36キーのMiniAxeが動かないわけがない
#define USB_MAX_POWER_CONSUMPTION 100

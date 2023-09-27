#pragma once

// VIAが0xFEEDを許容しなくなっていたので、自分用だし適当に変更
#undef VENDOR_ID
#define VENDOR_ID 0xBEEF

// VIAのレイヤー数にNICOLA用レイヤー分を追加
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
// 8枚以上レイヤーを使うことはないので削減
#define LAYER_STATE_8BIT

// WindowsのリモートデスクトップにShiftが送られていないので、
// 1000Hz -> 100Hz に戻す
// https://github.com/qmk/qmk_firmware/blob/master/docs/ja/keycodes_us_ansi_shifted.md
#define USB_POLLING_INTERVAL_MS 10

// 安物のUSBハブ付きテンキーでバスパワー不測の警告が出たので、
// デフォルト値500mA -> 100mA に変更
// ※実測はしていないが、LED付き75%キーボードのMD770が警告なしで動いているのだから、
// 　LEDなし36キーのMiniAxeが動かないわけがない
#define USB_MAX_POWER_CONSUMPTION 100

// MiniAxeは36キーなので、読点「、」を入力するためにあいまいな句読点を使用する
#define NICOLA_FUZZY_PUNCTUATION

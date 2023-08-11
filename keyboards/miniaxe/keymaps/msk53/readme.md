# 私家版VIA/Remap対応MiniAxe
VIAだとKC_INT系が指定できなかったので、Remapに対応した

## ベースバージョン
Remap対応のため、下記から分岐した
- tag:0.18.17
- VIA_PROTOCOL_VERSION 0x000A

## VENDOR_IDの変更
VIAが既存のVENDOR_ID 0xFEEDを許容しなくなっていたので、
自分用だし分かり易く0xBEEFに変更した。  
PRODUCT_IDは既存値0x3939のまま変更なし。
歯応えの良いお肉ができた。
~~~json
	"vendorId":"0xBEEF",
	"productId":"0x3939",
~~~

## レイアウト定義ファイル(miniaxe.json)
info.jsonから作成した。
### key colorの指定
- #aaaaaa for modifier keys
    - 最下段の親指キー
- #777777 for accents
    - ホームポジション
### customKeycodes
既存のcustom_keycodesを、VIA/Remapのカスタムキーで選択可能にした。 
```c
enum custom_keycodes {
  QWERTY = USER00, // SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};
```
VIA/Remapのカスタムキーは、VIA有効時のみ使用可能な定数USER00～USER15で定義されている。  
VIA V12 protocol以降はQK_KB_0～QK_KB_31に変更が必要。  
こちらはVIAが無効でも使用可能。  
ref. VIA Protocol 12 + fixes #19916
https://github.com/qmk/qmk_firmware/pull/19916



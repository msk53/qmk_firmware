# 私家版VIA/Remap対応MiniAxe
VIAだとKC_INT系が指定できなかった(2023/04時点)ので、Remapを使用している。  

## ビルド時の指定
キーボード名が"miniaxe/msk53"になる
~~~
qmk compile -kb miniaxe/msk53 -km <keymap>
~~~

## ベースバージョン
2023/09のRemapバージョン更新に、下記で対応
- tag:0.22.10
- VIA_PROTOCOL_VERSION 0x000C

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
  QWERTY = QK_KB_0, // SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};
```
 




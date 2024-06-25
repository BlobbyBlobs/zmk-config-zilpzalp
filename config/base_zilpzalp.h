#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/mouse.h>

#define BIRD 0
#define NUM 1
#define NAV 2
#define SYM 3
#define FUN 4


&sk {
    release-after-ms = <5000>;
   // lazy;
};

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
    conditional_layers {
        compatible = "zmk,conditional-layers";
        tri_layer {
            if-layers = <1 3>;
            then-layer = <4>;
        };
    };
};


#define COMBO(NAME, BINDINGS, KEYPOS, TIMEOUT) \
combo_##NAME { \
    timeout-ms = <TIMEOUT>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
};

/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        COMBO(z, &kp Z, 18 19, 35)
        COMBO(v, &kp V, 0 1, 35)
        COMBO(q, &kp Q, 1 2, 35)
	COMBO(x, &kp X, 19 20, 35)
	COMBO(sqt, &kp SQT, 21 22, 35)
        COMBO(slash, &kp SLASH, 22 23, 35)
        COMBO(enter, &kp ENTER, 21 23, 35)
        COMBO(esc, &kp ESC, 10 18, 40)
        COMBO(tab, &kp TAB, 18 20, 35)
	COMBO(mb1, &mkp MB1, 11 20, 25)
	COMBO(mb2, &mkp MB2, 10 19, 25)
/* parentheticals */
        COMBO(lbkt, &kp LBKT, 0 9, 35)
	COMBO(lbrc, &kp LBRC, 1 10, 35)
        COMBO(lpar, &kp LPAR, 2 11, 35)
        COMBO(lt, &kp LT, 3 12, 35)
        COMBO(gt, &kp GT, 4 13, 35)
        COMBO(rpar, &kp RPAR, 5 14, 35)
        COMBO(rbrc, &kp RBRC, 6 15, 35)
	COMBO(rbkt, &kp RBKT, 7 16, 35)
/* caps */
        COMBO(capslock, &kp CAPSLOCK, 0 7, 50)
        COMBO(caps, &caps_word, 2 5, 50)
/* deletion */ 
        COMBO(delword, &kp LC(BSPC), 5 7, 35)
    };
};


//     __________________________  __________________________
//    /     0  |  1  |  2  |  3  \/   4 |   5 |   6 |   7    \
// |  8  |  9  | 10  | 11  | 12  /\  13 |  14 |  15 |  16 | 17  |
//    \    18  | 19  | 20    /        \    21 |  22 |  23   /
//          \    24  | 25  /            \  26 |  27    /
//           --------------              --------------


/ {

    behaviors {
	
	
        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            retro-tap;
            bindings = <&mo &kp>, <&kp>;
        };

	spc_lt: space_layer_tap {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "tap-preferred";
            tapping-term-ms = <175>;
            quick-tap-ms = <100>;
            retro-tap;
            bindings = <&mo &kp>, <&kp>;
        };

        shift_bp: shift_bp_hold_tap {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "hold-preferred";
            tapping-term-ms = <200>;
            quick-tap-ms = <300>;
            bindings = <&kp>, <&kp>;
        };

	isk: intuitive_sk {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            retro-tap;
            flavor = "hold-preferred";
            tapping-term-ms = <200>;
            bindings = <&kp>, <&sk>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };

	comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};

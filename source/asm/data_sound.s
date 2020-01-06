snd_space_break:
byte 002h,006h,020h,01fh,041h  ; white noise (freq 874 Hz), max vol, swept down, duration 32
byte 010h  ; end

snd_move_invalid:
byte 000h,000h,002h,005h  ; periodic noise (freq 125 Hz), max vol, duration 5
byte 010h  ; end

snd_menu_selection:
byte 080h,0beh,000h,002h  ; tone (freq 588.7Hz), max vol, duration 2
byte 080h,097h,000h,002h  ; tone (freq 740.8Hz), max vol, duration 2
byte 080h,07fh,000h,002h  ; tone (freq 880.8Hz), max vol, duration 2
byte 090h  ; end

snd_victory:
byte 040h,0beh,000h,010h  ; tone (freq 588.7Hz), max vol, duration 16
byte 064h  ; rest, duration 4
byte 040h,0beh,000h,003h  ; tone (freq 588.7Hz), max vol, duration 3
byte 062h  ; rest, duration 2
byte 040h,0beh,000h,003h  ; tone (freq 588.7Hz), max vol, duration 3
byte 062h  ; rest, duration 2
byte 040h,07fh,000h,02ah  ; tone (freq 880.8Hz), max vol, duration 42
byte 050h  ; end
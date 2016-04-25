Channel000:
		.db		$db
		.db		$50
		.db		$dc
		.db		$1f
		.db		$d0
		.db		$00
		.db		$f1
		.db		$ff
bass1:
		.db		$a0
		.db		$30
		.db		$a0
		.db		$30
		.db		$a0
		.db		$30
		.db		$a0
		.db		$30
		.db		$80
		.db		$30
		.db		$80
		.db		$30
		.db		$80
		.db		$30
		.db		$80
		.db		$30
		.db		$60
		.db		$30
		.db		$60
		.db		$30
		.db		$60
		.db		$30
		.db		$60
		.db		$30
		.db		$30
		.db		$30
		.db		$30
		.db		$30
		.db		$30
		.db		$30
		.db		$30
		.db		$30
		.db		$f1
		.db		$f1
		.db		$ff
head1:
		.db		$50
		.db		$0c
		.db		$50
		.db		$0c
		.db		$00
		.db		$0c
		.db		$50
		.db		$0c
		.db		$30
		.db		$0c
		.db		$30
		.db		$0c
		.db		$00
		.db		$0c
		.db		$30
		.db		$0c
		.db		$60
		.db		$0c
		.db		$60
		.db		$0c
		.db		$00
		.db		$0c
		.db		$60
		.db		$0c
		.db		$a0
		.db		$0c
		.db		$a0
		.db		$0c
		.db		$00
		.db		$0c
		.db		$a0
		.db		$0c
		.db		$f1
		.db		$f1
		.db		$ff
void:
		.db		$00
		.db		$30
		.db		$00
		.db		$30
		.db		$00
		.db		$30
		.db		$00
		.db		$30
		.db		$f1
		.db		$f1
		.db		$ff
drum1:
		.db		$f8
		.db		$00
		.db		$d4
		.db		$ed
		.db		$7f
		.db		$ee
		.db		$ff
		.db		$f8
		.db		$00
		.db		$10
		.db		$18
		.db		$00
		.db		$18
		.db		$f8
		.db		$01
		.db		$20
		.db		$18
		.db		$00
		.db		$18
		.db		$f8
		.db		$00
		.db		$10
		.db		$18
		.db		$10
		.db		$18
		.db		$f8
		.db		$01
		.db		$20
		.db		$18
		.db		$00
		.db		$18
		.db		$f1
		.db		$f1
		.db		$ff
TheBass:
		.db		$f0
		.db		LOW(Channel000)
		.db		HIGH(Channel000)
		.db		$d1
		.db		$dd
		.db		$ee
		.db		$e5
		.db		$00
		.db		$e6
		.db		$00
		.db		$f0
		.db		LOW(bass1)
		.db		HIGH(bass1)
		.db		$ef
		.db		LOW(TheBass)
		.db		HIGH(TheBass)
		.db		$ff
head:
		.db		$f0
		.db		LOW(Channel000)
		.db		HIGH(Channel000)
		.db		$d4
		.db		$dd
		.db		$bf
		.db		$e5
		.db		$05
		.db		$e6
		.db		$07
		.db		$e3
		.db		$00
		.db		$e3
		.db		$08
		.db		$f0
		.db		LOW(void)
		.db		HIGH(void)
		.db		$e4
		.db		$e3
		.db		$08
		.db		$f0
		.db		LOW(head1)
		.db		HIGH(head1)
		.db		$e4
		.db		$e4
		.db		$ef
		.db		LOW(head)
		.db		HIGH(head)
		.db		$ff
DRUM:
		.db		$f0
		.db		LOW(Channel000)
		.db		HIGH(Channel000)
		.db		$d5
		.db		$dd
		.db		$ff
		.db		$f8
		.db		$00
		.db		$e3
		.db		$00
		.db		$e3
		.db		$04
		.db		$f0
		.db		LOW(void)
		.db		HIGH(void)
		.db		$e4
		.db		$e3
		.db		$08
		.db		$f0
		.db		LOW(drum1)
		.db		HIGH(drum1)
		.db		$e4
		.db		$e4
		.db		$ef
		.db		LOW(DRUM)
		.db		HIGH(DRUM)
		.db		$ff
Channel001:
		.db		$dc
		.db		$1f
		.db		$d1
		.db		$f8
		.db		$00
		.db		$dd
		.db		$ff
		.db		$e5
		.db		$10
		.db		$f1
		.db		$ff
Channel002:
		.db		$f0
		.db		LOW(Channel001)
		.db		HIGH(Channel001)
		.db		$10
		.db		$0c
		.db		$ff
Channel003:
		.db		$dc
		.db		$1f
		.db		$d3
		.db		$f8
		.db		$00
		.db		$dd
		.db		$ff
		.db		$e5
		.db		$16
		.db		$f1
		.db		$ff
Channel004:
		.db		$f0
		.db		LOW(Channel003)
		.db		HIGH(Channel003)
		.db		$60
		.db		$0c
		.db		$ff
MODU_TAB:
wiggle2:					;0
	.db	$00
	.db	$00
	.db	$01
	.db	$02
	.db	$04
	.db	$08
	.db	$0c
	.db	$10
	.db	$14
	.db	$10
	.db	$0c
	.db	$08
	.db	$04
	.db	$02
	.db	$01
	.db	$00
	.db	$00
	.db	$ff
	.db	$fe
	.db	$fc
	.db	$f8
	.db	$f4
	.db	$f0
	.db	$ec
	.db	$f0
	.db	$f4
	.db	$f8
	.db	$fc
	.db	$fe
	.db	$ff
	.db	$00
	.db	$00
	.db	$80
;----- end wiggle2 ----
;----end MODU_TAB----

;--------percussion-----------
perc000:
	.db	$c0
	.db	$11
	.db	$e0
	.db	$2d
	.db	$d0
	.db	$ff
	.db	$b3
	.db	$ac
	.db	$b0
	.db	$67
	.db	$1f
	.db	$1b
	.db	$1d
	.db	$1a
	.db	$f0
perc001:
	.db	$c0
	.db	$11
	.db	$e0
	.db	$2d
	.db	$d0
	.db	$ff
	.db	$b3
	.db	$ac
	.db	$b0
	.db	$67
	.db	$1f
	.db	$1b
	.db	$1d
	.db	$1a
	.db	$f0
perc002:
	.db	$c0
	.db	$11
	.db	$e0
	.db	$2d
	.db	$d0
	.db	$ff
	.db	$b3
	.db	$ac
	.db	$b0
	.db	$67
	.db	$1f
	.db	$1b
	.db	$1d
	.db	$1a
	.db	$f0
perc003:
	.db	$c0
	.db	$01
	.db	$e0
	.db	$00
	.db	$d0
	.db	$dd
	.db	$bf
	.db	$ff
	.db	$bf
	.db	$ff
	.db	$bb
	.db	$b8
	.db	$f0
perc004:
	.db	$c0
	.db	$01
	.db	$e0
	.db	$00
	.db	$d0
	.db	$ff
	.db	$b0
	.db	$c8
	.db	$b1
	.db	$90
	.db	$b3
	.db	$20
	.db	$0f
	.db	$14
	.db	$b3
	.db	$e8
	.db	$b2
	.db	$ee
	.db	$0f
	.db	$14
	.db	$b3
	.db	$e8
	.db	$b7
	.db	$d0
	.db	$bb
	.db	$b8
	.db	$bf
	.db	$ff
	.db	$09
	.db	$0f
	.db	$f0
perc005:
	.db	$c0
	.db	$03
	.db	$e0
	.db	$1e
	.db	$d0
	.db	$dd
	.db	$b0
	.db	$c8
	.db	$1e
	.db	$b1
	.db	$5e
	.db	$f0
perc006:
	.db	$c0
	.db	$11
	.db	$e0
	.db	$2d
	.db	$d0
	.db	$ff
	.db	$b3
	.db	$ac
	.db	$b0
	.db	$67
	.db	$1f
	.db	$1b
	.db	$1d
	.db	$1a
	.db	$f0
perc007:
	.db	$c0
	.db	$01
	.db	$e0
	.db	$00
	.db	$d0
	.db	$ff
	.db	$b3
	.db	$ac
	.db	$b0
	.db	$67
	.db	$1f
	.db	$1b
	.db	$1d
	.db	$b1
	.db	$f4
	.db	$b3
	.db	$84
	.db	$f0
perc008:
	.db	$c0
	.db	$11
	.db	$e0
	.db	$2d
	.db	$d0
	.db	$ff
	.db	$b3
	.db	$ac
	.db	$b0
	.db	$67
	.db	$1f
	.db	$1b
	.db	$1d
	.db	$1a
	.db	$f0
perc009:
	.db	$c0
	.db	$11
	.db	$e0
	.db	$2d
	.db	$d0
	.db	$ff
	.db	$b3
	.db	$ac
	.db	$b0
	.db	$67
	.db	$1f
	.db	$1b
	.db	$1d
	.db	$1a
	.db	$f0
perc010:
	.db	$c0
	.db	$11
	.db	$e0
	.db	$2d
	.db	$d0
	.db	$ff
	.db	$b3
	.db	$ac
	.db	$b0
	.db	$67
	.db	$1f
	.db	$1b
	.db	$1d
	.db	$1a
	.db	$f0
perc011:
	.db	$c0
	.db	$11
	.db	$e0
	.db	$2d
	.db	$d0
	.db	$ff
	.db	$b3
	.db	$ac
	.db	$b0
	.db	$67
	.db	$1f
	.db	$1b
	.db	$1d
	.db	$1a
	.db	$f0
;--------end percussion-----------

PITCH_IX:		=		$0000
FREQ_IX:		=		$0000
MODU_IX:
		.db		LOW(wiggle2)
		.db		HIGH(wiggle2)
;----end MODU_IX----

DRUM_TAB:
		.db		LOW(perc003)
		.db		HIGH(perc003)
		.db		LOW(perc004)
		.db		HIGH(perc004)
		.db		LOW(perc005)
		.db		HIGH(perc005)
		.db		LOW(perc006)
		.db		HIGH(perc006)
		.db		LOW(perc007)
		.db		HIGH(perc007)
		.db		LOW(perc008)
		.db		HIGH(perc008)
		.db		LOW(perc009)
		.db		HIGH(perc009)
		.db		LOW(perc010)
		.db		HIGH(perc010)
		.db		LOW(perc011)
		.db		HIGH(perc011)
		.db		LOW(perc000)
		.db		HIGH(perc000)
		.db		LOW(perc001)
		.db		HIGH(perc001)
		.db		LOW(perc002)
		.db		HIGH(perc002)
TEMPO:			=		$0050
WAVE_BASE:		=		$0000
N_WAVES:		=		0

;--------Begin NOPE--------
NOPE:
		.db		$23
		.db		LOW(TheBass)
		.db		HIGH(TheBass)
		.db		LOW(head)
		.db		HIGH(head)
		.db		LOW(DRUM)
		.db		HIGH(DRUM)
;--------End NOPE--------

;--------Begin Beep--------
Beep:
		.db		$a0
		.db		LOW(Channel002)
		.db		HIGH(Channel002)
;--------End Beep--------

;--------Begin Boop--------
Boop:
		.db		$a0
		.db		LOW(Channel004)
		.db		HIGH(Channel004)
;--------End Boop--------

;-----------Track Index Table------------
TRACK_IX:
		.db		LOW(NOPE)
		.db		HIGH(NOPE)
		.db		LOW(Beep)
		.db		HIGH(Beep)
		.db		LOW(Boop)
		.db		HIGH(Boop)
;-----------End Track Index Table--------

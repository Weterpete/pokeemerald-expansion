GraniteCave_B2F_MapScripts::
	.byte 0

BrawlyIsInACave::
	lockall
	faceplayer
	msgbox BrawlyIsInACave_Text_0, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	removeobject 10
	clearflag FLAG_UNUSED_0x02F
	setflag FLAG_UNUSED_0x030
	delay 40
	fadescreen FADE_FROM_BLACK
	releaseall
	end


WallyIsInAGym::
	msgbox WallyIsInAGym_Text_0, MSGBOX_NPC
	end


BrawlyIsInACave_Text_0:
	.string "Oh!\pAre you a challenger?\nI knew I shouldn't have left the\lGYM early today.\pI'll head back now.$"

WallyIsInAGym_Text_0:
	.string "{PLAYER}!\nAre you looking for BRAWLY too?\pHe must've gone off somewhere.\nMaybe check GRANITE CAVE?$"

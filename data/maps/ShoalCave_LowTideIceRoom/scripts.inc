ShoalCave_LowTideIceRoom_MapScripts::
	.byte 0

ShoalCave_LowTideIceRoom_Alecia::
	lockall
	faceplayer
	playbgm MUS_ENCOUNTER_ELITE_FOUR, 0
	msgbox Alecia_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MARCOS, Alecia_Defeat
	msgbox Alecia_Outro, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playse SE_BALL_THROW
	waitse
	playse SE_BALL_OPEN
	fadescreen FADE_TO_BLACK
	setflag FLAG_UNUSED_0x029
	removeobject 2
	fadescreen FADE_FROM_BLACK
	releaseall
	return


Alecia_Intro::
	.string "ALECIA: What's that, kiddo?\nOh yes, I did direct that LAPRAS to\lblock the gym.\pARTHUR's approach of directly hassling\nthe GYM LEADER built up bad blood.\pIn my opinion, it would be better to\ncreate a problem and solve it to become\la hero in the citizens' eyes.\pI suppose you'll want to be battle me\nnow to thwart my plan.\pSo be it.$"

Alecia_Defeat::
	.string "RATTATAS!\nYou cleansed my toxins!$"

Alecia_Outro::
	.string "Well now I suppose you'll want me to\ncall back the LAPRAS?\pIf I must oblige…\pNow, to make my departure.\nSMOKE BALL, GO!$"

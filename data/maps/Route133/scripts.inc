Route133_MapScripts::
	.byte 0

Route133_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN, Route133_Text_FranklinIntro, Route133_Text_FranklinDefeat
	msgbox Route133_Text_FranklinPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA, Route133_Text_DebraIntro, Route133_Text_DebraDefeat
	msgbox Route133_Text_DebraPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Linda::
	trainerbattle_single TRAINER_LINDA, Route133_Text_LindaIntro, Route133_Text_LindaDefeat
	msgbox Route133_Text_LindaPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN, Route133_Text_WarrenIntro, Route133_Text_WarrenDefeat
	msgbox Route133_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Beck::
	trainerbattle_single TRAINER_BECK, Route133_Text_BeckIntro, Route133_Text_BeckDefeat
	msgbox Route133_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Mollie::
	trainerbattle_single TRAINER_MOLLIE, Route133_Text_MollieIntro, Route133_Text_MollieDefeat
	msgbox Route133_Text_MolliePostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Conor::
	trainerbattle_single TRAINER_CONOR, Route133_Text_ConorIntro, Route133_Text_ConorDefeat
	msgbox Route133_Text_ConorPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_RoadBlock::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_HM08, Route133_RoadBlock_2
	msgbox Route133_RoadBlock_Text_5, MSGBOX_NPC
Route133_RoadBlock_1:
	waitmessage
	releaseall
	return

Route133_RoadBlock_2:
	msgbox Route133_RoadBlock_Text_0, MSGBOX_NPC
	goto_if_set FLAG_UNUSED_0x02C, Route133_RoadBlock_5
	msgbox Route133_RoadBlock_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route133_RoadBlock_8
	msgbox Route133_RoadBlock_Text_4, MSGBOX_NPC
	goto Route133_RoadBlock_1

Route133_RoadBlock_5:
	msgbox Route133_RoadBlock_Text_1, MSGBOX_NPC
	goto Route133_RoadBlock_1

Route133_RoadBlock_8:
	msgbox Route133_RoadBlock_Text_3, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	playse SE_WARP_OUT
	removeobject 10
	setflag FLAG_UNUSED_0x02A
	setflag FLAG_UNUSED_0x02C
	delay 40
	fadescreen FADE_FROM_BLACK
	goto Route133_RoadBlock_1


Route133_RoadBlock_Text_0:
	.string "I saw some pirate guy run down by here.\nCan you chase after him?\lIt'd be a huge favor.$"

Route133_RoadBlock_Text_1:
	.string "Oh, wait, sorry.\nI just heard he was spotted somewhere\lelse.\pBetter check there.$"

Route133_RoadBlock_Text_2:
	.string "So do you wanna come this way?\pYou won't have time to check somewhere\nelse if you do.$"

Route133_RoadBlock_Text_3:
	.string "Great! I'll get out of your way then.$"

Route133_RoadBlock_Text_4:
	.string "Alright, but keep searching.\pHe might be on ROUTE 123, if you want to\ncheck there.$"

Route133_RoadBlock_Text_5:
	.string "Excuse me, this route isn't open at the\nmoment. There's a blackout.\pSUNNYSHORE and LUMIOSE are having\nsimilar experiences.$"

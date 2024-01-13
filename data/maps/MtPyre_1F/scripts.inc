MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "All sorts of beings wander the slopes\n"
	.string "of MT. PYRE…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Have a POKéMON hold that\n"
	.string "CLEANSE TAG.\p"
	.string "It will help ward off wild POKéMON.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Did you come to pay your respect\n"
	.string "to the spirits of departed POKéMON?\p"
	.string "You must care for your POKéMON a lot.\p"
    .string "Would you care to train them in a\n"
    .string "gauntlet through this tower?$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "This is the final resting place of my\n"
	.string "ZIGZAGOON. I cherished it…$"

PyreGauntletEntry::
	lockall
	faceplayer
	goto_if_set FLAG_UNUSED_0x027, PyreGauntletEntry_2
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_YESNO
	goto_if_unset FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS, PyreGauntletEntry_5
	msgbox PyreGauntletEntry_Text_4, MSGBOX_DEFAULT
PyreGauntletEntry_1:
	waitmessage
	releaseall
	return

PyreGauntletEntry_2:
	msgbox PyreGauntletEntry_Text_0, MSGBOX_DEFAULT
	goto PyreGauntletEntry_1

PyreGauntletEntry_5:
	compare VAR_RESULT, YES
	goto_if_eq PyreGauntletEntry_8
	msgbox PyreGauntletEntry_Text_3, MSGBOX_DEFAULT
	goto PyreGauntletEntry_1

PyreGauntletEntry_8:
	msgbox PyreGauntletEntry_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_PlayerBackUp
	applymovement 2, MtPyre_LadyBackUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_PlayerGoForward
	waitmovement 0
	applymovement 2, MtPyre_LadyReturn
	waitmovement 0
	msgbox PyreGauntletEntry_Text_2, MSGBOX_DEFAULT
	setflag FLAG_UNUSED_0x027
	goto PyreGauntletEntry_1


MtPyre_PlayerBackUp:
	walk_down
	face_up
	step_end

MtPyre_PlayerGoForward:
	walk_up
	walk_up
	walk_up
	face_down
	step_end

MtPyre_LadyBackUp:
	walk_down
	walk_left
	face_right
	step_end

MtPyre_LadyReturn:
	walk_right
	walk_up
	step_end

PyreGauntletEntry_Text_0:
	.string "You've already made a decision.\nYou may not back out at this point.$"

PyreGauntletEntry_Text_1:
	.string "You may enter, though I do not\nanticipate your victory.$"

PyreGauntletEntry_Text_2:
	.string "Now you're stuck here.\pHehehe… good luck!$"

PyreGauntletEntry_Text_3:
	.string "A wise decision, maybe.\nYet it still displays utter cowardice.$"

PyreGauntletEntry_Text_4:
	.string "Apologies, but the mourners are no\nlonger available to “spar.”\pDo not try again later.$"

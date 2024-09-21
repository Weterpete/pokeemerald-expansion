AbandonedShip_Room_B1F_MapScripts::
	.byte 0

AbandonedShip_LegendaryBeastEncounter::
	lockall
	msgbox AbandonedShip_LegendaryBeastEncounter_Text_0
	waitmessage
	closemessage
	random 3
	setflag FLAG_UNUSED_0x04F
	compare VAR_RESULT, 0
	goto_if_eq AbandonedShip_LegendaryBeastEncounter_2
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_LegendaryBeastEncounter_3
	compare VAR_RESULT, 2
	goto_if_eq AbandonedShip_LegendaryBeastEncounter_4
AbandonedShip_LegendaryBeastEncounter_1:
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq AbandonedShip_LegendaryBeastEncounter_9
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq AbandonedShip_LegendaryBeastEncounter_10
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq AbandonedShip_LegendaryBeastEncounter_11
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq AbandonedShip_LegendaryBeastEncounter_12
AbandonedShip_LegendaryBeastEncounter_8:
	waitmessage
	clearflag FLAG_UNUSED_0x04F
	setflag FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_TM13
	releaseall
	return

AbandonedShip_LegendaryBeastEncounter_2:
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAIKOU, 70, ITEM_LUM_BERRY
	goto AbandonedShip_LegendaryBeastEncounter_1

AbandonedShip_LegendaryBeastEncounter_3:
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ENTEI, 70, ITEM_LUM_BERRY
	goto AbandonedShip_LegendaryBeastEncounter_1

AbandonedShip_LegendaryBeastEncounter_4:
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 70, ITEM_LUM_BERRY
	goto AbandonedShip_LegendaryBeastEncounter_1

AbandonedShip_LegendaryBeastEncounter_9:
	call DefeatedOrCaptured_LegendaryBeast
	goto AbandonedShip_LegendaryBeastEncounter_8

AbandonedShip_LegendaryBeastEncounter_10:
	call DefeatedOrCaptured_LegendaryBeast
	goto AbandonedShip_LegendaryBeastEncounter_8

AbandonedShip_LegendaryBeastEncounter_11:
	call RanAway_LegendaryBeast
	goto AbandonedShip_LegendaryBeastEncounter_8

AbandonedShip_LegendaryBeastEncounter_12:
	call RanAway_LegendaryBeast
	goto AbandonedShip_LegendaryBeastEncounter_8


DefeatedOrCaptured_LegendaryBeast::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	return


RanAway_LegendaryBeast::
	playmoncry SPECIES_UNOWN, CRY_MODE_ENCOUNTER
	msgbox RanAway_LegendaryBeast_Text_0, MSGBOX_AUTOCLOSE
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	msgbox RanAway_LegendaryBeast_Text_1
	return


AbandonedShip_LegendaryBeastEncounter_Text_0:
	.string "A mighty beast emerged from the portal!$"

RanAway_LegendaryBeast_Text_0:
	.string "RAAHR…$"

RanAway_LegendaryBeast_Text_1:
	.string "The beast disappeared back into the portal.$"

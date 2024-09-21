MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "When I'm here…\n"
	.string "A curious power flows into me…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "The power is ebbing away…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Perhaps the power is from the spirits\n"
	.string "of POKéMON in fitful sleep here…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… I lost the match, but…\n"
	.string "I have this little ability…\p"
	.string "Without ever laying my hands on\n"
	.string "your POKéNAV… Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Behind you…\n"
	.string "What is it…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Something faded away…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "The POKéMON at rest here…\n"
	.string "Sometimes, they play…$"

MtPyre_6F_Text_CedricIntro:
	.string "Have you lost your bearings?\n"
	.string "Have no fear for I am here!$"

MtPyre_6F_Text_CedricDefeat:
	.string "Weren't you lost?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "I had this feeling that a lost TRAINER\n"
	.string "would be panicked and easy to beat.\p"
	.string "It's dirty and I won't try it again…$"

MtPyre_GhostEncounter::
	lockall
	msgbox MtPyre_GhostEncounter_Text_0
	waitmessage
	closemessage
	playmoncry SPECIES_MISDREAVUS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_UNUSED_0x04F
	setwildbattle SPECIES_MISDREAVUS, 50, ITEM_SALAC_BERRY
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq MtPyre_GhostEncounter_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MtPyre_GhostEncounter_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MtPyre_GhostEncounter_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MtPyre_GhostEncounter_5
MtPyre_GhostEncounter_1:
	waitmessage
	clearflag FLAG_UNUSED_0x04F
	setflag FLAG_ITEM_MT_PYRE_6F_TM30
	releaseall
	return

MtPyre_GhostEncounter_2:
	call DefeatedOrCaptured_Wild_Pokemon
	goto MtPyre_GhostEncounter_1

MtPyre_GhostEncounter_3:
	call DefeatedOrCaptured_Wild_Pokemon
	goto MtPyre_GhostEncounter_1

MtPyre_GhostEncounter_4:
	call RanAway_Wild_Pokemon
	goto MtPyre_GhostEncounter_1

MtPyre_GhostEncounter_5:
	call RanAway_Wild_Pokemon
	goto MtPyre_GhostEncounter_1


DefeatedOrCaptured_Wild_Pokemon::
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	return


RanAway_Wild_Pokemon::
	playmoncry SPECIES_MISDREAVUS, CRY_MODE_ENCOUNTER
	msgbox RanAway_Wild_Pokemon_Text_0, MSGBOX_AUTOCLOSE
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	msgbox RanAway_Wild_Pokemon_Text_1
	return


MtPyre_GhostEncounter_Text_0:
	.string "A vengeful spirit emerged from the bag!$"

RanAway_Wild_Pokemon_Text_0:
	.string "Reavuss…$"

RanAway_Wild_Pokemon_Text_1:
	.string "The MISDREAVUS flew away ethereally.$"

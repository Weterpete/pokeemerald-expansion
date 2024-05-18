MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3R_1R_EventScript_PoryPC::
	lockall
	setvar VAR_UNUSED_0x409D, 1
	msgbox PoryPC_Intro, MSGBOX_DEFAULT
	goto EventScript_PC
	releaseall
	end

PoryPC_Trigger::
	lockall
	playmoncry SPECIES_PORYGON2, CRY_MODE_NORMAL
	msgbox PoryPC_Broke, MSGBOX_DEFAULT
	waitmessage
	fadescreen FADE_TO_BLACK
	removeobject 5
	setflag FLAG_UNUSED_0x028
	delay 20
	fadescreen FADE_FROM_BLACK
	setvar VAR_UNUSED_0x409D, 2
	releaseall
	end

PoryPC_Intro:
	.string "This PORYGON2 looks volatile, but like\n"
	.string "it could be used as a PC.$"

PoryPC_GoodVersion:
	.string "This PORYGON2 looks helpful, like it\n"
	.string "could be used as a PC.$"

PoryPC_Broke:
	.string "Oh, no!\p"
	.string "It broke. You won't be able to use it\n"
	.string "again.$"

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "What did I do to deserve this guard\n"
	.string "posting?\p"
	.string "My left ear is burning up!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "I'm getting heat exhaustion…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Do you think it's odd that we're wearing\n"
	.string "hoods in this magma-filled volcano?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "We joined so we can help our leader\n"
	.string "achieve his fantastic vision.\p"
	.string "I don't care if you're with TEAM AQUA\n"
	.string "or if you're just some kid passing by.\p"
	.string "No one interferes with us and gets\n"
	.string "away with it!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh, no!\n"
	.string "You're not to be trusted at all!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Listen to me.\n"
	.string "TEAM MAGMA is right!\p"
	.string "Don't listen to TEAM AQUA.\n"
	.string "Don't believe their lies!$"


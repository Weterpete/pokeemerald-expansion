SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Who are you?\n"
	.string "Where did you come in from?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Lost it…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "I can't find the way out!\p"
	.string "I'm not afraid. Don't get me wrong!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Turns out that my problem wasn't warp\n"
	.string "panels at all! It was being a man.$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "And Shelly was so supportive…$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Dressing like this feels so much better\n"
	.string "than before!\p"
	.string "Losing doesn't, though. You punk.$"


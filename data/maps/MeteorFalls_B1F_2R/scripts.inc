MeteorFalls_B1F_2R_MapScripts::
	.byte 0

MeteorFalls_B1F_2R_RegiPortal::
	lockall
	msgbox MeteorFalls_B1F_2R_RegiPortal_Text_0
	waitmessage
	closemessage
	setflag FLAG_ITEM_METEOR_FALLS_B1F_2R_TM02
	random 3
	compare VAR_RESULT, 0
	goto_if_eq MeteorFalls_B1F_2R_RegiPortal_2
	compare VAR_RESULT, 1
	goto_if_eq MeteorFalls_B1F_2R_RegiPortal_3
	compare VAR_RESULT, 2
	goto_if_eq MeteorFalls_B1F_2R_RegiPortal_4
MeteorFalls_B1F_2R_RegiPortal_1:
	releaseall
	return

MeteorFalls_B1F_2R_RegiPortal_2:
	playmoncry SPECIES_REGIROCK, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	warp MAP_DESERT_RUINS, 2
	goto MeteorFalls_B1F_2R_RegiPortal_1

MeteorFalls_B1F_2R_RegiPortal_3:
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	warp MAP_ISLAND_CAVE, 2
	goto MeteorFalls_B1F_2R_RegiPortal_1

MeteorFalls_B1F_2R_RegiPortal_4:
	playmoncry SPECIES_REGISTEEL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	warp MAP_ANCIENT_TOMB, 2
	goto MeteorFalls_B1F_2R_RegiPortal_1


MeteorFalls_B1F_2R_RegiPortal_Text_0:
	.string "You were dragged into the portal!$"

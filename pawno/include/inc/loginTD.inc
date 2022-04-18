#include <YSI\y_hooks>

//

static 
    Text:gblackbar[3];

hook OnGameModeInit(){
	blackbar1 = TextDrawCreate(0.000000, -1.000000, "New Textdraw");
	TextDrawBackgroundColor(blackbar1, 255);
	TextDrawFont(blackbar1, 1);
	TextDrawLetterSize(blackbar1, 0.000000, 14.100000);
	TextDrawColor(blackbar1, -1);
	TextDrawSetOutline(blackbar1, 0);
	TextDrawSetProportional(blackbar1, 1);
	TextDrawSetShadow(blackbar1, 1);
	TextDrawUseBox(blackbar1, 1);
	TextDrawBoxColor(blackbar1, 255);
	TextDrawTextSize(blackbar1, 711.000000, 10.000000);
	TextDrawSetSelectable(blackbar1, 0);

	blackbar2 = TextDrawCreate(0.000000, 319.000000, "New Textdraw");
	TextDrawBackgroundColor(blackbar2, 255);
	TextDrawFont(blackbar2, 1);
	TextDrawLetterSize(blackbar2, 0.000000, 14.100000);
	TextDrawColor(blackbar2, -1);
	TextDrawSetOutline(blackbar2, 0);
	TextDrawSetProportional(blackbar2, 1);
	TextDrawSetShadow(blackbar2, 1);
	TextDrawUseBox(blackbar2, 1);
	TextDrawBoxColor(blackbar2, 255);
	TextDrawTextSize(blackbar2, 711.000000, 10.000000);
	TextDrawSetSelectable(blackbar2, 0);

	//

	return 1;
}

hook OnPlayerConnect(playerid){

	ToggleLoginTDForPlayer(playerid, true);
	return 1;
}

hook OnPlayerSpawn(playerid){

	ToggleLoginTDForPlayer(playerid, false);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason){

	ToggleLoginTDForPlayer(playerid, false);
	return 1;
}

ToggleLoginTDForPlayer(playerid, bool:status){

	new i;

	if(status){
		for(i = 0; i < sizeof(gTextDrawLogin); i++)
			TextDrawShowForPlayer(playerid, gTextDrawLogin[i]);
	}
	else{
		for(i = 0; i < sizeof(gTextDrawLogin); i++)
			TextDrawHideForPlayer(playerid, gTextDrawLogin[i]);
	}

	return 1;
}
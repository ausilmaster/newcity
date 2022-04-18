#include <YSI\y_hooks>

new PlayerText:cWspeedo[MAX_PLAYERS][10];

hook OnGameModeInit()
{
	print("\n--------------------------------------");
	print("-----Vehicle Speedometer by ConnorW-----");
	print("--------------------------------------\n");
	return 1;
}

hook OnPlayerConnect(playerid)
{
	//------------------------------------------------------------------------//
	cWspeedo[playerid][0] = CreatePlayerTextDraw(playerid, 525.111389, 394.088836, "box");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][0], 0.000000, -0.044444);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][0], 623.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][0], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][0], -1);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][0], 0x000000AA);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][0], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][0], 0);

	cWspeedo[playerid][1] = CreatePlayerTextDraw(playerid, 627.777770, 365.715454, "box");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][1], 0.000000, 6.133327);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][1], 621.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][1], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][1], -1);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][1], 1);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][1], 0x000000AA);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][1], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][1], 0);

	cWspeedo[playerid][2] = CreatePlayerTextDraw(playerid, 565.889099, 341.168945, "");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][2], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][2], 60.000000, 73.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][2], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][2], 5);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawSetPreviewModel(playerid, cWspeedo[playerid][2], 411);
	PlayerTextDrawSetPreviewRot(playerid, cWspeedo[playerid][2], 0.000000, 0.000000, -30.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, cWspeedo[playerid][2], 1, 1);

	cWspeedo[playerid][3] = CreatePlayerTextDraw(playerid, 524.222167, 395.582153, "220");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][3], 0.342222, 1.316266);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][3], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][3], 1);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][3], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][3], 3);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][3], 0);

	cWspeedo[playerid][4] = CreatePlayerTextDraw(playerid, 523.777770, 382.142395, "infernus");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][4], 0.172888, 0.903111);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][4], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][4], 1);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][4], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][4], 2);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][4], 0);

	cWspeedo[playerid][5] = CreatePlayerTextDraw(playerid, 526.000244, 408.026733, "KM/H");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][5], 0.175555, 0.669155);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][5], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][5], -1378294017);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][5], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][5], 0);

	cWspeedo[playerid][6] = CreatePlayerTextDraw(playerid, 572.933105, 396.080047, "100");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][6], 0.301333, 1.171911);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][6], 2);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][6], 1);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][6], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][6], 3);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][6], 0);

	cWspeedo[playerid][7] = CreatePlayerTextDraw(playerid, 572.509460, 407.528869, "FUEL");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][7], 0.151111, 0.689067);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][7], 2);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][7], -1378294017);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][7], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][7], 0);

	cWspeedo[playerid][8] = CreatePlayerTextDraw(playerid, 621.111633, 396.080108, "999.0");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][8], 0.231555, 1.052444);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][8], 3);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][8], 1);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][8], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][8], 3);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][8], 0);

	cWspeedo[playerid][9] = CreatePlayerTextDraw(playerid, 618.444335, 406.533325, "HEALTH");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][9], 0.145778, 0.699022);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][9], 3);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][9], -1378294017);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][9], 255);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][9], 0);

	//-------------------------------------------------------------------------//

	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	for(new i = 0; i < 10; i ++) {
        PlayerTextDrawDestroy(playerid, cWspeedo[playerid][i]);
		cWspeedo[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
	}
	return 1;
}


hook OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER)
	{
	    new vehicleid = GetPlayerVehicleID(playerid);
        new vstr[30];
		format(vstr, sizeof(vstr), "%s", GetVehicleName(vehicleid));
		PlayerTextDrawSetString(playerid, cWspeedo[playerid][4], vstr);

		if(!PlayerInfo[playerid][pToggleTextdraws] && VehicleHasEngine(vehicleid)){
	        PlayerTextDrawSetPreviewModel(playerid, cWspeedo[playerid][2], GetVehicleModel(GetPlayerVehicleID(playerid)));		    
			if(!IsAbicycle(vehicleid))
			{
				ShowCWSpeedo(playerid);
			}
		}
	}
	else if(oldstate == PLAYER_STATE_DRIVER)
	{
        HideCWSpeedo(playerid);
	}
	return 1;
}

hook OnPlayerUpdate(playerid)
{
	new vehicle = GetPlayerVehicleID(playerid);
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER) // Making sure the player is in a vehicle as driver
	{
		new Float:H;
		GetVehicleHealth(vehicle, H);
		new speed[24];
		format(speed, sizeof(speed), "%.0f", GetVehicleSpeed(vehicle));
		PlayerTextDrawSetString(playerid, cWspeedo[playerid][3], speed);
		new vehfuel[24];
		format(vehfuel, sizeof(vehfuel), "%d", vehicleFuel[vehicle]);
		PlayerTextDrawSetString(playerid, cWspeedo[playerid][6], vehfuel);
        new vehiclehealth[24];
        format(vehiclehealth, sizeof(vehiclehealth), "%.1f", H);
		PlayerTextDrawSetString(playerid, cWspeedo[playerid][8], vehiclehealth);
	}
	return 1;
}

IsAbicycle(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 481, 509, 510: return true;
	}
	return false;
}

ShowCWSpeedo(playerid){
	for(new i = 0; i < 10; i++) {
		PlayerTextDrawShow(playerid, cWspeedo[playerid][i]);
	}
	return 1;
}
HideCWSpeedo(playerid){
	for(new i = 0; i < 10; i++) {
		PlayerTextDrawHide(playerid, cWspeedo[playerid][i]);
	}
	return 1;
}
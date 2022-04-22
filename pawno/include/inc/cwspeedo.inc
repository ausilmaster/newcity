#include <YSI\y_hooks>

new PlayerText:cWspeedo[MAX_PLAYERS][24];

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
	cWspeedo[playerid][23] = CreatePlayerTextDraw(playerid, 495.500000, 385.562500, "LD_SPAC:WHITE");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][23], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][23], 119.000000, 46.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][23], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][23], 0x24282DFF);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][23], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][23], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][23], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][23], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][23], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][23], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][23], 0);

	cWspeedo[playerid][22] = CreatePlayerTextDraw(playerid, 517.500000, 396.937500, "particle:lamp_shad_64");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][22], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][22], 102.000000, -10.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][22], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][22], 0xFFFFFF19);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][22], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][22], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][22], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][22], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][22], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][22], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][22], 0);

	cWspeedo[playerid][21] = CreatePlayerTextDraw(playerid, 497.500000, 386.875000, "LD_SPAC:WHITE");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][21], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][21], 28.000000, 11.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][21], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][21], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][21], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][21], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][21], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][21], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][21], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][21], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][21], 0);

	cWspeedo[playerid][20] = CreatePlayerTextDraw(playerid, 495.000000, 396.937500, "particle:lamp_shad_64");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][20], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][20], 32.000000, -10.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][20], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][20], 0xFF0000D7);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][20], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][20], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][20], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][20], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][20], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][20], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][20], 0);

	cWspeedo[playerid][19] = CreatePlayerTextDraw(playerid, 511.000000, 387.750000, "particle:lamp_shad_64");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][19], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][19], 105.000000, 10.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][19], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][19], 0xFFFFFF17);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][19], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][19], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][19], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][19], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][19], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][19], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][19], 0);

	cWspeedo[playerid][18] = CreatePlayerTextDraw(playerid, 570.000000, 389.062500, "FUEL: 49 L");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][18], 0.187500, 0.676800);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][18], 0.000000, 79.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][18], 2);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][18], 0xFFFFFFFF);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][18], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][18], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][18], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][18], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][18], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][18], 1);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][18], 0);

	cWspeedo[playerid][17] = CreatePlayerTextDraw(playerid, 502.000000, 428.437500, "particle:lamp_shad_64");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][17], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][17], 103.000000, -29.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][17], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][17], 0xFFFFFF0A);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][17], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][17], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][17], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][17], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][17], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][17], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][17], 0);

	cWspeedo[playerid][16] = CreatePlayerTextDraw(playerid, 497.500000, 399.125000, "LD_SPAC:WHITE");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][16], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][16], 28.000000, 30.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][16], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][16], 0xA52A2AFF);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][16], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][16], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][16], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][16], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][16], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][16], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][16], 0);

	cWspeedo[playerid][15] = CreatePlayerTextDraw(playerid, 498.500000, 399.125000, "LD_SPAC:WHITE");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][15], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][15], 26.000000, 29.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][15], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][15], 0x24282DFF);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][15], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][15], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][15], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][15], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][15], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][15], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][15], 0);

	cWspeedo[playerid][14] = CreatePlayerTextDraw(playerid, 511.000000, 402.625000, "SB");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][14], 0.151500, 0.545600);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][14], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][14], 2);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][14], -232380673);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][14], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][14], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][14], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][14], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][14], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][14], 0);

	cWspeedo[playerid][13] = CreatePlayerTextDraw(playerid, 510.500000, 411.375000, "ENGINE");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][13], 0.151500, 0.545600);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][13], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][13], 2);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][13], -232380673);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][13], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][13], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][13], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][13], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][13], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][13], 0);

	cWspeedo[playerid][12] = CreatePlayerTextDraw(playerid, 511.000000, 419.687500, "LIGHT");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][12], 0.151500, 0.545600);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][12], -0.029900, 1.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][12], 2);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][12], -232380673);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][12], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][12], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][12], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][12], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][12], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][12], 1);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][12], 0);

	cWspeedo[playerid][11] = CreatePlayerTextDraw(playerid, 496.000000, 425.375000, "particle:lamp_shad_64");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][11], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][11], 30.000000, -26.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][11], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][11], 0xFFFFFF0F);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][11], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][11], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][11], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][11], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][11], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][11], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][11], 0);

	cWspeedo[playerid][10] = CreatePlayerTextDraw(playerid, 569.500000, 402.625000, "0");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][10], 0.433400, 1.735600);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][10], 0.000000, 50.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][10], 2);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][10], 0xFFFFFFFF);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][10], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][10], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][10], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][10], 1);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][10], 0x00000027);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][10], 3);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][10], 1);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][10], 0);

	cWspeedo[playerid][9] = CreatePlayerTextDraw(playerid, 537.000000, 408.750000, "ld_beat:CHIT");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][9], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][9], 2.000000, 2.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][9], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][9], 0xFFFFFF11);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][9], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][9], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][9], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][9], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][9], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][9], 0);

	cWspeedo[playerid][8] = CreatePlayerTextDraw(playerid, 550.500000, 420.125000, "ld_beat:CHIT");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][8], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][8], 2.000000, 2.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][8], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][8], 0xFFFFFF11);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][8], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][8], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][8], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][8], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][8], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][8], 0);

	cWspeedo[playerid][7] = CreatePlayerTextDraw(playerid, 597.500000, 402.625000, "ld_beat:CHIT");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][7], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][7], 2.000000, 2.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][7], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][7], 0xFFFFFF11);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][7], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][7], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][7], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][7], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][7], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][7], 0);

	cWspeedo[playerid][6] = CreatePlayerTextDraw(playerid, 596.500000, 420.562500, "ld_beat:CHIT");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][6], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][6], 4.000000, 4.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][6], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][6], 0xFFFFFF11);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][6], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][6], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][6], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][6], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][6], 0);

	cWspeedo[playerid][5] = CreatePlayerTextDraw(playerid, 555.000000, 402.187500, "ld_beat:CHIT");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][5], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][5], 4.000000, 4.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][5], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][5], 0xFFFFFF05);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][5], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][5], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][5], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][5], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][5], 0);

	cWspeedo[playerid][4] = CreatePlayerTextDraw(playerid, 528.000000, 424.500000, "ld_beat:CHIT");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][4], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][4], 4.000000, 4.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][4], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][4], 0xFFFFFF05);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][4], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][4], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][4], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][4], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][4], 0);

	cWspeedo[playerid][3] = CreatePlayerTextDraw(playerid, 520.000000, 400.875000, "particle:lamp_shad_64");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][3], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][3], 95.000000, -2.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][3], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][3], 0x00000025);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][3], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][3], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][3], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][3], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][3], 0);

	cWspeedo[playerid][2] = CreatePlayerTextDraw(playerid, 516.000000, 417.500000, "particle:lamp_shad_64");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][2], 0.480000, 1.120000);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][2], 63.000000, 14.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][2], 1);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][2], 0xFFFFFF07);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][2], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][2], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][2], 0);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][2], 0);

	cWspeedo[playerid][1] = CreatePlayerTextDraw(playerid, 510.000000, 389.500000, "CAR");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][1], 0.187500, 0.676800);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][1], 1280.000000, 1280.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][1], 2);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][1], 0xFFFFFFFF);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][1], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][1], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][1], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][1], 0);

	cWspeedo[playerid][0] = CreatePlayerTextDraw(playerid, 568.500000, 418.375000, "KM/H");
	PlayerTextDrawLetterSize(playerid, cWspeedo[playerid][0], 0.171000, 0.576200);
	PlayerTextDrawTextSize(playerid, cWspeedo[playerid][0], 0.000000, 73.000000);
	PlayerTextDrawAlignment(playerid, cWspeedo[playerid][0], 2);
	PlayerTextDrawColor(playerid, cWspeedo[playerid][0], 0xFFFFFF2A);
	PlayerTextDrawUseBox(playerid, cWspeedo[playerid][0], 0);
	PlayerTextDrawBoxColor(playerid, cWspeedo[playerid][0], 0x80808080);
	PlayerTextDrawSetShadow(playerid, cWspeedo[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, cWspeedo[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, cWspeedo[playerid][0], 0x000000FF);
	PlayerTextDrawFont(playerid, cWspeedo[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, cWspeedo[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, cWspeedo[playerid][0], 0);

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
		if(!IsAbicycle(newstate))
		{
			ShowCWSpeedo(playerid);
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
		new speed[24];
		format(speed, sizeof(speed), "%.0f", GetVehicleSpeed(vehicle));
		PlayerTextDrawSetString(playerid, cWspeedo[playerid][10], speed);
		new vehfuel[24];
		format(vehfuel, sizeof(vehfuel), "%dL", vehicleFuel[vehicle]);
		PlayerTextDrawSetString(playerid, cWspeedo[playerid][18], vehfuel);

        new vehicleid = GetPlayerVehicleID(playerid);
		if(GetVehicleParams(vehicleid, VEHICLE_ENGINE))
		{
			PlayerTextDrawColor(playerid, cWspeedo[playerid][13], 852308735);
			PlayerTextDrawShow(playerid, cWspeedo[playerid][13]);
		}
		else 
		{
			PlayerTextDrawColor(playerid, cWspeedo[playerid][13], -232380673);
			PlayerTextDrawShow(playerid, cWspeedo[playerid][13]);
		}
		if(ExBJck[playerid] == 1)
		{
			PlayerTextDrawColor(playerid, cWspeedo[playerid][14], 852308735);
			PlayerTextDrawShow(playerid, cWspeedo[playerid][14]);
		}
		else
		{
			PlayerTextDrawColor(playerid, cWspeedo[playerid][14], -232380673);
			PlayerTextDrawShow(playerid, cWspeedo[playerid][14]);
		}
		if(GetVehicleParams(vehicleid, VEHICLE_LIGHTS))
		{
			PlayerTextDrawColor(playerid, cWspeedo[playerid][12], 852308735);
			PlayerTextDrawShow(playerid, cWspeedo[playerid][12]);
		}
		else
		{
			PlayerTextDrawColor(playerid, cWspeedo[playerid][12], -232380673);
			PlayerTextDrawShow(playerid, cWspeedo[playerid][12]);
		}
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
	for(new i = 0; i < 24; i++) {
		PlayerTextDrawShow(playerid, cWspeedo[playerid][i]);
	}
	return 1;
}
HideCWSpeedo(playerid){
	for(new i = 0; i < 24; i++) {
		PlayerTextDrawHide(playerid, cWspeedo[playerid][i]);
	}
	return 1;
}